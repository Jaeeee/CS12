#include <iostream>

using namespace std;

double mean(const double array[], int arraySize);
void remove(double array[], int &arraySize, int index);
void display(const double array[], int arraySize);

double mean(const double array[], int arraySize) {
    double sum = 0.0;
    for (int i = 0; i < arraySize; i++) {
        sum+= array[i];
    }
    return sum / arraySize;
}

void remove(double array[], int &arraySize, int index) {
      for (int i = index; i+1 < arraySize ; i++) {
            array[i] = array[i+1];
     }
     arraySize--;
}

void display(const double array[], int arraySize) {
    for (int i = 0; i < arraySize -1; i++) {
        cout << array[i] << ", ";
    }
    cout << array[arraySize-1];
}

int main() {
int remov = 0;
int size = 10;
double arr[10] = { 0.0 };
cout << "Enter 10 values:" << endl;
for (int i =0; i < size; i++) {
    cin >> arr[i];
}
cout << endl;
cout << "Mean: " << mean(arr, size) << endl;
cout << endl;
cout << "Enter index of value to be removed: " << endl;
cin >> remov;
cout << "Before removing value: ";
display(arr,size);
cout <<  endl;
remove(arr, size, remov);
cout << "After removing value: ";
// size--;
display(arr,size);
cout <<  endl;

return 0;    
}