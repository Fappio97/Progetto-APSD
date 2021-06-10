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
                    printf("0 ");
                    break;
                case germoglio:
                    printf("1 ");
                    break;
                case pianta:
                    printf("2 ");
                    break;
                case albero:
                    printf("3 ");
                    break;
                case germoglioSecco:
                    printf("4 ");
                    break;
                case piantaSecca:
                    printf("5 ");
                    break;
                case alberoSecco:
                    printf("6 ");
                    break;
                case germoglioInfetto:
                    printf("7 ");
                    break;
                case piantaInfetta:
                    printf("8 ");
                    break;
                case alberoInfetto:
                    printf("9 ");
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

/*
    clock_t inizio = clock();

    Terreno a;
    a.setPercentuali(Percentuali(0.75, 0.3, 0.1, 0.5, 1, 3));
    a.start();
    a.generaCasualmenteInizio();

    for(int i = 0; i < 1000; ++i)
        a.ciclo();

    printf("Tempo esecuzione = %f", (double) (clock() - inizio) / CLOCKS_PER_SEC );
    printf(" secondi\n");
*/
}
