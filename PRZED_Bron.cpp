#include "PRZED_Bron.h"

Patyk::Patyk()
{
	klasa = "patyk";

	obrazenia = 1;
};

Slaby_miecz::Slaby_miecz()
{
	klasa = "slaby miecz";

	obrazenia = 3;
};

Mocny_miecz::Mocny_miecz()
{
	klasa = "mocny miecz";

	obrazenia = 5;
};

Slaba_wlocznia::Slaba_wlocznia()
{
	klasa = "slaba wlocznia";

	obrazenia = 3;
}

Mocna_wlocznia::Mocna_wlocznia()
{
	klasa = "mocna wlocznia";

	obrazenia = 5;
}

/////

Proca::Proca ()
{
	klasa = "proca";

	obrazenia = 1; pojemnosc = 5;

	mozliwa_amunicja.push_back ( "male kamienie" );
}

Luk::Luk()
{
	klasa = "luk";

	obrazenia = 3; pojemnosc = 3;

	mozliwa_amunicja.push_back ( "slabe strzaly" );
	mozliwa_amunicja.push_back ( "mocne strzaly" );
}

Kusza::Kusza()
{
	klasa = "kusza";

	obrazenia = 5; pojemnosc = 1;

	mozliwa_amunicja.push_back ( "mocne strzaly" );
}

/////

Kamienie::Kamienie ()
{
	klasa = "kamienie";

	obrazenia = 1; zawartosc = 5;
}

Noze_do_rzucania::Noze_do_rzucania ()
{
	klasa = "noze do rzucania";

	obrazenia = 5; zawartosc = 3;
}

Granat::Granat ()
{
	klasa = "granat";

	obrazenia = 10; zawartosc = 3;
}