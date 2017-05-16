
#ifdef _MSC_VER	
#define _CRT_SECURE_NO_WARNINGS 1
#endif
#include "grcz.h"
#include <string>

template<typename typ1>
void zapisdolistywynikow(typ1 imie, int punkty)
{

	FILE *stream;

	stream = fopen("listawynikow.txt", "a+");
	fprintf(stream, "%s %d\n", imie.c_str(), punkty);
	fclose(stream);

}

bool CzyPlikIstnieje(FILE* stream)
{
	if (stream == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool CzyPlikJestPusty(FILE* stream)
{
	long s;
	s = ftell(stream);
	fseek(stream, 0, SEEK_END);
	if (ftell(stream) == 0)
	{
		return true;
	}
	fseek(stream, s, SEEK_SET);
	return false;
}

void odczytlisty()
{
	FILE *stream;
	string wynik;
	char znak;
	stream = fopen("listawynikow.txt", "r");
	if (!CzyPlikIstnieje(stream))
	{
		cout << "Plik listy wynikow nie istnieje!" << endl;
		cout << "Rozegraj gre na tym komputerze aby stworzyc nowa liste" << endl;
		cout << "Nacisnij enter aby kontynuowac" << endl;
		getline(cin, wynik);
		return;
	}
	else
	{
		if (CzyPlikJestPusty(stream))
		{
			cout << "Plik jest pusty!" << endl;
			cout << "Rozegraj gre na tym komputerze aby stworzyc liste" << endl;
			cout << "Nacisnij enter aby kontynuowac" << endl;
			getline(cin, wynik);
			fclose(stream);
		}
		else
		{
			do
			{


				wynik = "";
				//plik istnieje i jest nie pusty
				do
				{
					fscanf(stream, "%c", &znak);
					wynik += znak;
				} while (!feof(stream) && znak != '\n');
				cout << wynik;
			} while (!feof(stream));
			cout << "Nacisnij enter aby kontynuowac" << endl;
			getline(cin, wynik);
			fclose(stream);
		}
	}

}

void nowagra()
{
	//kulek nie da sie bezargumentowo
	Gracz *Nowy = new Gracz();

	//kolory 9-15


	//chyba dziala
	//nowa gra
	Nowy->ustawImie();
	Nowy->opcjaZapisu();
	Nowy->UmiesclosowaKulke();
	Nowy->UmiesclosowaKulke();
	Nowy->UmiesclosowaKulke();

	Nowy->rysujMape();
	Nowy->zapiszdopliku();
	Nowy->policzPuste();
	do
	{
		Nowy->pokazmenu();
		if (Nowy->czyKoniec == 1)
		{
			return;
		}

		while (Nowy->sprawdzBicie())
		{
			Nowy->rysujMape();
			Nowy->policzPuste();
			Nowy->zapiszdopliku();
			Nowy->pokazmenu();
			if (Nowy->czyKoniec == 1)
			{
				Nowy->rysujMape();
				Nowy->policzPuste();
				Nowy->zapiszdopliku();
				return;
			}
		}

		if (Nowy->iloscpustych >= 1)
		{
			Nowy->UmiesclosowaKulke();
			if (Nowy->iloscpustych >= 2)
			{
				Nowy->UmiesclosowaKulke();
				if (Nowy->iloscpustych >= 3)
				{
					Nowy->UmiesclosowaKulke();
				}
			}
		}
		Nowy->sprawdzBicie();

		Nowy->rysujMape();
		Nowy->policzPuste();
		Nowy->zapiszdopliku();
		if (Nowy->iloscpustych == 0)
		{
			Nowy->wypisanie();
			//koniec gry
			Nowy->KoniecGry();
		}
	} while (Nowy->iloscpustych > 0);

	zapisdolistywynikow(Nowy->getImie(), Nowy->getPunkty());
	delete Nowy;

}





bool CzyWPlikuJestPlansza(FILE* stream)
{
	/*
	Zwraca false jesli Plansza nie poprawna
	*/
	long s;
	s = ftell(stream);
	char znak;
	int wymaganailoscwierszy = Wielkosc + 2;//czyli zawierajcych CO NAJMNIEJ Wielkosc+2 znakow
	int i = 0;
	int j = 0;
	int a;
	string test;
	//plik nie jest pusty i posiada co najmniej 1 linijke

	do
	{
		test = "";
		i = 0;

		fscanf(stream, "%c", &znak);
		do
		{
			if (i == 0 && znak == '\n')
			{
				cout << "Wykryto manipulacje w pliku zapisu. Wykryto pusty wiersz" << endl;
				cout << "Wczytanie nie powiodlo sie" << endl;
				fseek(stream, s, SEEK_SET);
				return false;
			}
			i++;
			test += znak;
			fscanf(stream, "%c", &znak);
		} while (!feof(stream) && znak != '\n' && i < Wielkosc + 2);
		while (!feof(stream) && znak != '\n')
		{
			fscanf(stream, "%c", &znak);
		}
		if (test.length() < Wielkosc + 2)
		{
			cout << "Wykryto manipulacje w pliku zapisu. Wiersze maja zbyt malo znakow" << endl;
			cout << "Wczytanie nie powiodlo sie" << endl;
			fseek(stream, s, SEEK_SET);
			return false;
		}
		//tutaj wiemy juz ze badany wiersz jest Wielkosc+2 znakowy
		//musmy miec Wielkosc+2 takich wierszy
		j++;
		if (j < Wielkosc + 2 && feof(stream))
		{
			cout << "Wykryto manipulacje w pliku zapisu. Zbyt malo wierszy" << endl;
			cout << "Wczytywanie nie powiodlo sie" << endl;
			fseek(stream, s, SEEK_SET);
			return false;
		}

	} while (j < Wielkosc + 2);
	if (j == wymaganailoscwierszy)
	{
		//a wiec plansza jest i jest poprawna
		//trzeba jeszcze sprobowac zaimportowac punkty i imie

		if (!feof(stream))
		{
			if (fscanf(stream, "%d", &a) != 1)
			{
				cout << "Nie udalo sie wczytac wyniku" << endl;
				cout << "Wczytywanie nie powiodlo sie" << endl;
				fseek(stream, s, SEEK_SET);
				return false;
			}
		}
		else
		{
			cout << "Brak ilosci punktow" << endl;
			cout << "Wczytywanie nie powiodlo sie" << endl;
			fseek(stream, s, SEEK_SET);
			return false;
		}
		//tutaj jestesmy juz pewni ze wynik istenieje i jest poprawny tj. jest cyfra
		fscanf(stream, "%c", &znak);
		if (!feof(stream))
		{
			test = "";
			do
			{

				i++;
				test += znak;
				fscanf(stream, "%c", &znak);
			} while (!feof(stream) && znak != '\n');

		}
		else
		{
			cout << "Brak imienia" << endl;
			cout << "Wczytywanie nie powiodlo sie" << endl;
			fseek(stream, s, SEEK_SET);
			return false;

		}

		//imie:
		//czyli imie da sie zaimportowac
		cout << "Plik wczytany" << endl;

		fseek(stream, s, SEEK_SET);
		return true;
	}
	else
	{
		cout << "Nie osiagnieto wymagana ilosc wierszy" << endl;
		fseek(stream, s, SEEK_SET);
		return false;
	}

}

bool wczytajgre()
{
	/*
	Tworzy nowa gre na podstawie zapisu
	Jesli nie uda sie - false
	Jesli gracz zakonczy gre normalnie - true
	*/

	string doodczytu;
	string smieci;
	char znak;
	string wynik[Wielkosc + 2];
	FILE *stream;
	Gracz *Nowy = new Gracz();
	int punkty;
	string imie;
	int k = 0;
	cout << "Prosze podac nazwe pliku do odczytu" << endl;
	getline(cin, doodczytu);
	cout << endl;
	stream = fopen(doodczytu.c_str(), "r");
	if (!CzyPlikIstnieje(stream))
	{
		cout << "Plik nie istenieje" << endl;
		cout << "Nacisnij enter aby kontynuowac..." << endl;
		getline(cin, smieci);
		return false;
	}
	if (CzyPlikJestPusty(stream))
	{
		cout << "Plik pusty" << endl;
		cout << "Nacisnij enter aby kontynuowac..." << endl;
		getline(cin, smieci);
		fclose(stream);
		return false;
	}
	// w tym miejscu plik istnieje i nie jest pusty
	//podejmiemy wiec probe odczytu
	//najpierw sprawdzimy liczbe znakow. jesli jest mniejsza niz zakladana to odczyt sie nie powiedzie
	//w przypadku zbyt duzej liczby znakow zostana one zignorowane
	//lub bednych znakow
	//ale musimy to sprawdzic jedynie dla pierwszych Wielkosc+2 wierszy i dla Wielkosc+2 kolumn
	if (CzyWPlikuJestPlansza(stream) == true)
	{
		cout << "Nacisnij enter aby kontynuowac..." << endl;
		getline(cin, smieci);
	}
	else
	{
		cout << "Nacisnij enter aby kontynuowac..." << endl;
		getline(cin, smieci);
		return false;
	}


	for (int i = 0; i < Wielkosc + 2; i++)
	{
		for (int j = 0; j < Wielkosc + 2; j++)
		{
			fscanf(stream, "%c", &znak);
			wynik[i] += znak;
		}
		do
		{
			fscanf(stream, "%c", &znak);
		} while (znak != '\n');
	}

	fscanf(stream, "%d", &punkty);
	fscanf(stream, "%c", &znak); //\n
	Nowy->setIloscPunktow(punkty);
	if (!feof(stream))
	{
		fscanf(stream, "%c", &znak);
		imie = "";
		do
		{
			imie += znak;
			fscanf(stream, "%c", &znak);
		} while (!feof(stream) && znak != '\n');

	}
	Nowy->setImie(imie);
	fclose(stream);
	//w tym miejscu ukonczono pobieraniu z pliku
	//NIE zakladamy ze jest on poprawny, ale wczytywanie sie udalo
	//ewentualne wczytane bledy sa poprawiane na etapie tworzenia pola

	Nowy->pobierzMape(wynik);
	Nowy->stworzGreNaPodstawieMapy();
	Nowy->opcjaZapisu();

	Nowy->rysujMape();
	Nowy->policzPuste();
	if (Nowy->iloscpustych <= 0)
	{
		cout << "Na tej planszy Gra zostala juz zakonczona!" << endl;
		cout << "Nacisnij enter aby kontynuowac...." << endl;
		getline(cin, smieci);

		return true;
	}

	if (Nowy->iloscpustych > (Wielkosc*Wielkosc) - 3)
	{
		Nowy->UmiesclosowaKulke();
		if (Nowy->iloscpustych > (Wielkosc*Wielkosc) - 2)
		{
			Nowy->UmiesclosowaKulke();
			if (Nowy->iloscpustych > (Wielkosc*Wielkosc) - 1)
			{
				Nowy->UmiesclosowaKulke();
			}
		}
	}
	Nowy->zapiszdopliku();
	do
	{
		Nowy->pokazmenu();
		if (Nowy->czyKoniec == 1)
		{
			return true;
		}

		while (Nowy->sprawdzBicie())
		{
			Nowy->rysujMape();
			Nowy->policzPuste();
			Nowy->zapiszdopliku();
			Nowy->pokazmenu();
			if (Nowy->czyKoniec == 1)
			{
				Nowy->rysujMape();
				Nowy->policzPuste();
				Nowy->zapiszdopliku();
				return true;
			}
		}

		if (Nowy->iloscpustych >= 1)
		{
			Nowy->UmiesclosowaKulke();
			if (Nowy->iloscpustych >= 2)
			{
				Nowy->UmiesclosowaKulke();
				if (Nowy->iloscpustych >= 3)
				{
					Nowy->UmiesclosowaKulke();
				}
			}
		}
		Nowy->sprawdzBicie();
		Nowy->rysujMape();
		Nowy->policzPuste();
		Nowy->zapiszdopliku();
		if (Nowy->iloscpustych == 0)
		{
			Nowy->wypisanie();
			//koniec gry
			Nowy->KoniecGry();
		}
	} while (Nowy->iloscpustych > 0);

	zapisdolistywynikow(Nowy->getImie(), Nowy->getPunkty());
	delete Nowy;
	return true;
}

template<typename wybor>
bool menu(wybor w)
{
	if (w == "Nowa Gra")
	{
		nowagra();
		return true;
	}
	else if (w == "Wczytaj Gre")
	{
		wczytajgre();
		return true;
	}
	else if (w == "Lista")
	{
		odczytlisty();
		return true;
	}
	else if (w == "Koniec")
	{
		return false;
	}
	else if (w == "Zasady")
	{

		string smieci;
		system("cls");
		cout << "Zasady:" << endl;
		cout << "Gra polega na ustawianiu kulek (kwadratow) w poziome " << endl << "lub pionowe linie i dkugosci co najmniej 5" << endl;
		cout << "Gracz co ture ma prawo przestawic 1 kulke :" << endl << " jezeli nastapi zbicie gracz moze ponownie wykonac ruch" << endl;
		cout << " jezeli nie nastapi zbicie :" << endl << " na planszy w losowych miejscach pojawiaja sie 3 dodatkowe kulki" << endl << " w kolorach opisanych w prognozie" << endl;
		cout << "Nacisnij enter aby kontynuowac";
		getline(cin, smieci);
		return true;
	}
	else
	{
		string smieci;
		cout << "Wprowadzono niepoprawne dane" << endl;
		cout << "Nacisnij enter aby kontynuowac" << endl;
		getline(cin, smieci);
		cin.sync();
		cin.clear();
		return true;
	}
}


int main()
{
	//kulek nie da sie bezargumentowo
	//kolory 9-15
	bool czyGramy = true;
	string wybor;
	do
	{
		system("cls");
		cout << "Witaj w grze w Kulki" << endl;
		cout << "Wpisz: " << endl;
		cout << "Nowa Gra - aby zaczac nowa gre" << endl;
		cout << "Wczytaj Gre - aby wczytac gre" << endl;
		cout << "Lista - aby zobaczyc liste wynikow" << endl;
		cout << "Zasady - aby poznac reguly gry w kulki" << endl;
		cout << "Koniec - aby wyjsc z aplikacji" << endl;
		getline(cin, wybor);
		czyGramy = menu(wybor);
	} while (czyGramy);


	//nowagra();

	//zostalo:
	//szablony funkcji
	//wczytywanie gry (wystarczy aby liczba znakow sie zgadzala)
	//
	//lista wynikow na zyczenie




	return 0;
}