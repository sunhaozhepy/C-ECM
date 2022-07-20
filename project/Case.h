#pragma once
#include <string>
using namespace std;

class Case
{
public:
	Case();
	Case(string nom);
	string getNom();
	void setNom(string nom);
	virtual void arreterSur();
	bool operator ==(const Case& case_autre);

protected:
	string nom;
};

