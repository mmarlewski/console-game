#pragma once

#include <Windows.h>
#include <iostream>

class Konsola;
class Czas;
class Licznik;
class Tablica_okien;
class Tablica_obiektow;
class Tablica_umiejetnosci;
class Mapa;
class Obiekt;
class Przedmiot;
class Tryb;
class Tryb_wybor;
class Tryb_ekwipunek;
class Tryb_ruch;
class Tryb_wybor_umiejetnosci;
class Tryb_umiejetnosc;

class Gra
{
	public:

	Gra ();
	~Gra ();

	void zacznij ();
	void petla ();
	void zmien_tryb ();

	void dodaj_obiekt ( Obiekt* _obiekt, int _y, int _x, int _gracz, std::string _imie );
	void dodaj_przedmiot ( Obiekt* _obiekt, Przedmiot* _przedmiot );

	Konsola* konsola;
	Czas* czas;
	Tablica_okien* tablica_okien;
	Mapa* mapa;
	Tablica_obiektow* tablica_obiektow;
	Tablica_umiejetnosci* tablica_umiejetnosci;

	Tryb* tryb;
	int tura;
	Licznik* licznik_petli;

	Tryb_wybor* tryb_wybor;
	Tryb_ekwipunek* tryb_ekwipunek;
	Tryb_ruch* tryb_ruch;
	Tryb_wybor_umiejetnosci* tryb_wybor_umiejetnosci;
	Tryb_umiejetnosc* tryb_umiejetnosc;
};

