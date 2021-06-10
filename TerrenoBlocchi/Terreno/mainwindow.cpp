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
#include "ui_mainwindow.h"

#include <QPainter>

#define dimensioneCelle 20

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    suolo = new Terreno();
    inizializzaSuolo();
    primoAvvio = true;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(aggiornaInterfaccia()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete suolo;
    delete timer;
}

void MainWindow::inizializzaSuolo() {
    suolo->start();
}

void MainWindow::aggiornaInterfaccia() {
    if(primoAvvio) {
        on_salvaImpostazioni_clicked();
        suolo->generaCasualmenteInizio();
        primoAvvio = false;
    }
    else
        suolo->ciclo();
    repaint();
}

void MainWindow::paintEvent(QPaintEvent* event) {
    QPainter paint(this);

    Pianta** terreno = suolo->getTerreno();

    for_ij {
        switch(terreno[i][j].getStato()) {
            case vuoto: {
                QColor colore(153, 102, 51);
                paint.fillRect(10 + i * dimensioneCelle, 10 + j * dimensioneCelle, dimensioneCelle, dimensioneCelle, colore);
                break;
            }
            case germoglio: {
                QColor colore(153, 255, 102);
                paint.fillRect(10 + i * dimensioneCelle, 10 + j * dimensioneCelle, dimensioneCelle, dimensioneCelle, colore);
                break;
            }
            case pianta: {
                QColor colore(51, 204, 51);
                paint.fillRect(10 + i * dimensioneCelle, 10 + j * dimensioneCelle, dimensioneCelle, dimensioneCelle, colore);
                break;
            }
            case albero: {
                QColor colore(51, 102, 0);
                paint.fillRect(10 + i * dimensioneCelle, 10 + j * dimensioneCelle, dimensioneCelle, dimensioneCelle, colore);
                break;
            }
            case germoglioSecco: {
                QColor colore(255, 204, 102);
                paint.fillRect(10 + i * dimensioneCelle, 10 + j * dimensioneCelle, dimensioneCelle, dimensioneCelle, colore);
                break;
            }
            case piantaSecca: {
                QColor colore(204, 102, 0);
                paint.fillRect(10 + i * dimensioneCelle, 10 + j * dimensioneCelle, dimensioneCelle, dimensioneCelle, colore);
                break;
            }
            case alberoSecco: {
                QColor colore(153, 51, 0);
                paint.fillRect(10 + i * dimensioneCelle, 10 + j * dimensioneCelle, dimensioneCelle, dimensioneCelle, colore);
                break;
            }
            case germoglioInfetto: {
                QColor colore(255, 102, 102);
                paint.fillRect(10 + i * dimensioneCelle, 10 + j * dimensioneCelle, dimensioneCelle, dimensioneCelle, colore);
                break;
            }
            case piantaInfetta: {
                QColor colore(255, 80, 80);
                paint.fillRect(10 + i * dimensioneCelle, 10 + j * dimensioneCelle, dimensioneCelle, dimensioneCelle, colore);
                break;
            }
            case alberoInfetto: {
                QColor colore(255, 0, 0);
                paint.fillRect(10 + i * dimensioneCelle, 10 + j * dimensioneCelle, dimensioneCelle, dimensioneCelle, colore);
                break;
            }
        }
    }
    if(suolo->getBiologico())
        ui->biologico->setText("Terreno biologico");
    else
        ui->biologico->setText("Terreno NON biologico");
    ui->statusbar->showMessage(suolo->numeroElementiPresenti(), 2000);
}

void MainWindow::on_Start_clicked()
{
    timer->start(2000);
}

void MainWindow::on_Stop_clicked()
{
    timer->stop();
}

void MainWindow::on_salvaImpostazioni_clicked()
{
    double pianteInizio = ui->pianteInizio->value();
    double pianteSecche = ui->pianteSecche->value();
    double piantaInfetta = ui->piantaInfetta->value();
    double nuovaPianta = ui->nuovaPianta->value();
    int numeroMinViciniInfetti = ui->viciniInfetti->value();
    int numeroMinViniciSecchi = ui->viciniSecchi->value();

    suolo->setPercentuali(Percentuali(pianteInizio, pianteSecche, piantaInfetta, nuovaPianta, numeroMinViciniInfetti, numeroMinViniciSecchi));
}

void MainWindow::on_Guarisci_clicked()
{
    suolo->guarisciTutto();
    repaint();
}
