//#include "stdafx.h"
#include "ListePersonnel.h"
#include<string>
#include<iostream>
using namespace std;
ListePersonnel::ListePersonnel(){
	tab = new Personnel*[100]();
	nb = 0;
	taille = 4;
}
void ListePersonnel::ajout_Personnel(Personnel*ptPersonnel){
	if (nb<taille){
		tab[nb] = ptPersonnel;
		nb++;
	}
	else{
		doubleTableau(tab);
	}

}
void ListePersonnel::afficherSalaires(){
	for (int i = 0; i<nb; i++){
		cout << "nom:  " << tab[i]->nom << "        salaire: " << tab[i]->salaire<< endl;
	}
}
Personnel** ListePersonnel::doubleTableau(Personnel**&tabl){
	Personnel**tmp = new Personnel*[2 * taille];
	for (int i = 0; i<=taille; i++){
		tmp[i] = tabl[i];
	}
	delete[] tab;
	tabl = tmp;
	taille = 2 * taille;
	return tmp;
}