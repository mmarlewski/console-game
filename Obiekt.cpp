#include "Obiekt.h"

#include "PRZED_Zbroja.h"

Obiekt::Obiekt ()
{
	amunicja = nullptr;
	bron = nullptr;
	bron_biala = nullptr;
	bron_dystansowa = nullptr;
	bron_miotana = nullptr;
	zbroja = nullptr;
}

Obiekt::~Obiekt ()
{
	for ( int i = 0; i < ekwipunek.size (); i++ )
	{
		delete ekwipunek[i];
	}
}

void Obiekt::przyjmij_obrazenia ( int _obrazenia )
{
	if ( czy_hp )
	{
		if ( zbroja != nullptr )
		{
			if ( _obrazenia - zbroja->ochrona > 0 )
			{
				hp_teraz -= ( _obrazenia - zbroja->ochrona );
			}
		}
		else
		{
			hp_teraz -= _obrazenia;
		}

		if ( hp_teraz < 0 )
		{
			hp_teraz = 0;
		}
	}
}