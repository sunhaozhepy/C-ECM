#include <iostream>
#include "Jeu.h"
using namespace std;

Jeu::Jeu(int nb_joueurs, Joueur* joueurs, Case* plateau)
{
    this->plateau = plateau;
    this->joueurs = joueurs;
    this->nb_joueurs = nb_joueurs;
}

Case* Jeu::getPlateau()
{
	return this->plateau;
}

void Jeu::setPlateau(Case* plateau)
{
	this->plateau = plateau;
}

int Jeu::getNbjoueurs()
{
    return this->nb_joueurs;
}

void Jeu::setNbjoueurs(int nb_joueurs)
{
    this->nb_joueurs = nb_joueurs;
}

Joueur* Jeu::getJoueurs()
{
    return this->joueurs;
}

void Jeu::setJoueurs(Joueur* joueurs)
{
    this->joueurs = joueurs;
}

void Jeu::commencerLaPartie()
{
    Gobelet gobelet(2);
	gobelet.setDe(6);
    De de_depart(this->nb_joueurs);
    int joueur_actuel = de_depart.getvaleur(); // Premier joueur
    int i = 0; // compteur de tour
    int nb_tours = 10;
    while (i < nb_tours * this->nb_joueurs)
    {
        system("pause");
        this->joueurs[joueur_actuel].jouer(this->plateau, &gobelet);
        joueur_actuel++;
        joueur_actuel = joueur_actuel % nb_joueurs;
        i++;
    };	
    cout << "Fin de partie." << endl;
    system("pause");
}