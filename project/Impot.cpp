#include <iostream>
#include "Impot.h"

Impot::Impot(string nom) : Case(nom) { cout << "Nouvelle case impot." << endl; }

void Impot::arreterSur(Pion* pion)
{
	int montant = pion->getJoueur()->getSolde();
	pion->getJoueur()->setSolde(montant - 1000); //enlever 1000 euros
	if (pion->getJoueur()->getSolde() < 0)
	{
		pion->getJoueur()->setRuine(true);
	}
}