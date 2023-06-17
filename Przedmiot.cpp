#include "Przedmiot.h"

Przedmiot::Przedmiot ()
{
	//
}

Przedmiot::~Przedmiot ()
{
	//
}

Amunicja::Amunicja ()
{
	rodzaj = "amunicja";
}
Amunicja::~Amunicja ()
{
	//
}

Bron::Bron ()
{
	rodzaj = "bron";
}

Bron::~Bron ()
{
	//
}

Bron_biala::Bron_biala ()
{
	rodzaj_broni = "biala";
}

Bron_biala::~Bron_biala ()
{
	//
}

Bron_dystansowa::Bron_dystansowa ()
{
	rodzaj_broni = "dystansowa";
}

Bron_dystansowa::~Bron_dystansowa ()
{
	//
}

bool Bron_dystansowa::czy_jest_amunicja ( std::string _amunicja )
{
	bool czy = 0;

	for ( int i = 0; i < mozliwa_amunicja.size (); i++ )
	{
		if ( mozliwa_amunicja[i] == _amunicja )
		{
			czy = 1;
		}
	}

	return czy;
}

Bron_miotana::Bron_miotana ()
{
	rodzaj_broni = "miotana";
}

Bron_miotana::~Bron_miotana ()
{
	//
}

Zbroja::Zbroja ()
{
	rodzaj = "zbroja";
}

Zbroja::~Zbroja()
{
	//
}