#include "Tryb_ekwipunek.h"

#include "Tablica_okien.h"
#include "Mapa.h"
#include "Obiekt.h"
#include "Przedmiot.h"
#include "Okno_obszar.h"
#include "Okno_napis.h"

Tryb_ekwipunek::Tryb_ekwipunek ()
{
	//
}

Tryb_ekwipunek::~Tryb_ekwipunek ()
{
	//
}

void Tryb_ekwipunek::stworz_okna ()
{
	okno_mapa = new Okno_obszar ( mapa->obraz_mapy, 0, mapa->dlugosc_mapy, 0, mapa->szerokosc_mapy );

	okno_imie = new Okno_napis ( 0, 12, 20 );
	okno_tytul = new Okno_napis ( 2, 12, 20 );
	okno_wroc = new Okno_napis ( 2, 35, 4 );

	for ( int i = 0; i < 5; i++ )
	{
		okno_nazwa[i] = new Okno_napis ( 4 + 2 * i, 12, 20 );
		okno_wartosc_1[i] = new Okno_napis ( 4 + 2 * i, 31, 2 );
		okno_wartosc_2[i] = new Okno_napis ( 4 + 2 * i, 34, 2 );
	}

	okno_lewa_strzalka = new Okno_napis ( 14, 12, 5 );
	okno_nr_czesci = new Okno_napis ( 14, 18, 5 );
	okno_prawa_strzalka = new Okno_napis ( 14, 24, 5 );
}

void Tryb_ekwipunek::zniszcz_okna ()
{
	delete okno_mapa;
	delete okno_imie;
	delete okno_tytul;
	delete okno_wroc;

	for ( int i = 0; i < 5; i++ )
	{
		delete okno_nazwa[i];
		delete okno_wartosc_1[i];
		delete okno_wartosc_2[i];
	}

	delete okno_lewa_strzalka;
	delete okno_nr_czesci;
	delete okno_prawa_strzalka;
}

void Tryb_ekwipunek::zacznij ()
{
	tablica_okien->dodaj_okno ( okno_mapa );
	tablica_okien->dodaj_okno ( okno_imie );
	tablica_okien->dodaj_okno ( okno_tytul );
	tablica_okien->dodaj_okno ( okno_wroc );

	for ( int i = 0; i < 5; i++ )
	{
		tablica_okien->dodaj_okno ( okno_nazwa[i] );
		tablica_okien->dodaj_okno ( okno_wartosc_1[i] );
		tablica_okien->dodaj_okno ( okno_wartosc_2[i] );
	}

	tablica_okien->dodaj_okno ( okno_lewa_strzalka );
	tablica_okien->dodaj_okno ( okno_nr_czesci );
	tablica_okien->dodaj_okno ( okno_prawa_strzalka );

	mapa->wyczysc_obraz_mapy ();
	mapa->dolacz_obiekty_do_obrazu_mapy ();
	mapa->dolacz_kursor_do_obrazu_mapy ();

	for ( int i = 0; i < obiekt->ekwipunek.size (); i++ )
	{
		if ( rodzaj_przedmiotow == "amunicja" )
		{
			if ( obiekt->ekwipunek[i]->rodzaj == "amunicja" )
			{
				if ( obiekt->bron_dystansowa != nullptr )
				{
					if ( obiekt->bron_dystansowa->czy_jest_amunicja ( obiekt->ekwipunek[i]->klasa ) )
					{
						przedmioty.push_back ( obiekt->ekwipunek[i] );
					}
				}
			}
		}
		else if ( rodzaj_przedmiotow == "bron" )
		{
			if ( obiekt->ekwipunek[i]->rodzaj == "bron" )
			{
				przedmioty.push_back ( obiekt->ekwipunek[i] );
			}
		}
		else if ( rodzaj_przedmiotow == "zbroja" )
		{
			if ( obiekt->ekwipunek[i]->rodzaj == "zbroja" )
			{
				przedmioty.push_back ( obiekt->ekwipunek[i] );
			}
		}
	}

	if ( rodzaj_przedmiotow == "amunicja" )
	{
		kolor_wartosc_1 = kolor::ciemny_czerwony;
		kolor_wartosc_2 = kolor::ciemny_zolty ;
	}
	else if ( rodzaj_przedmiotow == "bron" )
	{
		kolor_wartosc_1 = kolor::ciemny_czerwony;
		kolor_wartosc_2 = kolor::ciemny_zolty;
	}
	else if ( rodzaj_przedmiotow == "zbroja" )
	{
		kolor_wartosc_1 = kolor::ciemny_niebieski;
		kolor_wartosc_2 = kolor::ciemny_zolty;
	}

	max_czesci = ( przedmioty.size () + 4 ) / 5;
	nr_czesci = 0;

	okno_mapa->aktywuj ();

	okno_imie->aktywuj ();
	okno_imie->zmien_napis ( obiekt->imie );
	okno_imie->zmien_kolor ( kolor::czarny, kolor::jasny_rozowy );

	okno_tytul->aktywuj ();

	if ( rodzaj_przedmiotow == "amunicja" )
	{
		if ( przedmioty.size () > 0 )
		{
			okno_tytul->zmien_napis ( "wybierz amunicje" );
		}
		else
		{
			okno_tytul->zmien_napis ( "brak amunicji" );
		}

		okno_tytul->zmien_kolor ( kolor::czarny, kolor::ciemny_zolty );
	}
	else if ( rodzaj_przedmiotow == "bron" )
	{
		if ( przedmioty.size () > 0 )
		{
			okno_tytul->zmien_napis ( "wybierz bron" );
		}
		else
		{
			okno_tytul->zmien_napis ( "brak broni" );
		}

		okno_tytul->zmien_kolor ( kolor::czarny, kolor::ciemny_czerwony );
	}
	else if ( rodzaj_przedmiotow == "zbroja" )
	{
		if ( przedmioty.size () > 0 )
		{
			okno_tytul->zmien_napis ( "wybierz zbroje" );
		}
		else
		{
			okno_tytul->zmien_napis ( "brak zbroji" );
		}

		okno_tytul->zmien_kolor ( kolor::czarny, kolor::ciemny_niebieski );
	}

	okno_wroc->aktywuj ();
	okno_wroc->zmien_napis ( "wroc" );

	pokaz_czesc_ekwipunku ();
}

void Tryb_ekwipunek::zakoncz ()
{
	przedmioty.clear ();

	tablica_okien->usun_okno ( okno_mapa );
	tablica_okien->usun_okno ( okno_imie );
	tablica_okien->usun_okno ( okno_tytul );
	tablica_okien->usun_okno ( okno_wroc );

	for ( int i = 0; i < 5; i++ )
	{
		tablica_okien->usun_okno ( okno_nazwa[i] );
		tablica_okien->usun_okno ( okno_wartosc_1[i] );
		tablica_okien->usun_okno ( okno_wartosc_2[i] );
	}

	tablica_okien->usun_okno ( okno_lewa_strzalka );
	tablica_okien->usun_okno ( okno_nr_czesci );
	tablica_okien->usun_okno ( okno_prawa_strzalka );
}

void Tryb_ekwipunek::petla ()
{
	///// wroc

	if ( okno_wroc->myszka_weszla )
	{
		okno_wroc->zmien_kolor ( kolor::czarny, kolor::ciemny_czerwony );
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

	///// przedmioty

	for ( int i = 0; i < 5; i++ )
	{
		if ( nr_czesci * 5 + i < przedmioty.size () )
		{
			///// myszka_weszla

			if ( okno_nazwa[i]->myszka_weszla )
			{
				if ( przedmioty[nr_czesci * 5 + i]->rodzaj == "amunicja" )
				{
					if ( dynamic_cast< Amunicja* >( przedmioty[nr_czesci * 5 + i] ) == obiekt->amunicja )
					{
						okno_nazwa[i]->zmien_napis ( "- zalozono -" );
					}
					else
					{
						okno_nazwa[i]->zmien_napis ( "- zaloz -" );
					}

					okno_nazwa[i]->zmien_kolor ( kolor::czarny, kolor::jasny_zolty );
				}
				else if ( przedmioty[nr_czesci * 5 + i]->rodzaj == "bron" )
				{
					if ( dynamic_cast< Bron* >( przedmioty[nr_czesci * 5 + i] ) == obiekt->bron )
					{
						okno_nazwa[i]->zmien_napis ( "- zalozono -" );
					}
					else
					{
						okno_nazwa[i]->zmien_napis ( "- zaloz -" );
					}

					okno_nazwa[i]->zmien_kolor ( kolor::czarny, kolor::jasny_czerwony );
				}
				else if ( przedmioty[nr_czesci * 5 + i]->rodzaj == "zbroja" )
				{
					if ( dynamic_cast< Zbroja* >( przedmioty[nr_czesci * 5 + i] ) == obiekt->zbroja )
					{
						okno_nazwa[i]->zmien_napis ( "- zalozono -" );
					}
					else
					{
						okno_nazwa[i]->zmien_napis ( "- zaloz -" );
					}

					okno_nazwa[i]->zmien_kolor ( kolor::czarny, kolor::jasny_niebieski );
				}
			}

			///// myszka_wyszla

			if ( okno_nazwa[i]->myszka_wyszla )
			{
				okno_nazwa[i]->zmien_napis ( przedmioty[nr_czesci * 5 + i]->klasa );

				okno_nazwa[i]->zmien_kolor ( kolor::czarny, kolor::bialy );
			}

			///// l_klikniety

			if ( okno_nazwa[i]->l_klikniety )
			{
				bool czy_zalozyc = false;

				if ( przedmioty[nr_czesci * 5 + i]->rodzaj == "amunicja" )
				{
					if ( dynamic_cast< Amunicja* >( przedmioty[nr_czesci * 5 + i] ) != obiekt->amunicja )
					{
						czy_zalozyc = true;
					}
				}
				else if ( przedmioty[nr_czesci * 5 + i]->rodzaj == "bron" )
				{
					if ( dynamic_cast< Bron* >( przedmioty[nr_czesci * 5 + i] ) != obiekt->bron )
					{
						czy_zalozyc = true;
					}
				}
				else if ( przedmioty[nr_czesci * 5 + i]->rodzaj == "zbroja" )
				{
					if ( dynamic_cast< Zbroja* >( przedmioty[nr_czesci * 5 + i] ) != obiekt->zbroja )
					{
						czy_zalozyc = true;
					}
				}

				if ( czy_zalozyc )
				{
					if ( przedmioty[nr_czesci * 5 + i]->rodzaj == "amunicja" )
					{
						if ( obiekt->amunicja != nullptr )
						{
							obiekt->amunicja->zawartosc += obiekt->bron_dystansowa->zawartosc;

							obiekt->bron_dystansowa->zawartosc = 0;
						}

						obiekt->amunicja = dynamic_cast< Amunicja* >( przedmioty[nr_czesci * 5 + i] );
					}
					else if ( przedmioty[nr_czesci * 5 + i]->rodzaj == "bron" )
					{
						if ( obiekt->amunicja != nullptr )
						{
							obiekt->amunicja->zawartosc += obiekt->bron_dystansowa->zawartosc;

							obiekt->bron_dystansowa->zawartosc = 0;
						}

						obiekt->amunicja = nullptr;

						obiekt->bron_biala = nullptr;
						obiekt->bron_dystansowa = nullptr;
						obiekt->bron_miotana = nullptr;

						obiekt->bron = dynamic_cast< Bron* >( przedmioty[nr_czesci * 5 + i] );

						if ( dynamic_cast< Bron* >( przedmioty[nr_czesci * 5 + i] )->rodzaj_broni == "biala" )
						{
							obiekt->bron_biala = dynamic_cast< Bron_biala* >( przedmioty[nr_czesci * 5 + i] );
						}
						else if ( dynamic_cast< Bron* >( przedmioty[nr_czesci * 5 + i] )->rodzaj_broni == "dystansowa" )
						{
							obiekt->bron_dystansowa = dynamic_cast< Bron_dystansowa* >( przedmioty[nr_czesci * 5 + i] );
						}
						else if ( dynamic_cast< Bron* >( przedmioty[nr_czesci * 5 + i] )->rodzaj_broni == "miotana" )
						{
							obiekt->bron_miotana = dynamic_cast< Bron_miotana* >( przedmioty[nr_czesci * 5 + i] );
						}
					}
					else if ( przedmioty[nr_czesci * 5 + i]->rodzaj == "zbroja" )
					{
						obiekt->zbroja = dynamic_cast< Zbroja* >( przedmioty[nr_czesci * 5 + i] );
					}

					nastepny_tryb = "wybor";
					czy_tryb_ma_trwac = false;
				}
			}
		}
	}

	if ( okno_lewa_strzalka->myszka_weszla )
	{
		okno_lewa_strzalka->zmien_napis ( "<<<< " );
	}

	if ( okno_lewa_strzalka->myszka_wyszla )
	{
		okno_lewa_strzalka->zmien_napis ( " <<<<" );
	}

	if ( okno_prawa_strzalka->myszka_weszla )
	{
		okno_prawa_strzalka->zmien_napis ( " >>>>" );
	}

	if ( okno_prawa_strzalka->myszka_wyszla )
	{
		okno_prawa_strzalka->zmien_napis ( ">>>> " );
	}

	if ( okno_lewa_strzalka->l_klikniety )
	{
		if ( nr_czesci > 0 )
		{
			nr_czesci--;
			pokaz_czesc_ekwipunku ();
		}
	}

	if ( okno_prawa_strzalka->l_klikniety )
	{
		if ( nr_czesci < max_czesci - 1 )
		{
			nr_czesci++;
			pokaz_czesc_ekwipunku ();
		}
	}
}

void Tryb_ekwipunek::pokaz_czesc_ekwipunku ()
{
	for ( int i = 0; i < 5; i++ )
	{
		okno_nazwa[i]->deaktywuj ();
		okno_wartosc_1[i]->deaktywuj ();
		okno_wartosc_2[i]->deaktywuj ();

		if ( nr_czesci * 5 + i < przedmioty.size () )
		{
			okno_nazwa[i]->aktywuj ();
			okno_wartosc_1[i]->aktywuj ();

			if ( rodzaj_przedmiotow == "amunicja" )
			{
				okno_wartosc_2[i]->aktywuj ();

				wartosc_1 = dynamic_cast< Amunicja* >( przedmioty[nr_czesci * 5 + i] )->obrazenia;
				wartosc_2 = dynamic_cast< Amunicja* >( przedmioty[nr_czesci * 5 + i] )->zawartosc;
			}
			else if ( rodzaj_przedmiotow == "bron" )
			{
				if ( dynamic_cast< Bron* >( przedmioty[nr_czesci * 5 + i] )->rodzaj_broni == "biala" )
				{
					wartosc_1 = dynamic_cast< Bron_biala* >( przedmioty[nr_czesci * 5 + i] )->obrazenia;
					wartosc_2 = 0;
				}
				else if ( dynamic_cast< Bron* >( przedmioty[nr_czesci * 5 + i] )->rodzaj_broni == "dystansowa" )
				{
					okno_wartosc_2[i]->aktywuj ();

					wartosc_1 = dynamic_cast< Bron_dystansowa* >( przedmioty[nr_czesci * 5 + i] )->obrazenia;
					wartosc_2 = dynamic_cast< Bron_dystansowa* >( przedmioty[nr_czesci * 5 + i] )->pojemnosc;
				}
				else if ( dynamic_cast< Bron* >( przedmioty[nr_czesci * 5 + i] )->rodzaj_broni == "miotana" )
				{
					okno_wartosc_2[i]->aktywuj ();

					wartosc_1 = dynamic_cast< Bron_miotana* >( przedmioty[nr_czesci * 5 + i] )->obrazenia;
					wartosc_2 = dynamic_cast< Bron_miotana* >( przedmioty[nr_czesci * 5 + i] )->zawartosc;
				}
			}
			else if ( rodzaj_przedmiotow == "zbroja" )
			{
				wartosc_1 = dynamic_cast< Zbroja* >( przedmioty[nr_czesci * 5 + i] )->ochrona;
				wartosc_2 = 0;
			}

			okno_nazwa[i]->zmien_napis ( przedmioty[nr_czesci * 5 + i]->klasa );
			okno_wartosc_1[i]->zmien_kolor ( kolor::czarny, kolor_wartosc_1 );
			okno_wartosc_1[i]->zmien_napis ( std::to_string ( wartosc_1 ) );
			okno_wartosc_2[i]->zmien_kolor ( kolor::czarny, kolor_wartosc_2 );
			okno_wartosc_2[i]->zmien_napis ( std::to_string ( wartosc_2 ) );
		}
	}

	if ( nr_czesci > 0 )
	{
		okno_lewa_strzalka->aktywuj ();
		okno_lewa_strzalka->zmien_napis ( " <<<<" );
	}
	else
	{
		okno_lewa_strzalka->deaktywuj ();
	}

	if ( przedmioty.size () > 0 )
	{
		okno_nr_czesci->aktywuj ();
		okno_nr_czesci->zmien_napis ( std::to_string ( nr_czesci + 1 ) + " / " + std::to_string ( max_czesci ) );
	}
	else
	{
		okno_nr_czesci->deaktywuj ();
	}

	if ( nr_czesci < max_czesci - 1 )
	{
		okno_prawa_strzalka->aktywuj ();
		okno_prawa_strzalka->zmien_napis ( ">>>> " );
	}
	else
	{
		okno_prawa_strzalka->deaktywuj ();
	}
}
