#include "minmax.h"
#include <iostream>
#include <windows.h>

using namespace std;

MinMax::MinMax()
{

}
void MinMax::okreslObszarPrzeszukiwania(int x, int y)
{
    indeksPoczatek_oX = x - obramowaniePrzeszukiwania_x;
    indeksKoniec_oX = x + obramowaniePrzeszukiwania_x + 1;
    indeksPoczatek_oY = y - obramowaniePrzeszukiwania_y;
    indeksKoniec_oY = y + obramowaniePrzeszukiwania_y;


    if(indeksPoczatek_oX < 0)
    {
        indeksPoczatek_oX = 0;
    }
    if(indeksKoniec_oX > m)
    {
        indeksKoniec_oX = m;
    }

    if(indeksPoczatek_oY < 0)
    {
        indeksPoczatek_oY = 0;
    }
    if(indeksKoniec_oY  >  n)
    {
        indeksKoniec_oY = n;
    }

    //cout << "Przeszukiwanie w obszarze  oX " <<  indeksPoczatek_oX << "  " <<  indeksKoniec_oX<< endl;
    //cout << "Przeszukiwanie w obszarze  oY " <<  indeksPoczatek_oY << "  " <<  indeksKoniec_oY<< endl;
}
void MinMax::okreslResponsywnieSasiedztwo(int** tab, int x, int y)
{
    int pustePola = 0;
    obramowaniePrzeszukiwania_x = 4;
    obramowaniePrzeszukiwania_y = 5;
    okreslObszarPrzeszukiwania(x, y);
    cout << "Przeszukiwanie w obszarze  oX " <<  indeksPoczatek_oX << "  " <<  indeksKoniec_oX<< endl;
    cout << "Przeszukiwanie w obszarze  oY " <<  indeksPoczatek_oY << "  " <<  indeksKoniec_oY<< endl;



    for (int i = indeksPoczatek_oY; i < indeksKoniec_oY; i++)
    {
        for (int j = indeksPoczatek_oX; j < indeksKoniec_oX; j++)
        {
            if (tab[i][j] == -1)
            {
                pustePola++;
            }
        }
    }
    if(pustePola > 35)
    {
        obramowaniePrzeszukiwania_x = 2;
        obramowaniePrzeszukiwania_y = 2;
        okreslObszarPrzeszukiwania(x, y);
    }


    pustePola = 0;
    for (int i = indeksPoczatek_oY; i < indeksKoniec_oY; i++)
    {
        for (int j = indeksPoczatek_oX; j < indeksKoniec_oX; j++)
        {
            if (tab[i][j] == -1)
            {
                pustePola++;
            }
        }
    }
    if(pustePola > 20)
    {
        obramowaniePrzeszukiwania_x = 1;
        obramowaniePrzeszukiwania_y = 1;
        okreslObszarPrzeszukiwania(x, y);
    }

    //cout << "OBRAMOWANIE PEZESZUKIWANIA X = " << obramowaniePrzeszukiwania_x << endl;
    //cout << "Przeszukiwanie w obszarze  oX " <<  indeksPoczatek_oX << "  " <<  indeksKoniec_oX<< endl;
    //cout << "Przeszukiwanie w obszarze  oY " <<  indeksPoczatek_oY << "  " <<  indeksKoniec_oY<< endl;
    cout << "Rozmiar obszaru poszukiwania" << indeksKoniec_oX - indeksPoczatek_oX << endl;



}



int MinMax::findBestMove(int** tab,int player, int poprzedniRuch_x, int poprzedniRuch_y, int* licznikRuchow)
{

    if(responsywneSasiedstwo == false)
    {
        okreslObszarPrzeszukiwania(poprzedniRuch_x, poprzedniRuch_y);
    }
    else
    {
        okreslResponsywnieSasiedztwo(tab, poprzedniRuch_x, poprzedniRuch_y);
        okreslObszarPrzeszukiwania(poprzedniRuch_x, poprzedniRuch_y);
    }


    int* tablicaKolejnosci = new int[m];
    utworzLosowaKolejnosc(tablicaKolejnosci);

    //Sleep(100000);
    playerTurn = player;
    licznikWywolan = 0;

    if(player == 1)
    {
        ai = 1;
        opponent = 2;
    }
    else
    {
        ai = 2;
        opponent = 1;
    }

    int bestScore = INT_MIN;
    int bestScorePosition_x = INT_MIN;
    int iterator = 0;
    int iteratorBest = 0;

    for (int i = indeksPoczatek_oX; i < indeksKoniec_oX; i++)
    {

       // Is the spot available?
       if (tab[0][tablicaKolejnosci[i]] == -1)
       {

            wykonajRuch(tab, tablicaKolejnosci[i]);
            licznikWywolan = 0;
            int score = minMaxAlgorithm(tab, 0, false, licznikRuchow);
            //cout << "SCORE = " << score << endl;
            cofnijRuch(tab, tablicaKolejnosci[i]);
            if (score > bestScore)
            {

                bestScore = score;
                bestScorePosition_x = tablicaKolejnosci[i];
                iteratorBest = iterator;
            }
            iterator++;

        }
       else
       {
           //cout << "OMIJAM POZYCJE " << tablicaKolejnosci[i]<< endl;
           //cout << "Przeszukiwanie w obszarze  oX " <<  indeksPoczatek_oX << "  " <<  indeksKoniec_oX<< endl;
          // cout << "Przeszukiwanie w obszarze  oY " <<  indeksPoczatek_oY << "  " <<  indeksKoniec_oY<< endl;
       }

    }
    //cout << "BEST SCORE = " << bestScore << endl;
    //cout << "Najlepszy tuch to pozycja " << bestScorePosition_x << "   dla sprawdzenia " << iteratorBest <<  endl;
    cout << *licznikRuchow << endl;
    cout << "LiczbaWywolan = " << licznikWywolan << endl;
    return bestScorePosition_x;
}

int MinMax::minMaxAlgorithm(int** tab, int depth, bool isMaximizing, int* licznikRuchow)
{
       *licznikRuchow++;
        licznikWywolan++;
      int result = checkWinner(tab);
      if(ograniczenieGlebokosci == true)
      {
            if(depth == flagaPoziomTrudnosci)
            {
                return 3;
            }
      }
      if (result != 0)
      {
          if (result == ai)
          {
              //cout << "Wygrana po " << depth << " ruchach "<<endl;
              return 10;
          }
          if(result == opponent)
          {
             int pom = INT_MIN;
             //cout << "Przegrana po " << depth << " ruchach "<<endl;
             pom += depth;
             return pom;
          }

          // remis
          if(result == 3)
          {
              return 0;
          }
          return -1221;
      }

      /*
        maksymalizujemy wartosc dla naszego ruchu
      */
      if (isMaximizing)
      {
        int bestScore = INT_MIN;
        for (int i = indeksPoczatek_oX; i < indeksKoniec_oX; i++)
        {

               // Is the spot available?
               if (tab[0][i] == -1)
               {
                    wykonajRuch(tab, i);
                    int score;
                    score = minMaxAlgorithm(tab, depth + 1, false, licznikRuchow);
                    if(score > bestScore)
                    {
                        bestScore = score;
                    }
                    cofnijRuch(tab, i);   // kasujemy wpisana wartosc
                    //cout << "Best score dla " << score << "   " << bestScore << endl;
                    if(score > 0)
                    {
                        return score;
                    }
               }

        }
        return bestScore;
      }
      /*
            gdy jest ruch przeciwnika to szukamy najmniejszej wartości
      */
      else
       {
            int bestScore = 100;
            for (int i = indeksPoczatek_oX; i < indeksKoniec_oX; i++)
            {

                    // Is the spot available?
                    if (tab[0][i] == -1)
                    {
                        wykonajRuch(tab, i);
                        int score = minMaxAlgorithm(tab, depth + 1, true, licznikRuchow);
                        cofnijRuch(tab, i);
                        if(score < bestScore)
                        {
                            bestScore = score;
                        }
                        if(score < 0)
                        {
                            return score;
                        }
                        //cout << "Najmniejszy wynik to " << bestScore << endl;
                    }

            }
            return bestScore;
      }
}




void MinMax::wykonajRuch(int** tab, int pozycja_x)
{
    for (int i = n - 1; i >= 0; i--)
    {
        if (tab[i][pozycja_x] == -1)
        {
            tab[i][pozycja_x] = playerTurn;
            break;
        }
    }

    if(playerTurn == 1)
    {
        playerTurn = 2;
    }
    else
    {
        playerTurn = 1;
    }

}
void MinMax::cofnijRuch(int** tab, int pozycja_x)
{
    for (int i = 0; i < n; i++)
    {
        if (tab[i][pozycja_x] != -1)
        {
            tab[i][pozycja_x] = -1;
            break;
        }
    }
}


void MinMax::wypiszPlansze(int **plansza)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (plansza[i][j] == -1)
            {
                cout << "-" << "   ";
            }
            else
            {
                cout << plansza[i][j] << "   ";
            }
        }
        cout << endl;
    }
}


int MinMax::checkWinner(int **plansza)
{
    int pomGracz1 = 0;
    int pomGracz2 = 0;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            // sprawdzanie dla gracza 1
            if (plansza[i][j] == 1)
            {
                pomGracz1++;
            }
            if (pomGracz1 >= 4)
            {
                return 1;
            }
            if (plansza[i][j] != 1)
            {
                pomGracz1 = 0;
            }



            // sprawdzanie dla gracza 2
            if (plansza[i][j] == 2)
            {
                pomGracz2++;

            }
            if (pomGracz2 >= 4)
            {
                return 2;
            }
            if (plansza[i][j] != 2)
            {
                pomGracz2 = 0;
            }
        }
        pomGracz1 = 0;
        pomGracz2 = 0;
    }

    /*
        sprawdzenie czy jest wygrany w pionie
    */
    pomGracz1 = 0;
    pomGracz2 = 0;
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            // sprawdzanie dla gracza 1
            if (plansza[i][j] == 1)
            {
                pomGracz1++;
            }
            if (pomGracz1 >= 4)
            {
                return 1;
            }
            if (plansza[i][j] != 1)
            {
                pomGracz1 = 0;
            }



            // sprawdzanie dla gracza 2
            if (plansza[i][j] == 2)
            {
                pomGracz2++;

            }
            if (pomGracz2 >= 4)
            {
                return 2;
            }
            if (plansza[i][j] != 2)
            {
                pomGracz2 = 0;
            }
        }
        pomGracz1 = 0;
        pomGracz2 = 0;
    }

    /*
        sprawdzenie, czy jest wygrany po skosie "funkcja malejaca y = -x"
    */

    pomGracz1 = 0;
    pomGracz2 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // dla gracza 1
            pomGracz1 = 0;
            pomGracz2 = 0;
            int pomX = 0;
            int pomY = 0;
            if (plansza[i][j] == 1)
            {
                pomX = j;
                pomY = i;
                while (pomY < n && pomX < m && plansza[pomY][pomX] == 1)
                {
                    pomGracz1++;
                    pomY++;
                    pomX++;
                    //cout <<"Gracz1 - pozycja "<< pomY << "  " << pomX << "  "<< pomGracz1 << endl;
                }

                if (pomGracz1 >= 4)
                {
                    return 1;
                }
            }

            // dla gracza 2
            pomX = 0;
            pomY = 0;
            if (plansza[i][j] == 2)
            {
                pomX = j;
                pomY = i;
                while (pomY < n && pomX < m && plansza[pomY][pomX] == 2 )
                {
                    pomGracz2++;
                    pomY++;
                    pomX++;
                 }
                 if (pomGracz2 >= 4)
                {
                    return 2;
                }
            }
        }
        pomGracz1 = 0;
        pomGracz2 = 0;
    }


    /*
    sprawdzenie, czy jest wygrany po skosie "funkcja rosnaca y = x"
    */

    pomGracz1 = 0;
    pomGracz2 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // dla gracza 1
            pomGracz1 = 0;
            pomGracz2 = 0;
            int pomX = 0;
            int pomY = 0;
            if (plansza[i][j] == 1)
            {
                pomX = j;
                pomY = i;
                while (pomY < n && pomX >= 0 && plansza[pomY][pomX] == 1)
                {
                    pomGracz1++;
                    pomY++;
                    pomX--;
                    //cout << "Gracz1 - pozycja " << pomY << "  " << pomX << "  " << pomGracz1 << endl;
                }
                 if (pomGracz1 >= 4)
                {
                    return 1;
                }
            }

            // dla gracza 2
            pomX = 0;
            pomY = 0;
            if (plansza[i][j] == 2)
            {
                pomX = j;
                pomY = i;
                while (pomY < n && pomX >= 0 < m && plansza[pomY][pomX] == 2)
                {
                    pomGracz2++;
                    pomY++;
                    pomX--;
                    //cout << "Gracz2 - pozycja " << pomY << "  " << pomX << "  " << pomGracz1 << endl;

                }
                if (pomGracz2 >= 4)
                {
                    return 2;
                }
            }
        }
        pomGracz1 = 0;
        pomGracz2 = 0;
    }


    // sprawdzanie czy plansza jest pelna
    bool planszaPelna = true;
    for (int i = indeksPoczatek_oY; i < indeksKoniec_oY; i++)
    {
        for (int j = indeksPoczatek_oX; j < indeksKoniec_oX; j++)
        {
            if (plansza[i][j] == -1)
            {

                planszaPelna = false;
            }
        }
    }
    if(planszaPelna == true)
    {
        //wypiszPlansze(plansza);
        //cout << endl;
        //Sleep(2000);
        return 3;
    }

    return 0;
}


void MinMax::ustawFlagi(int flagaAlfaBeta, int flagaPoziomTrudnosci,int flagaHeurystyka)
{
    this->flagaAlfaBeta = flagaAlfaBeta;
    this->flagaPoziomTrudnosci = flagaPoziomTrudnosci;
    this->flagaHeurystyka = flagaHeurystyka;


}

void MinMax::utworzLosowaKolejnosc(int* tab)
{
    int liczbaLosowa;
    for(int i = 0; i < m; i++)
    {
        liczbaLosowa = rand()%m;
        if (sprawdzLiczbe(liczbaLosowa, tab, n) == false)
        {
            i -= 1;
        }
        else
        {
            tab[i] = liczbaLosowa;
        }
    }
}




bool MinMax::sprawdzLiczbe(int liczba, int* tab, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (tab[i] == liczba)
            return false;

    }
    return true;
}
