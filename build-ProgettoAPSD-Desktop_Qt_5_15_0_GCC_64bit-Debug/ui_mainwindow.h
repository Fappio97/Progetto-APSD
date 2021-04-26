/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *Gioco;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *Start;
    QPushButton *Stop;
    QPushButton *Settings;
    QWidget *Impostazioni;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QDoubleSpinBox *pianteInizio;
    QLabel *label_2;
    QDoubleSpinBox *pianteSecche;
    QLabel *label_3;
    QDoubleSpinBox *piantaInfetta;
    QLabel *label_4;
    QSpinBox *viciniInfetti;
    QLabel *label_5;
    QDoubleSpinBox *nuovaPianta;
    QLabel *label_6;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 791, 545));
        Gioco = new QWidget();
        Gioco->setObjectName(QString::fromUtf8("Gioco"));
        verticalLayoutWidget = new QWidget(Gioco);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(640, 40, 131, 241));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Start = new QPushButton(verticalLayoutWidget);
        Start->setObjectName(QString::fromUtf8("Start"));

        verticalLayout->addWidget(Start);

        Stop = new QPushButton(verticalLayoutWidget);
        Stop->setObjectName(QString::fromUtf8("Stop"));

        verticalLayout->addWidget(Stop);

        Settings = new QPushButton(verticalLayoutWidget);
        Settings->setObjectName(QString::fromUtf8("Settings"));

        verticalLayout->addWidget(Settings);

        stackedWidget->addWidget(Gioco);
        Impostazioni = new QWidget();
        Impostazioni->setObjectName(QString::fromUtf8("Impostazioni"));
        Impostazioni->setMaximumSize(QSize(791, 16777215));
        Impostazioni->setStyleSheet(QString::fromUtf8(""));
        formLayoutWidget = new QWidget(Impostazioni);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(180, 160, 431, 217));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        pianteInizio = new QDoubleSpinBox(formLayoutWidget);
        pianteInizio->setObjectName(QString::fromUtf8("pianteInizio"));
        pianteInizio->setDecimals(2);
        pianteInizio->setMaximum(1.000000000000000);
        pianteInizio->setSingleStep(0.010000000000000);
        pianteInizio->setValue(0.750000000000000);

        formLayout->setWidget(0, QFormLayout::FieldRole, pianteInizio);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        pianteSecche = new QDoubleSpinBox(formLayoutWidget);
        pianteSecche->setObjectName(QString::fromUtf8("pianteSecche"));
        pianteSecche->setMaximum(1.000000000000000);
        pianteSecche->setSingleStep(0.010000000000000);
        pianteSecche->setValue(0.300000000000000);

        formLayout->setWidget(1, QFormLayout::FieldRole, pianteSecche);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        piantaInfetta = new QDoubleSpinBox(formLayoutWidget);
        piantaInfetta->setObjectName(QString::fromUtf8("piantaInfetta"));
        piantaInfetta->setMaximum(1.000000000000000);
        piantaInfetta->setSingleStep(0.010000000000000);
        piantaInfetta->setValue(0.100000000000000);

        formLayout->setWidget(2, QFormLayout::FieldRole, piantaInfetta);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        viciniInfetti = new QSpinBox(formLayoutWidget);
        viciniInfetti->setObjectName(QString::fromUtf8("viciniInfetti"));
        viciniInfetti->setMaximum(8);
        viciniInfetti->setValue(1);

        formLayout->setWidget(3, QFormLayout::FieldRole, viciniInfetti);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        nuovaPianta = new QDoubleSpinBox(formLayoutWidget);
        nuovaPianta->setObjectName(QString::fromUtf8("nuovaPianta"));
        nuovaPianta->setMinimum(0.000000000000000);
        nuovaPianta->setMaximum(1.000000000000000);
        nuovaPianta->setSingleStep(0.010000000000000);
        nuovaPianta->setValue(0.500000000000000);

        formLayout->setWidget(4, QFormLayout::FieldRole, nuovaPianta);

        label_6 = new QLabel(Impostazioni);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(330, 120, 141, 19));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label_6->setFont(font1);
        pushButton = new QPushButton(Impostazioni);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(270, 424, 261, 27));
        stackedWidget->addWidget(Impostazioni);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Terreno", nullptr));
        Start->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        Stop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        Settings->setText(QCoreApplication::translate("MainWindow", "Impostazioni", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Percentuale di piante piantate all'inizio ", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Percentuale che una pianta secchi", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Percentuale che una pianta si infetti ", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Numero minimo di vicini infetti affinch\303\251\n"
"la pianta sana si infetti", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Percentuale di piantare un nuovo germoglio", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "IMPOSTAZIONI", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Gioco", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
