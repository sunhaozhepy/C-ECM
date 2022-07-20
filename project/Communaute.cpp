#include <iostream>
#include "Communaute.h"

Communaute::Communaute(string nom) : Case(nom) { cout << "Nouvelle case communaut¨¦." << endl; }

void Communaute::arreterSur(Pion* pion)
{
	int montant = pion->getJoueur()->getSolde();
	pion->getJoueur()->setSolde(montant + 1000); //ajouter 1000 euros
}