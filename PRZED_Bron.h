#pragma once

#include "Przedmiot.h"

class Patyk :public Bron_biala
{
	public:

	Patyk ();
};

class Slaby_miecz :public Bron_biala
{
	public:

	Slaby_miecz ();
};

class Mocny_miecz :public Bron_biala
{
	public:

	Mocny_miecz ();
};

class Slaba_wlocznia :public Bron_biala
{
	public:

	Slaba_wlocznia ();
};

class Mocna_wlocznia :public Bron_biala
{
	public:

	Mocna_wlocznia ();
};

/////

class Proca :public Bron_dystansowa
{
	public:

	Proca ();
};

class Luk :public Bron_dystansowa
{
	public:

	Luk ();
};

class Kusza :public Bron_dystansowa
{
	public:

	Kusza ();
};

/////

class Kamienie :public Bron_miotana
{
	public:

	Kamienie ();
};

class Noze_do_rzucania :public Bron_miotana
{
	public:

	Noze_do_rzucania ();
};

class Granat :public Bron_miotana
{
	public:

	Granat ();
};