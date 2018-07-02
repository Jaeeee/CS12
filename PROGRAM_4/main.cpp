#include <iostream>

#include "IntVector.h"

using namespace std;

int main() {
    IntVector intv = IntVector(2);
    cout << "Size of IntVector: " << intv.size() << endl;
    cout << "Capacity of IntVector: " << intv.capacity() << endl;
    cout << "Front of IntVector: " << intv.front() << endl;
    cout << "Back of IntVector: " << intv.back() << endl;
    for (unsigned i = 0; i < intv.size(); i++) {
        cout << intv.at(i) << " ";
    }
    cout << endl;
    bool empty = intv.empty();
    if (empty == true) {
        cout << "EMPTY" << endl;
    } else {
        cout << "NOT EMPTY" << endl;
    }
    intv.resize(20);
    cout << "Back of vector:" << intv.back() << endl;
    intv.pop_back();
    cout << "Back of vector (after pop back): " << intv.back() << endl;
    intv.assign(1, 100000);
    cout << "Vector: " << endl;
      for (unsigned i = 0; i < intv.size(); i++) {
        cout << intv.at(i) << " ";
    }
      cout << endl;
    cout << "Vector after push_back: " << endl;
    intv.push_back(69);
      for (unsigned i = 0; i < intv.size(); i++) {
        cout << intv.at(i) << " ";
    }
      cout << endl;
          cout << "Inserting 69 @ 3: " << endl;
    intv.insert(1, 522);
       for (unsigned i = 0; i < intv.size(); i++) {
        cout << intv.at(i) << " ";
    }
      cout << endl;
          cout << "Erasing: " << endl;
    intv.erase(3);
      for (unsigned i = 0; i < intv.size(); i++) {
        cout << intv.at(i) << " ";
    }
      cout << endl;
    cout << "Assigning... (prep expand)" << endl;
    intv.assign(5, 3000);
      for (unsigned i = 0; i < intv.size(); i++) {
        cout << intv.at(i) << " ";
    }
      cout << endl;
    cout << "Resizing.." << endl;
    intv.resize(30);
      for (unsigned i = 0; i < intv.size(); i++) {
        cout << intv.at(i) << " ";
    }
      cout << endl;
    return 0;
}