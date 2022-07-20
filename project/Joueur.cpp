#include <iostream>
#include <algorithm>
#include "Joueur.h"

Joueur::Joueur() {}

Joueur::Joueur(string nom, Pion* pion, int solde)
{
	this->nom = nom;
	this->pion = pion;
	this->solde = solde;
	cout << "Nouveau joueur initié." << endl;
}

string Joueur::getNom()
{
	return this->nom;
}

void Joueur::setNom(string nom)
{
	this->nom = nom;
}

void Joueur::inputNom()
{
	string nom_joueur;
	cout << "Nom du joueur : ";
	cin >> nom_joueur;
	this->nom = nom_joueur;
}

Pion* Joueur::getPion()
{
	return this->pion;
}

void Joueur::setPion(Pion* pion)
{
	this->pion = pion;
}

int Joueur::getSolde()
{
	return this->solde;
}

void Joueur::setSolde(int solde)
{
	this->solde = solde;
}

bool Joueur::getRuine()
{
	return this->ruine;
}

void Joueur::setRuine(bool ruine)
{
	this->ruine = ruine;
}

void Joueur::jouer(Case* plateau, Gobelet* gobelet)
{
	if (this->ruine)
	{
		cout << "Ce joueur est en ruine. Il ne peut plus jouer." << endl;
	}
	else if (this->pion->getInPrison())
	{
		cout << "Ce joueur est en prison. Il en sera libéré après ce tour." << endl;
		this->pion->setInPrison(false);
	}
	else
	{
		int deplacement = gobelet->getvaleur();
		cout << "Le gobelet donne un " << deplacement << "." << endl;
		int x = distance(plateau, find(plateau, plateau + 40, *(this->pion->getPosition())));
		this->pion->setPosition(plateau + (x + deplacement) % 40);
		cout << "Vous êtes arrivé sur la case " << this->pion->getPosition()->getNom() << "." << endl;
		this->pion->getPosition()->arreterSur();
		if (x + deplacement > 40)
		{
			int montant = pion->getJoueur()->getSolde();
			pion->getJoueur()->setSolde(montant + 1000); //ajouter 1000 euros
		}
	}
}

