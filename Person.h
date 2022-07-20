#ifndef Person_H
#define Person_H
#include <string>
#include <iostream>
using namespace std;

class Person
{
public:
    Person(string first, string last, string addr = "", string tel = "");
    string get_first_name();
    string get_last_name();
    string get_address();
    string get_telephone();
    void set_first_name(string first);
    void set_last_name(string last);
    void set_address(string addr);
    void set_telephone(string tel);
    virtual void print();

public: //ListPersonnel::calculate_salary()
    string first_name;
    string last_name;
protected:
    string address;
    string telephone;
};

class Student : public Person
{
public:
    Student(string first, string last, string addr = "", string tel = "", string promo = "", string group = "", double score = -1);
    string get_promotion();
    string get_tdgroup();
    double get_gpa();
    void set_promotion(string promo);
    void set_tdgroup(string group);
    void set_gpa(double score);
    void print();

private:
    string promotion;
    string tdgroup;
    double gpa;
};

class Personnel : public Person
{
public:
    Personnel(string first, string last, double amount = 0, string addr = "", string tel = "");
    double get_salary();
    void set_salary(double amount);
    void print();
    virtual double calculate_salary();

public: //ListPersonnel::calculate_salary()
    double salary;
};

class PersonnelAdmin : public Personnel
{
public:
    PersonnelAdmin(string first, string last, double amount, double rate_input, string addr = "", string tel = "", int hours = 0);
    int get_sup_hours();
    double get_rate();
    void set_sup_hours(int hours);
    void set_rate(double rate_input);
    double calculate_salary();
    void print();

private:
    int sup_hours = 0;
    double rate = 0;
};

class PermanentTeacher : public Personnel
{
public:
    PermanentTeacher(string first, string last, double amount, int grade_input, double award_input, string addr = "", string tel = "", string bureau = "");
    string get_office();
    int get_grade();
    double get_award();
    void set_office(string bureau);
    void set_grade(int grade_input);
    void set_award(double award_input);
    void print();
    double calculate_salary();

private:
    string office;
    int grade;
    double award;
};

class TemporaryTeacher : public Personnel
{
public:
    TemporaryTeacher(string first, string last, double amount, string locker_input, double rate_input, string addr = "", string tel = "", int number_hour = 0);
    string get_locker();
    int get_hour();
    double get_rate();
    void set_locker(string locker_input);
    void set_hour(int hour_input);
    void set_rate(double rate_input);
    void print();
    double calculate_salary();

private:
    string locker;
    int hour;
    double rate;
};

class ListPersonnel
{
public:
	ListPersonnel();
	void add_Personnel(Personnel* ptrPersonnel);
	void calculate_salary();
	Personnel** doubleSize(Personnel** &tabl);

private:
	Personnel** tab;
	int number;
	int size;
};

#endif