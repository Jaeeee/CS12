#include <iostream>
#include "SortedSet.h"

using namespace std;

SortedSet::SortedSet():IntList() {
    
}

SortedSet::~SortedSet() {
    
}

SortedSet::SortedSet(const SortedSet &a):IntList(a) {
    
}

SortedSet::SortedSet(const IntList &a):IntList(a) {
    remove_duplicates();
    IntList::selection_sort();
}

const bool SortedSet::in(int data) const {
    for (IntNode *curr = head; curr != 0; curr = curr->next) {
        if (data == curr->data) {
            return true;
        }
    }
    return false;
}

const SortedSet SortedSet::operator |(const SortedSet &rhs) const {
    SortedSet temp = *this;
    for (IntNode *curr = rhs.head; curr != 0; curr = curr->next) {
        temp.IntList::insert_ordered(curr->data);
    }
    temp.remove_duplicates();
    return temp;
}

const SortedSet SortedSet::operator &(const SortedSet &rhs) const {
    SortedSet blah = SortedSet();
    SortedSet temp = *this;
    for (IntNode *curr = rhs.head; curr != 0; curr = curr->next) {
        if (temp.in(curr->data) == true) {
            blah.IntList::insert_ordered(curr->data);
        }
    }
    blah.remove_duplicates();
    return blah;
}

void SortedSet::add(int data) {
   if (head == 0) {
      IntList::push_front(data);
   }
   else if (tail->data < data) {
      IntList::push_back(data);
   }
   else if (head->data > data) {
      IntList::push_front(data);
   }
   else {
      for (IntNode* curr = head; curr != 0; curr = curr->next) {
         if ((curr->data < data) && (curr->next->data > data)) { 
            IntNode* temp = new IntNode(data);
            IntNode* nextNode = curr->next;
            
            curr->next = temp;
            temp->next = nextNode;
         }
      }
   }
}


void SortedSet::push_front(int data) {
    add(data);
}    

void SortedSet::push_back(int data) {
    add(data);
}

void SortedSet::insert_ordered(int data) {
    add(data);
}

SortedSet SortedSet::operator|=(const SortedSet &rhs) {
   for (IntNode *curr = rhs.head; curr != 0; curr = curr->next) {
         this->insert_ordered(curr->data);
   }
   return *this;
}

SortedSet SortedSet::operator&=(const SortedSet &rhs) {
   SortedSet blah;
   for (IntNode *curr = rhs.head; curr != 0; curr = curr->next) {
      if (this->in(curr->data) == true) {
         blah.insert_ordered(curr->data);
      }
   }
   *this = blah;
   return *this;
}