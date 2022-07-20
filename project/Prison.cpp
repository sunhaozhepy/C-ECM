#include <iostream>
#include "Prison.h"

Prison::Prison(string nom) : Case(nom) { cout << "Nouvelle case prison." << endl; }

void Prison::arreterSur(Pion* pion) {}
