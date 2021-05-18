/*
This file is part of Terreno.

Terreno is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Terreno is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Terreno.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "terreno.h"


Terreno::Terreno() {
}

Terreno::Terreno(const Terreno& a) {
    allocaMatricePianta();

    for_ij
            terreno[i][j] = a.terreno[i][j];

    for_ij
            copiaTerreno[i][j] = a.copiaTerreno[i][j];

    percentuali = a.percentuali;
    biologico = a.biologico;
}

Terreno::~Terreno() {
    svuota();
}

void Terreno::svuota() {
    for_i
          free(terreno[i]);
    free(terreno);

    for_i
          free(copiaTerreno[i]);
    free(copiaTerreno);
}

void Terreno::operator=(const Terreno & a) {
    svuota();
    allocaMatricePianta();

    for_ij
            terreno[i][j] = a.terreno[i][j];

    for_ij
            copiaTerreno[i][j] = a.copiaTerreno[i][j];

    percentuali = a.percentuali;
    biologico = a.biologico;
}

void Terreno::allocaMatricePianta() {
    terreno = (int**) malloc(dim* sizeof(int*));

    for_i
            terreno[i] = static_cast<int*>(malloc(dim* sizeof(int)));

    copiaTerreno = (int**) malloc(dim* sizeof(int*));

    for_i
            copiaTerreno[i] = static_cast<int*>(malloc(dim* sizeof(int)));
}

void Terreno::copiaMatrice() {
    for_ij
            terreno[i][j] = copiaTerreno[i][j];
}


void Terreno::start() {
    biologico = true;

    allocaMatricePianta();

    for_ij
            terreno[i][j] = vuoto;
}

void Terreno::generaCasualmenteInizio() {
    unsigned int seed = time(NULL);
    for_ij {
        double random = (double)rand_r(&seed) / RAND_MAX;
        if (random < percentuali.percentualePianteIniziali) {
            int r1 = rand_r(&seed)%3 +1;
            terreno[i][j] = r1;
        }
        else
            terreno[i][j] = vuoto;
    }

 /*   for_i
        printf("numero random %f\n", rand() / double(RAND_MAX));*/
}

int Terreno::numeroAdiacenti(int i, int j, int statoIniziale, int statoFinale) const{
    int somma = 0;
//    printf("i %d, j %d\n", i, j);
    for(int x = i-1; x <= i+1; ++x) {
 //       printf("x %d\n", x);
        for(int y = j-1; y <= j+1; ++y) {
 //           printf("y %d\n", y);
            if(x >= 0 && x < dim && y >= 0 && y < dim) {
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

void Terreno::cicloPiantaViva(int i, int j, int stato, double r1, double r2) {
//    printf("%f %f\n", r1, r2);
    if( r1 < percentuali.percentualeInizioInfezione + (stato * 0.05) || numeroAdiacenti(i, j, germoglioInfetto, alberoInfetto) >= percentuali.numeroMinimoPropagazioneInfezione) {
        copiaTerreno[i][j] = (stato + 6);
//        printf("Numero infetti adiacenti allo stato %d, posizione %d %d, = %d\n", terreno[i][j].getStato(), i, j, numeroAdiacenti(i,j,germoglioInfetto, alberoInfetto));
//        printf("Numero minimo propagazione infezione = %d\n\n", percentuali.numeroMinimoPropagazioneInfezione);
    }
    else if( r2 < percentuali.percentualeSeccaPiante + (stato * 0.05) || numeroAdiacenti(i, j, germoglioSecco, alberoSecco) >= percentuali.numeroMinimoPropagazionePianteSecche) {
        copiaTerreno[i][j] = (stato + 3);
//        printf("Numero secchi adiacenti allo stato %d, posizione %d %d, = %d\n", terreno[i][j].getStato(), i, j, numeroAdiacenti(i,j,germoglioSecco, alberoSecco));
//        printf("Numero minimo propagazione secchi = %d\n\n", percentuali.numeroMinimoPropagazionePianteSecche);
    }
    else if(stato == germoglio || stato == pianta)
        copiaTerreno[i][j] = (stato + 1);
    else {
        copiaTerreno[i][j] = stato;
//        printf("sono nell'else del cicloPiantaViva, posizione %d, %d \n", i, j);
    }
}

void Terreno::ciclo() {
    unsigned int seed = time(NULL);
    for_ij {
        double random = (double)rand_r(&seed) / RAND_MAX;
        switch(terreno[i][j]) {
            case vuoto: {
                if(random < percentuali.percentualeNuovaPianta)
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
                cicloPiantaViva(i, j, terreno[i][j], random, random2);
                break;
            }
        }
    }
    copiaMatrice();
}

void Terreno::guarisciTutto() {
    bool almenoUnInfettoPresente = false;
    for_ij {
        if(terreno[i][j] >= germoglioInfetto && terreno[i][j] <= alberoInfetto) {
            terreno[i][j] = (terreno[i][j] - 6);
            almenoUnInfettoPresente = true;
        }
    }
    if(almenoUnInfettoPresente)
        biologico = false;
}

QString Terreno::numeroElementiPresenti() const {
    int vuota = 0, vivo = 0, secco = 0, infetti = 0;

    for_ij {
        switch(terreno[i][j]) {
            case vuoto:
                vuota ++;
                break;
            case germoglioInfetto ... alberoInfetto:
                infetti ++;
                break;
            case germoglioSecco ... alberoSecco:
                secco ++;
                break;
            case germoglio ... albero:
                vivo ++;
                break;
        }
    }
    return "Numero zolle vuote: " + QString::number(vuota) + ". Numero zolle vive: " + QString::number(vivo) + ". Numero zolle secche: " + QString::number(secco) + ". Numero zolle infette: " + QString::number(infetti);
}

bool Terreno::getBiologico() const
{
    return biologico;
}

int** Terreno::getTerreno() const
{
    return terreno;
}

void Terreno::setPercentuali(const Percentuali &value)
{
    percentuali = value;
}
