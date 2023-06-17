#include "Umiejetnosci.h"

#include "Mapa.h"
#include "Pole.h"
#include "Obiekt.h"
#include "Obraz.h"
#include "Znak.h"
#include "Punkt.h"
#include "Odcinek.h"
#include "Okrag.h"
#include "Przedmiot.h"

Blyskawica::Blyskawica ()
{
	nazwa = "blyskawica";
	koszt = 3;

	okrag = new Okrag ();
	odcinek = new Odcinek ();
}

Blyskawica::~Blyskawica ()
{
	delete okrag;
	delete odcinek;
}

void Blyskawica::ustal_oznaczenie_wybor ()
{
	for ( int i = 1; i <= 10; i++ )
	{
		mapa->wyznacz_okrag ( okrag, y_obiekt, x_obiekt, i );

		for ( int j = 0; j < okrag->dlugosc; j++ )
		{
			if ( okrag->zbior_punktow[j].wsp_b )
			{
				mapa->zwroc_pole ( okrag->zbior_punktow[j].wsp_y, okrag->zbior_punktow[j].wsp_x )->oznaczenie_wybor = true;
			}
		}
	}
}

void Blyskawica::ustal_oznaczenie_efekt ()
{
	mapa->wyznacz_odcinek ( odcinek, y_obiekt, x_obiekt, y_cel, x_cel );

	for ( int i = 1; i < odcinek->dlugosc; i++ )
	{
		mapa->zwroc_pole ( odcinek->zbior_punktow[i].wsp_y, odcinek->zbior_punktow[i].wsp_x )->oznaczenie_efekt = true;
	}
}

void Blyskawica::wykonaj_umiejetnosc ()
{
	for ( int i = 1; i < odcinek->dlugosc; i++ )
	{
		if ( mapa->zwroc_pole ( odcinek->zbior_punktow[i].wsp_y, odcinek->zbior_punktow[i].wsp_x )->obiekt != nullptr )
		{
			mapa->zwroc_pole ( odcinek->zbior_punktow[i].wsp_y, odcinek->zbior_punktow[i].wsp_x )->obiekt->przyjmij_obrazenia ( 2 );
		}
	}
}

void Blyskawica::ustal_animacje ()
{
	Obraz* obraz_1 = new Obraz ( mapa->dlugosc_mapy, mapa->szerokosc_mapy );
	Obraz* obraz_2 = new Obraz ( mapa->dlugosc_mapy, mapa->szerokosc_mapy );
	Obraz* obraz_3 = new Obraz ( mapa->dlugosc_mapy, mapa->szerokosc_mapy );

	for ( int i = 1; i < odcinek->dlugosc; i++ )
	{
		if ( i % 2 == 0 )
		{
			obraz_1->obraz[odcinek->zbior_punktow[i].wsp_y][odcinek->zbior_punktow[i].wsp_x].znak = L'/';
			obraz_3->obraz[odcinek->zbior_punktow[i].wsp_y][odcinek->zbior_punktow[i].wsp_x].znak = L'/';
			obraz_2->obraz[odcinek->zbior_punktow[i].wsp_y][odcinek->zbior_punktow[i].wsp_x].znak = L'\\';
		}
		else
		{
			obraz_1->obraz[odcinek->zbior_punktow[i].wsp_y][odcinek->zbior_punktow[i].wsp_x].znak = L'\\';
			obraz_3->obraz[odcinek->zbior_punktow[i].wsp_y][odcinek->zbior_punktow[i].wsp_x].znak = L'\\';
			obraz_2->obraz[odcinek->zbior_punktow[i].wsp_y][odcinek->zbior_punktow[i].wsp_x].znak = L'/';
		}

		obraz_1->obraz[odcinek->zbior_punktow[i].wsp_y][odcinek->zbior_punktow[i].wsp_x].przezroczysty = false;
		obraz_1->obraz[odcinek->zbior_punktow[i].wsp_y][odcinek->zbior_punktow[i].wsp_x].kolor_przod = kolor::jasny_zolty;
		obraz_1->obraz[odcinek->zbior_punktow[i].wsp_y][odcinek->zbior_punktow[i].wsp_x].kolor_tyl = kolor::czarny;
		obraz_2->obraz[odcinek->zbior_punktow[i].wsp_y][odcinek->zbior_punktow[i].wsp_x].przezroczysty = false;
		obraz_2->obraz[odcinek->zbior_punktow[i].wsp_y][odcinek->zbior_punktow[i].wsp_x].kolor_przod = kolor::jasny_zolty;
		obraz_2->obraz[odcinek->zbior_punktow[i].wsp_y][odcinek->zbior_punktow[i].wsp_x].kolor_tyl = kolor::czarny;
		obraz_3->obraz[odcinek->zbior_punktow[i].wsp_y][odcinek->zbior_punktow[i].wsp_x].przezroczysty = false;
		obraz_3->obraz[odcinek->zbior_punktow[i].wsp_y][odcinek->zbior_punktow[i].wsp_x].kolor_przod = kolor::jasny_zolty;
		obraz_3->obraz[odcinek->zbior_punktow[i].wsp_y][odcinek->zbior_punktow[i].wsp_x].kolor_tyl = kolor::czarny;
	}

	obrazy_animacji.push_back ( obraz_1 );
	obrazy_animacji.push_back ( obraz_2 );
	obrazy_animacji.push_back ( obraz_3 );
}