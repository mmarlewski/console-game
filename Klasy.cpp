#include "Klasy.h"

#include "Tablica_umiejetnosci.h"
#include "PRZED_Bron.h"
#include "PRZED_Amunicja.h"
#include "PRZED_Zbroja.h"

Rycerz::Rycerz()
{
	klasa = "rycerz";
	symbol = L'\u042f';
	wysokosc = 2;
	czy_hp = 1; hp_max = 20;
	czy_ap = 1; ap_max = 5;
	czy_ekw = 1; ekw_max = 20;
	czy_umiej = 1;
};

void Rycerz::ustal_umiejetnosci ( Tablica_umiejetnosci* _tablica_umiejetnosci )
{
	if ( bron != nullptr )
	{
		if ( bron->klasa == "slaby miecz" || bron->klasa == "mocny miecz" )
		{
			umiejetnosci.push_back ( _tablica_umiejetnosci->dzgniecie_mieczem );
			umiejetnosci.push_back ( _tablica_umiejetnosci->zamach_mieczem );
		}
	}

	umiejetnosci.push_back ( _tablica_umiejetnosci->blyskawica );
	umiejetnosci.push_back ( _tablica_umiejetnosci->kula_ognia );
}

Wlocznik::Wlocznik()
{
	klasa = "wlucznik";
	symbol = L'\u039b';
	wysokosc = 2;
	czy_hp = 1; hp_max = 15;
	czy_ap = 1; ap_max = 10;
	czy_ekw = 1; ekw_max = 15;
	czy_umiej = 1;
};

void Wlocznik::ustal_umiejetnosci ( Tablica_umiejetnosci* _tablica_umiejetnosci )
{
	if ( bron != nullptr )
	{
		if ( bron->klasa == "slaba wlocznia" || bron->klasa == "mocna wlocznia" )
		{
			umiejetnosci.push_back ( _tablica_umiejetnosci->dzgniecie_wlocznia );
			umiejetnosci.push_back ( _tablica_umiejetnosci->przebicie_wlocznia );
		}
	}
}

Lucznik::Lucznik()
{
	klasa = "lucznik";
	symbol = L'\u03f7';
	wysokosc = 2;
	czy_hp = 1; hp_max = 10;
	czy_ap = 1; ap_max = 10;
	czy_ekw = 1; ekw_max = 10;
	czy_umiej = 1;
};

void Lucznik::ustal_umiejetnosci ( Tablica_umiejetnosci* _tablica_umiejetnosci )
{
	if ( bron != nullptr )
	{
		if ( bron->klasa == "luk" || bron->klasa == "luk" )
		{
			if ( bron_dystansowa->zawartosc > 0 )
			{
				//
			}
		}
	}
}

Mag::Mag()
{
	klasa = "mag";
	symbol = L'\u03a9';
	wysokosc = 2;
	czy_hp = 1; hp_max = 10;
	czy_ap = 1; ap_max = 10;
	czy_ekw = 1; ekw_max = 10;
	czy_umiej = 1;
};

void Mag::ustal_umiejetnosci ( Tablica_umiejetnosci* _tablica_umiejetnosci )
{
	//
}

Skrzynka::Skrzynka()
{
	klasa = "skrzynka";
	symbol = L'#';
	wysokosc = 1;
	czy_hp = 1; hp_max = 2;
	czy_ap = 0; ap_max = 0;
	czy_ekw = 0; ekw_max = 0;
	czy_umiej = 0;
};

void Skrzynka::ustal_umiejetnosci ( Tablica_umiejetnosci* _tablica_umiejetnosci )
{
	//
}

Bryla_lodu::Bryla_lodu()
{
	klasa = "bryla lodu";
	symbol = L'\u0394';
	wysokosc = 2;
	czy_hp = 1; hp_max = 5;
	czy_ap = 0; ap_max = 0;
	czy_ekw = 0; ekw_max = 0;
	czy_umiej = 0;
};

void Bryla_lodu::ustal_umiejetnosci ( Tablica_umiejetnosci* _tablica_umiejetnosci )
{
	//
}

Niski_mur::Niski_mur()
{
	klasa = "niski mur";
	symbol = L'\u03a0';
	wysokosc = 1;
	czy_hp = 0; hp_max = 0;
	czy_ap = 0; ap_max = 0;
	czy_ekw = 0; ekw_max = 0;
	czy_umiej = 0;
};

void Niski_mur::ustal_umiejetnosci ( Tablica_umiejetnosci* _tablica_umiejetnosci )
{
	//
}

Wysoki_mur::Wysoki_mur()
{
	klasa = "wysoki mur";
	symbol = L'\u041f';
	wysokosc = 2;
	czy_hp = 0; hp_max = 0;
	czy_ap = 0; ap_max = 0;
	czy_ekw = 0; ekw_max = 0;
	czy_umiej = 0;
};

void Wysoki_mur::ustal_umiejetnosci ( Tablica_umiejetnosci* _tablica_umiejetnosci )
{
	//
}