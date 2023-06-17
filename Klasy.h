#pragma once

#include "Obiekt.h"

class Rycerz :public Obiekt
{
	public:

	Rycerz ();

	void ustal_umiejetnosci ( Tablica_umiejetnosci* _tablica_umiejetnosci );
};

class Wlocznik :public Obiekt
{
	public:

	Wlocznik ();

	void ustal_umiejetnosci ( Tablica_umiejetnosci* _tablica_umiejetnosci );
};

class Lucznik :public Obiekt
{
	public:

	Lucznik ();

	void ustal_umiejetnosci ( Tablica_umiejetnosci* _tablica_umiejetnosci );
};

class Mag :public Obiekt
{
	public:

	Mag ();

	void ustal_umiejetnosci ( Tablica_umiejetnosci* _tablica_umiejetnosci );
};

class Skrzynka :public Obiekt
{
	public:

	Skrzynka ();

	void ustal_umiejetnosci ( Tablica_umiejetnosci* _tablica_umiejetnosci );
};

class Bryla_lodu :public Obiekt
{
	public:

	Bryla_lodu ();

	void ustal_umiejetnosci ( Tablica_umiejetnosci* _tablica_umiejetnosci );
};

class Niski_mur :public Obiekt
{
	public:

	Niski_mur ();

	void ustal_umiejetnosci ( Tablica_umiejetnosci* _tablica_umiejetnosci );
};

class Wysoki_mur :public Obiekt
{
	public:

	Wysoki_mur ();

	void ustal_umiejetnosci ( Tablica_umiejetnosci* _tablica_umiejetnosci );
};