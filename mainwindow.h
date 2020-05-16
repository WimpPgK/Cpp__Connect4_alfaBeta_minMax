#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include "ui_mainwindow.h"
#include "silnikgry.h"
#include "minmax.h"
#include <iostream>;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
using namespace std;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void rozpocznijGre();
    void wyswietlPlansze();
    int sprawdzStanGry();
    void resetRozgrywki();
    void zarzadzajRozgrywka(string trybRozgrywki1,string alfaBeta_1, string poziomTrudnosci_1,string heurystykaOceny_1,string alfaBeta_2,string poziomTrudnosci_2,string heurystykaOceny_2);

    int kolejnyRuchAI(bool);
    int licznikRuchow;
    void AIvsAI();

    ~MainWindow();
    QString sciezkaGrafikaWolnePole = "E:/Dropbox/InneProjekty/006_/Programy/GUI/Connect4/Graphic/001.jpg";
    QString sciezkaGrafikaGracz01 = "E:/Dropbox/InneProjekty/006_/Programy/GUI/Connect4/Graphic/002.jpg";
    QString sciezkaGrafikaGracz02 = "E:/Dropbox/InneProjekty/006_/Programy/GUI/Connect4/Graphic/003.jpg";
    int skalaGrafikiX = 90;
    int skalaGrafikiY = 90;

    int flagaTrybGry;
    static const int n = 6;
    static const int m = 7;

    int flagaAlfaBeta_1;
    int flagaAlfaBeta_2;
    int flagaPoziomTrudnosci_1;
    int flagaPoziomTrudnosci_2;
    int flagaHeurystyka_1;
    int flagaHeurystyka_2;



    QLabel* tab[n][m];
    SilnikGry o1;
    MinMax m1;


private slots:
    void on_button00_clicked();

    void on_button01_clicked();

    void on_button02_clicked();

    void on_button03_clicked();

    void on_button04_clicked();

    void on_button05_clicked();

    void on_button06_clicked();

    void on_button_podpowiedz_clicked();

    void on_pushButton_start_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
