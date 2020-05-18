#include <iostream>
#include "obslugaplanszy.h"


using namespace std;
ObslugaPlanszy::ObslogaPlanszy()
{

}


int ObslugaPlanszy::sprawdzZwyciezce(int **plansza, int n, int m)
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
        return 3;
    }

    return 0;
}


void ObslugaPlanszy::wypiszPlansze(int **plansza, int n, int m)
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
