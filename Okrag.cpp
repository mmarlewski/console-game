#include "Okrag.h"

#include "Punkt.h"

Okrag::Okrag ()
{
    dlugosc = 0;
    zbior_punktow = nullptr;
}

Okrag::~Okrag ()
{
    if ( zbior_punktow != nullptr )
    {
        delete[] zbior_punktow;
    }
}