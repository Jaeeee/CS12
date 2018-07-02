#include <iostream>
#include "SortedSet.h"

using namespace std;

int main() {
    SortedSet s = SortedSet();
    s.add(3);
    s.add(8);
    s.add(300);
    s.add(148);
    cout << "SORTED SET 1: " << s << endl;
    SortedSet s2 = SortedSet();
    s2.add(10);
    s2.add(300);
    s2.add(8);
    cout << "SORTED SET 2: " << s2 << endl;
    // SortedSet s3 = s | s2;
    // cout << "SET 3 ( | OPERATOR): " << s3 << endl;
    // SortedSet s4 = s & s2;
    // cout << "SET 4 ( & OPERATOR): " << s4 << endl;
    // SortedSet s5 = s |= s2;
    // cout << "SET 5 ( |= OPERATOR): " << s3 << endl;
    // SortedSet s6 = s &= s2;
    // cout << "SET 6 ( &= OPERATOR): " << s6 << endl;
}