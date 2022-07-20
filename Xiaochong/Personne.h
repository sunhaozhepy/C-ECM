//#pragma once
#ifndef Personne_H 
#define Personne_H
#include<string>
#include<iostream>
using namespace std;
class Personne{

public:
	string nom;
	string prenom;
	string adresse;
	string telephone;

public:
	Personne(string nom, string prenom, string adr = "", string tel = "");


	string getnom();
	void setnom(string nom);

	string getprenom();
	void setprenom(string prenom);

	string getadresse();
	void setadresse(string adr);

	string gettelephone();
	void settelephone(string tel);

	void affiche();

};

#endif


