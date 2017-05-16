#ifdef _MSC_VER	
#define _CRT_SECURE_NO_WARNINGS 1
#endif
#include <time.h>
#include "grcz.h"

using namespace std;
//Wielkosc 9 - Mape trzeba inicjalizowac recznie 

Gracz::Gracz() : Plansza(), iloscpustych(Wielkosc * Wielkosc), iloscPunktow(0), czyKoniec(0), imie("")
{
	for (int i = 0; i < Wielkosc + 2; i++)
	{
		Mapa[i] = "HHHHHHHHHHH";
	}
}

string	Gracz::getImie()
{
	return imie;
}

int Gracz::getPunkty()
{
	return iloscPunktow;
}
Gracz::~Gracz()
{
}

void Gracz::setIloscPunktow(int ilosc)
{
	if (ilosc <= 0)
	{
		ilosc = 0;
	}
	iloscPunktow = ilosc;
}

void Gracz::setImie(string im)
{
	imie = im;
}

void Gracz::wypisanie()
{
	system("cls");
	Plansza::wypisanie();
	cout << endl;
}


void Gracz::ustawImie()
{
	string i;
	cout << "Wprowadz Imie:" << endl;
	getline(cin, imie);
	cout << endl << "Witaj " << imie << endl;
	cout << "Wcisnij dowolny klawisz aby kontynuowac" << endl;
	getline(cin, i);
}

void Gracz::stworzGreNaPodstawieMapy()
{
	char pom;
	for (int i = 0; i < Wielkosc; i++)
	{
		for (int j = 0; j < Wielkosc; j++)
		{
			//kolory [9-15]
			//czyli [1-7]
			pom = Mapa[i + 1][j + 1];
			//jesli bedziemy  wywolywac pole[i][j].pokazkulke(pom+8) to bedzie blad poniewaz zdarzaja sie rowniez znaki ' '
			//dlatego najlepszym rozwiazaniem jest switch
			switch (pom)
			{
			case '1':
				Pole[i][j].pokazKulke(9);
				break;
			case '2':
				Pole[i][j].pokazKulke(10);
				break;
			case '3':
				Pole[i][j].pokazKulke(11);
				break;
			case '4':
				Pole[i][j].pokazKulke(12);
				break;
			case '5':
				Pole[i][j].pokazKulke(13);
				break;
			case '6':
				Pole[i][j].pokazKulke(14);
				break;
			case '7':
				Pole[i][j].pokazKulke(15);
				break;
			default:
				Pole[i][j].ukryjKulke();
				break;
			}
		}
	}
}

void Gracz::pobierzMape(string wyj[])
{
	for (int i = 0; i < Wielkosc + 2; i++)
	{
		Mapa[i] = wyj[i];
	}
}

void Gracz::policzPuste()
{
	iloscpustych = 0;
	for (int i = 0; i < Wielkosc; i++)
	{
		for (int j = 0; j < Wielkosc; j++)
		{
			if (Pole[i][j].czyUkryta())
			{
				iloscpustych++;
			}
		}
	}
}


bool Gracz::sprawdzBicie()
{
	int dozbicia[Wielkosc][3] = { { 0 } };
	int dozbicia2[Wielkosc][3] = { { 0 } };
	int pom = iloscPunktow;


	for (int i = 0; i < Wielkosc; i++)
	{
		int pom;
		int ilosc = 0;
		int flaga = 0;
		int index = 0;
		for (int j = 0; j < Wielkosc - 1; j++)
		{
			if (!Pole[i][j].czyUkryta())
			{

				pom = Pole[i][j].getKolorKulki();
				ilosc = 1;
				while (j < Wielkosc - 1 && Pole[i][j + 1].getKolorKulki() == pom)
				{
					ilosc++;
					if (ilosc >= 5)
					{
						flaga = ilosc;
						index = j + 1 - ilosc + 1;
						dozbicia[i][2] = ilosc;
						dozbicia[i][1] = index;
					}
					j++;
				}
			}
		}
		dozbicia[i][0] = i;
	}
	//sprawdzenie kolumnami
	for (int i = 0; i < Wielkosc; i++)
	{
		int pom;
		int ilosc = 0;
		int flaga = 0;
		int index = 0;
		for (int j = 0; j < Wielkosc - 1; j++)
		{
			if (!Pole[j][i].czyUkryta())
			{
				pom = Pole[j][i].getKolorKulki();
				ilosc = 1;
				while (j < Wielkosc - 1 && Pole[j + 1][i].getKolorKulki() == pom)
				{
					ilosc++;
					if (ilosc >= 5)
					{
						flaga = ilosc;
						index = j + 1 - ilosc + 1;
						dozbicia2[i][2] = ilosc;
						dozbicia2[i][1] = index;
					}
					j++;
				}
			}
		}
		dozbicia2[i][0] = i;
	}


	//bicie
	for (int i = 0; i < Wielkosc; i++)
	{
		int o = 0;
		int k = 0;
		if (dozbicia[i][2] != 0)
		{
			for (int j = 0; j < dozbicia[i][2]; j++)
			{
				Pole[i][j + dozbicia[i][1]].ukryjKulke();
			}
		}
	}
	for (int i = 0; i < Wielkosc; i++)
	{
		int o = 0;
		int k = 0;
		if (dozbicia2[i][2] != 0)
		{
			for (int j = 0; j < dozbicia2[i][2]; j++)
			{
				Pole[j + dozbicia2[i][1]][i].ukryjKulke();
			}
		}
	}
	//liczenie punktow zarobionych
	for (int i = 0; i < Wielkosc; i++)
	{
		iloscPunktow += dozbicia[i][2];
		iloscPunktow += dozbicia2[i][2];
	}
	if (iloscPunktow>pom)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Gracz::pokazKulke(int w, int k, int kolor)
{
	//pokazuje kulke, poniewaz plansza sklada sie z juz utworzonych kulek, ktorym nadana jest wartosc czyPusta = true
	Plansza::pokazKulke(w, k, kolor);
}

void Gracz::rysujMape()
{
	int pom;
	for (int i = 0; i < Wielkosc; i++)
	{

		for (int j = 0; j < Wielkosc; j++)
		{
			if (Pole[i][j].czyUkryta())
			{
				Mapa[i + 1][j + 1] = ' ';
			}
			else
			{
				//	Mapa[i+1][j+1] = Pole[i][j].getKolorKulki(); daje zle wyniki poniewaz kolor kulki jest liczba 2 cyfrowa
				//kolory [9-15]
				//czyli [1-7]
				switch (pom = Pole[i][j].getKolorKulki())
				{
				case 9:
					Mapa[i + 1][j + 1] = '1';
					break;
				case 10:
					Mapa[i + 1][j + 1] = '2';
					break;
				case 11:
					Mapa[i + 1][j + 1] = '3';
					break;
				case 12:
					Mapa[i + 1][j + 1] = '4';
					break;
				case 13:
					Mapa[i + 1][j + 1] = '5';
					break;
				case 14:
					Mapa[i + 1][j + 1] = '6';
					break;
				case 15:
					Mapa[i + 1][j + 1] = '7';
					break;
				default:
					Mapa[i + 1][j + 1] = ' ';
					break;
				}
			}
		}
	}
	//mapa poprawna
}


void Gracz::zapiszdopliku()
{
	//zapisuje aktualna mape do pliku
	//a ponizej liczbe punktow
	FILE*stream;
	stream = fopen(plikdozapisu.c_str(), "w");
	//w tym miejscu mamy otworzony poprawny plik. zapisujemy mape
	for (int i = 0; i < Wielkosc + 2; i++)
	{
		for (int j = 0; j < Wielkosc + 2; j++)
		{
			fprintf(stream, "%c", Mapa[i][j]);
		}
		fprintf(stream, "\n");
	}
	fprintf(stream, "%d\n", iloscPunktow);
	fprintf(stream, "%s", imie.c_str());/// c_str poniewaz inaczej fprintf wypisze bzdury 



	fclose(stream);
}

void Gracz::opcjaZapisu()
{
	//pobiera od gracza nazwe pliku do ktorego bedzie zapisywana jego aktualna gra i tworzy taki plik
	FILE *stream;
	int czyok = 0;

	int czyistnieje = 0;

	do
	{
		czyok = 1;
		cout << "podaj nazwe pliku do zapisu, lub jego lokalizacje: " << endl;
		getline(cin, plikdozapisu);
		cout << endl;
		stream = fopen(plikdozapisu.c_str(), "w");
		if (stream == NULL)
		{
			czyistnieje = 0;
		}
		else
		{
			czyistnieje = 1;
		}

		if (czyistnieje == 0)
		{
			cout << "Blad otwierania pliku: " << strerror(errno) << endl;
			czyok = 0;
		}
	} while (czyok == 0);
	fclose(stream);
}

bool Gracz::przemiesckulke()
{
	//przyjmuje najpierw wspolrzedne kulki do przemieszczenia a nastepnie wspolrzede docelowe
	string smieci;
	int StartowyW = 0, StartowyK = 0, KoncowyK = 0, KoncowyW = 0;
	cout << "podaj wspolrzedne kulki do przemieszczenia:" << endl;
	cout << "podaj wiersz kulki do przemieszczenia: " << endl;

	cin.sync();
	cin.clear();
	cin >> StartowyW;
	while (!cin.good() || StartowyW<0 || StartowyW>Wielkosc - 1)
	{
		cout << endl << "Popraw wprowadzone dane." << endl;
		cin.sync();
		cin.clear();
		cin >> StartowyW;
	}

	cout << endl << "podaj kolumne kulki do przemieszczenia: " << endl;

	cin.sync();
	cin.clear();
	cin >> StartowyK;
	while (!cin.good() || StartowyK<0 || StartowyK>Wielkosc - 1)
	{
		cout << endl << "Popraw wprowadzone dane." << endl;
		cin.sync();
		cin.clear();
		cin >> StartowyK;
	}
	cout << endl << "podaj docelowy wiersz: " << endl;
	cin.sync();
	cin.clear();
	cin >> KoncowyW;
	while (!cin.good() || KoncowyW<0 || KoncowyW>Wielkosc - 1)
	{
		cout << endl << "Popraw wprowadzone dane." << endl;
		cin.sync();
		cin.clear();
		cin >> KoncowyW;
	}

	cout << endl << "podaj docelowa kolumne: " << endl;

	cin.sync();
	cin.clear();
	cin >> KoncowyK;
	while (!cin.good() || KoncowyK<0 || KoncowyK>Wielkosc - 1)
	{
		cout << endl << "Popraw wprowadzone dane." << endl;
		cin.sync();
		cin.clear();
		cin >> KoncowyK;
	}
	cin.sync();
	cin.clear();
	cout << endl;
	//wczytane dane. sprawdzenie czy jest taka kulka



	if (!Pole[StartowyW][StartowyK].czyUkryta() && Pole[KoncowyW][KoncowyK].czyUkryta())
	{
		//sprawdzenie czy da sie przemiescic
		//musi byc zrobiona mapa
		bool pom;
		pom = czyIstenieje(Mapa, KoncowyK + 1, KoncowyW + 1, StartowyW + 1, StartowyK + 1);
		if (pom == true)
		{
			Pole[KoncowyW][KoncowyK].pokazKulke(Pole[StartowyW][StartowyK].getKolorKulki());
			zapiszdopliku();
			Pole[StartowyW][StartowyK].ukryjKulke();
			return true;
		}
		else
		{
			cout << "\nNie mozna przemiescic" << endl;
			cout << "Nacisnij enter aby kontynuowac";
			getline(cin, smieci);
			return false;
		}

		//potem trzeba zrobic mape
	}
	else
	{
		cout << "Wprowadzono bledne dane. Podana kulka nie istnieje lub pole jest juz zajete" << endl;
		cout << "nacisnij enter aby kontynuowac";
		getline(cin, smieci);
		return false;
	}
}

void Gracz::pokazmenu()
{
	//wypisuje plansze a ponizej prognoze kulek oraz menu dzialan

	wypisanie();
	prognoza();
	cout << "liczba punktow:" << iloscPunktow << endl;
	cout << "co chcesz zrobic ?" << endl;
	cout << "1. Przemiesc kulke" << endl;
	cout << "2. Zapisz i zakoncz" << endl;
	int odp;

	cin.sync();
	cin.clear();
	cin >> odp;
	while (!cin.good() || odp<1 || odp>3)
	{
		cout << endl << "Popraw wprowadzone dane." << endl;
		cin.sync();
		cin.clear();
		cin >> odp;
	}
	if (odp == 1)
	{
		while (!przemiesckulke())
		{
			;
		}
	}
	if (odp == 2)
	{
		zapiszdopliku();
		czyKoniec = 1;
	}

	cin.sync();
	cin.clear();


}

void Gracz::KoniecGry()
{
	string smieci;

	cout << endl << "Brawo! Ukonczyles/as gre z wynikiem " << iloscPunktow << endl << endl;
	cout << "Dziekujemy za poswiecony czas!" << endl << endl;
	cout << "Autor: Lukasz Miros" << endl;
	cout << "W grze wykorzystano algorytm (plik Lbrnt.h oraz Lbrnt.cpp ) inspirowany praca" << endl;
	cout << "Mgr. Jerzego Walaszka ze strony http://eduinf.waw.pl/inf/alg/001_search/0128.php " << endl;
	cout << "Nacisnij Enter aby kontynuowac..." << endl;
	getline(cin, smieci);
}