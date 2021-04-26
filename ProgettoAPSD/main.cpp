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

#include "mainwindow.h"

#include <QApplication>

#include "terreno.h"

/*void stampa(const Terreno& a) {

    Pianta** terreno = a.getTerreno();
    for_i {
        for_j {
            switch(terreno[i][j].getStato()) {
                case vuoto:
                    printf("1 ");
                    break;
                case seme:
                    printf("2 ");
                    break;
                case pianta:
                    printf("3 ");
                    break;
                case albero:
                    printf("4 ");
                    break;
                case secca:
                    printf("5 ");
                    break;
                case semeInfetto:
                    printf("6 ");
                    break;
                case piantaInfetta:
                    printf("7 ");
                    break;
                case alberoInfetto:
                    printf("8 ");
                    break;

            }
        }
        printf("\n");
    }
}*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

/*    Terreno a;
    a.setPercentualePianteIniziali(0.75);
    a.setPercentualeNuovaPianta(0.75);
    a.setPercentualeSeccaPiante(0.75);
    a.setPercenualeInizioInfezione(0.75);
    a.start();

    stampa(a);

    a.ciclo();

    stampa(a);*/
}
