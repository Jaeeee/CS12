#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>

using namespace std;

struct IntNode {
    int data;
    IntNode *next;
    IntNode(int data) : data(data), next(0) {}
};

class IntList {
    private:
        IntNode *head;
        IntNode *tail;
    public:
        IntList();
        IntList(const IntList &cpy);
        IntList & operator=(const IntList &rhs);
        ~IntList();
        void display() const;
        void push_front(int value);
        void push_back(int value);
        void pop_front();
        void clear();
        void selection_sort();
        void insert_ordered(int value);
        void remove_duplicates();
        bool empty() const;
        const int & front() const;
        const int & back() const;
        friend ostream & operator<<(ostream &out, const IntList &rhs);
};

#endif