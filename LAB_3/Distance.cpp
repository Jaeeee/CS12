#include <cmath>
#include <iostream>

using namespace std;

#include "Distance.h"

Distance::Distance() {
    feet = 0;
    inches = 0.0;
}

Distance::Distance(unsigned ft, double in) {
    feet = ft;
    inches = in;
    init();
}

Distance::Distance(double in) {
    feet = 0;
    inches = in;
    init();
}

unsigned Distance::getFeet() const {
    return feet;
}

double Distance::getInches() const {
    return inches;
}

double Distance::distanceInInches() const {
    return ((feet * 12)+inches);
}

double Distance::distanceInFeet() const {
    return (feet + (inches / 12));
}

double Distance::distanceInMeters() const {
    return (((feet * 12) + inches) * 0.0254); 
}

const Distance Distance::operator+(const Distance &rhs) const {
    Distance dummy = Distance(rhs.feet + feet, rhs.inches + inches);
    return dummy;
}

const Distance Distance::operator-(const Distance &rhs) const {
    Distance dummy = Distance(distanceInInches() - rhs.distanceInInches());
    return dummy;
}

ostream & operator<<(ostream &out, const Distance &rhs) {
    out << rhs.feet << "' " << rhs.inches << "\"";
    return out;
}

void Distance::init() {
    feet = abs(feet);
    if (inches < 0) {
        inches *= -1;
    }
    while (inches >= 12) {
        inches -= 12;
        feet++;
    }
}


