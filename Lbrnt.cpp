#include "Lbrnt.h"
using namespace std;
#define Wielkosc 9

//PONIZSZY KOD INSPIROWANY PRAC¥ MGR JERZEGO WA£ASZKA 
//ZE STRONY : http://eduinf.waw.pl/inf/alg/001_search/0128.php
//25.08.2013

kolejka::kolejka() : glowa(NULL), wsk(NULL)
{
}

kolejka::~kolejka()
{
	while (glowa != NULL)
	{
		pop();
	}
}

void kolejka::naKoniec(int w, int k)
{

	ellist * nowy = new ellist;
	nowy->nast = NULL;
	nowy->w = w;
	nowy->k = k;
	if (wsk != NULL)
	{
		wsk->nast = nowy;
	}
	else
	{
		glowa = nowy;
	}
	wsk = nowy;
}

int kolejka::frontw()
{
	return glowa->w;
}

int kolejka::frontk()
{
	return glowa->k;
}

void kolejka::pop()
{
	if (glowa)
	{
		ellist * p = glowa;
		glowa = glowa->nast;
		if (!glowa) wsk = NULL;
		delete p;
	}

}
bool kolejka::czyniePusta()
{
	if (glowa == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void szukaj(string lab[], int Wk, int Ww, int Sw, int Sk)
{

	kolejka * K = new kolejka();
	int  w, k;  //x,y - wsp. S,

	w = Sw;
	k = Sk;

	K->naKoniec(w, k);
	while (K->czyniePusta())
	{
		w = K->frontw();
		k = K->frontk();
		K->pop();
		if (w == Ww&&k == Wk)
		{
			break;
		}

		if (lab[w - 1][k] == ' ')
		{
			K->naKoniec(w - 1, k);
			lab[w - 1][k] = 'd';
			/*
			cout << "znaleziono d" << endl;

			cout << lab[0].c_str() << endl;
			cout << lab[1].c_str() << endl;
			cout << lab[2].c_str() << endl;
			cout << lab[3].c_str() << endl;
			cout << lab[4].c_str() << endl;
			cout<<lab[5].c_str()<<endl;
			cout<<lab[6].c_str()<<endl;
			cout<<lab[7].c_str()<<endl;
			cout<<lab[8].c_str()<<endl;

			*/

		}

		if (lab[w + 1][k] == ' ')
		{
			lab[w + 1][k] = 'g';
			K->naKoniec(w + 1, k);

			/*
			cout << "znaleziono g" << endl;

			cout << lab[0].c_str() << endl;
			cout << lab[1].c_str() << endl;
			cout << lab[2].c_str() << endl;
			cout << lab[3].c_str() << endl;
			cout << lab[4].c_str() << endl;
			cout<<lab[5].c_str()<<endl;
			cout<<lab[6].c_str()<<endl;
			cout<<lab[7].c_str()<<endl;
			cout<<lab[8].c_str()<<endl;

			*/

		}

		if (lab[w][k - 1] == ' ')
		{
			lab[w][k - 1] = 'p';
			K->naKoniec(w, k - 1);

			/*
			cout << "znaleziono p" << endl;

			cout << lab[0].c_str() << endl;
			cout << lab[1].c_str() << endl;
			cout << lab[2].c_str() << endl;
			cout << lab[3].c_str() << endl;
			cout << lab[4].c_str() << endl;
			cout<<lab[5].c_str()<<endl;
			cout<<lab[6].c_str()<<endl;
			cout<<lab[7].c_str()<<endl;
			cout<<lab[8].c_str()<<endl;

			*/
		}

		if (lab[w][k + 1] == ' ')
		{
			lab[w][k + 1] = 'l';
			K->naKoniec(w, k + 1);
			/*
			cout << "znaleziono l" << endl;
			cout << lab[0].c_str() << endl;
			cout << lab[1].c_str() << endl;
			cout << lab[2].c_str() << endl;
			cout << lab[3].c_str() << endl;
			cout << lab[4].c_str() << endl;
			cout<<lab[5].c_str()<<endl;
			cout<<lab[6].c_str()<<endl;
			cout<<lab[7].c_str()<<endl;
			cout<<lab[8].c_str()<<endl;

			*/
		}

	}

}

bool czyIstenieje(string lab[], int Wk, int Ww, int Sw, int Sk)
{
	lab[Sw][Sk] = 'S';
	szukaj(lab, Wk, Ww, Sw, Sk);
	if (lab[Ww][Wk] == 'l' || lab[Ww][Wk] == 'g' || lab[Ww][Wk] == 'p' || lab[Ww][Wk] == 'd')
	{
		return true;
	}
	else
	{
		return false;
	}
}
