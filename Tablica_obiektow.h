#pragma once

#include <vector>

class Obiekt;

class Tablica_obiektow
{
	public:

	Tablica_obiektow ();
	~Tablica_obiektow ();

	void dodaj_obiekt ( Obiekt* _obiekt );
	void usun_obiekt ( Obiekt* _obiekt );

	std::vector<Obiekt*> tablica_obiektow;
};

