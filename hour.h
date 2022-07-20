#include <iostream>
using namespace std;

class Hour
{
public:
    Hour(int h, int m)
    {
        if (check_hour(h, m))
        {
            hour = h;
            minute = m;
        }
    }
    int get_hour()
    {
        return hour;
    }
    int get_minute()
    {
        return minute;
    }
    void set_minute(int minute_input)
    {
        if (minute_input <= 59 && 0 <= minute_input)
        {
            minute = minute_input;
        }
    }
    void set_hour(int hour_input)
    {
        if (hour_input <= 23 && 0 <= hour_input)
        {
            hour = hour_input;
        }
    }
    void print()
    {
        cout << hour << " : " << minute << endl;
    }
    bool operator== (const Hour& hour_input)
    {
        return hour == hour_input.hour && minute == hour_input.minute;
    }

private:
    int hour = 0;
    int minute = 0;
    bool check_hour(int hour, int minute)
    {
        if (0 <= hour && hour <= 23 && 0 <= minute && minute <= 59)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};