#include "date.h"
#include "hour.h"
using namespace std;

class RDV
{
public:
    RDV(Date d, Hour h, string p, int nb, string *list) : date(d), hour(h), place(p), number_people(nb), list_people(list) {}
    Date get_date()
    {
        return date;
    }
    Hour get_hour()
    {
        return hour;
    }
    string get_place()
    {
        return place;
    }
    int get_number_people()
    {
        return number_people;
    }
    string* get_list_people()//这里返回的是指向list_people数组的指针
    {
        return list_people;
    }
    void set_date(const Date& d)
    {
        date = d;
    }
    void set_hour(const Hour& h)
    {
        hour = h;
    }
    void set_place(string p)
    {
        place = p;
    }
    void set_number(int nb)
    {
        number_people = nb;
    }
    void set_list_people(string *list)
    {
        list_people = list;
    }
    void set_participant(int i, string name)
    {
        list_people[i] = name;
    }
    void print_RDV();
    bool verify_compatible_merchant(RDV rdv);
    bool verify_compatible_client(RDV rdv);

private:
    Date date;
    Hour hour;
    string place;
    int number_people;
    string *list_people;
};

bool RDV::verify_compatible_merchant(RDV rdv)//商家当时间相同时冲突，返回false
{
    if (this->hour == rdv.hour && this->date == rdv.date)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool RDV::verify_compatible_client(RDV rdv) //顾客当时间相同且参加人员有重叠时冲突（一个人不可能同时在两个地方），返回false
{
    if (this->hour == rdv.hour && this->date == rdv.date)
    {
        if (!no_common(this->list_people, this->number_people, rdv.list_people, rdv.number_people))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return true;
    }
}

void RDV::print_RDV()
{
    date.print();
    hour.print();
    cout << "place: " << place << endl;
    cout << "number of people: " << number_people << endl;
    cout << "list of participants: " << endl;
    for (int i = 0; i < number_people; i++)
    {
        cout << list_people[i] << ", ";
    }
}

bool no_common(int* arr1, int len1, int* arr2, int len2)
{
    int count = 0;
    for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                count++;
            }
        }
    }
    bool result = (count == 0)? true : false;
    return result;
}

bool no_common(string* arr1, int len1, string* arr2, int len2)
{
    int count = 0;
    for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                count++;
            }
        }
    }
    bool result = (count == 0)? true : false;
    return result;
}

int main()
{
   Date date(17, 11, 2021);
   Hour hour(22, 46);

}