//#include "stdafx.h"
#include "EnseignantVacataire.h"
#include<string>
#include<iostream>

using namespace std;
EnseignantVacataire::EnseignantVacataire(string nom, string prenom, float salaire, string c, float t, int nbHeures = 0)
	:Personnel(nom, prenom, salaire){
	casier = c;
	taux = t;
	nbreHeures = nbHeures;
}
float EnseignantVacataire::calculSalaire(){
	salaire = taux*nbreHeures;
	return salaire;
}

void EnseignantVacataire::affiche(){
	this->calculSalaire();
	cout <<"nom:  " << nom << endl;
	cout <<"prenom:  " << prenom << endl;
	cout << "salaire:  " << salaire << endl;
}