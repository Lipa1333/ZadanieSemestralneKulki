#pragma once
#include "klk.h"
#include <Windows.h>

class Plansza
{
public:
	Plansza();
	virtual ~Plansza(); 

	virtual void wypisanie(); //wypisuje pola planszy
	void ukryjKulke(int w, int k); //usuwa (ukrywa) kulke na podanej pozycji
	void pokazKulke(int w, int k,int kolor); //tworzy (pokazuje) kulke na podanej pozycji o podanym kolorze
	void UmiesclosowaKulke(); // umieszcza (pokazuje) na losowym miejscu na planszy kulke i przesuwa kolejke prognozy o jedno miejsce a na ostatnim miejscu osuje nowa kulke
	void prognoza(); // wypisuje najblizsze 3 kulki

protected:

	Kulka**Pole; //"de facto" plansza do gry
	HANDLE hKonsola; //sluzy do kolorowania konsoli
	int rozmiarX; //ilosc kolumn
	int rozmiarY; //ilosc wierszy
	int wylosowane[3]; //3 kolejne wylosowane kulki (tylko kolorki);

};


