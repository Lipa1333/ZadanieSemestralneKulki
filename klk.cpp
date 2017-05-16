#include "klk.h"



Kulka::Kulka() : czyPusta(true), kolorkulki(1)
{
}

Kulka::~Kulka()
{
}

void Kulka::ukryjKulke()
{
	czyPusta = true;
	kolorkulki = 1;
}
bool Kulka::czyUkryta()
{
	return czyPusta;
}
int Kulka::getKolorKulki()
{
	return kolorkulki;
}

void Kulka::pokazKulke(int kolor)
{
	kolorkulki = kolor;
	czyPusta = false;
}