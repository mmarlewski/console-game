#include "Mapa.h"

#include "Pole.h"
#include "Obiekt.h"
#include "Punkt.h"
#include "Odcinek.h"
#include "Okrag.h"
#include "Obraz.h"
#include "Znak.h"

Mapa::Mapa ( int _dlugosc_mapy, int _szerokosc_mapy )
{
	dlugosc_mapy = _dlugosc_mapy;
	szerokosc_mapy = _szerokosc_mapy;

	mapa = new Pole* [dlugosc_mapy];

	for ( int i = 0; i < dlugosc_mapy; i++ )
	{
		mapa[i] = new Pole[szerokosc_mapy];
	}

	obraz_mapy = new Obraz ( dlugosc_mapy, szerokosc_mapy );

	kursor_y = 0;
	kursor_x = 0;
}

Mapa::~Mapa ()
{
	for ( int i = 0; i < dlugosc_mapy; i++ )
	{
		delete[] mapa[i];
	}

	delete[] mapa;

	delete obraz_mapy;
}

void Mapa::przesun_kursor_na_srodek ()
{
	kursor_y = dlugosc_mapy / 2;
	kursor_x = szerokosc_mapy / 2;
}

Pole* Mapa::zwroc_pole_pod_kursorem ()
{
	return &mapa[kursor_y][kursor_x];
}

Pole* Mapa::zwroc_pole ( int _y, int _x )
{
	if ( _y < 0 ) _y = 0;
	if ( _y > dlugosc_mapy - 1 ) _y = dlugosc_mapy - 1;
	if ( _x < 0 ) _x = 0;
	if ( _x > szerokosc_mapy - 1 ) _x = szerokosc_mapy - 1;

	return &mapa[_y][_x];
}

void Mapa::wyczysc_obraz_mapy ()
{
	for ( int i = 0; i < dlugosc_mapy; i++ )
	{
		for ( int j = 0; j < szerokosc_mapy; j++ )
		{
			obraz_mapy->obraz[i][j].znak = L' ';
			obraz_mapy->obraz[i][j].kolor_przod = kolor::bialy;
			obraz_mapy->obraz[i][j].kolor_tyl = kolor::czarny;
			obraz_mapy->obraz[i][j].przezroczysty = false;
		}
	}
}

void Mapa::wyczysc_oznaczenie_wybor ()
{
	for ( int i = 0; i < dlugosc_mapy; i++ )
	{
		for ( int j = 0; j < szerokosc_mapy; j++ )
		{
			mapa[i][j].oznaczenie_wybor = 0;
		}
	}
}

void Mapa::wyczysc_oznaczenie_efekt ()
{
	for ( int i = 0; i < dlugosc_mapy; i++ )
	{
		for ( int j = 0; j < szerokosc_mapy; j++ )
		{
			mapa[i][j].oznaczenie_efekt = 0;
		}
	}
}

void Mapa::dolacz_obiekty_do_obrazu_mapy ()
{
	for ( int i = 0; i < dlugosc_mapy; i++ )
	{
		for ( int j = 0; j < szerokosc_mapy; j++ )
		{
			if ( mapa[i][j].obiekt != nullptr )
			{
				obraz_mapy->obraz[i][j].znak = mapa[i][j].obiekt->symbol;
			}
		}
	}
}

void Mapa::dolacz_oznaczenie_wybor_do_obrazu_mapy ()
{
	for ( int i = 0; i < dlugosc_mapy; i++ )
	{
		for ( int j = 0; j < szerokosc_mapy; j++ )
		{
			if ( mapa[i][j].oznaczenie_wybor )
			{
				obraz_mapy->obraz[i][j].kolor_tyl = kolor::ciemny_szary;
			}
		}
	}
}

void Mapa::dolacz_oznaczenie_efekt_do_obrazu_mapy ()
{
	for ( int i = 0; i < dlugosc_mapy; i++ )
	{
		for ( int j = 0; j < szerokosc_mapy; j++ )
		{
			if ( mapa[i][j].oznaczenie_efekt )
			{
				obraz_mapy->obraz[i][j].kolor_tyl = kolor::jasny_szary;
			}
		}
	}
}

void Mapa::dolacz_kursor_do_obrazu_mapy ()
{
	for ( int i = 0; i < dlugosc_mapy; i++ )
	{
		for ( int j = 0; j < szerokosc_mapy; j++ )
		{
			if ( i == kursor_y && j == kursor_x )
			{
				obraz_mapy->obraz[i][j].kolor_przod = kolor::czarny;
				obraz_mapy->obraz[i][j].kolor_tyl = kolor::bialy;
			}
		}
	}
}

void Mapa::ustal_odleglosci ( int _y_start, int _x_start )
{
	for ( int i = 0; i < dlugosc_mapy; i++ )
	{
		for ( int j = 0; j < szerokosc_mapy; j++ )
		{
			mapa[i][j].odleglosc = 100;
		}
	}

	mapa[_y_start][_x_start].odleglosc = 0;

	for ( int k = 0; k < 20; k++ )
	{
		for ( int i = 0; i < dlugosc_mapy; i++ )
		{
			for ( int j = 0; j < szerokosc_mapy; j++ )
			{
				if ( mapa[i][j].odleglosc == k )
				{
					if ( i > 0 && j > 0 )
					{
						if ( mapa[i - 1][j - 1].obiekt == nullptr && mapa[i - 1][j - 1].odleglosc == 100 )
						{
							mapa[i - 1][j - 1].odleglosc = k + 1;
						}
					}

					if ( i > 0 )
					{
						if ( mapa[i - 1][j].obiekt == nullptr && mapa[i - 1][j].odleglosc == 100 )
						{
							mapa[i - 1][j].odleglosc = k + 1;
						}
					}

					if ( i > 0 && j < szerokosc_mapy - 1 )
					{
						if ( mapa[i - 1][j + 1].obiekt == nullptr && mapa[i - 1][j + 1].odleglosc == 100 )
						{
							mapa[i - 1][j + 1].odleglosc = k + 1;
						}
					}

					if ( j < szerokosc_mapy - 1 )
					{
						if ( mapa[i][j + 1].obiekt == nullptr && mapa[i][j + 1].odleglosc == 100 )
						{
							mapa[i][j + 1].odleglosc = k + 1;
						}
					}

					if ( i < dlugosc_mapy - 1 && j < szerokosc_mapy - 1 )
					{
						if ( mapa[i + 1][j + 1].obiekt == nullptr && mapa[i + 1][j + 1].odleglosc == 100 )
						{
							mapa[i + 1][j + 1].odleglosc = k + 1;
						}
					}

					if ( i < dlugosc_mapy - 1 )
					{
						if ( mapa[i + 1][j].obiekt == nullptr && mapa[i + 1][j].odleglosc == 100 )
						{
							mapa[i + 1][j].odleglosc = k + 1;
						}
					}

					if ( i < dlugosc_mapy - 1 && j > 0 )
					{
						if ( mapa[i + 1][j - 1].obiekt == nullptr && mapa[i + 1][j - 1].odleglosc == 100 )
						{
							mapa[i + 1][j - 1].odleglosc = k + 1;
						}
					}

					if ( j > 0 )
					{
						if ( mapa[i][j - 1].obiekt == nullptr && mapa[i][j - 1].odleglosc == 100 )
						{
							mapa[i][j - 1].odleglosc = k + 1;
						}
					}
				}
			}
		}
	}
}

void Mapa::wyznacz_punkt ( Punkt* _punkt, int _wsp_y, int _wsp_x )
{
	_punkt->wsp_y = _wsp_y;
	_punkt->wsp_x = _wsp_x;

	if ( 0 <= _punkt->wsp_y && _punkt->wsp_y <= dlugosc_mapy - 1 && 0 <= _punkt->wsp_x && _punkt->wsp_x <= szerokosc_mapy - 1 )
	{
		_punkt->wsp_b = true;
	}
	else
	{
		_punkt->wsp_b = false;
	}
}

void Mapa::wyznacz_odcinek ( Odcinek* _odcinek, int _pocz_y, int _pocz_x, int _kon_y, int _kon_x )
{
	if ( _odcinek->zbior_punktow != nullptr )
	{
		delete[] _odcinek->zbior_punktow;
	}

	_odcinek->dlugosc = max ( abs ( _pocz_y - _kon_y ), abs ( _pocz_x - _kon_x ) ) + 1;

	_odcinek->zbior_punktow = new Punkt[_odcinek->dlugosc];

	double t;

	for ( int i = 0; i < _odcinek->dlugosc; i++ )
	{
		t = i / double ( _odcinek->dlugosc - 1 );

		_odcinek->zbior_punktow[i].wsp_y = int ( round ( ( double ) _pocz_y + t * double ( _kon_y - _pocz_y ) ) );
		_odcinek->zbior_punktow[i].wsp_x = int ( round ( ( double ) _pocz_x + t * double ( _kon_x - _pocz_x ) ) );

		if ( 0 <= _odcinek->zbior_punktow[i].wsp_y && _odcinek->zbior_punktow[i].wsp_y <= dlugosc_mapy - 1 &&
			 0 <= _odcinek->zbior_punktow[i].wsp_x && _odcinek->zbior_punktow[i].wsp_x <= szerokosc_mapy - 1 )
		{
			_odcinek->zbior_punktow[i].wsp_b = true;
		}
		else
		{
			_odcinek->zbior_punktow[i].wsp_b = false;
		}
	}
}

void Mapa::wyznacz_okrag ( Okrag* _okrag, int _srodek_y, int _srodek_x, int _promien )
{
	if ( _okrag->zbior_punktow != nullptr )
	{
		delete[] _okrag->zbior_punktow;
	}

	_okrag->dlugosc = _promien * 8;

	_okrag->zbior_punktow = new Punkt[_okrag->dlugosc];

	int wsp_y = _srodek_y - _promien;
	int wsp_x = _srodek_x - _promien;

	for ( int i = 0; i < _promien * 2; i++ )
	{
		_okrag->zbior_punktow[_promien * 0 + i].wsp_y = wsp_y;
		_okrag->zbior_punktow[_promien * 0 + i].wsp_x = wsp_x;

		if ( 0 <= wsp_y && wsp_y <= dlugosc_mapy - 1 && 0 <= wsp_x && wsp_x <= szerokosc_mapy - 1 )
		{
			_okrag->zbior_punktow[_promien * 0 + i].wsp_b = true;
		}
		else
		{
			_okrag->zbior_punktow[_promien * 0 + i].wsp_b = false;
		}

		wsp_x++;
	}

	for ( int i = 0; i < _promien * 2; i++ )
	{
		_okrag->zbior_punktow[_promien * 2 + i].wsp_y = wsp_y;
		_okrag->zbior_punktow[_promien * 2 + i].wsp_x = wsp_x;

		if ( 0 <= wsp_y && wsp_y <= dlugosc_mapy - 1 && 0 <= wsp_x && wsp_x <= szerokosc_mapy - 1 )
		{
			_okrag->zbior_punktow[_promien * 2 + i].wsp_b = true;
		}
		else
		{
			_okrag->zbior_punktow[_promien * 2 + i].wsp_b = false;
		}

		wsp_y++;
	}

	for ( int i = 0; i < _promien * 2; i++ )
	{
		_okrag->zbior_punktow[_promien * 4 + i].wsp_y = wsp_y;
		_okrag->zbior_punktow[_promien * 4 + i].wsp_x = wsp_x;

		if ( 0 <= wsp_y && wsp_y <= dlugosc_mapy - 1 && 0 <= wsp_x && wsp_x <= szerokosc_mapy - 1 )
		{
			_okrag->zbior_punktow[_promien * 4 + i].wsp_b = true;
		}
		else
		{
			_okrag->zbior_punktow[_promien * 4 + i].wsp_b = false;
		}

		wsp_x--;
	}

	for ( int i = 0; i < _promien * 2; i++ )
	{
		_okrag->zbior_punktow[_promien * 6 + i].wsp_y = wsp_y;
		_okrag->zbior_punktow[_promien * 6 + i].wsp_x = wsp_x;

		if ( 0 <= wsp_y && wsp_y <= dlugosc_mapy - 1 && 0 <= wsp_x && wsp_x <= szerokosc_mapy - 1 )
		{
			_okrag->zbior_punktow[_promien * 6 + i].wsp_b = true;
		}
		else
		{
			_okrag->zbior_punktow[_promien * 6 + i].wsp_b = false;
		}

		wsp_y--;
	}
}