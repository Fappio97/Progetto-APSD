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

const int dim = 4;

#define for_i for(int i = 0; i < dim; ++i)
#define for_j for(int j = 0; j < dim; ++j)  //implementato per prova, eliminalo
#define for_ij for_i for(int j = 0; j < dim; ++j)

class Terreno
{
    Pianta** terreno;
    double percentualePianteIniziali;
    double percentualeSeccaPiante;
    double percenualeInizioInfezione;
    int numeroMinimoPropagazioneInfezione;
    double percentualeNuovaPianta;
    bool biologico;

public:
    Terreno();
    ~Terreno();
    void svuota();

    void start(); //primo avvio
    void restart(); //risemina il terreno
    void generaCasualmenteInizio();   //genera casualmente lo stato delle piante all'inzio
    void cicloPiantaViva(int, int, int); //funzione che tratta le piante, vede se si diffonde il parassita, se seccano oppure crescono
    void ciclo();   //ciclo dell'evoluzione
    void guarisciTutto();   //guarisce tutte le piante infette
    int numeroInfettiAdiacenti(int, int) const;   //se una pianta è infetta, vi è una probabilità diversa dall'inizio di propagazione del virus, che si espande alle piante adiacenti, limiti dei bordi, come un terreno
    QString numeroElementiPresenti() const;

    double getPercentualeNuovaPianta() const;
    void setPercentualeNuovaPianta(double value);
    double getPercenualeDiffusioneParassita() const;
    void setPercenualeDiffusioneParassita(double value);
    double getPercentualeSeccaPiante() const;
    void setPercentualeSeccaPiante(double value);
    double getPercentualePianteIniziali() const;
    void setPercentualePianteIniziali(double value);
    double getPercenualeInizioInfezione() const;
    void setPercenualeInizioInfezione(double value);
    int getNumeroMinimoPropagazioneInfezione() const;
    void setNumeroMinimoPropagazioneInfezione(int value);
    bool getBiologico() const;
    void setBiologico(bool value);
    Pianta **getTerreno() const;


};

#endif // TERRENO_H
