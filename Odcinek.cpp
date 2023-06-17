#include "Odcinek.h"

#include "Punkt.h"

Odcinek::Odcinek ()
{
	dlugosc = 0;
	zbior_punktow = nullptr;
}

Odcinek::~Odcinek ()
{
	if ( zbior_punktow != nullptr )
	{
		delete[] zbior_punktow;
	}
}