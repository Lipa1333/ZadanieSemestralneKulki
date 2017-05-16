#pragma once
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
class Kulka
{
public:
	~Kulka(); 
	Kulka();
	void ukryjKulke();  //usuwa (tak naprawde ukrywa)
	bool czyUkryta(); //zwraca wartosc pola czyPusta
	void pokazKulke(int kolor); //tworzy (pokazuje) kulke na danej pozycji
	int getKolorKulki();  
private:
	int kolorkulki;
	bool czyPusta;

};



