#include <iostream>

using namespace std;

int main() {
    
int a = 1, b = 2, *ptr = &b;
a = *ptr;

cout << a << ", " << b << ", " << *ptr << endl;

}