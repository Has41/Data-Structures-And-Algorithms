#include <iostream>
#include "D:\Data Structures & Algorithms\LinearDataStructures\LinkedLists\SinglyLinkedList/Node.h"
using namespace std;

template<class T>
class LinkedStack {
private:
    Node<T>* top;
public:
    LinkedStack() {
        this->top = 0;
    }
    void push(T element);
    T pop();
    bool isEmpty();
    T topValue();
};

template<class T>
void LinkedStack<T>::push(T element) {
    Node<T>* newNode = new Node<T>(element, nullptr);
    if (top == nullptr) {
        top = newNode;
    } else {
        newNode->setNext(top);
        top = newNode;
    }
}

template<class T>
T LinkedStack<T>::pop() {
    if (top == nullptr) {
        cerr << "Stack Underflow! \n";
        return T();
    } else if (top->getNext() == nullptr) {
        T element = top->getInfo();
        delete top;
        top = nullptr;
        return element;
    } else {
        Node<T>* newNode = top->getNext();
        T element = top->getInfo();
        delete top;
        top = newNode;
        return element;
    }
}

template<class T>
bool LinkedStack<T>::isEmpty() {
    return top == nullptr;
}

template<class T>
T LinkedStack<T>::topValue() {
    if (top == nullptr) {
        cerr << "Stack Underflow! \n";
        return T();
    }
    return top->getInfo();
}