#include <iostream>
using namespace std;

class Date
{
public:
    Date(int d, int m, int y)
    {
        if (checkDate(d, m, y))
        {
            day = d;
            month = m;
            year = y;
        }
    }
    ~Date()
    {
    }
    int getDay()
    {
        return day;
    }
    int getMonth()
    {
        return month;
    }
    int getYear()
    {
        return year;
    }
    void setDay(int d)
    {
        if (1 <= d && d <= 31)
        {
            day = d;
        }
    }
    void setMonth(int m)
    {
        if (1 <= m && m <= 12)
        {
            month = m;
        }
    }
    void setYear(int y)
    {
        if (1915 <= y && y <= 2020)
        {
            year = y;
        }
    }
    void print()
    {
        cout << "day: " << day << "\tmonth: " << month << "\tyear: " << year << endl;
    }

    bool operator== (const Date& date)
    {
        return day == date.day && month == date.month && year == date.year;
    }

private:
    int day = 1;
    int month = 1;
    int year = 1915;
    bool checkDate(int d, int m, int y)
    {
        if (1 <= d && d <= 31 && 1 <= m && m <= 12 && 1915 <= y && y <= 2020)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};