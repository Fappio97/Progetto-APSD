#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// grandezza matrice partenza SIZE * SIZE
#define SIZE 1000

// numero volte ciclo
#define VOLTE 1000

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

}

int numeroAdiacenti(int** terreno, int i, int j, int statoIniziale, int statoFinale) {
    int somma = 0;
//    printf("i %d, j %d\n", i, j);
    for(int x = i-1; x <= i+1; ++x) {
 //       printf("x %d\n", x);
        for(int y = j-1; y <= j+1; ++y) {
 //           printf("y %d\n", y);
            if(x >= 0 && x < SIZE && y >= 0 && y < SIZE) {
//                printf("primo if\n");
                if(terreno[x][y] >= statoIniziale && terreno[x][y] <= statoFinale) {
//                    printf("secondo if\n");
                    somma++;
                }
            }
        }
    }

    return somma;
}

void cicloPiantaViva(int** terreno, int** copiaTerreno, int i, int j, int stato, double r1, double r2) {
    if( r1 < percentualeInizioInfezione + (stato * 0.01) || (numeroAdiacenti(terreno, i, j, germoglioInfetto, alberoInfetto) >= numeroMinimoPropagazioneInfezione && numeroMinimoPropagazioneInfezione != 0)) {
        copiaTerreno[i][j] += 6;
    }
    else if( r2 < percentualeSeccaPiante + (stato * 0.01) || (numeroAdiacenti(terreno, i, j, germoglioSecco, alberoSecco) >= numeroMinimoPropagazionePianteSecche && numeroMinimoPropagazionePianteSecche != 0)) {
        copiaTerreno[i][j] += 3;
    }
    else if(stato == germoglio || stato == pianta)
        copiaTerreno[i][j] += 1;
    else {
        copiaTerreno[i][j] = stato;
    }
}

void ciclo(int** terreno, int** copiaTerreno) {
    unsigned int seed = time(NULL);
    for_ij {
        double random = (double)rand_r(&seed) / RAND_MAX;
        switch(terreno[i][j]) {
            case vuoto: {
                if(random < percentualeNuovaPianta)
                    copiaTerreno[i][j] = germoglio;
                else
                    copiaTerreno[i][j] = vuoto;
                break;
            }
            case germoglioInfetto ... alberoInfetto: {
                copiaTerreno[i][j] = vuoto;
                break;
            }
            case germoglioSecco ... alberoSecco: {
                copiaTerreno[i][j] = vuoto;
                break;
            }
            case germoglio ... albero: {
                double random2 = (double)rand_r(&seed) / RAND_MAX;
                cicloPiantaViva(terreno, copiaTerreno, i, j, terreno[i][j], random, random2);
                break;
            }
        }
    }
}

int main(int argc, char* argv[]) {

	int** terreno = (int**) malloc(SIZE* sizeof(int*));
	for(int i = 0; i < SIZE; ++i)
		terreno[i] = (int*) malloc(SIZE* sizeof(int));
		
	int** copiaTerreno = (int**) malloc(SIZE* sizeof(int*));
	for(int i = 0; i < SIZE; ++i)
		copiaTerreno[i] = (int*) malloc(SIZE* sizeof(int));
		
	for_ij
		terreno[i][j] = 0;
		
	clock_t inizio = clock();
	
	for(int i = 0; i < VOLTE; ++i)
        ciclo(terreno, copiaTerreno);
        
    printf("Tempo esecuzione = %f", (double) (clock() - inizio) / CLOCKS_PER_SEC );
			
	for(int i = 0; i < SIZE; ++i)
		free(terreno[i]);
	free(terreno);
	
	for(int i = 0; i < SIZE; ++i)
		free(copiaTerreno[i]);
	free(copiaTerreno);
	
return 0;
}

