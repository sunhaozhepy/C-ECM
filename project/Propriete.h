#pragma once
#include "Case.h"
#include "Pion.h"
#include "Joueur.h"

class Propriete :
    public Case
{
public:
    Propriete();
    Propriete(string nom, int loyer, int prixAchat);
    int getLoyer();
    void setLoyer(int loyer);
    int getPrixAchat();
    void setPrixAchat(int prixAchat);
    Joueur* getProprietaire();
    void setProprietaire(Joueur* joueur);
    void arreterSur(Pion* pion);

protected:
    int loyer;
    int prixAchat;
    Joueur* proprietaire = NULL;
};

