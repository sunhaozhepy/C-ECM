#include <iostream>
#include "Gobelet.h"
using namespace std;

Gobelet::Gobelet(int nbDe)
{
	this->nbDe = nbDe;
	cout << "Nouveau gobelet créé." << endl;
}

int Gobelet::getvaleur()
{
	int counter = 0;
	for (int i = 0; i < this->nbDe; i++)
	{
		counter += this->de->getvaleur();
	}
	return counter;
}

De* Gobelet::getDe()
{
	return this->de;
}

void Gobelet::setDe(int nbFaces)
{
	De autre_de(nbFaces);
	this->de = &autre_de;
}

int Gobelet::getNbDe()
{
	return this->nbDe;
}

void Gobelet::setNbDe(int nbDe)
{
	this->nbDe = nbDe;
}