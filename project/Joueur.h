#pragma once
#include <string>
#include "Gobelet.h"
#include "Pion.h"
#include "Police.h"
using namespace std;

class Pion;

class Joueur
{
public:
	Joueur();
	Joueur(string nom, Pion* pion, int solde);
	string getNom();
	void setNom(string nom);
	void inputNom();
	Pion* getPion();
	void setPion(Pion* pion);
	void jouer(Case* plateau, Gobelet* gobelet);
	int getSolde();
	void setSolde(int solde);
	bool getRuine();
	void setRuine(bool ruine);

private:
	string nom;
	Pion* pion;
	int solde;
	bool ruine = false;
};

