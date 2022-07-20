#pragma once
#include "Joueur.h"
#include "De.h"

class Jeu
{
    private:
        int nb_joueurs;
        Joueur* joueurs;
        Case* plateau;
    public:
        Jeu(int nb_joueurs, Joueur* joueurs, Case* plateau);
        void commencerLaPartie();
        void setPlateau(Case* plateau);
        Case* getPlateau();
        void setNbjoueurs(int nb_joueurs);
        int getNbjoueurs();
        void setJoueurs(Joueur* joueurs);
        Joueur* getJoueurs();
};

