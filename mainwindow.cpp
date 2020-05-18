#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <iostream>
#include "silnikgry.h"
#include <cstdlib>
#include <ctime>
#include <QMessageBox>
#include "sztucznaInteligencja.h"
#include <QApplication>
#include <string>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap wolnePole(sciezkaGrafikaWolnePole);
    QPixmap gracz01(sciezkaGrafikaGracz01);
    QPixmap gracz02(sciezkaGrafikaGracz02);


    /*
        Powiazujemy tablice wskaznikow z nazwami etykiey tek zeby moc iterowac po label'ach
    */
    tab[0][0] = ui->label_1;
    tab[1][0] = ui->label_2;
    tab[2][0] = ui->label_3;
    tab[3][0] = ui->label_4;
    tab[4][0] = ui->label_5;
    tab[5][0] = ui->label_6;

    tab[0][1] = ui->label_7;
    tab[1][1] = ui->label_8;
    tab[2][1] = ui->label_9;
    tab[3][1] = ui->label_10;
    tab[4][1] = ui->label_11;
    tab[5][1] = ui->label_12;

    tab[0][2] = ui->label_13;
    tab[1][2] = ui->label_14;
    tab[2][2] = ui->label_15;
    tab[3][2] = ui->label_16;
    tab[4][2] = ui->label_17;
    tab[5][2] = ui->label_18;

    tab[0][3] = ui->label_19;
    tab[1][3] = ui->label_20;
    tab[2][3] = ui->label_21;
    tab[3][3] = ui->label_22;
    tab[4][3] = ui->label_23;
    tab[5][3] = ui->label_24;

    tab[0][4] = ui->label_25;
    tab[1][4] = ui->label_26;
    tab[2][4] = ui->label_27;
    tab[3][4] = ui->label_28;
    tab[4][4] = ui->label_29;
    tab[5][4] = ui->label_30;

    tab[0][5] = ui->label_31;
    tab[1][5] = ui->label_32;
    tab[2][5] = ui->label_33;
    tab[3][5] = ui->label_34;
    tab[4][5] = ui->label_35;
    tab[5][5] = ui->label_36;

    tab[0][6] = ui->label_37;
    tab[1][6] = ui->label_38;
    tab[2][6] = ui->label_39;
    tab[3][6] = ui->label_40;
    tab[4][6] = ui->label_41;
    tab[5][6] = ui->label_42;
        licznikRuchow = 0;

    /*
        zeby dopasowac wielkosc obrazka do wielkosci pola
    */

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            tab[i][j]->setPixmap(wolnePole.scaled(skalaGrafikiX, skalaGrafikiY, Qt::IgnoreAspectRatio));
        }
    }
    rozpocznijGre();
}

void MainWindow::rozpocznijGre()
{

    srand(time(NULL));
    QString komunikat = "Ruch gracza ";
    ui->label_turaGracza->setText(komunikat + QString::number(silnikGry.turaGracza));

    //o1.wypiszPlansze();
    //o1.rozgrywka();

    //cout << "DZIALAM !" << endl;


}

void MainWindow::wyswietlPlansze()
{
    QPixmap wolnePole(sciezkaGrafikaWolnePole);
    QPixmap gracz01(sciezkaGrafikaGracz01);
    QPixmap gracz02(sciezkaGrafikaGracz02);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (silnikGry.plansza[i][j] == -1)
            {
                tab[i][j]->setPixmap(wolnePole.scaled(skalaGrafikiX, skalaGrafikiY, Qt::IgnoreAspectRatio));

            }
            else if(silnikGry.plansza[i][j] == 1)
            {
                tab[i][j]->setPixmap(gracz01.scaled(skalaGrafikiX, skalaGrafikiY, Qt::IgnoreAspectRatio));
            }
            else if(silnikGry.plansza[i][j] == 2)
            {
                tab[i][j]->setPixmap(gracz02.scaled(skalaGrafikiX, skalaGrafikiY, Qt::IgnoreAspectRatio));
            }
        }
    }

}


MainWindow::~MainWindow()
{
    delete ui;
}


int MainWindow::sprawdzStanGry()
{
    int flaga = silnikGry.sprawdzStanGry();
    if(flaga == 1)
    {
        QMessageBox::StandardButton reply = QMessageBox::information(this, "Wynik gry", "Wygrywa gracz 1");
        resetRozgrywki();
    }
    if(flaga == 2)
    {
        QMessageBox::StandardButton reply = QMessageBox::information(this, "Wynik gry", "Wygrywa gracz 2");
        resetRozgrywki();
    }
    if(flaga == 3)
    {
        QMessageBox::StandardButton reply = QMessageBox::information(this, "Wynik gry", "Remis - plansza została zapełniona");
        resetRozgrywki();
    }
    return flaga;

}
void MainWindow::resetRozgrywki()
{
    silnikGry.resetRozgrywki();
    wyswietlPlansze();
    QString komunikat = "Ruch gracza ";
    ui->label_turaGracza->setText(komunikat + QString::number(silnikGry.turaGracza));
}

void MainWindow::on_button00_clicked()
{
    silnikGry.ruchGracza(0);
    wyswietlPlansze();
    sprawdzStanGry();
    QString komunikat = "Ruch gracza ";
    ui->label_turaGracza->setText(komunikat + QString::number(silnikGry.turaGracza));
    if(flagaTrybGry == 2)
    {
        kolejnyRuchAI(false);
    }

}

void MainWindow::on_button01_clicked()
{
    silnikGry.ruchGracza(1);
    wyswietlPlansze();
    sprawdzStanGry();
    QString komunikat = "Ruch gracza ";
    ui->label_turaGracza->setText(komunikat + QString::number(silnikGry.turaGracza));
    if(flagaTrybGry == 2)
    {
        kolejnyRuchAI(false);
    }
}

void MainWindow::on_button02_clicked()
{
    silnikGry.ruchGracza(2);
    wyswietlPlansze();
    sprawdzStanGry();
    QString komunikat = "Ruch gracza ";
    ui->label_turaGracza->setText(komunikat + QString::number(silnikGry.turaGracza));
    if(flagaTrybGry == 2)
    {
        kolejnyRuchAI(false);
    }
}

void MainWindow::on_button03_clicked()
{
    silnikGry.ruchGracza(3);
    wyswietlPlansze();
    sprawdzStanGry();
    QString komunikat = "Ruch gracza ";
    ui->label_turaGracza->setText(komunikat + QString::number(silnikGry.turaGracza));
    if(flagaTrybGry == 2)
    {
        kolejnyRuchAI(false);
    }
}

void MainWindow::on_button04_clicked()
{
    silnikGry.ruchGracza(4);
    wyswietlPlansze();
    sprawdzStanGry();
    QString komunikat = "Ruch gracza ";
    ui->label_turaGracza->setText(komunikat + QString::number(silnikGry.turaGracza));
    if(flagaTrybGry == 2)
    {
        kolejnyRuchAI(false);
    }
}

void MainWindow::on_button05_clicked()
{
    silnikGry.ruchGracza(5);
    wyswietlPlansze();
    sprawdzStanGry();
    QString komunikat = "Ruch gracza ";
    ui->label_turaGracza->setText(komunikat + QString::number(silnikGry.turaGracza));
    if(flagaTrybGry == 2)
    {
        kolejnyRuchAI(false);
    }
}

void MainWindow::on_button06_clicked()
{
    silnikGry.ruchGracza(6);
    wyswietlPlansze();
    sprawdzStanGry();
    QString komunikat = "Ruch gracza ";
    ui->label_turaGracza->setText(komunikat + QString::number(silnikGry.turaGracza));
    if(flagaTrybGry == 2)
    {
        kolejnyRuchAI(false);
    }
}


void MainWindow::on_pushButton_start_clicked()
{
    /*
        pobieramy wszystkie dane z interfejsu w celu pozniejszego ich obslozenia w funkcji zarzadzajRozgrywka
    */
    QString QString_trybRozgrywki = ui->comboBox_trybRozgrywki->currentText();
    string trybRozgrywki1 = QString_trybRozgrywki.toLocal8Bit().constData();

    QString QString_alfaBeta_1 = ui->comboBox_alfaBeta_1->currentText();
    QString QString_poziomTrudnosci_1 = ui->comboBox_poziomTrudnosci_1->currentText();
    QString QString_heurystykaOceny_1 = ui->comboBox_heurystykaOceny_1->currentText();
    string alfaBeta_1 = QString_alfaBeta_1.toLocal8Bit().constData();
    string poziomTrudnosci_1 = QString_poziomTrudnosci_1.toLocal8Bit().constData();
    string heurystykaOceny_1 = QString_heurystykaOceny_1.toLocal8Bit().constData();


    QString QString_alfaBeta_2 = ui->comboBox_alfaBeta_2->currentText();
    QString QString_poziomTrudnosci_2 = ui->comboBox_poziomTrudnosci_2->currentText();
    QString QString_heurystykaOceny_2 = ui->comboBox_heurystykaOceny_2->currentText();
    string alfaBeta_2 = QString_alfaBeta_2.toLocal8Bit().constData();
    string poziomTrudnosci_2 = QString_poziomTrudnosci_2.toLocal8Bit().constData();
    string heurystykaOceny_2 = QString_heurystykaOceny_2.toLocal8Bit().constData();

    zarzadzajRozgrywka(trybRozgrywki1, alfaBeta_1, poziomTrudnosci_1, heurystykaOceny_1, alfaBeta_2, poziomTrudnosci_2, heurystykaOceny_2);

}

void MainWindow::zarzadzajRozgrywka(string trybRozgrywki,string alfaBeta_1, string poziomTrudnosci_1,string heurystykaOceny_1,string alfaBeta_2,string poziomTrudnosci_2,string heurystykaOceny_2)
{

    if(alfaBeta_1 == "Alfa-Beta")
    {
        flagaAlfaBeta_1 = 1;
    }
    else
    {
        flagaAlfaBeta_1 = 2;
    }

    if(alfaBeta_2 == "Alfa-Beta")
    {
        flagaAlfaBeta_2 = 1;
    }
    else
    {
        flagaAlfaBeta_2 = 2;
    }

    flagaPoziomTrudnosci_1 = stoi(poziomTrudnosci_1);
    flagaPoziomTrudnosci_2 = stoi(poziomTrudnosci_2);
    flagaHeurystyka_1 = stoi(heurystykaOceny_1);
    flagaHeurystyka_2 = stoi(heurystykaOceny_2);




    if(trybRozgrywki == "Player vs Player")
    {
        flagaTrybGry = 1;
    }
    else if(trybRozgrywki == "Player vs AI")
    {
        flagaTrybGry = 2;
    }
    else
    {
        AIvsAI();
    }

}

void MainWindow::AIvsAI()
{

    while(true)
    {
        int flaga = kolejnyRuchAI(true);
        qApp->processEvents();
        if(flaga  == 1 || flaga  == 2 || flaga  == 3)
        {
            break;
        }
    }
}

int MainWindow::kolejnyRuchAI(bool AIAI)
{
    wyswietlPlansze();
    SztucznaInteligencja m1;
    if(AIAI == true)
    {
        if(silnikGry.turaGracza == 1)
        {
            m1.ustawFlagi(flagaAlfaBeta_1, flagaPoziomTrudnosci_1, flagaHeurystyka_1);
        }
        else
        {
            m1.ustawFlagi(flagaAlfaBeta_2, flagaPoziomTrudnosci_2, flagaHeurystyka_2);
        }
    }
    else
    {
        m1.ustawFlagi(flagaAlfaBeta_1, flagaPoziomTrudnosci_1, flagaHeurystyka_1);
    }

    int pom = m1.znajdzNajlepszyRuch(silnikGry.plansza, silnikGry.turaGracza, silnikGry.poprzedniRuch_x, silnikGry.poprzedniRuch_y);
    silnikGry.ruchGracza(pom);
    wyswietlPlansze();
    int flaga = sprawdzStanGry();
    return flaga;

}
