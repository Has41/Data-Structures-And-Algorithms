#include <iostream>
#include "PNode.h"
using namespace std;

template<class T>
class PriorityQueue {
private:
    PNode<T>* front;
    PNode<T>* rear;
public:
    PriorityQueue() {
        this->front = nullptr;
        this->rear = nullptr;
    }
    void enqueue(T element, int priority);
    T dequeue();
    bool isEmpty();
    T frontValue();
    T rearValue();
};

template<class T>
void PriorityQueue<T>::enqueue(T element, int priority) {
    PNode<T>* n = new PNode<T>(element, priority, nullptr);
    if (rear == nullptr && front == nullptr) {
        front = rear = n;
    } else if (priority <= front->getPriority()) {
        n->setNext(front);
        front = n;
    } else {
        PNode<T>* current = front;
        PNode<T>* previous = nullptr;

        while (current != nullptr && current->getPriority() <= priority) {
            previous = current;
            current = (PNode<T>*)current->getNext();
        }

        if (previous != nullptr) {
            previous->setNext(n);
        }
        n->setNext(current);

        if (current == nullptr) {
            rear = n;
        }
    }
}

template<class T>
T PriorityQueue<T>::dequeue() {
    if (rear == nullptr && front == nullptr) {
        cerr << "Error!!! Queue is Empty\nNothing to Dequeue....";
        return T();
    } else if (front == rear) {
        T element = front->getInfo();
        front = rear = nullptr;
        return element;
    } else {
        T element = front->getInfo();
        PNode<T>* temp = front;
        front = (PNode<T>*)front->getNext();
        delete temp;
        return element;
    }
}

template<class T>
bool PriorityQueue<T>::isEmpty() {
    return front == nullptr && rear == nullptr;
}

template<class T>
T PriorityQueue<T>::frontValue() {
    if (rear == nullptr && front == nullptr) {
        cerr << "Error!!! Queue is Empty";
        return T();
    }
    return front->getInfo();
}

template<class T>
T PriorityQueue<T>::rearValue() {
    if (rear == nullptr && front == nullptr) {
        cerr << "Error!!! Queue is Empty";
        return T();
    } 
    return rear->getInfo();

} 