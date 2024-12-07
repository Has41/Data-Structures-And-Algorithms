#include <iostream>
#include "D:\Data Structures & Algorithms\LinearDataStructures\LinkedLists\SinglyLinkedList/Node.h"
using namespace std;

template<class T> // To make it usefull for all pre-defined or user-defined data types
class LinkedQueue {
// Instance Variable
private:
    Node<T>* front;
    Node<T>* rear;
public:
// Default Constructor
    LinkedQueue() {
        this->front = 0;
        this->rear = 0;
    }
// Methods / Functions
    void enqueue(T element); // addToHead()
    T dequeue(); // removeFromHead()
    bool isEmpty();
    T frontValue();
    T rearValue();
};

template<class T>
void LinkedQueue<T>::enqueue(T element) {
// Creating an Object of a new Node
    Node<T>* n = new Node<T>(element, 0);
    14
        if (rear == 0 && front == 0) {
            front = n;
            rear = n;
        } // if
        else {
            n->setNext(front);
            front = n;
        } // else
} // enqueue


template<class T>
T LinkedQueue<T>::dequeue() {
    if (rear == 0 && front == 0) {
        cerr << "Error!!! Queue is Empty\nNothing to Dequeue....";
    } // if
    else if (front == rear) {
        T element = rear->getInfo();
        front = 0;
        rear = 0;
        return element;
    } // else if
    else {
        Node<T>* ptr = front;
        while (ptr->getNext()->getNext() != 0) {
            ptr = ptr->getNext();
        } // while
        T element = rear->getInfo();
        ptr->setNext(0);
        rear = ptr;
        return element;
    } // else
} // dequeue

template<class T>
bool LinkedQueue<T>::isEmpty() {
    if (rear == 0 && front == 0) {
        return true;
    } // if
    else {
        return false;
    } // else
} // isEmpty

template<class T>
T LinkedQueue<T>::frontValue() {
    if (rear == 0 && front == 0) {
        cerr << "Error!!! Queue is Empty";
        15
    } // if
    else {
        return front->getInfo();
    }
} // frontValue

template<class T>
T LinkedQueue<T>::rearValue() {
    if (rear == 0 && front == 0) {
        cerr << "Error!!! Queue is Empty";
    } // if
    else {
        return rear->getInfo();
    } // else
} // rearValue