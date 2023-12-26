#include "Node.h"

Node::Node(std::string w) : word(w), next(nullptr), prev(nullptr) {}

std::string Node::getWord() const {
    return word;
}

void Node::setWord(const std::string& w) {
    word = w;
}

Node* Node::getNext() const {
    return next;
}

void Node::setNext(Node* n) {
    next = n;
}

Node* Node::getPrev() const {
    return prev;
}

void Node::setPrev(Node* p) {
    prev = p;
}


// member functions
bool Node::operator==(const std::string& rhs) const {
    return word == rhs;
}

bool Node::operator!=(const std::string& rhs) const {
    return word != rhs;
}

bool Node::operator>(const std::string& rhs) const {
    return word > rhs;
}

bool Node::operator<(const std::string& rhs) const {
    return word < rhs;
}

bool Node::operator>=(const std::string& rhs) const {
    return word >= rhs;
}

bool Node::operator<=(const std::string& rhs) const {
    return word <= rhs;
}

// Non-member functions
bool operator>(const std::string& lhs, const Node& rhs) {
    return lhs > rhs.getWord();
}

bool operator<(const std::string& lhs, const Node& rhs) {
    return lhs < rhs.getWord();
}

bool operator>=(const std::string& lhs, const Node& rhs) {
    return lhs >= rhs.getWord();
}

bool operator<=(const std::string& lhs, const Node& rhs) {
    return lhs <= rhs.getWord();
}

bool operator==(const std::string& lhs, const Node& rhs) {
    return lhs == rhs.getWord();
}

bool operator!=(const std::string& lhs, const Node& rhs) {
    return lhs != rhs.getWord();
}

bool Node::operator==(const Node& other) const {
    return word == other.word;
}

bool Node::operator!=(const Node& other) const {
    return word != other.word;
}

bool Node::operator>(const Node& other) const {
    return word > other.word;
}

bool Node::operator<(const Node& other) const {
    return word < other.word;
}

bool Node::operator>=(const Node& other) const {
    return word >= other.word;
}

bool Node::operator<=(const Node& other) const {
    return word <= other.word;
}
