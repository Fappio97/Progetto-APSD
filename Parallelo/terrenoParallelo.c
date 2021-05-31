#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// grandezza matrice partenza SIZE * SIZE
#define SIZE 10

// numero volte ciclo
#define VOLTE 5

// percentuali
#define percentualePianteIniziali 0.75
#define percentualeNuovaPianta 0.75
#define percentualeInizioInfezione 0.1
#define numeroMinimoPropagazioneInfezione 1
#define percentualeSeccaPiante 0.3
#define numeroMinimoPropagazionePianteSecche 3

// stati zolla terreno
#define vuoto 0
#define germoglio 1
#define pianta 2
#define albero 3
#define germoglioSecco 4
#define piantaSecca 5
#define alberoSecco 6
#define germoglioInfetto 7
#define piantaInfetta 8
#define alberoInfetto 9

#define for_i for(int i = 0; i < SIZE; ++i)
#define for_j for(int j = 0; j < SIZE; ++j)
#define for_ij for_i for_j


// converte la matrice dinamica in vettore in modo tale da avere elementi continui in memoria
void convertiMatriceInVettore(int** matrice, int* vettore) {
	int k;
	for(int i = 0; i < SIZE; ++i) {
		for(int j = 0; j < SIZE; ++j) {
			k = j * SIZE + i;
			vettore[k] = matrice[i][j];
		}
	}
}

// stampa un vettore come se fosse una matrice
void stampaVettoreComeMatrice(int* vettore, int dimVettore, FILE* output) {
	int cont = 0, x = 0;
	
	for(int i = 0; cont < SIZE * SIZE; i += SIZE, ++cont) {
		if(i >= dimVettore) {
			fprintf(output, "\n");
			x++;
			i = x;
		}
		fprintf(output, "%d ", vettore[i]);
	}
	fprintf(output, "\n\n");
}

// genera casualmente le piante nel terreno iniziale
void generaCasualmenteInizio(int** terreno) {
    unsigned int seed = time(NULL);
    for_ij {
        double random = (double)rand_r(&seed) / RAND_MAX;
        if (random < percentualePianteIniziali) {
            int r1 = rand_r(&seed)%3 +1;
            terreno[i][j] = r1;
        }
        else
            terreno[i][j] = vuoto;
    }

 /*   for_i
        printf("numero random %f\n", rand() / double(RAND_MAX));*/
}

// mi restituisce il numero di adiacenti
int numeroAdiacenti(int* vettore, const int indice, int statoIniziale, int statoFinale, int dimVettoreLocale) { 
	// in questo modo x punta alla colonna precedente al vicino alto sinistro di indice
	// y è sopra di lui
	// z ha l'indice della colonna successiva rispetto ad indice
    int somma = 0, x = indice - SIZE - 1, y = indice - 1, z = indice + SIZE - 1;
    
    for(int i = 0; i < 3; ++i, ++x, ++y, ++z) {
		if(x >= 0)
			if(vettore[x] >= statoIniziale && vettore[x] <= statoFinale)
				somma++;
		if(z < dimVettoreLocale)
			if(vettore[z] >= statoIniziale && vettore[z] <= statoFinale)
				somma++;
		if(y != indice) {
			if(indice % SIZE == 0 && y != indice - 1)
				somma++;
			if((indice - 1) % SIZE == 0 && y != indice + 1)
				somma++;
		}
	}

    return somma;
}

void cicloPiantaViva(int* vettore, int* copiaVettore, const int indice, double r1, double r2, int dimVettoreLocale) {

    if( r1 < percentualeInizioInfezione + (vettore[indice] * 0.01) || numeroAdiacenti(vettore, indice, germoglioInfetto, alberoInfetto, dimVettoreLocale) >= numeroMinimoPropagazioneInfezione)
        copiaVettore[indice] = vettore[indice] + 6;
        
    else if( r2 < percentualeSeccaPiante + (vettore[indice] * 0.01) || numeroAdiacenti(vettore, indice, germoglioSecco, alberoSecco, dimVettoreLocale) >= numeroMinimoPropagazionePianteSecche)
        copiaVettore[indice] = vettore[indice] + 3;
        
    else if(vettore[indice] == germoglio || vettore[indice] == pianta)
    	copiaVettore[indice] = vettore[indice] + 1;

}

void ciclo(int* vettore, int* copiaVettore, const int indice, int dimVettoreLocale) {
    unsigned int seed = time(NULL);
    double random = (double)rand_r(&seed) / RAND_MAX;
    switch(vettore[indice]) {
	case vuoto: {
	    if(random < percentualeNuovaPianta)
		copiaVettore[indice] = germoglio;
            else
                copiaVettore[indice] = vuoto;
            break;
       }
       case germoglioInfetto ... alberoInfetto: {
       		copiaVettore[indice] = vuoto;
            break;
       }
       case germoglioSecco ... alberoSecco: {
        	copiaVettore[indice] = vuoto;
            break;
       }
       case germoglio ... albero: {
       		double random2 = (double)rand_r(&seed) / RAND_MAX;
            cicloPiantaViva(vettore, copiaVettore, indice, random, random2, dimVettoreLocale);
            break;
       }
       default:
       	    break;
    }
}

int main(int argc, char* argv[]) {
  
  	FILE *output;

	// apre il file in scrittura 
  	output = fopen("scrivi.txt", "w");
  	
  	// se non riesce stampa un errore
  	if(output == NULL) {
   		perror("Errore in apertura del file");
    	exit(1);
  	}
  	
	int myID, processi;

	// creo la matrice dinamicamente	
	int** matrice = (int**) malloc(SIZE* sizeof(int*));
	for(int i = 0; i < SIZE; ++i)
		matrice[i] = (int*) malloc(SIZE* sizeof(int));
		
	int dimVettore = SIZE * SIZE;
	
	// creo un vettore in cui linearizzo la matrice dinamica
	int* vettore = (int*) malloc(dimVettore* sizeof(int));
	
	// creo un vettoreLocale dove invierò i vari valori ai processori
	int* vettoreLocale;
	
	// creo una copia del vettoreLocale dove farò le evoluzioni sulla base del vettoreLocale
	int* copiaVettoreLocale;
		
	
	MPI_Init(&argc, &argv);
	
	MPI_Comm_size(MPI_COMM_WORLD, &processi);
	MPI_Comm_rank(MPI_COMM_WORLD, &myID);
	
	MPI_Status status;    
	MPI_Request request;
	
	if(SIZE % processi != 0) {
		if(myID == 0)
			printf("Compila con un numero di processi sottomultiplo di %d\n", SIZE);
		MPI_Finalize();
		exit(1);
	}
	
	// numero elementi che devono essere ripartiti fra i processori
	int elementiPerProcesso = dimVettore / processi;
	
	// la dimensione del vettoreLocale è pari agli elementi per processo + 2 volte la size delle colonne, che rappresentano le colonne ghost
	int dimVettoreLocale = elementiPerProcesso + (2 * SIZE);
	
	vettoreLocale = (int*) malloc(dimVettoreLocale* sizeof(int));
	copiaVettoreLocale = (int*) malloc(dimVettoreLocale* sizeof(int));
	
	// Creazione datatype, è continuo in quanto le colonne sul vettore
	// sono scandite linearmente
	MPI_Datatype datatype;
	MPI_Type_contiguous(SIZE, MPI_INT, &datatype);
    	MPI_Type_commit(&datatype);
	
	if(myID == 0) {
		fprintf(output, "Terreno iniziale\n");
		for_i {
			for_j {
				matrice[i][j] = 0;
				fprintf(output, "%d ", matrice[i][j]);
			}
			fprintf(output, "\n");
		}
		fprintf(output, "\n");
					
		generaCasualmenteInizio(matrice);
		convertiMatriceInVettore(matrice, vettore);
	} 
	
	// inizializzo le parti che non ricevo a -1
	for(int i = 0; i < dimVettoreLocale; ++i)
		vettoreLocale[i] = -1;
	
	// invio ad ogni processo, sul loro vettoreLocale, le colonne su cui devono lavorare
	// da notare che gliele invio sul vettoreLocale non dalla posizione 0 ma dalla poszione
	// SIZE poiché gli elementi che vanno da 0 a SIZE rappresenteranno la cella ghost di sinistra
	// per quel processore e siccome il vettoreLocale ha dimensione dimVettoreLocale + (2 * SIZE)
	// non si riempirà mai no lo scatter le ultime SIZE posizioni che rappresentano la cella ghost
	// di destra
	
	// creazione di elementi per la topologia cartesiana
	// la topologia cartesiana sarà di una dimensione, non avrà periodicità
	// perché il mio automa cellulare non prevede ciò
	int dimensione[1],cordinate[1];
	dimensione[0] = 0, cordinate[0] = 0;
	int myIDcartesiano;
	MPI_Comm comm1D;
	int periodicita[1];
	
	// periodicità false, non mi serve nel mio automa
	periodicita[0] = 0;  
	
	int riordina = 1;
	MPI_Dims_create(processi, 1, dimensione);
	MPI_Cart_create(MPI_COMM_WORLD, 1, dimensione, periodicita, riordina, &comm1D);
	
	// cerco le cordinate di ogni processo sulla topologia
	MPI_Cart_coords(comm1D, myID, 1, cordinate);
	
	// uso le cordinate ottenute prima per ottenere il mio rank
	MPI_Cart_rank(comm1D, cordinate, &myIDcartesiano);
	
	int sinistra, destra;
	MPI_Cart_shift(comm1D, 0, 1, &sinistra, &destra);

	MPI_Barrier(MPI_COMM_WORLD);
	double inizio = MPI_Wtime();

	// ciclo
	for(int i = 0; i < VOLTE; ++i) {
	
		if(myID == 0) {
			fprintf(output, "Ciclo = %d\n", i);
			stampaVettoreComeMatrice(vettore, dimVettore, output);
		}
		
		// invio gli elementi partizionandoli con lo scatter al vettoreLocale su ogni
		// processo
		MPI_Scatter(vettore, elementiPerProcesso, MPI_INT, &vettoreLocale[SIZE], elementiPerProcesso, MPI_INT, 0, MPI_COMM_WORLD);
	
		// per ogni processore mi domande se esso ha un vicino sinistro e destro
		// dato che la funzione shift restituisce un valore negativo se non possiede quel vicino
		// per ogni vicino scambio, per i vicini da sinistra l'ultima cella del vicino e la metto 
		// nelle posizione da 0 a SIZE, per quelle da destra nell'ultime posizioni del vettoreLocale
		if(sinistra >= 0) {
			MPI_Irecv(&vettoreLocale[0], 1, datatype, sinistra, 2, MPI_COMM_WORLD, &request);
			MPI_Send(&vettoreLocale[SIZE], 1, datatype, sinistra, 3, MPI_COMM_WORLD);
		}
		if(destra >= 0) {
			MPI_Irecv(&vettoreLocale[dimVettoreLocale - SIZE], 1, datatype, destra, 3, MPI_COMM_WORLD, &request);
			MPI_Send(&vettoreLocale[dimVettoreLocale - (2 * SIZE)], 1, datatype, destra, 2, MPI_COMM_WORLD);
		}
	

		// con questo for escludo le celle adiacenti alle celle ghost, sia destra che sinistra
		// poiché non sono ancora sicuro che siano avvenuti gli scambi e per velocità queste
		// possono essere effettuate indifferentemente dalla recv, così le evolvo
		for(int j = SIZE * 2; j < dimVettoreLocale - (SIZE * 2); ++j)
			ciclo(vettoreLocale, copiaVettoreLocale, j, dimVettoreLocale);
			
		// metto una barrier perché per poter andare avanti devo essere avvenuti gli scambi
		MPI_Wait(&request, &status);
		
		// effettuo il ciclo da SIZE perché le ccelle da 0 a SIZE sono ghost e quindi non vanno
		// evolute in questo processo
		for(int j = SIZE; j < SIZE * 2; ++j)
			ciclo(vettoreLocale, copiaVettoreLocale, j, dimVettoreLocale);
		for(int j = dimVettoreLocale - (SIZE * 2); j < dimVettoreLocale; ++j)
			ciclo(vettoreLocale, copiaVettoreLocale, j, dimVettoreLocale);

		// ritorno gli elementi dei vettoriLocale di ogni porcessore nel vettore che
		// rappresenta la matrice linearizzata nel processore 0
		MPI_Gather(&copiaVettoreLocale[SIZE], elementiPerProcesso, MPI_INT, vettore, elementiPerProcesso, MPI_INT, 0, MPI_COMM_WORLD);
		
	}
	
	// c'era una gather prima quindi potrei evitare di mettera la barrier in quanto 
	// la messaggistica collettiva è sincronizzata, ma la faccio per una certezza maggiore
	// in quanto c'era un ciclo prima
	MPI_Barrier(MPI_COMM_WORLD);
	double fine = MPI_Wtime();
	
	if(myID == 0)
		fprintf(output, "Durata totale: %f\n", fine - inizio);

	// chiude il file su cui scrive
	fclose(output);
 	
	// deallocazioni
	MPI_Comm_free(&comm1D);
			
	for(int i = 0; i < SIZE; ++i)
		free(matrice[i]);
	free(matrice);
	
	free(vettore);
	
	free(vettoreLocale);	
	
	MPI_Finalize();
return 0;
}

