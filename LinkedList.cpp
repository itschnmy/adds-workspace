#include "LinkedList.h"
#include <iostream>
#include <limits>
using namespace std;

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::LinkedList(int* array, int len) : head(nullptr) {
    if (len <= 0) return;
    head = new Node(array[0]);
    Node* current = head;
    for (int i = 1; i < len; ++i) {
        current->link = new Node(array[i]);
        current = current->link;
    }
}

LinkedList::~LinkedList() {
    Node* i = head;
    while(i != nullptr) {
        Node* next = i->link;
        delete i;
        i = next;
    }
    head = nullptr;
}

void LinkedList::insertPosition(int pos, int newNum) {
    Node* newNode = new Node(newNum);
    if (pos <= 1 || head == nullptr) {
        newNode->link = head;
        head = newNode;
        return;
    }

    Node *current = head;
    for (int i = 1; i < pos - 1 && current->link != nullptr; i++) {
        current = current->link;
    }

    newNode->link = current->link;
    current->link = newNode;
}

bool LinkedList::deletePosition(int pos) {
    if (head == nullptr || pos < 1) {
        return false;
    }

    if (pos == 1) {
        Node* i = head;
        head = head->link;
        delete i;
        return true;
    }

    Node *prev = head;
    for (int i = 1; i < pos - 1 && prev->link != nullptr; i++) {
        prev = prev->link;
    }
    if (prev->link == nullptr) {
        return false;
    }
    Node* del = prev->link;
    prev->link = del->link;
    delete del;
    return true;
}

int LinkedList::get(int pos) {
    if (pos < 1) return numeric_limits<int>::max();

    Node* i = head;
    int index = 1;
    while (i != nullptr) {
        if (index == pos) {
            return i->data;
        }
        i = i->link;
        index++;
    }
    return numeric_limits<int>::max();
}

int LinkedList::search(int target) {
    Node* i = head;
    int pos = 1;
    while (i != nullptr) {
        if (i->data == target) return pos;
        i = i->link;
        pos++;
    }
    return -1;
}


void LinkedList::printList() {
    if (head == nullptr) return;
    Node* i = head;
    cout << "[";
    while (i != nullptr) {
        cout << i->data;
        if (i->link != nullptr) {
            cout << " ";
        }
        i = i->link;
    }
    cout << "]" << endl;
}
