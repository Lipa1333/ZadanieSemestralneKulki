#pragma once
#include <stdio.h>
#include <iostream>
#include <string.h>
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


using namespace std;

//PONIZSZY KOD INSPIROWANY PRAC¥ MGR JERZEGO WA£ASZKA 
//ZE STRONY : http://eduinf.waw.pl/inf/alg/001_search/0128.php
//25.08.2013

struct ellist
{
	ellist *nast;
	int w;
	int k;
};

class kolejka
{
public:
	kolejka();
	~kolejka();
	void naKoniec(int x, int y); //dodaje aktualnie badany element na koniec kolejki
	int frontw();  //zwraca element aktualnengo elementu na szczycie kolejki
	int frontk(); //zwraca element aktualnengo elementu na szczycie kolejki
	void pop(); //usuwa aktualny pierwszy element 
	bool czyniePusta(); 
private:
	ellist * glowa;
	ellist * wsk;

};

void szukaj(string lab[], int Wk, int Ww, int Sw, int Sk);  //przeszukuje labirynt w celu dotarcia z punktu S do punktu W
bool czyIstenieje(string lab[], int Wk, int Ww, int Sw, int Sk); //sprawdza czy istnieje sciezka w labiryncie (wywoluje funkcje szukaj)
	