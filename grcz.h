#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include "plnsz.h"
#include "Lbrnt.h"
using namespace std;
#define Wielkosc 9
/*
Kolory kulek :
1 - Chabrowy - 9
2 - Zielony Jaskrawy - 10
3 - Cyjan - 11
4 - Karmazynowy - 12
5 - fio³kowy - 13
6 - kanarkowy - 14
7 - per³owy - 15
*/
class Gracz : public Plansza
{
public:
	Gracz();
	~Gracz();
	void wypisanie(); //wypisuje na ekran
	void policzPuste(); //zlicza puste miejsca na planszy
	bool sprawdzBicie(); //sprawdza czy w ktoryms wierszu lubkolumnie znajduje sie 5 lub wiecej kulek i je usuwa oraz dodaje punkty
	void rysujMape(); //aktualizuje pole Mapa
	void opcjaZapisu(); //ustanawia pole plikdozapisu
	void zapiszdopliku(); //zapisuje do pliku aktualna gre
	bool przemiesckulke(); //kompletne menu przemiszczenia kulki
	void pokazmenu();  //pokazuje mozliwe wybory operacji na planszy
	void KoniecGry();  //teskt wyswietlany na koniec gry
	void ustawImie(); //kompletne menu aktualizacji pole imie
	void stworzGreNaPodstawieMapy(); //odtwarza pola na planszy na podstawie danych w polu Mapa
	void pobierzMape(string wyj[]);  //pobiera mape z pliku
	void setIloscPunktow(int ilosc); //aktualizuje ilosc punktow (przy wczytywaniu z pliku)
	void setImie(string im); //ustanawia imie (przy wczytywaniu z pliku) 
	string getImie(); //zwraca imie
	int getPunkty(); //zwraca punkty

	int czyKoniec; //flaga
	int iloscpustych; // ilosc pustych pol na planszy


private:
	void pokazKulke(int w, int k, int kolor);  //tworzy (pokazuje) kulke we wskazanym punkcie

	int iloscPunktow; 
	string Mapa[Wielkosc + 2]; //Obraz planszy do gry. Wielkosc+2 poniewaz jest uzupelniona o znaki 'H' na krawedziach
	string plikdozapisu;
	string imie;
};


