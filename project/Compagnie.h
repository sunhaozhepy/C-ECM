#pragma once
#include "Propriete.h"

class Compagnie :
    public Propriete
{
    public:
        Compagnie(string nom, int loyer, int prixAchat);
};

