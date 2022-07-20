#include <iostream>
#include "De.h"
using namespace std;

De::De(int nbFaces)
{
	this->nbFaces = nbFaces;
	cout << "Nouveau d¨¦ cr¨¦¨¦." << endl;
}

int De::getnbFaces()
{
	return this->nbFaces;
}

void De::setnbFaces(int nbFaces)
{
	this->nbFaces = nbFaces;
}

int De::getvaleur()
{
	int valeur = rand() % 6 + 1;
	return valeur;
}
