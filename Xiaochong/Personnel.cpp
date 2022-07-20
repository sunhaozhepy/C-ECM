//#include "stdafx.h"
#include "Personnel.h"
#include<string>
#include<iostream>
using namespace std;
Personnel::Personnel(string nom, string prenom, float sal) :Personne(nom, prenom){

	salaire = sal;
}
float Personnel::calculSalaire(){
	return salaire;
}
void Personnel::set_salaire(float salaire){
	salaire = salaire;
}

void Personnel::P_affiche(){
	this->affiche();
	cout << " salaire:  " << salaire << endl;
}

