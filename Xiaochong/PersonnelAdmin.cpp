//#include "stdafx.h"
#include "PersonnelAdmin.h"
#include<string>
#include<iostream>
using namespace std;
PersonnelAdmin::PersonnelAdmin(string nom, string prenom, float sal, float t, int heuressup) :Personnel(nom, prenom, sal){
	heuresSup = heuressup;
	taux=t;
}
float PersonnelAdmin::calculSalaire(){
	salaire = salaire + taux*heuresSup;
	return salaire;
}
void PersonnelAdmin::admin_affiche(){
	//this->affiche();
	this->calculSalaire();
	cout << "nom: " << nom << endl;
	cout << "prenom: " << prenom << endl;
	cout << "taux: " << taux << endl;
	cout << "heuresSup: " << heuresSup << endl;
	cout << "salaire:  " << salaire << endl;
}