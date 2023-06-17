#include "Gra.h"

#include <iostream>
#include <chrono>
#include <cmath>

#include "Konsola.h"
#include "Czas.h"
#include "Licznik.h"
#include "Tablica_okien.h"
#include "Tablica_obiektow.h"
#include "Tablica_umiejetnosci.h"
#include "Tryb.h"
#include "Tryb_wybor.h"
#include "Tryb_ekwipunek.h"
#include "Tryb_ruch.h"
#include "Tryb_wybor_umiejetnosci.h"
#include "Tryb_umiejetnosc.h"
#include "Klasy.h"
#include "Mapa.h"
#include "Pole.h"
#include "PRZED_Amunicja.h"
#include "PRZED_Bron.h"
#include "PRZED_Zbroja.h"

Gra::Gra ()
{
	licznik_petli = new Licznik ();

	konsola = new Konsola ( 30, 40 );
	czas = new Czas ();
	tablica_okien = new Tablica_okien ( 30, 40 );
	tablica_obiektow = new Tablica_obiektow ();
	tablica_umiejetnosci = new Tablica_umiejetnosci ();
	mapa = new Mapa ( 30, 10 );

	tablica_okien->konsola = konsola;
	konsola->obraz = tablica_okien->wspolny_obraz_okien;
	czas->dodaj_licznik ( licznik_petli );

	tryb_wybor = new Tryb_wybor;
	tryb_ekwipunek = new Tryb_ekwipunek;
	tryb_ruch = new Tryb_ruch;
	tryb_wybor_umiejetnosci = new Tryb_wybor_umiejetnosci;
	tryb_umiejetnosc = new Tryb_umiejetnosc;

	tryb_wybor->tablica_okien = tablica_okien;
	tryb_wybor->mapa = mapa;
	tryb_wybor->tura = &tura;
	tryb_wybor->tryb_ekwipunek = tryb_ekwipunek;
	tryb_wybor->tryb_ruch = tryb_ruch;
	tryb_wybor->tryb_wybor_umiejetnosci = tryb_wybor_umiejetnosci;

	tryb_ekwipunek->tablica_okien = tablica_okien;
	tryb_ekwipunek->mapa = mapa;
	tryb_ekwipunek->tryb_wybor = tryb_wybor;

	tryb_ruch->tablica_okien = tablica_okien;
	tryb_ruch->mapa = mapa;
	tryb_ruch->tryb_wybor = tryb_wybor;

	tryb_wybor_umiejetnosci->tablica_okien = tablica_okien;
	tryb_wybor_umiejetnosci->tablica_umiejetnosci = tablica_umiejetnosci;
	tryb_wybor_umiejetnosci->mapa = mapa;
	tryb_wybor_umiejetnosci->tryb_wybor = tryb_wybor;
	tryb_wybor_umiejetnosci->tryb_umiejetnosc = tryb_umiejetnosc;

	tryb_umiejetnosc->tablica_okien = tablica_okien;
	tryb_umiejetnosc->czas = czas;
	tryb_umiejetnosc->mapa = mapa;
	tryb_umiejetnosc->tryb_wybor_umiejetnosci = tryb_wybor_umiejetnosci;

	tryb_wybor->stworz_okna ();
	tryb_ekwipunek->stworz_okna ();
	tryb_ruch->stworz_okna ();
	tryb_wybor_umiejetnosci->stworz_okna ();
	tryb_umiejetnosc->stworz_okna ();
}

Gra::~Gra ()
{
	czas->usun_licznik ( licznik_petli );
	delete licznik_petli;

	tryb_wybor->zniszcz_okna ();
	tryb_ekwipunek->zniszcz_okna ();
	tryb_ruch->zniszcz_okna ();
	tryb_wybor_umiejetnosci->zniszcz_okna ();
	tryb_umiejetnosc->zniszcz_okna ();

	delete tryb_wybor;
	delete tryb_ekwipunek;
	delete tryb_ruch;
	delete tryb_wybor_umiejetnosci;
	delete tryb_umiejetnosc;

	delete konsola;
	delete czas;
	delete tablica_okien;
	delete tablica_obiektow;
	delete tablica_umiejetnosci;
	delete mapa;
}

void Gra::zacznij ()
{
	dodaj_obiekt ( new Rycerz, 5, 5, 1, "Kamil" );

	dodaj_przedmiot ( mapa->mapa[5][5].obiekt, new Slaby_miecz );
	dodaj_przedmiot ( mapa->mapa[5][5].obiekt, new Mocny_miecz );
	dodaj_przedmiot ( mapa->mapa[5][5].obiekt, new Luskowa_zbroja );
	dodaj_przedmiot ( mapa->mapa[5][5].obiekt, new Plytowa_zbroja );
	dodaj_przedmiot ( mapa->mapa[5][5].obiekt, new Kamienie );


	dodaj_obiekt ( new Wlocznik, 2, 6, 1, "Damian" );

	dodaj_przedmiot ( mapa->mapa[2][6].obiekt, new Slaba_wlocznia );
	dodaj_przedmiot ( mapa->mapa[2][6].obiekt, new Mocna_wlocznia );
	dodaj_przedmiot ( mapa->mapa[2][6].obiekt, new Skorzana_zbroja );
	dodaj_przedmiot ( mapa->mapa[2][6].obiekt, new Luskowa_zbroja );
	dodaj_przedmiot ( mapa->mapa[2][6].obiekt, new Noze_do_rzucania );


	dodaj_obiekt ( new Lucznik, 6, 8, 2, "Sebastian" );

	dodaj_przedmiot ( mapa->mapa[6][8].obiekt, new Luk );
	dodaj_przedmiot ( mapa->mapa[6][8].obiekt, new Kusza );
	dodaj_przedmiot ( mapa->mapa[6][8].obiekt, new Proca );
	dodaj_przedmiot ( mapa->mapa[6][8].obiekt, new Slabe_strzaly );
	dodaj_przedmiot ( mapa->mapa[6][8].obiekt, new Mocne_strzaly );
	dodaj_przedmiot ( mapa->mapa[6][8].obiekt, new Male_kamienie );
	dodaj_przedmiot ( mapa->mapa[6][8].obiekt, new Lachmany );

	dodaj_obiekt ( new Skrzynka, 3, 3, 0, "skrzynka" );

	dodaj_przedmiot ( mapa->mapa[3][3].obiekt, new Granat );

	tura = 1;
	
	tryb = tryb_wybor;

	mapa->przesun_kursor_na_srodek ();

	tryb->czy_tryb_ma_trwac = true;

	tryb->zacznij ();

	konsola->zmien_tytul_konsoli ( "tak jak Pan Jezus powiedzial" );

	konsola->myszka_y = ( konsola->dlugosc_konsoli / 2 );
	konsola->myszka_x = ( konsola->szerokosc_konsoli / 2 );

	licznik_petli->zacznij_odliczanie ();

	while ( !konsola->zwroc_czy_esc () )
	{
		licznik_petli->zmierz_milisekundy ();

		if ( licznik_petli->zliczone_milisekundy > 10 )
		{
			licznik_petli->ustal_nowy_poczatek ();

			petla ();
		}
	}

	tryb->zakoncz ();
}

void Gra::petla ()
{
	konsola->pobierz_dane_myszki ();

	tablica_okien->zaktualizuj_okna ();

	tryb->petla ();

	if ( !tryb->czy_tryb_ma_trwac )
	{
		zmien_tryb ();
	}

	tablica_okien->ustal_wspolny_obraz ();

	konsola->zaktualizuj_konsole ();
}

void Gra::zmien_tryb ()
{
	std::string nastepny_tryb = tryb->nastepny_tryb;

	tryb->zakoncz ();

	if ( nastepny_tryb == "wybor" )
	{
		tryb=tryb_wybor;
	}
	else if ( nastepny_tryb == "ekwipunek" )
	{
		tryb=tryb_ekwipunek;
	}
	else if ( nastepny_tryb == "ruch" )
	{
		tryb = tryb_ruch;
	}
	else if ( nastepny_tryb == "wybor umiejetnosci" )
	{
		tryb = tryb_wybor_umiejetnosci;
	}
	else if ( nastepny_tryb == "umiejetnosc" )
	{
		tryb = tryb_umiejetnosc;
	}

	tryb->czy_tryb_ma_trwac = true;

	tryb->zacznij ();
}

void Gra::dodaj_obiekt ( Obiekt* _obiekt, int _y, int _x, int _gracz, std::string _imie )
{
	mapa->mapa[_y][_x].obiekt = _obiekt;

	_obiekt->pozycja_y = _y;
	_obiekt->pozycja_x = _x;

	_obiekt->gracz = _gracz;

	if ( _imie == "" )
	{
		_obiekt->imie = _obiekt->klasa;
	}
	else
	{
		_obiekt->imie = _imie;
	}

	tablica_obiektow->dodaj_obiekt ( _obiekt );

	_obiekt->hp_teraz = _obiekt->hp_max;
	_obiekt->ap_teraz = _obiekt->ap_max;
}

void Gra::dodaj_przedmiot ( Obiekt* _obiekt, Przedmiot* _przedmiot )
{
	_obiekt->ekwipunek.push_back ( _przedmiot );
}