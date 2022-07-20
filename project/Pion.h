#pragma once
#include "Case.h"

class Joueur;

class Pion
{
public:
	Pion();
	Pion(Joueur* joueur, Case* position);
	Joueur* getJoueur();
	void setJoueur(Joueur* joueur);
	Case* getPosition();
	void setPosition(Case* position);
	bool getInPrison();
	void setInPrison(bool inPrison);

private:
	Joueur* joueur;
	Case* position;
	bool inPrison = false;

};

