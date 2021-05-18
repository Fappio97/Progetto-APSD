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

#ifndef TERRENO_H
#define TERRENO_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <QString>

#include "pianta.h"
#include "percentuali.h"

const int dim = 4;

#define for_i for(int i = 0; i < dim; ++i)
#define for_j for(int j = 0; j < dim; ++j)  //implementato per prova, eliminalo
#define for_ij for_i for(int j = 0; j < dim; ++j)

class Terreno
{
    int** terreno;
    int** copiaTerreno;
    Percentuali percentuali;
    bool biologico;

public:
    Terreno();
    Terreno(const Terreno&);
    ~Terreno();
    void svuota();
    void operator=(const Terreno&);

    void allocaMatricePianta(); //alloca la matrice di pianta
    void copiaMatrice();    //copia il terreno2, dopo il ciclo, nel terreno1

    void start(); //primo avvio
    void generaCasualmenteInizio();   //genera casualmente lo stato delle piante all'inzio
    void cicloPiantaViva(int, int, int, double, double); //funzione che tratta le piante, vede se si diffonde il parassita, se seccano oppure crescono
    void ciclo();   //ciclo dell'evoluzione
    void guarisciTutto();   //guarisce tutte le piante infette
    int numeroAdiacenti(int, int, int, int) const;   //restituisce il numero di piante che presentano lo stato tra il range(statoIniziale, statoFinale), adiacenti alla zolla di terra di coordinate i,j. Mi serve per calcolare il numero di infetti e secchi adiacenti con un'unica funzione
    QString numeroElementiPresenti() const; //stampe per lo statusbar

    bool getBiologico() const;
    int **getTerreno() const;
    void setPercentuali(const Percentuali &value);
};

#endif // TERRENO_H
