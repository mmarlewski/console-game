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

Zamach_mieczem::Zamach_mieczem ()
{
	nazwa = "zamach mieczem";
	koszt = 2;

	odcinek = new Odcinek ();
	punkt_1 = new Punkt ();
	punkt_2 = new Punkt ();
	punkt_3 = new Punkt ();
	punkt_4 = new Punkt ();
}

Zamach_mieczem::~Zamach_mieczem ()
{
	delete odcinek;
	delete punkt_1;
	delete punkt_2;
	delete punkt_3;
	delete punkt_4;
}

void Zamach_mieczem::ustal_oznaczenie_wybor ()
{
	mapa->wyznacz_punkt ( punkt_1, y_obiekt - 1, x_obiekt );
	mapa->wyznacz_punkt ( punkt_2, y_obiekt, x_obiekt + 1 );
	mapa->wyznacz_punkt ( punkt_3, y_obiekt + 1, x_obiekt );
	mapa->wyznacz_punkt ( punkt_4, y_obiekt, x_obiekt - 1 );

	if ( punkt_1->wsp_b )
	{
		mapa->zwroc_pole ( punkt_1->wsp_y, punkt_1->wsp_x )->oznaczenie_wybor = true;
	}

	if ( punkt_2->wsp_b )
	{
		mapa->zwroc_pole ( punkt_2->wsp_y, punkt_2->wsp_x )->oznaczenie_wybor = true;
	}

	if ( punkt_3->wsp_b )
	{
		mapa->zwroc_pole ( punkt_3->wsp_y, punkt_3->wsp_x )->oznaczenie_wybor = true;
	}

	if ( punkt_4->wsp_b )
	{
		mapa->zwroc_pole ( punkt_4->wsp_y, punkt_4->wsp_x )->oznaczenie_wybor = true;
	}
}

void Zamach_mieczem::ustal_oznaczenie_efekt ()
{
	if ( y_cel == punkt_1->wsp_y && x_cel == punkt_1->wsp_x )
	{
		mapa->wyznacz_odcinek ( odcinek, y_cel, x_cel - 1, y_cel, x_cel + 1 );
	}

	if ( y_cel == punkt_2->wsp_y && x_cel == punkt_2->wsp_x )
	{
		mapa->wyznacz_odcinek ( odcinek, y_cel - 1, x_cel, y_cel + 1, x_cel );
	}

	if ( y_cel == punkt_3->wsp_y && x_cel == punkt_3->wsp_x )
	{
		mapa->wyznacz_odcinek ( odcinek, y_cel, x_cel + 1, y_cel, x_cel - 1 );
	}

	if ( y_cel == punkt_4->wsp_y && x_cel == punkt_4->wsp_x )
	{
		mapa->wyznacz_odcinek ( odcinek, y_cel + 1, x_cel, y_cel - 1, x_cel );
	}

	for ( int i = 0; i < odcinek->dlugosc; i++ )
	{
		if ( odcinek->zbior_punktow[i].wsp_b )
		{
			mapa->zwroc_pole ( odcinek->zbior_punktow[i].wsp_y, odcinek->zbior_punktow[i].wsp_x )->oznaczenie_efekt = true;
		}
	}
}

void Zamach_mieczem::wykonaj_umiejetnosc ()
{
	for ( int i = 0; i < odcinek->dlugosc; i++ )
	{
		if ( mapa->zwroc_pole ( odcinek->zbior_punktow[i].wsp_y, odcinek->zbior_punktow[i].wsp_x )->obiekt != nullptr )
		{
			mapa->zwroc_pole ( odcinek->zbior_punktow[i].wsp_y, odcinek->zbior_punktow[i].wsp_x )->obiekt->przyjmij_obrazenia ( obiekt->bron_biala->obrazenia );
		}
	}
}

void Zamach_mieczem::ustal_animacje ()
{
	Obraz* obraz_1 = new Obraz ( mapa->dlugosc_mapy, mapa->szerokosc_mapy );
	Obraz* obraz_2 = new Obraz ( mapa->dlugosc_mapy, mapa->szerokosc_mapy );
	Obraz* obraz_3 = new Obraz ( mapa->dlugosc_mapy, mapa->szerokosc_mapy );

	obraz_1->obraz[odcinek->zbior_punktow[0].wsp_y][odcinek->zbior_punktow[0].wsp_x].przezroczysty = false;
	obraz_1->obraz[odcinek->zbior_punktow[0].wsp_y][odcinek->zbior_punktow[0].wsp_x].znak = L'*';

	obraz_2->obraz[odcinek->zbior_punktow[0].wsp_y][odcinek->zbior_punktow[0].wsp_x].przezroczysty = false;
	obraz_2->obraz[odcinek->zbior_punktow[0].wsp_y][odcinek->zbior_punktow[0].wsp_x].znak = L'*';
	obraz_2->obraz[odcinek->zbior_punktow[1].wsp_y][odcinek->zbior_punktow[1].wsp_x].przezroczysty = false;
	obraz_2->obraz[odcinek->zbior_punktow[1].wsp_y][odcinek->zbior_punktow[1].wsp_x].znak = L'*';

	obraz_3->obraz[odcinek->zbior_punktow[0].wsp_y][odcinek->zbior_punktow[0].wsp_x].przezroczysty = false;
	obraz_3->obraz[odcinek->zbior_punktow[0].wsp_y][odcinek->zbior_punktow[0].wsp_x].znak = L'*';
	obraz_3->obraz[odcinek->zbior_punktow[1].wsp_y][odcinek->zbior_punktow[1].wsp_x].przezroczysty = false;
	obraz_3->obraz[odcinek->zbior_punktow[1].wsp_y][odcinek->zbior_punktow[1].wsp_x].znak = L'*';
	obraz_3->obraz[odcinek->zbior_punktow[2].wsp_y][odcinek->zbior_punktow[2].wsp_x].przezroczysty = false;
	obraz_3->obraz[odcinek->zbior_punktow[2].wsp_y][odcinek->zbior_punktow[2].wsp_x].znak = L'X';

	obrazy_animacji.push_back ( obraz_1 );
	obrazy_animacji.push_back ( obraz_2 );
	obrazy_animacji.push_back ( obraz_3 );
}