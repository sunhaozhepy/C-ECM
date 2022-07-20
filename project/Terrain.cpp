#include <iostream>
#include "Terrain.h"

Terrain::Terrain(string nom, int loyer, int prixAchat): Propriete::Propriete(nom, loyer, prixAchat) { cout << "Nouvelle case terrain." << endl; }