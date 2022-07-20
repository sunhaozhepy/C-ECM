//#include "stdafx.h"

#include "Personne.h"
#include <iostream>
#include <string>

using namespace std;

Personne::Personne(string n, string pre, string adr, string tel):nom(n),prenom(pre),adresse(adr),telephone(tel){

}

void Personne::setnom(string nom){
	nom = nom;
}

void Personne::setprenom(string prenom){
	prenom = prenom;
}

void Personne::setadresse(string adr){
	adresse = adr;
}

void Personne::settelephone(string tel){
	telephone = tel;
}

string Personne::getnom(){
	return nom;
}

string Personne::getprenom(){
	return prenom;
}

string Personne::gettelephone(){
	return telephone;
}

string Personne::getadresse(){
	return adresse;
}

void Personne::affiche(){
	cout << "nom: " << nom << endl;
	cout << "prenom: " << prenom << endl;
	cout << "adresse: " << adresse << endl;
	cout << "telephone: " << telephone << endl;
}

