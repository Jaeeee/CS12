#ifndef SORTEDSET_H
#define SORTEDSET_h

#include <iostream>
#include "IntList.h"

using namespace std;

class SortedSet:public IntList {
    public:
    SortedSet();
    SortedSet(const SortedSet &);
    SortedSet(const IntList &);
    ~SortedSet();
    const bool in(int data) const;
    const SortedSet operator |(const SortedSet &) const;
    const SortedSet operator &(const SortedSet &) const;
    void add(int data);
    void push_front(int data);
    void push_back(int data);
    void insert_ordered(int data);
    SortedSet operator |=(const SortedSet &);
    SortedSet operator &=(const SortedSet &);
    private:
};

#endif