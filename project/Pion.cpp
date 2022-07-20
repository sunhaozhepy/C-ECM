#include <iostream>
#include "Pion.h"

Pion::Pion() {}

Pion::Pion(Joueur* joueur, Case* position)
{
	this->joueur = joueur;
	this->position = position;
	cout << "Nouveau pion initi¨¦." << endl;
}

Joueur* Pion::getJoueur()
{
	return this->joueur;
}

void Pion::setJoueur(Joueur* joueur)
{
	this->joueur = joueur;
}

Case* Pion::getPosition()
{
	return this->position;
}

void Pion::setPosition(Case* position)
{
	this->position = position;
}

bool Pion::getInPrison()
{
	return inPrison;
}

void Pion::setInPrison(bool inPrison)
{
	this->inPrison = inPrison;
}