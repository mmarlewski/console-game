#include "Tablica_okien.h"

#include "Konsola.h"
#include "Okno.h"
#include "Okno_napis.h"
#include "Okno_obszar.h"
#include "Obraz.h"
#include "Znak.h"

Tablica_okien::Tablica_okien ( int _dlugosc_wspolnego_obrazu, int _szerokosc_wspolnego_obrazu )
{
	dlugosc_wspolnego_obrazu = _dlugosc_wspolnego_obrazu;
	szerokosc_wspolnego_obrazu = _szerokosc_wspolnego_obrazu;

	wspolny_obraz_okien = new Obraz ( dlugosc_wspolnego_obrazu, szerokosc_wspolnego_obrazu );
}

Tablica_okien::~Tablica_okien ()
{
	delete wspolny_obraz_okien;
}

void Tablica_okien::zaktualizuj_okna ()
{
	for ( int i = 0; i < tablica_okien.size (); i++ )
	{
		if ( konsola->myszka_y >= tablica_okien[i]->pozycja_y && konsola->myszka_y < tablica_okien[i]->pozycja_y + tablica_okien[i]->dlugosc &&
			 konsola->myszka_x >= tablica_okien[i]->pozycja_x && konsola->myszka_x < tablica_okien[i]->pozycja_x + tablica_okien[i]->szerokosc )
		{
			tablica_okien[i]->zaktualizuj ( true, konsola->myszka_l, konsola->myszka_p );

			tablica_okien[i]->kursor_y = konsola->myszka_y - tablica_okien[i]->pozycja_y;
			tablica_okien[i]->kursor_x = konsola->myszka_x - tablica_okien[i]->pozycja_x;
		}
		else
		{
			tablica_okien[i]->zaktualizuj ( false, false, false );

			tablica_okien[i]->kursor_y = 0;
			tablica_okien[i]->kursor_x = 0;
		}
	}
}

void Tablica_okien::ustal_wspolny_obraz ()
{
	for ( int i = 0; i < dlugosc_wspolnego_obrazu; i++ )
	{
		for ( int j = 0; j < szerokosc_wspolnego_obrazu; j++ )
		{
			wspolny_obraz_okien->obraz[i][j].znak = L' ';
			wspolny_obraz_okien->obraz[i][j].kolor_przod = kolor::czarny;
			wspolny_obraz_okien->obraz[i][j].kolor_tyl = kolor::czarny;
		}
	}

	for ( int k = 0; k < tablica_okien.size() ; k++ )
	{
		if ( tablica_okien[k]->czy_aktywne )
		{
			for ( int i = 0; i < tablica_okien[k]->dlugosc; i++ )
			{
				for ( int j = 0; j < tablica_okien[k]->szerokosc; j++ )
				{
					if ( tablica_okien[k]->obraz->obraz[i][j].przezroczysty == false )
					{
						if ( tablica_okien[k]->pozycja_y + i >= 0 && tablica_okien[k]->pozycja_y + i <= dlugosc_wspolnego_obrazu - 1 &&
							 tablica_okien[k]->pozycja_x + j >= 0 && tablica_okien[k]->pozycja_x + j <= szerokosc_wspolnego_obrazu - 1 )
						{
							wspolny_obraz_okien->obraz[tablica_okien[k]->pozycja_y + i][tablica_okien[k]->pozycja_x + j] = tablica_okien[k]->obraz->obraz[i][j];
						}
					}
				}
			}
		}
	}
}

void Tablica_okien::dodaj_okno ( Okno* _okno )
{
	bool czy_okno_juz_jest_dodane = false;

	for ( std::vector<Okno*>::iterator i = tablica_okien.begin (); i < tablica_okien.end (); i++ )
	{
		if ( *i == _okno )
		{
			czy_okno_juz_jest_dodane = true;

			break;
		}
	}

	if ( czy_okno_juz_jest_dodane == false )
	{
		tablica_okien.push_back ( _okno );
	}
}

void Tablica_okien::usun_okno ( Okno* _okno )
{
	for ( std::vector<Okno*>::iterator i = tablica_okien.begin (); i < tablica_okien.end (); i++ )
	{
		if ( *i == _okno )
		{
			tablica_okien.erase ( i );

			break;
		}
	}
}