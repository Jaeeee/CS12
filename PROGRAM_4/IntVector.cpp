#include "IntVector.h"
#include <stdexcept>
#include <iostream>

using namespace std;

IntVector::IntVector()
{
    sz = 0;
    cap = 0;
    data = 0;
}

IntVector::IntVector(unsigned size, int value)
{
    sz = size;
    cap = size;
    data = new int[cap];
    for (unsigned i = 0; i < sz; i++) {
        data[i] = value;
    }
}

IntVector::~IntVector()
{
    delete data;
}

unsigned IntVector::size() const
{
    return sz;
}

unsigned IntVector::capacity() const
{
    return cap;
}

bool IntVector::empty() const
{
    if (sz == 0) {
        return true;
    }
    else {
        return false;
    }
}

const int& IntVector::at(unsigned index) const
{
    if (index >= sz) {
        throw out_of_range("IntVector::at_range_check");
    }
    else {
        return data[index];
    }
}

int& IntVector::at(unsigned index)
{
    if (index >= sz) {
        throw out_of_range("IntVector::at_range_check");
    }
    else {
        return data[index];
    }
}
/**
 * 
This function inserts data at position index. To do this, all values currently at position index and greater are shifted to the right by 1 
(to the element right after its current position).
Size will be increased by 1. However, If size will become larger than capacity, this function needs to first double the capacity.
In other words, if capacity and size are both 20 when this function is called, 
this function must first increase the capacity to 40 and then it will be able to increase the size to 21.
Since other functions will also potentially need to expand (double) the capacity, call the private helper function named expand (see above) to do this for you.
This function should throw an out_of_range exception, passing it the string "IntVector::insert_range_check"
if the index is too large. See bottom of specifications for more details on how to throw an exception and how to test that it works properly.
**/
void IntVector::insert(unsigned index, int value)
{
    if (index > sz) {
        throw out_of_range("IntVector::insert_range_check");
    }
    if (sz + 1 > cap) {
        if (cap * 2 > sz + 1) {
            expand();
        } else {
            expand((sz+1)-cap);
        }
    }
    // } 
    // else if (sz >= cap) {
    //     expand();
    // }
    int tempVal = data[index];
    sz++;
    data[index] = value;
    for (unsigned i = sz - 1; i > index; i--) {
        swap(data[i+1], data[i]);
    }
    data[index + 1] = tempVal;
}

void IntVector::erase(unsigned index)
{
    if (index >= sz) {
        throw out_of_range("IntVector::erase_range_check");
    }
    for (unsigned i = index; i + 1 < sz; i++) {
        data[i] = data[i + 1];
    }
    sz--;
}

const int& IntVector::front() const
{
    return data[0];
}

int& IntVector::front()
{
    return data[0];
}

const int& IntVector::back() const
{
    return data[sz - 1];
}

int& IntVector::back()
{
    return data[sz - 1];
}

void IntVector::assign(unsigned n, int value)
{
    if (n > (2 * cap)) {
        expand(n - cap);
    }
    else if (n <= (2 * cap) && n > cap) {
        expand();
    }
            sz = n;
    for (unsigned i = 0; i < sz; i++) {
            data[i] = value;
        }
}

void IntVector::push_back(int value)
{
    if (cap == 0) {
        expand(1);
    }
    else if (sz >= cap) {
        expand();
    }
    sz++;
    data[sz - 1] = value;
}

void IntVector::pop_back()
{
    sz--;
}

void IntVector::expand() {
    int * temp = new int[cap * 2];
    
    for (unsigned i = 0; i < cap; ++i) {
        temp[i] = data[i];
    }
    
    delete [] data;
    data = temp;
    cap *= 2;
    
    return;
}

void IntVector::expand(unsigned amount) {
    int * temp = new int[cap + amount];
    
    for (unsigned i = 0; i < cap; ++i) {
        temp[i] = data[i];
    }
    
    delete [] data;
    data = temp;
    cap += amount;
    
    return;
}

// /**
//  * 
// This function will double the capacity of the vector. This function should reallocate memory for the dynamically allocated array and update the value of capacity. 
// Make sure your expand() function properly handles the case when capacity is 0 before calling expand(). This will be a special case within the expand() function.
// Make sure you don't create a memory leak here.
// **/
// void IntVector::expand()
// {
//     int* temp = data;
//     cap *= 2;
//     if (cap == 0) {
//         cap = 1;
//         data = new int[cap];
//     }
//     else {
//         data = new int[cap];
//         for (unsigned i = 0; i < sz; i++) {
//             data[i] = temp[i];
//         }
//     }
// }

// /**
//  * 
// This function will expand the capacity of the vector by the amount passed in.
// This function should reallocate memory for the dynamically allocated array and update the value of capacity.
// Make sure you don't create a memory leak here.
// **/
// void IntVector::expand(unsigned x)
// {
//     int *temp = new int[cap * 2];
//     for (unsigned i = 0; i < cap; i++) {
//         temp[i] = data[i];
//     }
//     delete [] data;
//     data = temp;
//     cap += x;
// }

void IntVector::clear()
{
    sz = 0;
}

void IntVector::reserve(unsigned n)
{
    	if (n > cap) {
				expand(n - cap);			
		}
}

void IntVector::resize(unsigned size, int value)
{
    if (size <= sz) {
        sz = size;
    }
    else if (size > sz) {
        if (size > cap * 2) {
            expand(size - cap);
        } else if ((size <= (2 * cap)) && size > cap) {
            expand();
        }
        for (unsigned i = sz; i < size; i++) {
            data[i] = value;
        }
        sz = size;
    }
}