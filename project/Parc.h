#pragma once
#include "Case.h"
#include "Pion.h"
#include "Joueur.h"

class Parc :
    public Case
{
public:
    Parc(string nom);
    void arreterSur(Pion* pion);
};

