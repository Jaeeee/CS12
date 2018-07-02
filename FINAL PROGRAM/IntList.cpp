#include "IntList.h"

#include <iostream>

using namespace std;

IntList::IntList() {
    head = 0;
    tail = 0;
}

IntList::IntList(const IntList &cpy) {
    head = 0;
    tail = 0;
    for (IntNode *newList = cpy.head; newList != 0; newList = newList->next) {
        push_back(newList->data);
    }
}

IntList::~IntList() {
    while (head != 0) {
        pop_front();
    }
}


IntList& IntList::operator=(const IntList& rhs) {
    if (this != &rhs) {
        this->head = 0;
        this->tail = 0;
    for (IntNode *newList = rhs.head; newList != 0; newList = newList->next) {
        this->push_back(newList->data);
        }
    }
    return *this;
} 

// IntList& IntList::operator=(const IntList& rhs)
// {
//     IntList* temp;
// 	if(this != &rhs) {
// 		clear();
// 		temp = new IntList(rhs);
// 		*this = *temp;
// 	}
// 	return *this;
// }

void IntList::display() const {
    if (head != 0) {
        IntNode *temp = head->next;
        cout << head->data;
        while (temp != 0) {
            cout << " " << temp->data;
            temp = temp->next;
        }
    }
}

void IntList::push_front(int value) {
    if (head != 0) {
        IntNode *temp = new IntNode(value);
        temp->next = head;
        head = temp;
    } else {
        head = new IntNode(value);
        tail = head;
    }
}

void IntList::push_back(int value) {
    if (head == 0) {
        head = tail = new IntNode(value);
        return;
    }
    IntNode *temp = new IntNode(value);
    tail->next = temp;
    tail = temp;
}

void IntList::pop_front() {
    if (head == 0) {
        return;
    } else if (head != 0) {
        IntNode *temp = head->next;
        delete head;
        head = temp;
    }
}

bool IntList::empty() const {
    if (head == 0) {
        return true;
    } else {
    return false;
    }
}

void IntList::selection_sort() {
    for (IntNode *i = head; i != 0; i = i->next) {
        int min = i->data;
        for (IntNode *j = i->next; j != 0; j = j->next) {
            if (j->data < min) {
                min = j->data;
                j->data = i->data;
                i->data = min;
            }
        }
    }
}

void IntList::remove_duplicates() {
    if (empty()) {
        return;
    }
    
   IntNode* marker = 0;
		IntNode* prev = head;
		IntNode* curr;

		for (curr = head; curr != 0; curr = curr->next) {
		marker = curr->next;
		prev = curr;
		while (marker != 0) {

		if (curr->data == marker->data) {

			IntNode* temp = marker;

			if (marker == tail) {
				marker = 0;
				prev->next = 0;
				tail = prev;
				delete temp;
				}
					else {
					prev->next = marker->next;
					marker = marker->next;
					delete temp;
					}
				}
				else {
				marker = marker->next;
				prev = prev->next;
				}
			}
		}
    }

void IntList::clear() {
    while (head != 0) {
        pop_front();
    }
}

void IntList::insert_ordered(int value) {
        if (head == 0 || value <= head->data) { 
			push_front(value);
	}
		else if (head->next == 0) {
			if (value > head->data) { 
				push_back(value);
			}
			else if (value <= head->data) { 
				push_front(value);
			}
		}
		else if (value >= tail->data) {
			push_back(value);
	}
	else {
		IntNode* prev = head;
		IntNode* curr = head->next;
		for (IntNode* cnt = head; value < prev->data ||
		 value > curr->data; cnt = cnt->next) {
			prev = cnt->next;
			curr = prev->next;
		}
		IntNode* temp = new IntNode(value);
		temp->next = curr;
		prev->next = temp;
		}
    }


const int & IntList::front() const {
    return head->data;  
}

const int & IntList::back() const {
    return tail->data;
}

ostream & operator<<(ostream &out, const IntList &rhs) {
    IntNode* temp = rhs.head;

		while (temp != 0) {
			if (temp == rhs.tail || rhs.tail == rhs.head) {
			out << temp->data;
		}	
			else {
			out << temp->data << ' ';
			}
		temp = temp->next;
		}
    return out;
}