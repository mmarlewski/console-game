#include "Konsola.h"

#include "Obraz.h"
#include "Znak.h"

Konsola::Konsola ( int _dlugosc_konsoli, int _szerokosc_konsoli )
{
	dlugosc_konsoli = _dlugosc_konsoli;
	szerokosc_konsoli = _szerokosc_konsoli;

	bufor = new CHAR_INFO[dlugosc_konsoli * szerokosc_konsoli];

	screen_buffer = GetStdHandle ( STD_OUTPUT_HANDLE );
	input_buffer = GetStdHandle ( STD_INPUT_HANDLE );

	SMALL_RECT wymiary_okno = { 0, 0, szerokosc_konsoli, dlugosc_konsoli, };
	SetConsoleWindowInfo ( screen_buffer, true, &wymiary_okno );

	COORD wymiary_bufor = { szerokosc_konsoli, dlugosc_konsoli };
	SetConsoleScreenBufferSize ( screen_buffer, wymiary_bufor );

	CONSOLE_FONT_INFOEX czcionka = { sizeof ( CONSOLE_FONT_INFOEX ), 0, { 10, 15 }, FF_DONTCARE, 400, L"Consolas" };
	SetCurrentConsoleFontEx ( screen_buffer, true, &czcionka );

	GetConsoleMode ( input_buffer, &stary_stan_konsoli );
	nowy_stan_konsoli = ( ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS );
	SetConsoleMode ( input_buffer, nowy_stan_konsoli );

	wymiary = { 0, 0, SHORT ( szerokosc_konsoli ), SHORT ( dlugosc_konsoli ) };
}

Konsola::~Konsola ()
{
	delete[] bufor;

	SetConsoleMode ( input_buffer, stary_stan_konsoli );
}

void Konsola::zaktualizuj_konsole ()
{
	for ( int i = 0; i < dlugosc_konsoli * szerokosc_konsoli; i++ )
	{
		bufor[i].Char.UnicodeChar = L'@';
		bufor[i].Attributes = ( FOREGROUND_GREEN );
	}

	WORD kolor_przod;
	WORD kolor_tyl;

	for ( int i = 0; i < obraz->dlugosc && i < dlugosc_konsoli; i++ )
	{
		for ( int j = 0; j < obraz->szerokosc && j < szerokosc_konsoli; j++ )
		{
			bufor[i * ( szerokosc_konsoli ) + j].Char.UnicodeChar = obraz->obraz[i][j].znak;

			switch ( obraz->obraz[i][j].kolor_przod )
			{
				case kolor::czarny: kolor_przod = ( 0 ); break;
				case kolor::ciemny_szary: kolor_przod = ( FOREGROUND_INTENSITY ); break;
				case kolor::jasny_szary: kolor_przod = ( FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE ); break;
				case kolor::bialy: kolor_przod = ( FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY ); break;
				case kolor::ciemny_niebieski: kolor_przod = ( FOREGROUND_BLUE ); break;
				case kolor::jasny_niebieski: kolor_przod = ( FOREGROUND_BLUE | FOREGROUND_INTENSITY ); break;
				case kolor::ciemny_zielony: kolor_przod = ( FOREGROUND_GREEN ); break;
				case kolor::jasny_zielony: kolor_przod = ( FOREGROUND_GREEN | FOREGROUND_INTENSITY ); break;
				case kolor::ciemny_morski: kolor_przod = ( FOREGROUND_GREEN | FOREGROUND_BLUE ); break;
				case kolor::jasny_morski: kolor_przod = ( FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY ); break;
				case kolor::ciemny_czerwony: kolor_przod = ( FOREGROUND_RED ); break;
				case kolor::jasny_czerwony: kolor_przod = ( FOREGROUND_RED | FOREGROUND_INTENSITY ); break;
				case kolor::ciemny_rozowy: kolor_przod = ( FOREGROUND_RED | FOREGROUND_BLUE ); break;
				case kolor::jasny_rozowy: kolor_przod = ( FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY ); break;
				case kolor::ciemny_zolty: kolor_przod = ( FOREGROUND_RED | FOREGROUND_GREEN ); break;
				case kolor::jasny_zolty: kolor_przod = ( FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY ); break;
			}

			switch ( obraz->obraz[i][j].kolor_tyl )
			{
				case kolor::czarny: kolor_tyl = ( 0 ); break;
				case kolor::ciemny_szary: kolor_tyl = ( BACKGROUND_INTENSITY ); break;
				case kolor::jasny_szary: kolor_tyl = ( BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE ); break;
				case kolor::bialy: kolor_tyl = ( BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY ); break;
				case kolor::ciemny_niebieski: kolor_tyl = ( BACKGROUND_BLUE ); break;
				case kolor::jasny_niebieski: kolor_tyl = ( BACKGROUND_BLUE | BACKGROUND_INTENSITY ); break;
				case kolor::ciemny_zielony: kolor_tyl = ( BACKGROUND_GREEN ); break;
				case kolor::jasny_zielony: kolor_tyl = ( BACKGROUND_GREEN | BACKGROUND_INTENSITY ); break;
				case kolor::ciemny_morski: kolor_tyl = ( BACKGROUND_GREEN | BACKGROUND_BLUE ); break;
				case kolor::jasny_morski: kolor_tyl = ( BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY ); break;
				case kolor::ciemny_czerwony: kolor_tyl = ( BACKGROUND_RED ); break;
				case kolor::jasny_czerwony: kolor_tyl = ( BACKGROUND_RED | BACKGROUND_INTENSITY ); break;
				case kolor::ciemny_rozowy: kolor_tyl = ( BACKGROUND_RED | BACKGROUND_BLUE ); break;
				case kolor::jasny_rozowy: kolor_tyl = ( BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY ); break;
				case kolor::ciemny_zolty: kolor_tyl = ( BACKGROUND_RED | BACKGROUND_GREEN ); break;
				case kolor::jasny_zolty: kolor_tyl = ( BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY ); break;
			}

			bufor[i * ( szerokosc_konsoli ) + j].Attributes = ( kolor_przod | kolor_tyl );
		}
	}

	WriteConsoleOutputW ( screen_buffer, bufor, { SHORT ( szerokosc_konsoli ), SHORT ( dlugosc_konsoli ) }, { 0, 0 }, &wymiary );
}

void Konsola::zmien_tytul_konsoli ( std::string _tytul )
{
	SetConsoleTitleA ( _tytul.c_str () );
}

void Konsola::pobierz_dane_myszki ()
{
	INPUT_RECORD* tablica_zdarzen;
	DWORD ile_zdarzen;

	GetNumberOfConsoleInputEvents ( input_buffer, &ile_zdarzen );

	tablica_zdarzen = new INPUT_RECORD[ile_zdarzen];

	if ( ile_zdarzen > 0 )
	{
		ReadConsoleInput ( input_buffer, tablica_zdarzen, ile_zdarzen, &ile_zdarzen );
	}

	if ( ile_zdarzen > 0 && tablica_zdarzen[0].EventType == MOUSE_EVENT )
	{
		myszka_y = tablica_zdarzen[0].Event.MouseEvent.dwMousePosition.Y;
		myszka_x = tablica_zdarzen[0].Event.MouseEvent.dwMousePosition.X;
	}

	delete[] tablica_zdarzen;

	myszka_l = ( GetAsyncKeyState ( VK_LBUTTON ) & 0x8000 );

	myszka_p = ( GetAsyncKeyState ( VK_RBUTTON ) & 0x8000 );
}

bool Konsola::zwroc_czy_esc ()
{
	return ( GetAsyncKeyState ( VK_ESCAPE ) & 0x8000 );
}