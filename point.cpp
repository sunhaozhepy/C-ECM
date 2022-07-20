#include <iostream>
using namespace std;

class Point
{
public:
    Point()
    {
        cout << 'Constructor called.' << endl;
    }
    Point(const Point& obj)
    {
        cout << 'Copy Constructor called.' << endl;
    }
    ~Point()
    {
        cout << 'Destructor called.' << endl;
    }
    double getX()
    {
        return x;
    }
    double getY()
    {
        return y;
    }
    double getZ()
    {
        return z;
    }
    void setX(double x_input)
    {
        x = x_input;
    }
    void setY(double y_input)
    {
        y = y_input;
    }
    void setZ(double z_input)
    {
        z = z_input;
    }
    void print_point()
    {
        cout << x << ', ' << y << ', ' << z << endl;
    }
    static void input_point()
    {
        cout << 'This is to create a new point in the point set.' << endl;
        double x_input, y_input, z_input;
        cout << 'The x coordinate:' << endl;
        cin >> x_input;
        cout << 'The y coordinate:' << endl;
        cin >> y_input;
        cout << 'The z coordinate:' << endl;
        cin >> z_input;
        Point point;
        point.setX(x_input);
        point.setY(y_input);
        point.setZ(z_input);
        cout << 'Successfully created.' << endl;
    }

private:
    double x;
    double y;
    double z;
};

int main()
{
    Point point;
    point.setX(5);
    point.setY(10);
    point.setZ(6.78);
    point.print_point();
}