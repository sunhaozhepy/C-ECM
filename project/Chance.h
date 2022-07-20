#pragma once
#include "Case.h"
#include "Pion.h"
#include "Joueur.h"

class Chance :
    public Case
{
public:
    Chance(string nom);
    void arreterSur(Pion* pion);
};

