#include "silnikgry.h"
#include <iostream>

using namespace std;

SilnikGry::SilnikGry()
{
    /*
        Alokujemy pamiec dla planszy i uzupelniamy plansze wartosciami poczatkowymi -1
    */
	plansza = new int* [n];
	for (int i = 0; i < n; i++)
	{
		plansza[i] = new int[m];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			plansza[i][j] = -1;
		}
	}

    /*
        ustalamy ze rozgrywke zaczyna gracz 1 i ustawiamy sztucznie poprzedni ruch AI, zeby poprawnie mogl
        dzialac algorytm zawezania dziedziny
    */
    turaGracza = 1;
    poprzedniRuch_x = 3;
    poprzedniRuch_y = 3;
}


void SilnikGry::ruchGracza(int pozycja_x)
{
    /*
       zaktualizowanie planszy poprzez zapisanie ruchu
       w petli schodzimy tak gleboko az znajdziemy pierwsze wolne miejsce gdzie mozemy
       umiescic nasz zeton
    */
    for (int i = n - 1; i >= 0; i--)
    {
        if (plansza[i][pozycja_x] == -1)
        {
            plansza[i][pozycja_x] = turaGracza;
            poprzedniRuch_x = pozycja_x;
            poprzedniRuch_y = i;
            break;
        }
    }

    if(turaGracza == 1)
    {
        turaGracza = 2;
    }
    else
    {
        turaGracza = 1;
    }

}


int SilnikGry::sprawdzStanGry()
{
    int zwyciezca = sprawdzZwyciestwo();
    if (zwyciezca == 1)
    {
        cout << "Wygral gracz 1" << endl;
        return 1;
    }
    else if (zwyciezca == 2)
    {
        cout << "Wygral gracz 2" << endl;
        return 2;
    }
    if (planszaJestPelna())
    {
        cout << "Gra zakonczyla sie remisem. Plansza jest pelna." << endl;
        return 3;
    }
    return 0;
}

int SilnikGry::sprawdzZwyciestwo()
{

	int pomGracz1 = 0;
	int pomGracz2 = 0;
	/*
		sprawdzanie czy jest wygrany w poziomie
	*/
	for (int i = 0; i < n; i++)
	{	
		
		for (int j = 0; j < m; j++)
		{	

            /*
                zliczamy ile jest zetonow gracza w poziomie pod rzad
            */

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
				//cout << endl << endl;
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

	return 0;
}

void SilnikGry::resetRozgrywki()
{
    /*
        resetujemy plansze ustawiajac wszedzie wartosc -1 i ustalamy kto bedzie rozpoczynac rozgrywke
    */
    turaGracza = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            plansza[i][j] = -1;
        }
    }
}

bool SilnikGry::planszaJestPelna()
{
	bool planszaPelna = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (plansza[i][j] == -1)
			{
				planszaPelna = false;
				break;
			}
		}
		if (planszaPelna == false)
		{
			break;
		}
	}
	return planszaPelna;
}

void SilnikGry::wypiszPlansze()
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
