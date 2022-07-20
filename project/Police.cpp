#include <iostream>
#include "Police.h"

Police::Police(string nom) : Case(nom) { cout << "Nouvelle case police." << endl; }

void Police::arreterSur(Pion* pion, Prison* prison)
{
	pion->setPosition(prison);
	pion->setInPrison(true);
}