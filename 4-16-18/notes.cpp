#include <iostream>

using namespace std;

class Point {
private:
    double xCoord;
    double yCoord;
public:
    Point();
    Point(double x, double y);
    void display() const; // (x, y)
    // void move(double dx, double dy);
    // void setX(double dx);
    // void setY(double dy);
    // double getX() const;
    // double getY() const;
};

Point::Point() {
    xCoord = 0.0;
    yCoord = 0.0;
}

Point::Point(double x, double y) {
    xCoord = x;
    yCoord = y;
}

void Point::display() const {
    cout << '(' << xCoord << ',' << yCoord << ')';    
}

int main() {
    Point p1;
    p1.display();
    
    cout << endl;
    
    Point p2 = Point(3.4, 3.5);
    p2.display();
}

