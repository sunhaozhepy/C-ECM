//#pragma once
#ifndef PERSONNELADMIN_H
#define PERSONNELADMIN_H
#include "Personnel.h"
#include<string>
class PersonnelAdmin :	public Personnel
{
public:
	PersonnelAdmin();
	PersonnelAdmin(string nom, string prenom, float salaire, float taux, int heuresSup = 0);
	float calculSalaire();
	void admin_affiche();
protected:
	int heuresSup;
	float taux;
};
#endif
