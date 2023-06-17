#include "Okno.h"

Okno::Okno ()
{
	//
}

Okno::~Okno ()
{
	//
}

void Okno::zaktualizuj ( bool _myszka, bool _myszka_l, bool _myszka_p )
{
	if ( myszka_weszla ) myszka_weszla = 0;
	if ( myszka_wyszla ) myszka_wyszla = 0;
	if ( !myszka_obecna && _myszka ) myszka_weszla = 1;
	if ( myszka_obecna && !_myszka ) myszka_wyszla = 1;
	if ( _myszka ) myszka_obecna = 1;
	if ( !_myszka ) myszka_obecna = 0;

	if ( _myszka )
	{
		if ( l_klikniety ) l_klikniety = 0;
		if ( l_wcisniety && !_myszka_l ) l_klikniety = 1;
		if ( _myszka_l ) l_wcisniety = 1;
		if ( !_myszka_l ) l_wcisniety = 0;

		if ( p_klikniety ) p_klikniety = 0;
		if ( p_wcisniety && !_myszka_p ) p_klikniety = 1;
		if ( _myszka_p ) p_wcisniety = 1;
		if ( !_myszka_p ) p_wcisniety = 0;
	}
	else
	{
		l_wcisniety = 0;
		l_klikniety = 0;
		p_wcisniety = 0;
		p_klikniety = 0;
	}
}

void Okno::aktywuj ()
{
	czy_aktywne = 1;

	myszka_obecna = 0;
	myszka_weszla = 0;
	myszka_wyszla = 0;

	l_wcisniety = 0;
	l_klikniety = 0;
	p_wcisniety = 0;
	p_klikniety = 0;
}

void Okno::deaktywuj ()
{
	czy_aktywne = 0;
}