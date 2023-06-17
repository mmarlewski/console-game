#include "Tryb_ruch.h"

#include "Tryb_wybor.h"
#include "Tablica_okien.h"
#include "Mapa.h"
#include "Pole.h"
#include "Obiekt.h"
#include "Okno_obszar.h"
#include "Okno_napis.h"

Tryb_ruch::Tryb_ruch ()
{
	//
}

Tryb_ruch::~Tryb_ruch ()
{
	//
}

void Tryb_ruch::stworz_okna ()
{
	okno_mapa = new Okno_obszar ( mapa->obraz_mapy, 0, mapa->dlugosc_mapy, 0, mapa->szerokosc_mapy );

	okno_imie = new Okno_napis ( 0, 12, 20 );
	okno_tytul = new Okno_napis ( 2, 12, 20 );
	okno_wroc = new Okno_napis ( 2, 35, 4 );
	okno_odleglosc = new Okno_napis ( 4, 12, 10 );
	okno_liczba = new Okno_napis ( 4, 25, 2 );
}

void Tryb_ruch::zniszcz_okna ()
{
	delete okno_mapa;
	delete okno_imie;
	delete okno_tytul;
	delete okno_wroc;
	delete okno_odleglosc;
	delete okno_liczba;
}

void Tryb_ruch::zacznij ()
{
	tablica_okien->dodaj_okno ( okno_mapa );
	tablica_okien->dodaj_okno ( okno_imie );
	tablica_okien->dodaj_okno ( okno_tytul );
	tablica_okien->dodaj_okno ( okno_wroc );
	tablica_okien->dodaj_okno ( okno_odleglosc );
	tablica_okien->dodaj_okno ( okno_liczba );

	mapa->ustal_odleglosci ( mapa->kursor_y, mapa->kursor_x );

	okno_mapa->aktywuj ();

	okno_imie->aktywuj ();
	okno_imie->zmien_napis ( obiekt->imie );
	okno_imie->zmien_kolor ( kolor::czarny, kolor::jasny_rozowy );

	okno_tytul->aktywuj ();
	okno_tytul->zmien_napis ( "Przemieszcz postac" );
	okno_tytul->zmien_kolor ( kolor::czarny, kolor::ciemny_morski );

	okno_wroc->aktywuj ();
	okno_wroc->zmien_napis ( "wroc" );
	okno_wroc->zmien_kolor ( kolor::czarny, kolor::bialy );

	okno_odleglosc->aktywuj ();
	okno_odleglosc->zmien_napis ( "Odleglosc:" );
	okno_odleglosc->zmien_kolor ( kolor::czarny, kolor::bialy );

	okno_liczba->deaktywuj ();
}

void Tryb_ruch::zakoncz ()
{
	tablica_okien->usun_okno ( okno_mapa );
	tablica_okien->usun_okno ( okno_imie );
	tablica_okien->usun_okno ( okno_tytul );
	tablica_okien->usun_okno ( okno_wroc );
	tablica_okien->usun_okno ( okno_odleglosc );
	tablica_okien->usun_okno ( okno_liczba );
}

void Tryb_ruch::petla ()
{
	///// mapa

	if ( okno_mapa->myszka_obecna )
	{
		if ( !( mapa->kursor_y == okno_mapa->kursor_y && mapa->kursor_x == okno_mapa->kursor_x ) )
		{
			mapa->kursor_y = okno_mapa->kursor_y;
			mapa->kursor_x = okno_mapa->kursor_x;

			mapa_przesunieto_kursor = true;
		}
	}

	if ( okno_mapa->l_klikniety )
	{
		if ( mapa->zwroc_pole_pod_kursorem ()->obiekt == nullptr && mapa->zwroc_pole_pod_kursorem ()->odleglosc <= obiekt->ap_teraz )
		{
			mapa->mapa[tryb_wybor->y_obiekt][tryb_wybor->x_obiekt].obiekt = nullptr;
			mapa->zwroc_pole_pod_kursorem ()->obiekt = obiekt;

			obiekt->ap_teraz -= mapa->zwroc_pole_pod_kursorem ()->odleglosc;

			tryb_wybor->mapa_kursor_stop = true;

			nastepny_tryb = "wybor";
			czy_tryb_ma_trwac = false;
		}
	}

	mapa->wyczysc_obraz_mapy ();
	mapa->dolacz_obiekty_do_obrazu_mapy ();
	mapa->dolacz_kursor_do_obrazu_mapy ();

	///// wroc

	if ( okno_wroc->myszka_weszla )
	{
		okno_wroc->zmien_kolor ( kolor::czarny, kolor::jasny_czerwony );
	}

	if ( okno_wroc->myszka_wyszla )
	{
		okno_wroc->zmien_kolor ( kolor::czarny, kolor::bialy );
	}
	
	if ( okno_wroc->l_klikniety )
	{
		mapa->kursor_y = tryb_wybor->y_obiekt;
		mapa->kursor_x = tryb_wybor->x_obiekt;

		nastepny_tryb = "wybor";
		czy_tryb_ma_trwac = false;
	}

	///// liczba

	if ( okno_mapa->myszka_obecna && mapa_przesunieto_kursor )
	{
		if ( mapa->zwroc_pole_pod_kursorem ()->obiekt == nullptr && mapa->zwroc_pole_pod_kursorem ()->odleglosc != 100 )
		{
			okno_liczba->aktywuj ();
			okno_liczba->zmien_napis ( std::to_string ( mapa->zwroc_pole_pod_kursorem ()->odleglosc ) );

			if ( mapa->zwroc_pole_pod_kursorem ()->odleglosc > obiekt->ap_teraz )
			{
				okno_liczba->zmien_kolor ( kolor::czarny, kolor::ciemny_czerwony );
			}
			else
			{
				okno_liczba->zmien_kolor ( kolor::czarny, kolor::ciemny_zielony );
			}
		}
		else
		{
			okno_liczba->deaktywuj ();
		}
	}
}