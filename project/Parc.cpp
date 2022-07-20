#include <iostream>
#include "Parc.h"

Parc::Parc(string nom) : Case(nom) { cout << "Nouvelle case parc." << endl; }

void Parc::arreterSur(Pion* pion) {}
