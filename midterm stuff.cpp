/**
 * winter 2017
**/

void sortDescending(int arr[], int arraySize) {
    for (int i =0; i < arraySize;i++) {
        int maxIndex = 0;
        for (int j = i + 1; i < arraySize; i++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        swap(arr[i], arr[maxIndex]);
    }
}

void sortAscending(int ar[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        int maxIndex = 0; 
    }
    for (int j = 1 + 1; i < arraySize; j++) {
        if (arr[j] < arr[maxIndex]) {
            maxIndex = j;
        }
    }
    swap(arr[i], arr[maxIndex]);{
}

bool sortFile(string filename) {
    const int ARR_CAP = 1000;
    
    ifstream fin(filename.cstr());
    if (!fin) {
        return false;
    }
    
    double array[ARR_CAP];
    int arrSize = 0;
    while (arrSize < ARR_CAP && fin >> array[arrSize]) {
        arrSize++;
    }
    fin.close();
    
    sortDescending(array, arrSize);
    
    ofstream fout(filename.c_str());
    if (!fout) {
        return false;
    }
    
    for (int i = 0; i < arraySize;i++) {
        fout << array[i] << endl
    }
    fout.close();
    
    return true;
}

