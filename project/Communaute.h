#pragma once
#include "Case.h"
#include "Pion.h"
#include "Joueur.h"

class Communaute :
    public Case
{
public:
    Communaute(string nom);
    void arreterSur(Pion* pion);
};

