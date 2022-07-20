#include <iostream>
#include "Compagnie.h"

Compagnie::Compagnie(string nom, int loyer, int prixAchat): Propriete::Propriete(nom, loyer, prixAchat) { cout << "Nouvelle case compagnie." << endl; }