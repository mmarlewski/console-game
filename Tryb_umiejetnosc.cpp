#include "Tryb_umiejetnosc.h"

#include "Tryb_wybor_umiejetnosci.h"
#include "Tablica_okien.h"
#include "Obraz.h"
#include "Czas.h"
#include "Mapa.h"
#include "Pole.h"
#include "Umiejetnosc.h"
#include "Obiekt.h"
#include "Licznik.h"
#include "Okno_obszar.h"
#include "Okno_napis.h"

Tryb_umiejetnosc::Tryb_umiejetnosc ()
{
	//
}

Tryb_umiejetnosc::~Tryb_umiejetnosc ()
{
	//
}

void Tryb_umiejetnosc::stworz_okna ()
{
	licznik_animacji = new Licznik ();
	czas->dodaj_licznik ( licznik_animacji );

	obraz_braku_animacji = new Obraz ( mapa->dlugosc_mapy, mapa->szerokosc_mapy );


	okno_mapa = new Okno_obszar ( mapa->obraz_mapy, 0, mapa->dlugosc_mapy, 0, mapa->szerokosc_mapy );
	okno_animacja = new Okno_obszar ( obraz_braku_animacji, 0, mapa->dlugosc_mapy, 0, mapa->szerokosc_mapy );

	okno_imie = new Okno_napis ( 0, 12, 20 );
	okno_tytul = new Okno_napis ( 2, 12, 20 );
	okno_wroc = new Okno_napis ( 2, 35, 4 );
}

void Tryb_umiejetnosc::zniszcz_okna ()
{
	czas->usun_licznik ( licznik_animacji );
	delete licznik_animacji;

	delete obraz_braku_animacji;


	delete okno_mapa;
	delete okno_animacja;
	delete okno_imie;
	delete okno_tytul;
	delete okno_wroc;
}

void Tryb_umiejetnosc::zacznij ()
{
	tablica_okien->dodaj_okno ( okno_mapa );
	tablica_okien->dodaj_okno ( okno_animacja );
	tablica_okien->dodaj_okno ( okno_imie );
	tablica_okien->dodaj_okno ( okno_tytul );
	tablica_okien->dodaj_okno ( okno_wroc );

	w_trakcie_animacji = false;
	mapa_przesunieto_kursor = false;

	umiejetnosc->mapa = mapa;
	umiejetnosc->obiekt = obiekt;
	umiejetnosc->y_obiekt = tryb_wybor_umiejetnosci->y_obiekt;
	umiejetnosc->x_obiekt = tryb_wybor_umiejetnosci->x_obiekt;

	mapa->wyczysc_oznaczenie_wybor ();
	umiejetnosc->ustal_oznaczenie_wybor ();
	mapa->wyczysc_oznaczenie_efekt ();

	mapa->wyczysc_obraz_mapy ();
	mapa->dolacz_obiekty_do_obrazu_mapy ();
	mapa->dolacz_oznaczenie_wybor_do_obrazu_mapy ();
	mapa->dolacz_kursor_do_obrazu_mapy ();

	okno_mapa->aktywuj ();

	okno_animacja->zmien_obraz ( obraz_braku_animacji );
	okno_animacja->deaktywuj ();

	okno_imie->aktywuj ();
	okno_imie->zmien_napis ( obiekt->imie );

	okno_tytul->aktywuj ();
	okno_tytul->zmien_napis ( "hgfhgfhgh" );

	okno_wroc->aktywuj ();
	okno_wroc->zmien_napis ( "wroc" );
}

void Tryb_umiejetnosc::zakoncz ()
{
	tablica_okien->usun_okno ( okno_mapa );
	tablica_okien->usun_okno ( okno_animacja );
	tablica_okien->usun_okno ( okno_imie );
	tablica_okien->usun_okno ( okno_tytul );
	tablica_okien->usun_okno ( okno_wroc );
}

void Tryb_umiejetnosc::petla ()
{
	if ( w_trakcie_animacji==false )
	{
		if ( okno_mapa->myszka_obecna )
		{
			if ( okno_mapa->kursor_y != mapa->kursor_y || okno_mapa->kursor_x != mapa->kursor_x )
			{
				mapa->kursor_y = okno_mapa->kursor_y;
				mapa->kursor_x = okno_mapa->kursor_x;

				mapa_przesunieto_kursor = true;
			}
		}

		if ( mapa_przesunieto_kursor )
		{
			umiejetnosc->y_cel = mapa->kursor_y;
			umiejetnosc->x_cel = mapa->kursor_x;

			mapa->wyczysc_oznaczenie_efekt ();

			if ( mapa->zwroc_pole_pod_kursorem ()->oznaczenie_wybor )
			{
				umiejetnosc->ustal_oznaczenie_efekt ();
			}

			mapa->wyczysc_obraz_mapy ();
			mapa->dolacz_obiekty_do_obrazu_mapy ();
			mapa->dolacz_oznaczenie_wybor_do_obrazu_mapy ();
			mapa->dolacz_oznaczenie_efekt_do_obrazu_mapy ();
			mapa->dolacz_kursor_do_obrazu_mapy ();
		}

		if ( okno_mapa->l_klikniety )
		{
			if ( mapa->zwroc_pole_pod_kursorem ()->oznaczenie_wybor )
			{
				mapa->wyczysc_obraz_mapy ();
				mapa->dolacz_obiekty_do_obrazu_mapy ();

				umiejetnosc->wykonaj_umiejetnosc ();

				okno_animacja->aktywuj ();

				umiejetnosc->ustal_animacje ();

				licznik_animacji->zacznij_odliczanie ();

				nr_obrazu_animacji = 0;

				okno_animacja->zmien_obraz ( umiejetnosc->obrazy_animacji[nr_obrazu_animacji] );

				w_trakcie_animacji = true;
			}
		}

		if ( okno_wroc->l_klikniety )
		{
			nastepny_tryb = "wybor umiejetnosci";
			czy_tryb_ma_trwac = false;
		}
	}
	else
	{
		licznik_animacji->zmierz_milisekundy ();

		if ( licznik_animacji->zliczone_milisekundy > 500 )
		{
			if ( nr_obrazu_animacji < umiejetnosc->obrazy_animacji.size () - 1 )
			{
				licznik_animacji->ustal_nowy_poczatek ();

				nr_obrazu_animacji++;

				okno_animacja->zmien_obraz ( umiejetnosc->obrazy_animacji[nr_obrazu_animacji] );
			}
			else
			{
				licznik_animacji->zakoncz_odliczanie ();

				umiejetnosc->wyczysc_animacje ();

				okno_animacja->deaktywuj ();

				mapa->kursor_y = tryb_wybor_umiejetnosci->y_obiekt;
				mapa->kursor_x = tryb_wybor_umiejetnosci->x_obiekt;

				nastepny_tryb = "wybor";
				czy_tryb_ma_trwac = false;
			}
		}
	}
}