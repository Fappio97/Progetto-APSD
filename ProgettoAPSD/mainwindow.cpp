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
    img = new immagini();


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
//    suolo->setPercentualePianteIniziali(0.75);
    suolo->start();
}

void MainWindow::aggiornaInterfaccia() {
    if(primoAvvio) {
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
    QVector<QPixmap> immagini = img->getImmagine();

//    QColor colore(250, 250, 250);
    for_ij {
        switch(terreno[i][j].getStato()) {
            case vuoto:
                paint.drawPixmap(i*dime, j*dime, immagini[vuoto]);
                break;
            case germoglio:
                paint.drawPixmap(i*dime, j*dime, immagini[germoglio]);
                break;
            case pianta:
                paint.drawPixmap(i*dime,j*dime, immagini[pianta]);
                break;
            case albero:
                paint.drawPixmap(i*dime, j*dime, immagini[albero]);
                break;
            case germoglioSecco:
                paint.drawPixmap(i*dime, j*dime, immagini[germoglioSecco]);
                break;
            case piantaSecca:
                paint.drawPixmap(i*dime, j*dime, immagini[piantaSecca]);
                break;
            case alberoSecco:
                paint.drawPixmap(i*dime, j*dime, immagini[alberoSecco]);
                break;
            case germoglioInfetto:
                paint.drawPixmap(i*dime, j*dime, immagini[germoglioInfetto]);
                break;
            case piantaInfetta:
                paint.drawPixmap(i*dime, j*dime, immagini[piantaInfetta]);
                break;
            case alberoInfetto:
                paint.drawPixmap(i*dime, j*dime, immagini[alberoInfetto]);
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
    double nuovaPianta = ui->nuovaPianta->value();
    suolo->setPercentualeNuovaPianta(nuovaPianta);

    double piantaInfetta = ui->piantaInfetta->value();
    suolo->setPercenualeInizioInfezione(piantaInfetta);

    double pianteInizio = ui->pianteInizio->value();
    suolo->setPercentualePianteIniziali(pianteInizio);

    double pianteSecche = ui->pianteSecche->value();
    suolo->setPercentualeSeccaPiante(pianteSecche);

    int numeroMinViciniInfetti = ui->viciniInfetti->value();
    suolo->setNumeroMinimoPropagazioneInfezione(numeroMinViciniInfetti);
}

void MainWindow::on_Guarisci_clicked()
{
    suolo->guarisciTutto();
    suolo->setBiologico(false);
    repaint();
}
