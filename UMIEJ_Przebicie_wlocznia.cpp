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

Przebicie_wlocznia::Przebicie_wlocznia ()
{
	nazwa = "przebicie wlocznia";
	koszt = 2;

	okrag = new Okrag ();
	odcinek = new Odcinek ();
}

Przebicie_wlocznia::~Przebicie_wlocznia ()
{
	delete okrag;
	delete odcinek;
}

void Przebicie_wlocznia::ustal_oznaczenie_wybor ()
{
	mapa->wyznacz_okrag ( okrag, y_obiekt, x_obiekt, 1 );

	for ( int i = 0; i < okrag->dlugosc; i++ )
	{
		if ( okrag->zbior_punktow[i].wsp_b )
		{
			mapa->zwroc_pole ( okrag->zbior_punktow[i].wsp_y, okrag->zbior_punktow[i].wsp_x )->oznaczenie_wybor = true;
		}
	}
}

void Przebicie_wlocznia::ustal_oznaczenie_efekt ()
{
	mapa->wyznacz_odcinek ( odcinek, y_cel, x_cel, y_cel + ( y_cel - y_obiekt ), x_cel + ( x_cel - x_obiekt ) );

	for ( int i = 0; i < odcinek->dlugosc; i++ )
	{
		if ( odcinek->zbior_punktow[i].wsp_b )
		{
			mapa->zwroc_pole ( odcinek->zbior_punktow[i].wsp_y, odcinek->zbior_punktow[i].wsp_x )->oznaczenie_efekt = true;
		}
	}
}

void Przebicie_wlocznia::wykonaj_umiejetnosc ()
{
	for ( int i = 0; i < odcinek->dlugosc; i++ )
	{
		if ( odcinek->zbior_punktow[i].wsp_b )
		{
			if ( mapa->zwroc_pole ( odcinek->zbior_punktow[i].wsp_y, odcinek->zbior_punktow[i].wsp_x )->obiekt != nullptr )
			{
				mapa->zwroc_pole ( odcinek->zbior_punktow[i].wsp_y, odcinek->zbior_punktow[i].wsp_x )->obiekt->przyjmij_obrazenia ( obiekt->bron_biala->obrazenia );
			}
		}
	}
}

void Przebicie_wlocznia::ustal_animacje ()
{
	Obraz* obraz_1 = new Obraz ( mapa->dlugosc_mapy, mapa->szerokosc_mapy );
	Obraz* obraz_2 = new Obraz ( mapa->dlugosc_mapy, mapa->szerokosc_mapy );
	

	obraz_1->obraz[odcinek->zbior_punktow[0].wsp_y][odcinek->zbior_punktow[0].wsp_x].przezroczysty = false;
	obraz_1->obraz[odcinek->zbior_punktow[0].wsp_y][odcinek->zbior_punktow[0].wsp_x].znak = L'X';
	obraz_1->obraz[odcinek->zbior_punktow[1].wsp_y][odcinek->zbior_punktow[1].wsp_x].przezroczysty = false;
	obraz_1->obraz[odcinek->zbior_punktow[1].wsp_y][odcinek->zbior_punktow[1].wsp_x].znak = L'X';

	obraz_2->obraz[odcinek->zbior_punktow[0].wsp_y][odcinek->zbior_punktow[0].wsp_x].przezroczysty = false;
	obraz_2->obraz[odcinek->zbior_punktow[0].wsp_y][odcinek->zbior_punktow[0].wsp_x].znak = L'X';
	obraz_2->obraz[odcinek->zbior_punktow[1].wsp_y][odcinek->zbior_punktow[1].wsp_x].przezroczysty = false;
	obraz_2->obraz[odcinek->zbior_punktow[1].wsp_y][odcinek->zbior_punktow[1].wsp_x].znak = L'X';

	obrazy_animacji.push_back ( obraz_1 );
	obrazy_animacji.push_back ( obraz_2 );
}