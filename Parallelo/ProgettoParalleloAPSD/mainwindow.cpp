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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

/*    QScreen *screen = QGuiApplication::primaryScreen();   //ridimensiona la pagina ma ho sempre il problema del layout dei bottoni
    QSize size = screen->availableGeometry().size() * 0.9;

    this->setWindowTitle("Terreno");    //sembra non funzionare
    this->setMinimumWidth(size.width());
    this->setMinimumHeight(size.height());*/


    ui->setupUi(this);
    suolo = new Terreno();
    inizializzaSuolo();
    primoAvvio = true;
    img = new Immagini();


    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(aggiornaInterfaccia()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete suolo;
    delete timer;
    delete img;
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

    int** terreno = suolo->getTerreno();
    QVector<QPixmap> immagini = img->getImmagini();

//    QColor colore(250, 250, 250);
    for_ij {
        switch(terreno[i][j]) {
            case vuoto:
                paint.drawPixmap(i * dimensioneCelle, j * dimensioneCelle, immagini[vuoto]);
                break;
            case germoglio:
                paint.drawPixmap(i * dimensioneCelle, j * dimensioneCelle, immagini[germoglio]);
                break;
            case pianta:
                paint.drawPixmap(i * dimensioneCelle, j * dimensioneCelle, immagini[pianta]);
                break;
            case albero:
                paint.drawPixmap(i * dimensioneCelle, j * dimensioneCelle, immagini[albero]);
                break;
            case germoglioSecco:
                paint.drawPixmap(i * dimensioneCelle, j * dimensioneCelle, immagini[germoglioSecco]);
                break;
            case piantaSecca:
                paint.drawPixmap(i * dimensioneCelle, j * dimensioneCelle, immagini[piantaSecca]);
                break;
            case alberoSecco:
                paint.drawPixmap(i * dimensioneCelle, j * dimensioneCelle, immagini[alberoSecco]);
                break;
            case germoglioInfetto:
                paint.drawPixmap(i * dimensioneCelle, j * dimensioneCelle, immagini[germoglioInfetto]);
                break;
            case piantaInfetta:
                paint.drawPixmap(i * dimensioneCelle, j * dimensioneCelle, immagini[piantaInfetta]);
                break;
            case alberoInfetto:
                paint.drawPixmap(i * dimensioneCelle, j * dimensioneCelle, immagini[alberoInfetto]);
                break;
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
