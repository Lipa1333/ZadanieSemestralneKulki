#include "plnsz.h"
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <string>
#define Wielkosc 9
using namespace std;
Plansza::Plansza()
{
	srand(time(NULL));
	hKonsola = GetStdHandle(STD_OUTPUT_HANDLE);
	//a teraz:
	Pole = new Kulka*[Wielkosc];
	for (int i = 0; i < Wielkosc; i++)
	{
		Pole[i] = new Kulka[Wielkosc];
	}
	//Na tym etapie mamy zdefiniowana Plansze 
	//Wypelniona pustymi kulkami
	rozmiarX = Wielkosc;
	rozmiarY = Wielkosc;
	wylosowane[0] = rand() % 7 + 9;
	wylosowane[1] = rand() % 7 + 9;
	wylosowane[2] = rand() % 7 + 9;

}
Plansza::~Plansza()
{
	for (int i = 0; i < Wielkosc; i++)
	{
		delete[]Pole[i];
	}
}

void Plansza::wypisanie()
{
	SetConsoleTextAttribute(hKonsola, 112);
	cout << "\\|";
	for (int i = 0; i < Wielkosc; i++)
	{
		cout << i << "|";
	}
	cout << endl;
	for (int j = 0; j < 2 * Wielkosc + 1; j++)
	{
		SetConsoleTextAttribute(hKonsola, 112);
		cout << "-";
	}
	cout << '-' << endl;

	for (int i = 0; i < Wielkosc; i++)
	{
		SetConsoleTextAttribute(hKonsola, 112);
		cout << i << "|";
		for (int j = 0; j < Wielkosc; j++)
		{
			if (Pole[i][j].czyUkryta())
			{
				SetConsoleTextAttribute(hKonsola, 119);
				cout << " ";
			}
			else
			{
				SetConsoleTextAttribute(hKonsola, Pole[i][j].getKolorKulki() + 112);
				cout << (char)219;
			}
			SetConsoleTextAttribute(hKonsola, 112);
			cout << "|";
		}
		cout << endl;

		for (int j = 0; j < 2 * Wielkosc + 1; j++)
		{
			SetConsoleTextAttribute(hKonsola, 112);
			cout << "-";
		}
		cout << "-" << endl;

		SetConsoleTextAttribute(hKonsola, 7);
	}
}

void Plansza::ukryjKulke(int w, int k)
{
	Pole[w][k].ukryjKulke();
}
void Plansza::pokazKulke(int w, int k, int kolor)
{
	Pole[w][k].pokazKulke(kolor);
}

void Plansza::UmiesclosowaKulke()
{

	int iloscPustych = 0;
	int **tab;
	int k = 0;
	int wylosowana;
	for (int i = 0; i < rozmiarX; i++)
	{
		for (int j = 0; j < rozmiarY; j++)
		{
			if (Pole[i][j].czyUkryta())
			{
				iloscPustych++;
			}
		}
	}

	//jak juz wiemy ile jest pustych to trzeba teraz je "uliniowic"

	tab = new int*[3];
	tab[0] = new int[iloscPustych]; //index
	tab[1] = new int[iloscPustych]; //wsp x
	tab[2] = new int[iloscPustych]; //wsp y

	for (int i = 0; i < iloscPustych; i++)
	{
		tab[0][i] = i;
	}

	for (int i = 0; i < rozmiarX; i++)
	{
		for (int j = 0; j < rozmiarY; j++)
		{
			if (Pole[i][j].czyUkryta())
			{
				tab[1][k] = i;
				tab[2][k] = j;
				k++;
			}
		}
	}
	//a wiec mamy uliniowiona tablice wspolrzednych 
	//no to losujemy

	wylosowana = rand() % iloscPustych;


	pokazKulke(tab[1][wylosowana], tab[2][wylosowana], wylosowane[0]);
	for (int i = 0; i < 3; i++)
	{
		delete[] tab[i];
	}
	delete tab;
	wylosowane[0] = wylosowane[1];
	wylosowane[1] = wylosowane[2];
	wylosowane[2] = rand() % 7 + 9;

}



void Plansza::prognoza()
{
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
	cout << "Najblizsze 3 kulki: " << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "kulka o kolorze:";
		switch (wylosowane[i])
		{
		case 9:
			cout << " niebieska";
			break;
		case 10:
			cout << " zielona";
			break;
		case 11:
			cout << " blekitna";
			break;
		case 12:
			cout << " czerwona";
			break;
		case 13:
			cout << " fioletowa";
			break;
		case 14:
			cout << " zolta";
			break;
		case 15:
			cout << " biala";
			break;

		default:
			break;
		}
		cout << endl;
	}
}



