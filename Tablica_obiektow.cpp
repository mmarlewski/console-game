#include "Tablica_obiektow.h"

Tablica_obiektow::Tablica_obiektow ()
{
	//
}

Tablica_obiektow::~Tablica_obiektow ()
{
	for ( int i = 0; i < tablica_obiektow.size (); i++ )
	{
		delete tablica_obiektow[i];
	}
}

void Tablica_obiektow::dodaj_obiekt ( Obiekt* _obiekt )
{
	tablica_obiektow.push_back ( _obiekt );
}

void Tablica_obiektow::usun_obiekt ( Obiekt* _obiekt )
{
	//
}