#include "losowaniebezpowtorzen.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void LosowanieBezPowtorzen::utworzLosowaKolejnosc(int* tab, int min, int max)
{
    srand(time(NULL));
    int m = max-min;
    int liczbaLosowa;
    //cout << "Losujemy liczby z przedzialu " << min << ";" << max;
    //cout << "Tablica ma rozmiar " << m;

    for(int i = 0; i < m; i++)
    {
        //cout << "losowanie" << endl;
        liczbaLosowa = rand()%m + min;
        if (sprawdzLiczbe(liczbaLosowa, tab, m) == false)
        {
            i -= 1;
        }
        else
        {
            tab[i] = liczbaLosowa;
        }
    }
}

bool LosowanieBezPowtorzen::sprawdzLiczbe(int liczba, int* tab, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (tab[i] == liczba)
            return false;

    }
    return true;
}
