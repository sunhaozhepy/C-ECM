#pragma once
#include "De.h"

class Gobelet
{
public:
	Gobelet(int nbDe);
	int getvaleur();
	int getNbDe();
	void setNbDe(int nbDe);
	void setDe(int nbFaces);
	De* getDe();

private:
	int nbDe;
	De* de = NULL;
};

