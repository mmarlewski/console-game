#pragma once

#include <string>
#include <vector>

class Przedmiot
{
	public:

	Przedmiot ();
	virtual ~Przedmiot ();

	std::string rodzaj;
	std::string klasa;
};

class Amunicja :public Przedmiot
{
	public:

	Amunicja ();
	virtual ~Amunicja ();

	int obrazenia;

	int zawartosc;
};

class Bron :public Przedmiot
{
	public:

	Bron ();
	virtual ~Bron ();

	std::string rodzaj_broni;
	int obrazenia;
};

class Bron_biala :public Bron
{
	public:

	Bron_biala ();
	virtual ~Bron_biala ();
};

class Bron_dystansowa :public Bron
{
	public:

	Bron_dystansowa ();
	virtual ~Bron_dystansowa ();

	bool czy_jest_amunicja ( std::string _amunicja );

	int zawartosc;
	int pojemnosc;

	Amunicja* wsk_amunicja;
	std::vector<std::string> mozliwa_amunicja;
};

class Bron_miotana :public Bron
{
	public:

	Bron_miotana ();
	virtual ~Bron_miotana ();

	int zawartosc;
};

class Zbroja :public Przedmiot
{
	public:

	Zbroja ();
	virtual ~Zbroja ();

	int ochrona;
};