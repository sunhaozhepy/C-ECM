#include "Case.h"
#include <iostream>

Case::Case() {}

Case::Case(string nom)
{
	this->nom = nom;
	cout << "Nouvelle case." << endl;
}

string Case::getNom()
{
	return this->nom;
}

void Case::setNom(string nom)
{
	this->nom = nom;
}

void Case::arreterSur() {}

bool Case::operator ==(const Case& case_autre)
{
	if (this->nom == case_autre.nom)
	{
		return true;
	}
	return false;
}