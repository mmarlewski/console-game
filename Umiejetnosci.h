#pragma once

#include "Umiejetnosc.h"

class Mapa;
class Obiekt;
class Obraz;
class Punkt;
class Odcinek;
class Okrag;

/*
void ::ustal_oznaczenie_wybor ()
{
	//
}

void ::ustal_oznaczenie_efekt ()
{
	//
}

void ::wykonaj_umiejetnosc ()
{
	//
}

void ::ustal_animacje ()
{
	//
}
*/

class Dzgniecie_mieczem :public Umiejetnosc
{
	public:

	Dzgniecie_mieczem ();
	~Dzgniecie_mieczem ();

	void ustal_oznaczenie_wybor ();
	void ustal_oznaczenie_efekt ();
	void wykonaj_umiejetnosc ();
	void ustal_animacje ();

	Okrag* okrag;
};

class Zamach_mieczem :public Umiejetnosc
{
	public:

	Zamach_mieczem ();
	~Zamach_mieczem ();

	void ustal_oznaczenie_wybor ();
	void ustal_oznaczenie_efekt ();
	void wykonaj_umiejetnosc ();
	void ustal_animacje ();

	Odcinek* odcinek;
	Punkt* punkt_1;
	Punkt* punkt_2;
	Punkt* punkt_3;
	Punkt* punkt_4;
};

class Dzgniecie_wlocznia :public Umiejetnosc
{
	public:

	Dzgniecie_wlocznia ();
	~Dzgniecie_wlocznia ();

	void ustal_oznaczenie_wybor ();
	void ustal_oznaczenie_efekt ();
	void wykonaj_umiejetnosc ();
	void ustal_animacje ();

	Okrag* okrag;
};

class Przebicie_wlocznia :public Umiejetnosc
{
	public:

	Przebicie_wlocznia ();
	~Przebicie_wlocznia ();

	void ustal_oznaczenie_wybor ();
	void ustal_oznaczenie_efekt ();
	void wykonaj_umiejetnosc ();
	void ustal_animacje ();

	Okrag* okrag;
	Odcinek* odcinek;
};

class Pojedynczy_strzal :public Umiejetnosc
{
	public:

	Pojedynczy_strzal ();
	~Pojedynczy_strzal ();

	void ustal_oznaczenie_wybor ();
	void ustal_oznaczenie_efekt ();
	void wykonaj_umiejetnosc ();
	void ustal_animacje ();

	Okrag* okrag;
	Odcinek* odcinek;
};

class Rzut_kamieniem :public Umiejetnosc
{
	public:

	Rzut_kamieniem ();
	~Rzut_kamieniem ();

	void ustal_oznaczenie_wybor ();
	void ustal_oznaczenie_efekt ();
	void wykonaj_umiejetnosc ();
	void ustal_animacje ();

	Okrag* okrag;
	Odcinek* odcinek;
};

class Blyskawica :public Umiejetnosc
{
	public:

	Blyskawica ();
	~Blyskawica ();

	void ustal_oznaczenie_wybor ();
	void ustal_oznaczenie_efekt ();
	void wykonaj_umiejetnosc ();
	void ustal_animacje ();

	Okrag* okrag;
	Odcinek* odcinek;
};

class Kula_ognia :public Umiejetnosc
{
	public:

	Kula_ognia ();
	~Kula_ognia ();

	void ustal_oznaczenie_wybor ();
	void ustal_oznaczenie_efekt ();
	void wykonaj_umiejetnosc ();
	void ustal_animacje ();

	Okrag* okrag;
	Odcinek* odcinek;
};