#include <iostream>
#include "Propriete.h"

Propriete::Propriete() {}

Propriete::Propriete(string nom, int loyer, int prixAchat)
{
	this->nom = nom;
	this->loyer = loyer;
	this->prixAchat = prixAchat;
	cout << "Nouvelle case propri¨¦t¨¦." << endl;
}

int Propriete::getLoyer()
{
	return this->loyer;
}

void Propriete::setLoyer(int loyer)
{
	this->loyer = loyer;
}

int Propriete::getPrixAchat()
{
	return this->prixAchat;
}

void Propriete::setPrixAchat(int prixAchat)
{
	this->prixAchat = prixAchat;
}

Joueur* Propriete::getProprietaire()
{
	return this->proprietaire;
}

void Propriete::setProprietaire(Joueur* joueur)
{
	this->proprietaire = joueur;
}

void Propriete::arreterSur(Pion* pion)
{
	if (this->proprietaire == NULL)
	{
		int acheter;
		cout << "Vous voulez acheter cette propri¨¦t¨¦? Tapez 1 pour oui, 2 pour non : ";
		cin >> acheter;
		switch (acheter)
		{
			case 1:
			{
				int solde = pion->getJoueur()->getSolde();
				if (solde < this->prixAchat)
				{
					cout << "Votre solde n'est pas suffisant. L'achat n'a pas ¨¦t¨¦ effectu¨¦." << endl;
				}
				else
				{
					this->proprietaire = pion->getJoueur();
					pion->getJoueur()->setSolde(solde - this->prixAchat);
				}
				break;
			}
			case 2:
			{
				break;
			}
			default:
			{
				cout << "Entr¨¦e invalide. L'achat n'a pas ¨¦t¨¦ effectu¨¦." << endl;
				break;
			}
		}
	}
	else 
	{
		int solde = pion->getJoueur()->getSolde();
		pion->getJoueur()->setSolde(solde - this->loyer);
		if (pion->getJoueur()->getSolde() < 0)
		{
			pion->getJoueur()->setRuine(true);
		}
		int solde_autre = this->getProprietaire()->getSolde();
		this->getProprietaire()->setSolde(solde_autre + this->loyer);
	}
}