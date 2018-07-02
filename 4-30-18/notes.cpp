#include <iostream>

using namespace std;

void display(int a[], int arr_size) { //if a[6], compiler will ignore it, no syntax error
    for (int i = 0; i < arr_size; i++) {
        cout << a[i] << " ";
        a[i]+=2;
    }
}

int main() {
    const int ARR_CAP = 6;
    int arr[ARR_CAP] = { 1, 2, 3, 4, 5, 6 };
    cout <<  arr[6] << endl; //undefined behavior when you go out of bounds of an array
    display(arr, ARR_CAP);
    cout << arr[3] << endl;
    return 0;
}

/**
 * ARRAYS - DIFFERENCES
 * Arrays: no bounds checking
 * passing array into function - multiple parameters
 * no size member function
 * vectors have to pass in through reference to make changes, arrays already by 
 * shouldnt have const in array function (display)
 * dont use & with arrays
 * can't use assignment operators with arrays (arr2 = x)
**/

/**
 * Arrays vs Vectors:
 * - Arrays use subscript operator [ ] to access individual elements
 * - cout << arr[5]; -undefined behavior if size is 5
 * - cout << v.at(5); - runtime error if size is 5
 * - no boundary checking for arrays
 * - arrays odn't have member funcitons
 * - declaring an array: int name[100] = {0};
 * - v1= v2; //allowed
 * - arr1 = arr2; //syntax error
 * - cout << v1 << endl; //syntax error
 * - cout << arr1 << endl; //allowed, but not usefuli to user
 * - don't use & to pass in arrays, they are essentiallly passed in by reference
**/

/**
 * syntax error - program runs, runtime error - program doesn't run
**/

/**
 * As soon as you do at least 1 initialization, the rest get initialized to 0 automatically
 * int arr[ARR_CAP] = { 0, 0 }; //trick to initialize everything to 0 in the
 **/