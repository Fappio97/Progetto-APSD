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
#include <QScreen>

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
    suolo->setPercentualePianteIniziali(0.75);
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

//    QColor colore(250, 250, 250);
    int dime = 4;
    for_ij {
        switch(terreno[i][j].getStato()) {
            case vuoto:
                paint.fillRect(10 + i*dime, 10 + j*dime, dime, dime, QColor(153, 153, 102));
                break;
            case seme:
                paint.fillRect(10 + i*dime, 10 + j*dime, dime, dime, QColor(153, 255, 153));
                break;
            case pianta:
                paint.fillRect(10 + i*dime, 10 + j*dime, dime, dime, QColor(0, 204, 102));
                break;
            case albero:
                paint.fillRect(10 + i*dime, 10 + j*dime, dime, dime, QColor(0, 51, 0));
                break;
            case secca:
                paint.fillRect(10 + i*dime, 10 + j*dime, dime, dime, QColor(102, 153, 153));
                break;
            case semeInfetto:
                paint.fillRect(10 + i*dime, 10 + j*dime, dime, dime, QColor(255, 153, 153));
                break;
            case piantaInfetta:
                paint.fillRect(10 + i*dime, 10 + j*dime, dime, dime, QColor(255, 80, 80));
                break;
            case alberoInfetto:
                paint.fillRect(10 + i*dime, 10 + j*dime, dime, dime, QColor(128, 0, 0));
                break;

        }
    }
    ui->statusbar->showMessage(suolo->numeroElementiPresenti(), 1000);
}

void MainWindow::on_start_clicked()
{
    timer->start(1000);
}

void MainWindow::on_stop_clicked()
{
    timer->stop();
}
