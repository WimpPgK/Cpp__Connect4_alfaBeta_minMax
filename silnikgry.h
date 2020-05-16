#pragma once
class SilnikGry
{
public:
	int** plansza;
	static const int n = 6;		// liczba wierszy
	static const int m = 7;		// liczba kolumn
    int turaGracza;					// gdy 1 to gracz 1 wykonuje ruch, gdzy 2 to gracz 2 wykonuje ruch
    int poprzedniRuch_x;
    int poprzedniRuch_y;

    SilnikGry();
	
	void rozgrywka();
    void ruchGracza(int pozycja_x);
    void resetRozgrywki();


    //ZWRACA  1: wygrywa gracz 1    2: wygrywa gracz 2     3: remis     0: gra toczy sie dalej
    int sprawdzStanGry();
	int sprawdzZwyciestwo();
	bool planszaJestPelna();
	void wypiszPlansze();

};

