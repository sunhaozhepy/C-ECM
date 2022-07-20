//#pragma once
#ifndef LISTEPERSONNEL_H
#define    LISTEPERSONNEL_H
#include "Personnel.h"
#include<string>
class ListePersonnel
{
private:
	Personnel**tab;
	int nb;
	int taille;
public:
	ListePersonnel();
	void ajout_Personnel(Personnel*ptPersonnel);
	void afficherSalaires();
	Personnel**doubleTableau(Personnel**&tabl);
};
#endif
