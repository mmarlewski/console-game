#include "Tryb_wybor.h"

#include "Tryb_ekwipunek.h"
#include "Tryb_ruch.h"
#include "Tryb_wybor_umiejetnosci.h"
#include "Tablica_okien.h"
#include "Mapa.h"
#include "Pole.h"
#include "Obiekt.h"
#include "PRZED_Bron.h"
#include "PRZED_Amunicja.h"
#include "PRZED_Zbroja.h"
#include "Okno_obszar.h"
#include "Okno_napis.h"
#include "Obraz.h"
#include "Znak.h"

Tryb_wybor::Tryb_wybor ()
{
	//
}

Tryb_wybor::~Tryb_wybor ()
{
	//
}

void Tryb_wybor::stworz_okna ()
{
	okno_mapa = new Okno_obszar ( mapa->obraz_mapy, 0, mapa->dlugosc_mapy, 0, mapa->szerokosc_mapy );

	okno_imie = new Okno_napis ( 0, 12, 20 );
	okno_klasa = new Okno_napis ( 2, 12, 15 );
	okno_gracz = new Okno_napis ( 2, 30, 7 );
	okno_hp = new Okno_napis ( 4, 12, 7 );
	okno_hp_pasek = new Okno_napis ( 5, 12, 25 );
	okno_ap = new Okno_napis ( 7, 12, 7 );
	okno_ap_pasek = new Okno_napis ( 8, 12, 25 );
	okno_bron_nazwa = new Okno_napis ( 10, 12, 20 );
	okno_bron_pojemnosc = new Okno_napis ( 10, 30, 7 );
	okno_bron_pasek = new Okno_napis ( 11, 12, 25 );
	okno_amunicja_nazwa = new Okno_napis ( 12, 12, 20 );
	okno_amunicja_pojemnosc = new Okno_napis ( 12, 30, 7 );
	okno_zaladuj = new Okno_napis ( 13, 12, 11 );
	okno_rozladuj = new Okno_napis ( 13, 25, 12 );
	okno_zbroja_nazwa = new Okno_napis ( 15, 12, 20 );
	okno_umiejetnosci = new Okno_napis ( 18, 12, 20 );
	okno_ruch = new Okno_napis ( 19, 12, 20 );
	okno_tura = new Okno_napis ( 26, 12, 20 );
	okno_zakoncz_ture = new Okno_napis ( 27, 12, 20 );
}

void Tryb_wybor::zniszcz_okna ()
{
	delete okno_mapa;
	delete okno_imie;
	delete okno_klasa;
	delete okno_gracz;
	delete okno_hp;
	delete okno_hp_pasek;
	delete okno_ap;
	delete okno_ap_pasek;
	delete okno_bron_nazwa;
	delete okno_bron_pojemnosc;
	delete okno_bron_pasek;
	delete okno_amunicja_nazwa;
	delete okno_amunicja_pojemnosc;
	delete okno_zaladuj;
	delete okno_rozladuj;
	delete okno_zbroja_nazwa;
	delete okno_umiejetnosci;
	delete okno_ruch;
	delete okno_tura;
	delete okno_zakoncz_ture;
}

void Tryb_wybor::zacznij ()
{
	tablica_okien->dodaj_okno ( okno_mapa );
	tablica_okien->dodaj_okno ( okno_imie );
	tablica_okien->dodaj_okno ( okno_klasa );
	tablica_okien->dodaj_okno ( okno_gracz );
	tablica_okien->dodaj_okno ( okno_hp );
	tablica_okien->dodaj_okno ( okno_hp_pasek );
	tablica_okien->dodaj_okno ( okno_ap );
	tablica_okien->dodaj_okno ( okno_ap_pasek );
	tablica_okien->dodaj_okno ( okno_bron_nazwa );
	tablica_okien->dodaj_okno ( okno_bron_pojemnosc );
	tablica_okien->dodaj_okno ( okno_bron_pasek );
	tablica_okien->dodaj_okno ( okno_amunicja_nazwa );
	tablica_okien->dodaj_okno ( okno_amunicja_pojemnosc );
	tablica_okien->dodaj_okno ( okno_zaladuj );
	tablica_okien->dodaj_okno ( okno_rozladuj );
	tablica_okien->dodaj_okno ( okno_zbroja_nazwa );
	tablica_okien->dodaj_okno ( okno_umiejetnosci );
	tablica_okien->dodaj_okno ( okno_ruch );
	tablica_okien->dodaj_okno ( okno_tura );
	tablica_okien->dodaj_okno ( okno_zakoncz_ture );

	obiekt = mapa->zwroc_pole_pod_kursorem ()->obiekt;

	okno_mapa->aktywuj ();

	okno_imie->aktywuj ();
	okno_imie->zmien_napis ( "* wybierz postac *" );
	okno_imie->zmien_kolor ( kolor::czarny, kolor::jasny_rozowy );

	okno_tura->aktywuj ();
	okno_tura->zmien_napis ( "# tura gracza " + std::to_string ( *tura ) + " #" );

	if ( *tura == 1 )
	{
		okno_tura->zmien_kolor ( kolor::czarny, kolor::ciemny_zielony );
	}
	else if ( *tura == 2 )
	{
		okno_tura->zmien_kolor ( kolor::czarny, kolor::ciemny_morski );
	}

	okno_zakoncz_ture->aktywuj ();
	okno_zakoncz_ture->zmien_napis ( "- zakoncz ture -" );
	okno_zakoncz_ture->zmien_kolor ( kolor::czarny, kolor::bialy );

	pokaz_info_obiektu ();

}

void Tryb_wybor::zakoncz ()
{
	tablica_okien->usun_okno ( okno_mapa );
	tablica_okien->usun_okno ( okno_imie );
	tablica_okien->usun_okno ( okno_klasa );
	tablica_okien->usun_okno ( okno_gracz );
	tablica_okien->usun_okno ( okno_hp );
	tablica_okien->usun_okno ( okno_hp_pasek );
	tablica_okien->usun_okno ( okno_ap );
	tablica_okien->usun_okno ( okno_ap_pasek );
	tablica_okien->usun_okno ( okno_bron_nazwa );
	tablica_okien->usun_okno ( okno_bron_pojemnosc );
	tablica_okien->usun_okno ( okno_bron_pasek );
	tablica_okien->usun_okno ( okno_amunicja_nazwa );
	tablica_okien->usun_okno ( okno_amunicja_pojemnosc );
	tablica_okien->usun_okno ( okno_zaladuj );
	tablica_okien->usun_okno ( okno_rozladuj );
	tablica_okien->usun_okno ( okno_zbroja_nazwa );
	tablica_okien->usun_okno ( okno_umiejetnosci );
	tablica_okien->usun_okno ( okno_ruch );
	tablica_okien->usun_okno ( okno_tura );
	tablica_okien->usun_okno ( okno_zakoncz_ture );
}

void Tryb_wybor::petla ()
{
	///// mapa

	if ( mapa_przesunieto_kursor )
	{
		mapa_przesunieto_kursor = false;
	}

	if ( okno_mapa->myszka_obecna )
	{
		if ( !mapa_kursor_stop )
		{
			if ( !( mapa->kursor_y == okno_mapa->kursor_y && mapa->kursor_x == okno_mapa->kursor_x ) )
			{
				mapa->kursor_y = okno_mapa->kursor_y;
				mapa->kursor_x = okno_mapa->kursor_x;

				mapa_przesunieto_kursor = true;
			}
		}
	}

	if ( okno_mapa->l_klikniety )
	{
		if ( mapa_kursor_stop )
		{
			mapa->kursor_y = okno_mapa->kursor_y;
			mapa->kursor_x = okno_mapa->kursor_x;

			mapa_przesunieto_kursor = true;
		}
		else
		{
			mapa_kursor_stop = 1;
		}
	}

	if ( okno_mapa->p_klikniety )
	{
		if ( mapa_kursor_stop )
		{
			mapa_kursor_stop = 0;
		}
	}

	mapa->wyczysc_obraz_mapy ();
	mapa->dolacz_obiekty_do_obrazu_mapy ();
	mapa->dolacz_kursor_do_obrazu_mapy ();

	if ( mapa_przesunieto_kursor )
	{
		pokaz_info_obiektu ();
	}

	///// zakoncz ture

	if ( okno_zakoncz_ture->myszka_weszla )
	{
		okno_zakoncz_ture->zmien_napis ( " -zakoncz ture- " );
	}

	if ( okno_zakoncz_ture->myszka_wyszla )
	{
		okno_zakoncz_ture->zmien_napis ( "- zakoncz ture -" );
	}

	if ( okno_zakoncz_ture->l_klikniety )
	{
		if ( *tura == 1 )
		{
			*tura = 2;

			okno_tura->zmien_kolor ( kolor::czarny, kolor::ciemny_morski );
		}
		else if( *tura == 2 )
		{
			*tura = 1;

			okno_tura->zmien_kolor ( kolor::czarny, kolor::ciemny_zielony );
		}

		mapa->przesun_kursor_na_srodek ();
		mapa_kursor_stop = false;
		pokaz_info_obiektu ();

		okno_tura->zmien_napis ( "# tura gracza " + std::to_string ( *tura ) + " #" );
	}

	if ( obiekt != nullptr && obiekt->gracz==*tura )
	{
		///// bron

		if ( okno_bron_nazwa->myszka_weszla )
		{
			okno_bron_nazwa->zmien_napis ( "- wybierz -" );
			okno_bron_nazwa->zmien_kolor ( kolor::czarny, kolor::jasny_czerwony );
		}

		if ( okno_bron_nazwa->myszka_wyszla )
		{
			if ( obiekt->bron == nullptr )
			{
				okno_bron_nazwa->zmien_napis ( "-brak broni-" );
			}
			else
			{
				okno_bron_nazwa->zmien_napis ( obiekt->bron->klasa );
			}

			okno_bron_nazwa->zmien_kolor ( kolor::czarny, kolor::ciemny_czerwony );
		}

		if ( okno_bron_nazwa->l_klikniety )
		{
			tryb_ekwipunek->obiekt = obiekt;
			tryb_ekwipunek->rodzaj_przedmiotow = "bron";

			nastepny_tryb = "ekwipunek";
			czy_tryb_ma_trwac = false;
		}

		///// amunicja

		if ( okno_amunicja_nazwa->myszka_weszla )
		{
			okno_amunicja_nazwa->zmien_napis ( "- wybierz -" );
			okno_amunicja_nazwa->zmien_kolor ( kolor::czarny, kolor::jasny_zolty );
		}

		if ( okno_amunicja_nazwa->myszka_wyszla )
		{
			if ( obiekt->amunicja == nullptr )
			{
				okno_amunicja_nazwa->zmien_napis ( "-brak amunicji-" );
			}
			else
			{
				okno_amunicja_nazwa->zmien_napis ( obiekt->amunicja->klasa );
			}

			okno_amunicja_nazwa->zmien_kolor ( kolor::czarny, kolor::ciemny_zolty );
		}

		if ( okno_amunicja_nazwa->l_klikniety && obiekt->bron_dystansowa != nullptr )
		{
			tryb_ekwipunek->obiekt = obiekt;
			tryb_ekwipunek->rodzaj_przedmiotow = "amunicja";

			nastepny_tryb = "ekwipunek";
			czy_tryb_ma_trwac = false;
		}

		///// zbroja

		if ( okno_zbroja_nazwa->myszka_weszla )
		{
			okno_zbroja_nazwa->zmien_napis ( "- wybierz -" );
			okno_zbroja_nazwa->zmien_kolor ( kolor::czarny, kolor::jasny_niebieski );
		}

		if ( okno_zbroja_nazwa->myszka_wyszla )
		{
			if ( obiekt->zbroja == nullptr )
			{
				okno_zbroja_nazwa->zmien_napis ( "-brak zbroji-" );
			}
			else
			{
				okno_zbroja_nazwa->zmien_napis ( obiekt->zbroja->klasa );
			}

			okno_zbroja_nazwa->zmien_kolor ( kolor::czarny, kolor::ciemny_niebieski );
		}

		if ( okno_zbroja_nazwa->l_klikniety )
		{
			tryb_ekwipunek->obiekt = obiekt;
			tryb_ekwipunek->rodzaj_przedmiotow = "zbroja";

			nastepny_tryb = "ekwipunek";
			czy_tryb_ma_trwac = false;
		}

		///// zaladuj

		if ( okno_zaladuj->myszka_weszla )
		{
			okno_zaladuj->zmien_napis ( "- zaladuj -" );
		}

		if ( okno_zaladuj->myszka_wyszla )
		{
			okno_zaladuj->zmien_napis ( " -zaladuj- " );
		}

		if ( okno_zaladuj->l_klikniety )
		{
			if ( obiekt != nullptr && obiekt->bron_dystansowa != nullptr && obiekt->amunicja != nullptr &&
				 obiekt->bron_dystansowa->zawartosc < obiekt->bron_dystansowa->pojemnosc && obiekt->amunicja->zawartosc > 0 )
			{
				obiekt->bron_dystansowa->zawartosc++;
				obiekt->amunicja->zawartosc--;

				//zwroc_okno ( "bron pojemnosc" )->
					//zmien_obraz ( std::to_string ( obiekt->bron_dystansowa->zawartosc ) + " / " + std::to_string ( obiekt->bron_dystansowa->pojemnosc ) );
				okno_amunicja_pojemnosc->zmien_napis ( std::to_string ( obiekt->amunicja->zawartosc ) );
				stworz_pasek_broni ();
			}
		}

		///// rozladuj

		if ( okno_rozladuj->myszka_weszla )
		{
			okno_rozladuj->zmien_napis ( "- rozladuj -" );
		}

		if ( okno_rozladuj->myszka_wyszla )
		{
			okno_rozladuj->zmien_napis ( " -rozladuj- " );
		}

		if ( okno_rozladuj->l_klikniety )
		{
			if ( obiekt != nullptr && obiekt->bron_dystansowa != nullptr && obiekt->amunicja != nullptr &&
				 obiekt->bron_dystansowa->zawartosc > 0 )
			{
				obiekt->amunicja->zawartosc += obiekt->bron_dystansowa->zawartosc;
				obiekt->bron_dystansowa->zawartosc = 0;

				//zwroc_okno ( "bron pojemnosc" )->
					//zmien_obraz ( std::to_string ( obiekt->bron_dystansowa->zawartosc ) + " / " + std::to_string ( obiekt->bron_dystansowa->pojemnosc ) );
				okno_amunicja_pojemnosc->zmien_napis ( std::to_string ( obiekt->amunicja->zawartosc ) );

				stworz_pasek_broni ();
			}
		}

		///// umiejetnosci

		if ( okno_umiejetnosci->myszka_weszla )
		{
			okno_umiejetnosci->zmien_napis ( "- umiejetnosci -" );
		}

		if ( okno_umiejetnosci->myszka_wyszla )
		{
			okno_umiejetnosci->zmien_napis ( " -umiejetnosci- " );
		}

		if ( okno_umiejetnosci->l_klikniety )
		{
			if ( obiekt != nullptr )
			{
				if ( obiekt->czy_umiej )
				{
					mapa_kursor_stop = true;

					tryb_wybor_umiejetnosci->obiekt = obiekt;
					tryb_wybor_umiejetnosci->y_obiekt = mapa->kursor_y;
					tryb_wybor_umiejetnosci->x_obiekt = mapa->kursor_x;

					nastepny_tryb = "wybor umiejetnosci";
					czy_tryb_ma_trwac = false;
				}
			}
		}
	
		///// ruch

		if ( okno_ruch->myszka_weszla )
		{
			okno_ruch->zmien_napis ( "- ruch -" );
		}

		if ( okno_ruch->myszka_wyszla )
		{
			okno_ruch->zmien_napis ( " -ruch- " );
		}

		if ( okno_ruch->l_klikniety )
		{
			y_obiekt = mapa->kursor_y;
			x_obiekt = mapa->kursor_x;

			mapa_kursor_stop = false;

			tryb_ruch->obiekt = obiekt;

			nastepny_tryb = "ruch";
			czy_tryb_ma_trwac = false;
		}
	}
}

void Tryb_wybor::pokaz_info_obiektu ()
{
	okno_klasa->deaktywuj ();
	okno_gracz->deaktywuj ();
	okno_hp->deaktywuj ();
	okno_hp_pasek->deaktywuj ();
	okno_ap->deaktywuj ();
	okno_ap_pasek->deaktywuj ();
	okno_bron_nazwa->deaktywuj ();
	okno_bron_pojemnosc->deaktywuj ();
	okno_bron_pasek->deaktywuj ();
	okno_amunicja_nazwa->deaktywuj ();
	okno_amunicja_pojemnosc->deaktywuj ();
	okno_zaladuj->deaktywuj ();
	okno_rozladuj->deaktywuj ();
	okno_zbroja_nazwa->deaktywuj ();
	okno_umiejetnosci->deaktywuj ();
	okno_ruch->deaktywuj ();

	obiekt = mapa->zwroc_pole_pod_kursorem ()->obiekt;

	if ( obiekt != nullptr )
	{
		///// imie

		okno_imie->zmien_napis ( obiekt->imie );
		okno_imie->zmien_kolor ( kolor::czarny, kolor::jasny_rozowy );

		///// klasa

		okno_klasa->aktywuj ();
		okno_klasa->zmien_napis ( obiekt->klasa );
		okno_klasa->zmien_kolor ( kolor::czarny, kolor::bialy );

		///// gracz

		okno_gracz->aktywuj ();

		if ( obiekt->gracz == 1 )
		{
			okno_gracz->zmien_napis ( "gracz 1" );
			okno_gracz->zmien_kolor ( kolor::czarny, kolor::ciemny_zielony );
		}
		else if ( obiekt->gracz == 2 )
		{
			okno_gracz->zmien_napis ( "gracz 2" );
			okno_gracz->zmien_kolor ( kolor::czarny, kolor::ciemny_morski );
		}
		else
		{
			okno_gracz->zmien_napis ( "-------" );
			okno_gracz->zmien_kolor ( kolor::czarny, kolor::ciemny_szary );
		}

		///// hp

		okno_hp->aktywuj ();
		okno_hp->zmien_kolor ( kolor::czarny, kolor::ciemny_czerwony );

		if ( obiekt->czy_hp )
		{
			okno_hp->zmien_napis ( std::to_string ( obiekt->hp_teraz ) + " / " + std::to_string ( obiekt->hp_max ) );

			okno_hp_pasek->aktywuj ();
			stworz_pasek_hp ();
		}
		else
		{
			okno_hp->zmien_napis ( "-----" );
		}

		///// ap

		if ( obiekt->gracz == *tura )
		{
			okno_ap->aktywuj ();
			okno_ap->zmien_kolor ( kolor::czarny, kolor::ciemny_zielony );

			if ( obiekt->czy_ap )
			{
				okno_ap->zmien_napis ( std::to_string ( obiekt->ap_teraz ) + " / " + std::to_string ( obiekt->ap_max ) );

				okno_ap_pasek->aktywuj ();
				stworz_pasek_ap ();
			}
			else
			{
				okno_ap->zmien_napis ( "-----" );
			}
		}

		///// bron

		okno_bron_nazwa->aktywuj ();
		okno_bron_nazwa->zmien_kolor ( kolor::czarny, kolor::ciemny_czerwony );

		if ( obiekt->bron != nullptr )
		{
			okno_bron_nazwa->zmien_napis ( obiekt->bron->klasa );

			if ( obiekt->bron->rodzaj_broni == "biala" )
			{
				//
			}

			if ( obiekt->bron->rodzaj_broni == "dystansowa" )
			{
				//zwroc_okno ( "bron pojemnosc" )->aktywuj ();
				//zwroc_okno ( "bron pojemnosc" )->
					//zmien_obraz ( std::to_string ( obiekt->bron_dystansowa->zawartosc ) + " / " + std::to_string ( obiekt->bron_dystansowa->pojemnosc ) );

				if ( obiekt->gracz == *tura )
				{
					okno_bron_pasek->aktywuj ();
					stworz_pasek_broni ();

					okno_amunicja_nazwa->aktywuj ();

					if ( obiekt->amunicja != nullptr )
					{
						okno_amunicja_nazwa->zmien_napis ( obiekt->amunicja->klasa );

						okno_amunicja_pojemnosc->aktywuj ();
						okno_amunicja_pojemnosc->zmien_napis ( std::to_string ( obiekt->amunicja->zawartosc ) );

						okno_zaladuj->aktywuj ();
						okno_zaladuj->zmien_napis ( "- zaladuj -" );

						okno_rozladuj->aktywuj ();
						okno_rozladuj->zmien_napis ( "- rozladuj -" );
					}
					else
					{
						okno_amunicja_nazwa->zmien_napis ( "-brak amunicji-" );
					}
				}
			}

			if ( obiekt->bron->rodzaj_broni == "miotana" )
			{
				if ( obiekt->gracz == *tura )
				{
					okno_bron_pojemnosc->aktywuj ();
					okno_bron_pojemnosc->zmien_napis ( std::to_string ( obiekt->bron_miotana->zawartosc ) );
				}
			}
		}
		else
		{
			okno_bron_nazwa->zmien_napis ( "-brak broni-" );
		}

		okno_zbroja_nazwa->aktywuj ();
		okno_zbroja_nazwa->zmien_kolor ( kolor::czarny, kolor::ciemny_niebieski );

		if ( obiekt->zbroja != nullptr )
		{
			okno_zbroja_nazwa->zmien_napis ( obiekt->zbroja->klasa );
		}
		else
		{
			okno_zbroja_nazwa->zmien_napis ( "-brak zbroji-" );
		}

		if ( obiekt->czy_umiej && obiekt->gracz == *tura  )
		{
			okno_umiejetnosci->aktywuj ();
			okno_umiejetnosci->zmien_napis ( " -umiejetnosci- " );
		}

		if ( obiekt->gracz == *tura )
		{
			okno_ruch->aktywuj ();
			okno_ruch->zmien_napis ( " -ruch- " );
		}
	}
	else
	{
		///// imie

		okno_imie->zmien_napis ( "* wybierz postac *" );
		okno_imie->zmien_kolor ( kolor::czarny, kolor::jasny_rozowy );
	}
}

void Tryb_wybor::stworz_pasek_hp ()
{
	int czesc_paska = ( okno_hp_pasek->szerokosc ) * ( double ( obiekt->hp_teraz ) / double ( obiekt->hp_max ) );

	int szerokosc_paska = okno_hp_pasek->szerokosc;

	for ( int i = 0; i < czesc_paska && i < szerokosc_paska; i++ )
	{
		okno_hp_pasek->obraz->obraz[0][i].znak = L':';
		okno_hp_pasek->obraz->obraz[0][i].kolor_przod = kolor::jasny_czerwony;
		okno_hp_pasek->obraz->obraz[0][i].kolor_tyl = kolor::czarny;
	}

	for ( int i = czesc_paska; i < szerokosc_paska; i++ )
	{
		okno_hp_pasek->obraz->obraz[0][i].znak = L':';
		okno_hp_pasek->obraz->obraz[0][i].kolor_przod = kolor::bialy;
		okno_hp_pasek->obraz->obraz[0][i].kolor_tyl = kolor::czarny;
	}
}

void Tryb_wybor::stworz_pasek_ap ()
{
	int czesc_paska = ( okno_ap_pasek->szerokosc ) * ( double ( obiekt->ap_teraz ) / double ( obiekt->ap_max ) );

	int szerokosc_paska = okno_ap_pasek->szerokosc;

	for ( int i = 0; i < czesc_paska && i < szerokosc_paska; i++ )
	{
		okno_ap_pasek->obraz->obraz[0][i].znak = L':';
		okno_ap_pasek->obraz->obraz[0][i].kolor_przod = kolor::jasny_zielony;
		okno_ap_pasek->obraz->obraz[0][i].kolor_tyl = kolor::czarny;
	}

	for ( int i = czesc_paska; i < szerokosc_paska; i++ )
	{
		okno_ap_pasek->obraz->obraz[0][i].znak = L':';
		okno_ap_pasek->obraz->obraz[0][i].kolor_przod = kolor::bialy;
		okno_ap_pasek->obraz->obraz[0][i].kolor_tyl = kolor::czarny;
	}
}

void Tryb_wybor::stworz_pasek_broni ()
{
	int zawartosc = obiekt->bron_dystansowa->zawartosc;

	int pojemnosc = obiekt->bron_dystansowa->pojemnosc;

	int szerokosc_paska = okno_bron_pasek->szerokosc;

	for ( int i = 0; i < zawartosc && i < szerokosc_paska; i++ )
	{
		okno_bron_pasek->obraz->obraz[0][i].znak = L'O';
		okno_bron_pasek->obraz->obraz[0][i].kolor_przod = kolor::jasny_niebieski;
		okno_bron_pasek->obraz->obraz[0][i].kolor_tyl = kolor::czarny;
	}

	for ( int i = zawartosc; i < pojemnosc && i < szerokosc_paska; i++ )
	{
		okno_bron_pasek->obraz->obraz[0][i].znak = L'X';
		okno_bron_pasek->obraz->obraz[0][i].kolor_przod = kolor::bialy;
		okno_bron_pasek->obraz->obraz[0][i].kolor_tyl = kolor::czarny;
	}

	for ( int i = pojemnosc ; i < szerokosc_paska; i++ )
	{
		okno_bron_pasek->obraz->obraz[0][i].znak = L' ';
		okno_bron_pasek->obraz->obraz[0][i].kolor_przod = kolor::bialy;
		okno_bron_pasek->obraz->obraz[0][i].kolor_tyl = kolor::czarny;
	}
}