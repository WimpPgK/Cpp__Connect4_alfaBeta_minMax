#ifndef MINMAX_H
#define MINMAX_H


class SztucznaInteligencja
{
    static const int n = 6;		// liczba wierszy
    static const int m = 7;		// liczba kolumn

    int obramowaniePrzeszukiwania_x = 5;
    int obramowaniePrzeszukiwania_y = 5;
    bool responsywneSasiedstwo = false;
    bool ograniczenieGlebokosci = true;
    int maksymalnaGlebokosc = 20;


    int indeksPoczatek_oX;
    int indeksPoczatek_oY;
    int indeksKoniec_oX;
    int indeksKoniec_oY;


public:
    SztucznaInteligencja();
    int znajdzNajlepszyRuch(int** tab, int playerNumber, int, int);
    int algorytmMinMaxAlfaBeta(int** tab, int depth, bool isMaximizing);
    int checkWinner(int** tab);
    void printGame(int** tab);
    void wykonajRuch(int** tab, int x);
    void cofnijRuch(int ** tab, int x);
    void wypiszPlansze(int ** tab);
    void okreslObszarPrzeszukiwania(int x, int y);
    void okreslResponsywnieSasiedztwo(int**, int x, int y);
    void ustawFlagi(int flagaAlfaBeta, int flagaPoziomTrudnosci,int flagaHeurystyka);
    void utworzLosowaKolejnosc(int* tab);
    bool sprawdzLiczbe(int liczba, int* tab, int n);

    int flagaAlfaBeta;
    int flagaPoziomTrudnosci;
    int flagaHeurystyka;
    int playerTurn;
    int ai;
    int opponent;

    int licznikWywolan;
};

#endif // MINMAX_H
