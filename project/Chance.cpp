#include <iostream>
#include "Chance.h"

Chance::Chance(string nom) : Case(nom) { cout << "Nouvelle case chance." << endl; }

void Chance::arreterSur(Pion* pion)
{
	int montant = pion->getJoueur()->getSolde();
	pion->getJoueur()->setSolde(montant + 1000); //ajouter 1000 euros
}