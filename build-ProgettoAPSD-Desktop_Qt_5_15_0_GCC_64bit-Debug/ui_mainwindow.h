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
#include <QtWidgets/QLineEdit>
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
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *label_7;
    QDoubleSpinBox *pianteInizio;
    QDoubleSpinBox *pianteSecche;
    QLabel *label_8;
    QDoubleSpinBox *piantaInfetta;
    QLabel *label_9;
    QSpinBox *viciniInfetti;
    QLabel *label_10;
    QDoubleSpinBox *nuovaPianta;
    QLabel *label_11;
    QLabel *label;
    QSpinBox *viciniSecchi;
    QLabel *label_6;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *Start;
    QPushButton *Stop;
    QPushButton *Guarisci;
    QLineEdit *biologico;
    QPushButton *salvaImpostazioni;
    QWidget *Impostazioni;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1150, 820);
        MainWindow->setMinimumSize(QSize(1150, 820));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(780, 16, 1160, 820));
        stackedWidget->setMinimumSize(QSize(1160, 820));
        Gioco = new QWidget();
        Gioco->setObjectName(QString::fromUtf8("Gioco"));
        formLayoutWidget_2 = new QWidget(Gioco);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(30, 352, 339, 213));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(formLayoutWidget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QFont font;
        font.setPointSize(10);
        label_7->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_7);

        pianteInizio = new QDoubleSpinBox(formLayoutWidget_2);
        pianteInizio->setObjectName(QString::fromUtf8("pianteInizio"));
        pianteInizio->setDecimals(2);
        pianteInizio->setMaximum(1.000000000000000);
        pianteInizio->setSingleStep(0.010000000000000);
        pianteInizio->setValue(0.750000000000000);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, pianteInizio);

        pianteSecche = new QDoubleSpinBox(formLayoutWidget_2);
        pianteSecche->setObjectName(QString::fromUtf8("pianteSecche"));
        pianteSecche->setMaximum(1.000000000000000);
        pianteSecche->setSingleStep(0.010000000000000);
        pianteSecche->setValue(0.300000000000000);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, pianteSecche);

        label_8 = new QLabel(formLayoutWidget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_8);

        piantaInfetta = new QDoubleSpinBox(formLayoutWidget_2);
        piantaInfetta->setObjectName(QString::fromUtf8("piantaInfetta"));
        piantaInfetta->setMaximum(1.000000000000000);
        piantaInfetta->setSingleStep(0.010000000000000);
        piantaInfetta->setValue(0.100000000000000);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, piantaInfetta);

        label_9 = new QLabel(formLayoutWidget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_9);

        viciniInfetti = new QSpinBox(formLayoutWidget_2);
        viciniInfetti->setObjectName(QString::fromUtf8("viciniInfetti"));
        viciniInfetti->setMaximum(8);
        viciniInfetti->setValue(1);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, viciniInfetti);

        label_10 = new QLabel(formLayoutWidget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_10);

        nuovaPianta = new QDoubleSpinBox(formLayoutWidget_2);
        nuovaPianta->setObjectName(QString::fromUtf8("nuovaPianta"));
        nuovaPianta->setMinimum(0.000000000000000);
        nuovaPianta->setMaximum(1.000000000000000);
        nuovaPianta->setSingleStep(0.010000000000000);
        nuovaPianta->setValue(0.500000000000000);

        formLayout_2->setWidget(4, QFormLayout::FieldRole, nuovaPianta);

        label_11 = new QLabel(formLayoutWidget_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_11);

        label = new QLabel(formLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label);

        viciniSecchi = new QSpinBox(formLayoutWidget_2);
        viciniSecchi->setObjectName(QString::fromUtf8("viciniSecchi"));
        viciniSecchi->setMaximum(8);
        viciniSecchi->setValue(3);

        formLayout_2->setWidget(5, QFormLayout::FieldRole, viciniSecchi);

        label_6 = new QLabel(Gioco);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(120, 304, 141, 19));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label_6->setFont(font1);
        verticalLayoutWidget = new QWidget(Gioco);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(100, 112, 160, 129));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Start = new QPushButton(verticalLayoutWidget);
        Start->setObjectName(QString::fromUtf8("Start"));

        verticalLayout->addWidget(Start);

        Stop = new QPushButton(verticalLayoutWidget);
        Stop->setObjectName(QString::fromUtf8("Stop"));

        verticalLayout->addWidget(Stop);

        Guarisci = new QPushButton(verticalLayoutWidget);
        Guarisci->setObjectName(QString::fromUtf8("Guarisci"));

        verticalLayout->addWidget(Guarisci);

        biologico = new QLineEdit(Gioco);
        biologico->setObjectName(QString::fromUtf8("biologico"));
        biologico->setGeometry(QRect(70, 40, 231, 27));
        biologico->setAlignment(Qt::AlignCenter);
        biologico->setReadOnly(true);
        salvaImpostazioni = new QPushButton(Gioco);
        salvaImpostazioni->setObjectName(QString::fromUtf8("salvaImpostazioni"));
        salvaImpostazioni->setGeometry(QRect(80, 584, 241, 27));
        stackedWidget->addWidget(Gioco);
        Impostazioni = new QWidget();
        Impostazioni->setObjectName(QString::fromUtf8("Impostazioni"));
        Impostazioni->setMaximumSize(QSize(791, 16777215));
        Impostazioni->setStyleSheet(QString::fromUtf8(""));
        stackedWidget->addWidget(Impostazioni);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1150, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Terreno", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Percentuale di piante piantate all'inizio ", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Percentuale che una pianta si infetti ", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Numero minimo di vicini infetti affinch\303\251\n"
"la pianta sana si infetti", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Percentuale di piantare un nuovo germoglio", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Percentuale che una pianta secchi", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Numero minimo di vicini secchi affinch\303\251\n"
"la pianta sana si secchi", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "IMPOSTAZIONI", nullptr));
        Start->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        Stop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        Guarisci->setText(QCoreApplication::translate("MainWindow", "Utilizza pesticida", nullptr));
        biologico->setText(QString());
        salvaImpostazioni->setText(QCoreApplication::translate("MainWindow", "Salva Impostazioni", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
