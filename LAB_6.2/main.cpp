#include <iostream>

#include "IntVector.h"

using namespace std;

int main() {
    IntVector intv = IntVector(10);
    cout << "Size of IntVector: " << intv.size() << endl;
    cout << "Capacity of IntVector: " << intv.capacity() << endl;
    cout << "Front of IntVector: " << intv.front() << endl;
    cout << "Back of IntVector: " << intv.back() << endl;
    for (unsigned i = 0; i < intv.size(); i++) {
        cout << intv.at(i) << " ";
    }
    cout << endl;   
    IntVector intv2 = IntVector(1);
     cout << "Size of IntVector: " << intv2.size() << endl;
    cout << "Capacity of IntVector: " << intv2.capacity() << endl;
    cout << "Front of IntVector: " << intv2.front() << endl;
    cout << "Back of IntVector: " << intv2.back() << endl;
    for (unsigned i = 0; i < intv2.size(); i++) {
        cout << intv2.at(i) << " ";
    }
    cout << endl;
    cout << "Testing for boundaries!" << endl;
    cout << "Value at 3 for IntVector: " << intv.at(3) << endl;
    cout << "Value at 3 for IntVector2: " << intv2.at(3) << endl;
    return 0;
}