//#pragma once
#ifndef Personnel_H
#define Personnel_H
#include "Personne.h"
#include<string>
class Personnel :	public Personne
{
public:
	Personnel(string nom, string prenom, float salaire=0);
	virtual float calculSalaire()=0;
	void set_salaire(float salaire);
	void P_affiche();
public:
	float salaire;
};
#endif
