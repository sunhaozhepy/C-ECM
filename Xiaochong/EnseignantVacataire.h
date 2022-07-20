//#pragma once
#ifndef ENSEIGNANTVACATAIRE_H
#define ENSEIGNANTVACATAIRE_H
#include "Personnel.h"
#include<string>
using namespace std;
class EnseignantVacataire :	public Personnel
{
public:

	EnseignantVacataire(string nom, string prenom, float salaire, string casier, float taux,int nbreHeures);
	float calculSalaire();

	void affiche();
protected:
	string casier;
	int nbreHeures;
	float taux;
};

#endif
