#pragma once

#include <iostream>
#include <vector>

class Obraz;
class Mapa;
class Obiekt;

class Umiejetnosc
{
	public:

	Umiejetnosc ();
	virtual ~Umiejetnosc ();

	virtual void ustal_oznaczenie_wybor () = 0;
	virtual void ustal_oznaczenie_efekt () = 0;
	virtual void wykonaj_umiejetnosc () = 0;
	virtual void ustal_animacje () = 0;
	void wyczysc_animacje ();

	std::string nazwa;
	int koszt;
	std::vector<Obraz*> obrazy_animacji;

	Mapa* mapa;
	Obiekt* obiekt;
	int y_obiekt;
	int x_obiekt;
	int y_cel;
	int x_cel;
};

