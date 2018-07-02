
#include <iostream>

using namespace std;
/* 1. create sthe push_front(), pop_front(), and the front() */

void IntList::push_front(int value) {
     IntNode* temp = new IntNode(value);
    
    if (head == 0) { //empty
        head = temp;
        tail = temp;
    }
    
    else {              //not empty
    temp -> next = head;
    head = temp;
    }
    
}

void IntList::push_back(int value) {
    IntNode* temp = new IntNode(value);
    
    if (tail == 0){
        head = temp;
        tail = temp;
    }
    
    else {
        tail -> next = temp;
        tail = temp;
    }
    
}


void IntList::pop_front() {
    if (head == 0) {
        return;
    }
    
    else if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    
    else {
        IntNode* temp = head;
        head = head -> next;
        delete temp;
    }
}

IntNode IntList::front() {
    return head;
}


/* 2. Write a void global function where you take an IntList by reference and reverse the order of it.
      Cannot use private variables like head, tail, or next since global, 
      and can only use the functions push_front(), pop_front (), front 
      ***IntList class needs to have a copy constructor for this to work**** */
      
      
void Reverse (IntList &original) { //pass by reference
    IntList temp; // create new list
    
    temp = original; // copy original list into temp
    
    while (original -> front() != 0) { // not empty
        original -> pop_front(); // keep on deleting
    }
    
    while (temp -> front() != 0) { //while temp is not empty
        original -> push_front(temp -> front()) //takes front of temp and puts in front of original
        temp -> pop_front(); //deletes front
    }
}

    
/* 3. Recursive function where you take in an int array by reference and its size, 
      determine how many positives and negative values are in the arr, 
      and return the difference betwen the number of positive and negative numbers (should be positive). 
      No loops, only recursion*/
      
      
int countVals (const int &arr, int size){
    
    if (size == 0) {
        return 0;
    }
    
    
    int value = arr[size - 1];
    int posOrNeg;
    int difference = 0;
    
    
    if ( value >= 0 ) {
        posOrNeg = 1;
    }
    
    if (value < 0) {
        
        posOrNeg = -1;
    }
    
    return difference = posOrNeg +  countVals (arr, size - 1);
    
}

      

/* 4. Create the int Vector constructor given size and value*/

IntVector::IntVector(unsigned size, int value) {
    sz = size;
    cap = size;
    data = new int[cap];
    for (unsigned i = 0; i < sz; ++i) {
        data[i] = value;
    }
    return;
}    




/* 5. Determine how many topics are in the BBoard * (Dont know if this is the right question) */  

int NumTopics() {
    int numTopics;
    for ( unsigned i = 0; i < messageList.size() ++i) {
        if (!messageList.at(i).isReply()) {
            numTopics++;
        }
    }
    return numTopics;
}

/* 6. (Not sure if questions is correct)  Reverse the order of an array? */

void arreverse(int* arr, int size) {
    int temp;
    
    for ( int i = 0; i < size; ++i) {
        if (i == size - 1 - i ) {
            return;
        } 
        else if (size - 1 - i == i + 1) {
            temp = arr[i];
            arr[i] = arr[size - 1 - i];
            arr[size - 1 - i] = temp;
            return;
        }
         else {
            temp = arr[i];
            arr[i] = arr[size - 1 - i];
            arr[size - 1 - i] = temp;
         }
        
    }
    
    return;
}


