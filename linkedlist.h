//
// Created by Subhan Khan on 12/26/23.
//

#ifndef DICTIONARYLL_LINKEDLIST_H
#define DICTIONARYLL_LINKEDLIST_H


#include "Node.h"
#include <string>

//declared linkedlist class and added private and public elements.
class LinkedList {
private:
    Node* head;
    Node* tail;
    int listSize;

// public definitions that are used in linkedlist.cpp
public:
    LinkedList();
    explicit LinkedList(const std::string& word);
    ~LinkedList();
    void push_back(const std::string& word);
    Node* insert_before(const std::string& newWord, Node* knownNode);
    int size() const;
    Node* getHead() const;
    Node* getTail() const;
    Node* deleteWord(Node* nodeToDelete);
    void print() const;
};

#endif