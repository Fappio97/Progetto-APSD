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

double Terreno::getPercentualeNuovaPianta() const
{
    return percentualeNuovaPianta;
}

void Terreno::setPercentualeNuovaPianta(double value)
{
    percentualeNuovaPianta = value;
}

double Terreno::getPercentualeSeccaPiante() const
{
    return percentualeSeccaPiante;
}

void Terreno::setPercentualeSeccaPiante(double value)
{
    percentualeSeccaPiante = value;
}

double Terreno::getPercentualePianteIniziali() const
{
    return percentualePianteIniziali;
}

void Terreno::setPercentualePianteIniziali(double value)
{
    percentualePianteIniziali = value;
}

double Terreno::getPercenualeInizioInfezione() const
{
    return percenualeInizioInfezione;
}

void Terreno::setPercenualeInizioInfezione(double value)
{
    percenualeInizioInfezione = value;
}

int Terreno::getNumeroMinimoPropagazioneInfezione() const
{
    return numeroMinimoPropagazioneInfezione;
}

void Terreno::setNumeroMinimoPropagazioneInfezione(int value)
{
    numeroMinimoPropagazioneInfezione = value;
}

bool Terreno::getBiologico() const
{
    return biologico;
}

void Terreno::setBiologico(bool value)
{
    biologico = value;
}

Pianta **Terreno::getTerreno() const
{
    return terreno;
}

Terreno::Terreno()
{
    percentualeNuovaPianta = 0.75;
    percentualeSeccaPiante = 0.2;
    percenualeInizioInfezione = 0.1;
    numeroMinimoPropagazioneInfezione = 2;
}

Terreno::~Terreno() {
    svuota();
}

void Terreno::svuota() {
    for_i
          free(terreno[i]);
    free(terreno);
}

void Terreno::start() {
    biologico = true;
    terreno = (Pianta**) malloc(dim* sizeof(Pianta*));

    for_i
            terreno[i] = static_cast<Pianta*>(malloc(dim* sizeof(Pianta)));

    for_ij
            terreno[i][j].setStato(vuoto);
}

void Terreno::restart() {
    if(terreno != nullptr)
        svuota();
    biologico = true;
    terreno = (Pianta**) malloc(dim* sizeof(Pianta*));

    for_i
            terreno[i] = static_cast<Pianta*>(malloc(dim* sizeof(Pianta)));
    generaCasualmenteInizio();
}

int generaPiantaViva() {
    return rand()%3 + 1;
}

void Terreno::generaCasualmenteInizio() {

    for_ij {
        if (rand() / double(RAND_MAX) < percentualePianteIniziali)
            terreno[i][j].setStato(generaPiantaViva());
        else
            terreno[i][j].setStato(vuoto);
    }

 /*   for_i
        printf("numero random %f\n", rand() / double(RAND_MAX));*/
}

bool generare(double percentuale) {
    return rand() / double(RAND_MAX) < percentuale;
}

int Terreno::numeroInfettiAdiacenti(int i, int j) const{
    int somma = 0;

    for(int x = i-1; x < i+1; ++x) {
        for(int y = j-1; y < j+1; ++y) {
            if(x >= 0 && x < dim && y >= 0 && y < dim && x != i && y != j)
                if(terreno[x][y].getStato() >= germoglioInfetto || terreno[x][y].getStato() <= alberoInfetto)
                    somma++;
        }
    }

    return somma;
}

void Terreno::cicloPiantaViva(int i, int j, int stato) {
    if(generare(percentualeSeccaPiante))
        terreno[i][j].setStato(stato + 3);
    else if(generare(percenualeInizioInfezione) || numeroInfettiAdiacenti(i, j) >= numeroMinimoPropagazioneInfezione)
        terreno[i][j].setStato(stato + 6);
    else
        terreno[i][j].setStato(stato+1);
}

void Terreno::ciclo() {
    for_ij {
        switch(terreno[i][j].getStato()) {
            case vuoto:
                if(generare(percentualeNuovaPianta)) {
                    //terreno[i][j].setStato(generaPiantaViva());
                    terreno[i][j].setStato(germoglio);
                }
                break;
            case germoglioInfetto ... alberoInfetto:
                terreno[i][j].setStato(vuoto);
                break;
            case germoglioSecco ... alberoSecco:
                terreno[i][j].setStato(vuoto);
                break;
            case germoglio ... albero:
                cicloPiantaViva(i, j, terreno[i][j].getStato());
                break;
        }
    }
}

void Terreno::guarisciTutto() {
    for_ij {
        if(terreno[i][j].getStato() >= germoglioInfetto && terreno[i][j].getStato() <= alberoInfetto)
            terreno[i][j].setStato(terreno[i][j].getStato() - 4);
    }
    biologico = false;
}

QString Terreno::numeroElementiPresenti() const {
    int vuota = 0, vivo = 0, secco = 0, infetti = 0;

    for_ij {
        switch(terreno[i][j].getStato()) {
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
