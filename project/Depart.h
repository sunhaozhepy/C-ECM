#pragma once
#include "Case.h"
#include "Pion.h"
#include "Joueur.h"

class Depart :
    public Case
{
public:
    Depart(string nom);
    void arreterSur(Pion* pion);
};

