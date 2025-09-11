#include "Node.h"
#include <iostream>

Node::Node(int value) :data(value), link(nullptr) {}

int Node::getData() {
    return data;
}

Node* Node::getLink() {
    return link;
}

void Node::setLink(Node* next) {
    link = next;
}