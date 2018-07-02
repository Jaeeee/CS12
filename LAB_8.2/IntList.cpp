#include "IntList.h"

#include <iostream>

using namespace std;

IntList::IntList() {
    head = 0;
}

void IntList::push_front(int value) {
    IntNode *temp = head;
    head = new IntNode(value);
    head->next = temp;
}

ostream &operator<<(ostream &out, IntNode *curr) {
    if (curr != 0) {
        if (curr->next == 0) {
            out << curr->data;
        } else {
            out << curr->data << ' ' << curr->next;
        }
    }
    return out;
}

ostream &operator<<(ostream &out, const IntList &rhs) {
    IntNode *temp = rhs.head;
    if (temp != 0) {
        if (temp->next == 0) {
            out << temp->data;
        } else {
            out << temp->data << ' ' << temp->next;
        }
    }
    return out;
}

bool IntList::exists(IntNode *curr, int value) const {
    if (curr == 0) {
        return false;
    } else if (curr->data == value) {
        return true;
    }
    return exists(curr->next, value);
}

bool IntList::exists(int value) const {
   if (head == 0) {
       return false;
   }
   else if (head->data == value) {
       return true;
   }
   return exists(head->next, value);
}