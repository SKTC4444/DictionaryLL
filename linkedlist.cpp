#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr), tail(nullptr), listSize(0) {}

LinkedList::LinkedList(const std::string& word) : head(new Node(word)), tail(head), listSize(1) {}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->getNext();
        delete current;
        current = next;
    }
}

// linked list push back operation
void LinkedList::push_back(const std::string& word) {
    Node* newNode = new Node(word);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->setNext(newNode);
        newNode->setPrev(tail);
        tail = newNode;
    }
    listSize++;
}

// Nodes in linked list
int LinkedList::size() const {
    return listSize;
}

Node* LinkedList::getHead() const {
    return head;
}

Node* LinkedList::getTail() const {
    return tail;
}

Node* LinkedList::deleteWord(Node* nodeToDelete) {
    if (!nodeToDelete) {
        return nullptr;
    }

    Node* nextNode = nodeToDelete->getNext();

    if (nodeToDelete == head) {
        head = nextNode;
    }
    if (nodeToDelete == tail) {
        tail = nodeToDelete->getPrev();
    }
    if (nodeToDelete->getPrev()) {
        nodeToDelete->getPrev()->setNext(nextNode);
    }
    if (nextNode) {
        nextNode->setPrev(nodeToDelete->getPrev());
    }

    delete nodeToDelete;
    listSize--;
    return nextNode;
}

Node* LinkedList::insert_before(const std::string& newWord, Node* knownNode) {
    Node* newNode = new Node(newWord);


    if (head == nullptr || knownNode == head) {
        newNode->setNext(head);
        if (head != nullptr) {
            head->setPrev(newNode);
        } else {

            tail = newNode;
        }
        head = newNode;
    } else {

        Node* prevNode = (knownNode != nullptr) ? knownNode->getPrev() : tail;
        newNode->setNext(knownNode);
        newNode->setPrev(prevNode);

        if (prevNode != nullptr) {
            prevNode->setNext(newNode);
        }

        if (knownNode != nullptr) {
            knownNode->setPrev(newNode);
        } else {

            tail = newNode;
        }
    }

    listSize++;
    return newNode;
}

void LinkedList::print() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->getWord() << std::endl;
        current = current->getNext();
    }
}
