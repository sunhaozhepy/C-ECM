#pragma once
#include "Case.h"
#include "Pion.h"
#include "Joueur.h"

class Impot :
    public Case
{
public:
    Impot(string nom);
    void arreterSur(Pion* pion);
};
