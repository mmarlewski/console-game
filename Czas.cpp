#include "Czas.h"

#include "Licznik.h"

Czas::Czas ()
{
	//
}

Czas::~Czas ()
{
	//
}

void Czas::zaktualizuj_liczniki ()
{
	for ( int i = 0; i < tablica_licznikow.size (); i++ )
	{
		if ( tablica_licznikow[i]->czy_odliczac )
		{
			tablica_licznikow[i]->zmierz_milisekundy ();
		}
	}
}

void Czas::dodaj_licznik ( Licznik* _licznik )
{
	tablica_licznikow.push_back ( _licznik );
}

void Czas::usun_licznik ( Licznik* _licznik )
{
	for ( std::vector<Licznik*>::iterator i = tablica_licznikow.begin (); i < tablica_licznikow.end (); i++ )
	{
		if ( *i == _licznik )
		{
			tablica_licznikow.erase ( i );

			break;
		}
	}
}