//#pragma once
#ifndef ELEVE_H
#define ELEVE_H
#include "Personne.h"
#include<string>
using namespace std;
class Eleve :	public Personne
{
protected:
	string promotion;
	string  gr_TD;
	float  GPA;


public:
	Eleve(string nom, string prenom, string pro, float GPA, string gr);
	Eleve();
	string getpromotion();
	void setpromotion(string pro);

	string getgr();
	void setgr(string gr);

	float  getGPA();
	void setGPA(float GPA);

	void E_affiche();
};
#endif
