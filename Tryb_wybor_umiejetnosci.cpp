#include "Tryb_wybor_umiejetnosci.h"

#include "Tryb_umiejetnosc.h"
#include "Tablica_okien.h"
#include "Mapa.h"
#include "Obiekt.h"
#include "Umiejetnosc.h"
#include "Okno_obszar.h"
#include "Okno_napis.h"

Tryb_wybor_umiejetnosci::Tryb_wybor_umiejetnosci ()
{
	//
}

Tryb_wybor_umiejetnosci::~Tryb_wybor_umiejetnosci ()
{
	//
}

void Tryb_wybor_umiejetnosci::stworz_okna ()
{
	okno_mapa = new Okno_obszar ( mapa->obraz_mapy, 0, mapa->dlugosc_mapy, 0, mapa->szerokosc_mapy );

	okno_imie = new Okno_napis ( 0, 12, 20 );
	okno_tytul = new Okno_napis ( 2, 12, 20 );
	okno_wroc = new Okno_napis ( 2, 35, 4 );
	okno_nazwa = new Okno_napis ( 4, 12, 20 );
	okno_koszt = new Okno_napis ( 4, 34, 2 );
	okno_wybierz = new Okno_napis ( 12, 12, 11 );
	okno_lewa_strzalka = new Okno_napis ( 14, 12, 5 );
	okno_nr_umiejetnosci = new Okno_napis ( 14, 18, 5 );
	okno_prawa_strzalka = new Okno_napis ( 14, 24, 5 );
}

void Tryb_wybor_umiejetnosci::zniszcz_okna ()
{
	delete okno_mapa;
	delete okno_imie;
	delete okno_tytul;
	delete okno_wroc;
	delete okno_nazwa;
	delete okno_koszt;
	delete okno_wybierz;
	delete okno_lewa_strzalka;
	delete okno_nr_umiejetnosci;
	delete okno_prawa_strzalka;
}

void Tryb_wybor_umiejetnosci::zacznij ()
{
	tablica_okien->dodaj_okno ( okno_mapa );
	tablica_okien->dodaj_okno ( okno_imie );
	tablica_okien->dodaj_okno ( okno_tytul );
	tablica_okien->dodaj_okno ( okno_wroc );
	tablica_okien->dodaj_okno ( okno_nazwa );
	tablica_okien->dodaj_okno ( okno_koszt );
	tablica_okien->dodaj_okno ( okno_wybierz );
	tablica_okien->dodaj_okno ( okno_lewa_strzalka );
	tablica_okien->dodaj_okno ( okno_nr_umiejetnosci );
	tablica_okien->dodaj_okno ( okno_prawa_strzalka );

	obiekt->umiejetnosci.clear ();

	obiekt->ustal_umiejetnosci ( tablica_umiejetnosci );

	mapa->kursor_y = y_obiekt;
	mapa->kursor_x = x_obiekt;

	mapa->wyczysc_obraz_mapy ();
	mapa->dolacz_obiekty_do_obrazu_mapy ();
	mapa->dolacz_kursor_do_obrazu_mapy ();

	okno_mapa->aktywuj ();

	okno_imie->aktywuj ();
	okno_imie->zmien_napis ( obiekt->imie );
	okno_imie->zmien_kolor ( kolor::czarny, kolor::jasny_rozowy );

	okno_tytul->aktywuj ();

	if ( obiekt->umiejetnosci.size () > 0 )
	{
		okno_tytul->zmien_napis ( "Wybierz umiejetnosc" );
	}
	else
	{
		okno_tytul->zmien_napis ( "Brak umiejetnosci" );
	}

	okno_tytul->zmien_kolor ( kolor::czarny, kolor::ciemny_zielony );

	okno_wroc->aktywuj ();
	okno_wroc->zmien_napis ( "wroc" );
	okno_wroc->zmien_kolor ( kolor::czarny, kolor::bialy );

	okno_nazwa->deaktywuj ();
	okno_nazwa->zmien_kolor ( kolor::czarny, kolor::bialy );

	okno_koszt->deaktywuj ();
	okno_koszt->zmien_kolor ( kolor::czarny, kolor::ciemny_zielony );

	okno_wybierz->deaktywuj ();
	okno_wybierz->zmien_kolor ( kolor::czarny, kolor::ciemny_zielony );
	okno_wybierz->zmien_napis ( "- wybierz -" );

	okno_lewa_strzalka->deaktywuj ();
	okno_lewa_strzalka->zmien_napis ( " <<" );
	okno_lewa_strzalka->zmien_kolor ( kolor::czarny, kolor::bialy );

	okno_nr_umiejetnosci->deaktywuj ();
	okno_nr_umiejetnosci->zmien_kolor ( kolor::czarny, kolor::bialy );

	okno_prawa_strzalka->deaktywuj ();
	okno_prawa_strzalka->zmien_napis ( ">> " );
	okno_prawa_strzalka->zmien_kolor ( kolor::czarny, kolor::bialy );

	if ( obiekt->umiejetnosci.size () > 0 )
	{
		nr_umiejetnosci = 0;

		okno_nazwa->aktywuj ();
		okno_koszt->aktywuj ();

		pokaz_umiejetnosc ();
	}
}

void Tryb_wybor_umiejetnosci::zakoncz ()
{
	tablica_okien->usun_okno ( okno_mapa );
	tablica_okien->usun_okno ( okno_imie );
	tablica_okien->usun_okno ( okno_tytul );
	tablica_okien->usun_okno ( okno_wroc );
	tablica_okien->usun_okno ( okno_nazwa );
	tablica_okien->usun_okno ( okno_koszt );
	tablica_okien->usun_okno ( okno_wybierz );
	tablica_okien->usun_okno ( okno_lewa_strzalka );
	tablica_okien->usun_okno ( okno_nr_umiejetnosci );
	tablica_okien->usun_okno ( okno_prawa_strzalka );
}

void Tryb_wybor_umiejetnosci::petla ()
{
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
		nastepny_tryb = "wybor";
		czy_tryb_ma_trwac = false;
	}

	///// wybierz

	if ( okno_wybierz->myszka_weszla )
	{
		okno_wybierz->zmien_napis ( " -wybierz- " );
	}

	if ( okno_wybierz->myszka_wyszla )
	{
		okno_wybierz->zmien_napis ( "- wybierz -" );
	}

	if ( okno_wybierz->l_klikniety )
	{
		tryb_umiejetnosc->umiejetnosc = obiekt->umiejetnosci[nr_umiejetnosci];
		tryb_umiejetnosc->obiekt = obiekt;

		y_obiekt = mapa->kursor_y;
		x_obiekt = mapa->kursor_x;

		nastepny_tryb = "umiejetnosc";
		czy_tryb_ma_trwac = false;
	}

	///// lewa strzalka

	if ( okno_lewa_strzalka->myszka_weszla )
	{
		okno_lewa_strzalka->zmien_napis ( "<< " );
	}

	if ( okno_lewa_strzalka->myszka_wyszla )
	{
		okno_lewa_strzalka->zmien_napis ( " <<" );
	}

	if ( okno_lewa_strzalka->l_klikniety )
	{
		if ( nr_umiejetnosci > 0 )
		{
			nr_umiejetnosci--;

			pokaz_umiejetnosc ();
		}
	}

	///// prawa strzalka

	if ( okno_prawa_strzalka->myszka_weszla )
	{
		okno_prawa_strzalka->zmien_napis ( " >>" );
	}

	if ( okno_prawa_strzalka->myszka_wyszla )
	{
		okno_prawa_strzalka->zmien_napis ( ">> " );
	}

	if ( okno_prawa_strzalka->l_klikniety )
	{
		if ( nr_umiejetnosci < obiekt->umiejetnosci.size () - 1 )
		{
			nr_umiejetnosci++;

			pokaz_umiejetnosc ();
		}
	}
}

void Tryb_wybor_umiejetnosci::pokaz_umiejetnosc ()
{
	okno_nazwa->zmien_napis ( obiekt->umiejetnosci[nr_umiejetnosci]->nazwa );

	okno_koszt->zmien_napis ( std::to_string ( obiekt->umiejetnosci[nr_umiejetnosci]->koszt ) );

	if ( obiekt->umiejetnosci.size () > 0 )
	{
		okno_wybierz->aktywuj ();
	}
	else
	{
		okno_wybierz->deaktywuj ();
	}

	if ( nr_umiejetnosci > 0 )
	{
		okno_lewa_strzalka->aktywuj ();
	}
	else
	{
		okno_lewa_strzalka->deaktywuj ();
	}

	if ( obiekt->umiejetnosci.size () > 1 )
	{
		okno_nr_umiejetnosci->aktywuj ();
		okno_nr_umiejetnosci->zmien_napis ( std::to_string ( nr_umiejetnosci + 1 ) + " / " + std::to_string ( obiekt->umiejetnosci.size () ) );
	}
	else
	{
		okno_nr_umiejetnosci->deaktywuj ();
	}

	if ( nr_umiejetnosci < obiekt->umiejetnosci.size () - 1 )
	{
		okno_prawa_strzalka->aktywuj ();
	}
	else
	{
		okno_prawa_strzalka->deaktywuj ();
	}

}