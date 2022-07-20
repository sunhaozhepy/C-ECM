#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

Person::Person(string first, string last, string addr = "", string tel = "") : first_name(first),
                                                                               last_name(last),
                                                                               address(addr),
                                                                               telephone(tel) {}
string Person::get_first_name()
{
    return first_name;
}
string Person::get_last_name()
{
    return last_name;
}
string Person::get_address()
{
    return address;
}
string Person::get_telephone()
{
    return telephone;
}
void Person::set_first_name(string first)
{
    first_name = first;
}
void Person::set_last_name(string last)
{
    last_name = last;
}
void Person::set_address(string addr)
{
    address = addr;
}
void Person::set_telephone(string tel)
{
    telephone = tel;
}
void Person::print()
{
    cout << first_name << ' ' << last_name << endl;
    cout << address << endl;
    cout << telephone << endl;
}
Student::Student(string first, string last, string addr = "", string tel = "", string promo = "", string group = "", double score = -1) : Person(first, last, addr, tel),
                                                                                                                                          promotion(promo),
                                                                                                                                          tdgroup(group),
                                                                                                                                          gpa(score) {}
string Student::get_promotion()
{
    return promotion;
}
string Student::get_tdgroup()
{
    return tdgroup;
}
double Student::get_gpa()
{
    return gpa;
}
void Student::set_promotion(string promo)
{
    promotion = promo;
}
void Student::set_tdgroup(string group)
{
    tdgroup = group;
}
void Student::set_gpa(double score)
{
    gpa = score;
}
void Student::print()
{
    cout << first_name << ' ' << last_name << endl;
    cout << address << endl;
    cout << telephone << endl;
    cout << promotion << endl;
    cout << tdgroup << endl;
    cout << gpa << endl;
}
Personnel::Personnel(string first, string last, double amount, string addr = "", string tel = "") : Person(first, last, addr, tel),
                                                                                                    salary(amount) {}
double Personnel::get_salary()
{
    return salary;
}
void Personnel::set_salary(double amount)
{
    salary = amount;
}
void Personnel::print()
{
    cout << first_name << ' ' << last_name << endl;
    cout << address << endl;
    cout << telephone << endl;
    cout << "salary: " << salary << endl;
}
double Personnel::calculate_salary()
{
    return salary;
}
PersonnelAdmin::PersonnelAdmin(string first, string last, double amount, double rate_input, string addr = "", string tel = "", int hours = 0) : Personnel(first, last, amount, addr, tel),
                                                                                                                                                sup_hours(hours),
                                                                                                                                                rate(rate_input) {}
int PersonnelAdmin::get_sup_hours()
{
    return sup_hours;
}
double PersonnelAdmin::get_rate()
{
    return rate;
}
void PersonnelAdmin::set_sup_hours(int hours)
{
    sup_hours = hours;
}
void PersonnelAdmin::set_rate(double rate_input)
{
    rate = rate_input;
}
double PersonnelAdmin::calculate_salary()
{
    return salary + sup_hours * rate;
}
void PersonnelAdmin::print()
{
    cout << first_name << ' ' << last_name << endl;
    cout << address << endl;
    cout << telephone << endl;
    cout << "salary: " << salary << endl;
    cout << "supplementary hours: " << sup_hours << endl;
    cout << "supplementary work hourly pay: " << rate << endl;
}
PermanentTeacher::PermanentTeacher(string first, string last, double amount, int grade_input, double award_input, string addr = "", string tel = "", string bureau = "") : Personnel(first, last, amount, addr, tel),
                                                                                                                                                                           grade(grade_input),
                                                                                                                                                                           award(award_input),
                                                                                                                                                                           office(bureau) {}
string PermanentTeacher::get_office()
{
    return office;
}
int PermanentTeacher::get_grade()
{
    return grade;
}
double PermanentTeacher::get_award()
{
    return award;
}
void PermanentTeacher::set_office(string bureau)
{
    office = bureau;
}
void PermanentTeacher::set_grade(int grade_input)
{
    grade = grade_input;
}
void PermanentTeacher::set_award(double award_input)
{
    award = award_input;
}
void PermanentTeacher::print()
{
    cout << first_name << ' ' << last_name << endl;
    cout << address << endl;
    cout << telephone << endl;
    cout << "salary: " << salary << endl;
    cout << "office: " << office << endl;
    cout << "grade: " << grade << endl;
    cout << "award: " << award << endl;
}
double PermanentTeacher::calculate_salary()
{
    return salary + grade * award / 100;
}
TemporaryTeacher::TemporaryTeacher(string first, string last, double amount, string locker_input, double rate_input, string addr = "", string tel = "", int number_hour = 0) : Personnel(first, last, amount, addr, tel),
                                                                                                                                                                               locker(locker_input),
                                                                                                                                                                               hour(number_hour),
                                                                                                                                                                               rate(rate_input) {}
string TemporaryTeacher::get_locker()
{
    return locker;
}
int TemporaryTeacher::get_hour()
{
    return hour;
}
double TemporaryTeacher::get_rate()
{
    return rate;
}
void TemporaryTeacher::set_locker(string locker_input)
{
    locker = locker_input;
}
void TemporaryTeacher::set_hour(int hour_input)
{
    hour = hour_input;
}
void TemporaryTeacher::set_rate(double rate_input)
{
    rate = rate_input;
}
void TemporaryTeacher::print()
{
    cout << first_name << ' ' << last_name << endl;
    cout << address << endl;
    cout << telephone << endl;
    cout << "salary: " << salary << endl;
    cout << "locker: " << locker << endl;
    cout << "number of working hours: " << hour << endl;
    cout << "hourly pay: " << rate << endl;
}
double TemporaryTeacher::calculate_salary()
{
    return rate * hour;
}
ListPersonnel::ListPersonnel()
{
    tab = new Personnel *[100]();
    number = 0;
    size = 4;
}
void ListPersonnel::add_Personnel(Personnel* ptPersonnel)
{
    if (number < size)
    {
        tab[number] = ptPersonnel;
        number++;
    }
    else
    {
        doubleSize(tab);
    }
}
void ListPersonnel::calculate_salary()
{
    for (int i = 0; i < number; i++)
    {
        cout << "name:  " << tab[i]->first_name << ' ' << tab[i]->last_name << endl;
        cout << "salary: " << tab[i]->salary << endl;
    }
}
Personnel** ListPersonnel::doubleSize(Personnel** &tabl)
{
    Personnel** tmp = new Personnel * [2 * size];
    for (int i = 0; i <= size; i++)
    {
        tmp[i] = tabl[i];
    }
    delete[] tab;
    tabl = tmp;
    size = 2 * size;
    return tmp;
}

int main()
{
    Person person();
    return 0;
}