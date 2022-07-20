//#include "stdafx.h"
#include "Eleve.h"


#include<string>
#include<iostream>
using namespace std;
Eleve::Eleve(string nom, string prenom, string promotion, float  GPA, string gr_TD)
:Personne(nom, prenom), promotion(promotion), GPA(GPA), gr_TD(gr_TD){
	promotion = "";
	GPA = -1;
	gr_TD = "";
}

void Eleve::setpromotion(string pro){
	promotion = pro;
}
void Eleve::setgr(string gr){
	gr_TD = gr;
}
void Eleve::setGPA(float GPA){
	GPA = GPA;
}

string Eleve::getgr(){
	return gr_TD;
}
float Eleve::getGPA(){
	return GPA;
}
string Eleve::getpromotion(){
	return promotion;
}

void Eleve::E_affiche()
{
	//this->affiche();
	cout << "nom: " << nom << endl;
	cout << "prenom: " << prenom << endl;
	cout << "promotion: " << promotion << endl;
	cout << "gr_Td: " << gr_TD << endl;
	cout << "GPA: " << GPA << endl;
}
