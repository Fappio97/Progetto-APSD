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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "terreno.h"
#include "immagini.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    virtual void paintEvent(QPaintEvent* event);

private slots:
    void aggiornaInterfaccia();

    void on_Start_clicked();

    void on_Stop_clicked();

    void on_salvaImpostazioni_clicked();

    void on_Guarisci_clicked();

private:
    Ui::MainWindow *ui;

    QTimer* timer;
    Terreno* suolo;
    Immagini* img;

    void inizializzaSuolo();
    bool primoAvvio;
};
#endif // MAINWINDOW_H
