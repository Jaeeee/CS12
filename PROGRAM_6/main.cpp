#include <cmath>
#include <iostream>

using namespace std;

int gcd(int x, int y) {
    x = abs(x);
    y = abs(y);
    
    if (y == 0) {
        return x;
    }
    return (gcd(y, x % y));
}

bool diophantine(int a, int b, int c, int &x, int &y) {
    if (c % gcd(a, b) != 0) {
        return false;
    } else if (a % b == 0) {
        x = 0;
        y = c / b;
        return true;
    } else if (a % b != 0) {
        int u, r, v, t;
        t = a/ b;
        r = a % b;
        u = t * (x+y);
        v = x;
        if (diophantine(b, r, c, u, v)) {
            x = v;
            y = u - (x * t);
            return true;
        }
    }
    return false;
}

int main() {

    int a, b, c, x, y;

    cout << "Enter a b c" << endl;
    cin >> a >> b >> c;
    cout << endl;

    cout << "Result: ";
    if (diophantine(a, b, c, x, y)) {
        cout << x << " " << y << endl;
    } else {
        cout << "No solution!" << endl;
    }

    return 0;
}