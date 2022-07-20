//#include "stdafx.h"
#include "EnseignantPermanent.h"

#include<string>
#include<iostream>

using namespace std;
EnseignantPermanent::EnseignantPermanent(string nom, string prenom, float sal, int G, float Mensuelle, string Bu="")
:Personnel(nom, prenom, sal){
	Grade = G;
	PrimeMensuelle = Mensuelle;
	Bureau = Bu;
}


float EnseignantPermanent::calculSalaire(){
	salaire = salaire + Grade*PrimeMensuelle / 100;
	return salaire;
}
void EnseignantPermanent::permanant_affiche(){
	this->calculSalaire();
	cout << "nom:  " << nom << endl;
	cout << "prenom:  " << prenom << endl;
	cout << "salaire:  " << salaire << endl;
}
