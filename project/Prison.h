#pragma once
#include "Case.h"
#include "Pion.h"
#include "Joueur.h"

class Prison :
    public Case
{
public:
    Prison(string nom);
    void arreterSur(Pion* pion);
};

