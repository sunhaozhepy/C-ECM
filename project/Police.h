#pragma once
#include "Case.h"
#include "Pion.h"
#include "Joueur.h"
#include "Prison.h"

class Police :
    public Case
{
public:
    Police(string nom);
    void arreterSur(Pion* pion, Prison* prison);
};

