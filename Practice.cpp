#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* link;
    Node(int value) : data(value), link(nullptr) {}
}

void deleteHeadNode(Node* head) {
    if (head == nullptr) {
        return;
    }
    Node* i = head;
    head = head->link;
    delete i;
}

void deleteLastNode(Node* head) {
    if (head == nullptr) {
        return;
    }
    if (head->link == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* i = head;
    int index = 0;
    while(i->link != nullptr) {
        i = i->link;
        index++;
    }
    Node* j = head;
    for (int i = 0; i < index-1; i++) {
        j = j->link;
    }

    j->link = nullptr;
    delete i;
}

void deleteAtPosition(Node* head, int pos) {
    if (head == nullptr || pos < 0) {
        return;
    }
    Node* i = head;
    if (pos == 0) {
        head = head->link;
        delete i;
        return;
    }
    for (int j = 0; j < pos; j++) {
        if (i->link == nullptr) {
            return;
        }
        i = i->link;
    }

    Node* del = i->link;
    i->link = del->link;
    delete del;
}

void deleteFirstValue(Node* head, int value) {
    if (head == nullptr) {
        return;
    }
    Node* i = head;
    while (i->link != nullptr && i->link->data != val) {
        i = i->link;
    }

    if (i->link != nullptr) {
        Node* del = i->link;
        i->link = del->link;
        delete del;
    }

}

void swapValues(Node* head, int i, int j) {
    if (head == nullptr || i < 0 || j < 0) {
        return;
    }
    Node* swap1 = head;
    Node* swap2 = head;

    for (int k = 0; k < i; k++) {
        if (swap1->link == nullptr) {
            return;
        }
        swap1 = swap1->link;
    }

    for (int k = 0; k < j; k++) {
        if (swap2->link == nullptr) {
            return;
        }
        swap2 = swap2->link;
    }

    swap(swap1->data, swap2->data);
}

void swapNodes()