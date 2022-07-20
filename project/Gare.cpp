#include <iostream>
#include "Gare.h"

Gare::Gare(string nom, int loyer, int prixAchat): Propriete::Propriete(nom, loyer, prixAchat) { cout << "Nouvelle case gare." << endl; }