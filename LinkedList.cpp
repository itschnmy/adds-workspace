#include "LinkedList.h"
#include <iostream>
#include <limits>
using namespace std;

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::LinkedList(int* array, int len) : head(nullptr) {
    Node* tail = nullptr;
    for (int i = 0; i < len; i++) {
        Node* newNode = new Node(array[i]);
        if (!head) {
            head = newNode;
            tail = head;
        } else {
            tail->setLink(newNode);
            tail = newNode;
        }
    }
}

LinkedList::~LinkedList() {
    Node* i = head;
    while(i) {
        Node* next = i->getLink();
        delete i;
        i = next;
    }
    head = nullptr;
}

void LinkedList::insertPosition(int pos, int newNum) {
    Node* newNode = new Node(newNum);
    if (pos <= 1 || !head) {
        newNode->setLink(head);
        head = newNode;
        return;
    }

    Node *i = head;
    int index = 1;
    while (i->getLink() && index < pos - 1) {
        i = i->getLink();
        index++;
    }

    newNode->setLink(i->getLink());
    i->setLink(newNode);
}

bool LinkedList::deletePosition(int pos) {
    if (!head || pos < 1) {
        return false;
    }

    if (pos == 1) {
        Node* i = head;
        head = head->getLink();
        delete i;
        return true;
    }

    Node *i = head;
    int index = 1;
    while (i->getLink() && index < pos - 1) {
        i = i->getLink();
        index++;
    }

    if (!i->getLink()) {
        return false;
    }

    Node* del = i->getLink();
    i->setLink(del->getLink());
    delete del;
    return true;
}

int LinkedList::get(int pos) {
    if (pos < 1) {
        return numeric_limits<int>::max();
    }
    Node *i = head;
    int index = 1;
    while (i->getLink() && index < pos - 1) {
        i = i->getLink();
        index++;
    }
    
    if (!i->getLink()) {
        return numeric_limits<int>::max();
    }

    return i->getData();
}

int LinkedList::search(int target) {
    Node* i = head;
    int pos = 1;
    while (i) {
        if (i->getData() == target) {
            return pos;
        }
        i = i->getLink();
        pos++;
    }
    return -1;
}


void LinkedList::printList() {
    Node* i = head;
    if (!i) return;
    cout << "[";
    while (i) {
        cout << i->getData();
        if (i->getLink()) {
            cout << " ";
            i = i->getLink();  
        }
    }
    cout << "]" << endl;
}
