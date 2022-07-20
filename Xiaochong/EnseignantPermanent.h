//#pragma once
#ifndef ENSEIGNANTPERMANENT_H
#define ENSEIGNANTPERMANENT_H
#include "Personnel.h"
#include<string>
class EnseignantPermanent :	public Personnel
{

public:
	EnseignantPermanent(string nom, string prenom, float salaire, int Grade, float PrimeMensuelle, string Bureau);
	
	float calculSalaire();
	void permanant_affiche();
protected:
	string Bureau;
	int Grade;
	float PrimeMensuelle;
};

#endif