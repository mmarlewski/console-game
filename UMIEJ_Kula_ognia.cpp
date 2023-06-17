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

Kula_ognia::Kula_ognia ()
{
	nazwa = "kula ognia";
	koszt = 5;

	okrag = new Okrag ();
	odcinek = new Odcinek ();
}

Kula_ognia::~Kula_ognia ()
{
	delete okrag;
	delete odcinek;
}

void Kula_ognia::ustal_oznaczenie_wybor ()
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

void Kula_ognia::ustal_oznaczenie_efekt ()
{
	mapa->wyznacz_odcinek ( odcinek, y_obiekt, x_obiekt, y_cel, x_cel );
	mapa->wyznacz_okrag ( okrag, y_cel, x_cel, 1 );

	for ( int i = 1; i < odcinek->dlugosc - 1; i++ )
	{
		mapa->zwroc_pole ( odcinek->zbior_punktow[i].wsp_y, odcinek->zbior_punktow[i].wsp_x )->oznaczenie_efekt = true;
	}

	for ( int i = 0; i < okrag->dlugosc; i++ )
	{
		mapa->zwroc_pole ( okrag->zbior_punktow[i].wsp_y, okrag->zbior_punktow[i].wsp_x )->oznaczenie_efekt = true;
	}
}

void Kula_ognia::wykonaj_umiejetnosc ()
{
	for ( int i = 1; i < odcinek->dlugosc - 1; i++ )
	{
		if ( mapa->zwroc_pole ( odcinek->zbior_punktow[i].wsp_y, odcinek->zbior_punktow[i].wsp_x )->obiekt != nullptr )
		{
			mapa->zwroc_pole ( odcinek->zbior_punktow[i].wsp_y, odcinek->zbior_punktow[i].wsp_x )->obiekt->przyjmij_obrazenia ( 5 );
		}
	}

	for ( int i = 0; i < okrag->dlugosc; i++ )
	{
		if ( mapa->zwroc_pole ( okrag->zbior_punktow[i].wsp_y, okrag->zbior_punktow[i].wsp_x )->obiekt != nullptr )
		{
			mapa->zwroc_pole ( okrag->zbior_punktow[i].wsp_y, okrag->zbior_punktow[i].wsp_x )->obiekt->przyjmij_obrazenia ( 5 );
		}
	}
}

void Kula_ognia::ustal_animacje ()
{
	Obraz** obrazy = new Obraz * [odcinek->dlugosc];

	for ( int i = 0; i < odcinek->dlugosc - 1; i++ )
	{
		obrazy[i]->obraz[odcinek->zbior_punktow[i + 1].wsp_y][odcinek->zbior_punktow[i + 1].wsp_x].znak = L'*';

		for ( int j = i + 1; j >= i - 1 && j > 1; j-- )
		{
			obrazy[i]->obraz[odcinek->zbior_punktow[j].wsp_y][odcinek->zbior_punktow[j].wsp_x].znak = L'\'';
		}
	}

	for ( int i = 0; i < okrag->dlugosc; i++ )
	{
		obrazy[odcinek->dlugosc - 1]->obraz[okrag->zbior_punktow[i].wsp_y][okrag->zbior_punktow[i].wsp_x].znak = L'X';
	}

	obrazy[odcinek->dlugosc - 1]->obraz[y_cel][x_cel].znak = L'X';

	for ( int i = 0; i < odcinek-> dlugosc; i++ )
	{
		obrazy_animacji.push_back ( obrazy[i] );
	}
}