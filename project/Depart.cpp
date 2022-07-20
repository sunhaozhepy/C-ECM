#include <iostream>
#include "Depart.h"

Depart::Depart(string nom) : Case(nom) { cout << "Nouvelle case départ." << endl; }

void Depart::arreterSur(Pion* pion) {}
