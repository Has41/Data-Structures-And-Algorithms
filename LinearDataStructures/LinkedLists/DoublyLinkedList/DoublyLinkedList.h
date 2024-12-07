#include <iostream>
#include "DNode.h"
using namespace std;

template<class T>

class DoublyLinkedList {
private:
    DNode<T>* head;
    DNode<T>* tail;
public:
    DoublyLinkedList() {
        head = 0;
        tail = 0;
    }
    void setHead(DNode<T>* head);
    void setTail(DNode<T>* tail);
    DNode<T>* getHead();
    DNode<T>* getTail();
    void forwardTraverse();
    void reverseTraverse();
    DNode<T>* searchElement(T element);
    void addToHead(T element);
    void addToTail(T element);
    void addAfter(T givenVal, T newVal);
    void addBefore(T givenVal, T newVal);
    void deleteFromHead();
    void deleteFromTail();
    void deleteNode(T element);
};

template<class T>
void DoublyLinkedList<T>::setHead(DNode<T>* head) {
    this->head = head;
}
template<class T>
void DoublyLinkedList<T>::setTail(DNode<T>* tail) {
    this->tail = tail;
}
template<class T>
DNode<T>* DoublyLinkedList<T>::getHead() {
    return head;
}
template<class T>
DNode<T>* DoublyLinkedList<T>::getTail() {
    return tail;
}

template<class T>
void DoublyLinkedList<T>::addToHead(T element) {
    DNode<T>* newNode = new DNode<T>(nullptr, element, nullptr);
    if (head == nullptr && tail == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->setNext(head);
        head->setPrev(newNode);
        setHead(newNode);
    }
}

template<class T>
void DoublyLinkedList<T>::addToTail(T element) {
    DNode<T>* newNode = new DNode<T>(nullptr, element, nullptr);
    if (head == nullptr && tail == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->setNext(newNode);
        newNode->setPrev(tail);
        setTail(newNode);
    }
}

template<class T>
void DoublyLinkedList<T>::forwardTraverse() {
    if (head == nullptr) {
        cerr << "List is empty!" << endl;
        return;
    }
    DNode<T>* index = head;

    while (index != nullptr) {
        index->displayNode();
        index = (DNode<T>*)index->getNext();
    }
}

template<class T>
void DoublyLinkedList<T>::reverseTraverse() {
    if (tail == nullptr) {
        cerr << "List is empty or tail not defined!" << endl;
        return;
    }
    DNode<T>* index = tail;

    while (index != nullptr) {
        index->displayNode();
        index = index->getPrev();
    }
}

template<class T>
DNode<T>* DoublyLinkedList<T>::searchElement(T element) {
    DNode<T>* index = head;

    while (index != nullptr) {
        if (element == index->getInfo()) {
            break;
        }
        index = (DNode<T>*)index->getNext();
    }
    return index;
}

template<class T>
void DoublyLinkedList<T>::addAfter(T givenVal, T newVal) {
    DNode<T>* givenNode = searchElement(givenVal);

    if ((head == nullptr && tail == nullptr) && givenNode == nullptr) {
        cerr << "List is empty or element not found!";
        return;
    } else if (givenVal == tail->getInfo()) {
        addToTail(newVal);
    } else {
        DNode<T>* newNode = new DNode<T>(nullptr, newVal, nullptr);
        DNode<T>* nextNode = (DNode<T>*)givenNode->getNext();
        newNode->setPrev(givenNode);
        newNode->setNext(nextNode);
        givenNode->setNext(newNode);
        if (nextNode) {
            nextNode->setPrev(newNode);
        }
    }
}

template<class T>
void DoublyLinkedList<T>::addBefore(T givenVal, T newVal) {
    DNode<T>* givenNode = searchElement(givenVal);

    if ((head == nullptr && tail == nullptr) && givenNode == nullptr) {
        cerr << "List is empty or element not found!";
        return;
    } else if (givenVal == head->getInfo()) {
        addToHead(newVal);
    } else {
        DNode<T>* newNode = new DNode<T>(nullptr, newVal, nullptr);
        DNode<T>* prevNode = givenNode->getPrev();
        newNode->setNext(givenNode);
        newNode->setPrev(prevNode);
        givenNode->setPrev(newNode);
        if (prevNode) {
            prevNode->setNext(newNode);
        }
    }
}

template<class T>
void DoublyLinkedList<T>::deleteFromHead() {
    if (head == nullptr && tail == nullptr) {
        cerr << "List is empty or element not found!";
        return;
    } else if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        DNode<T>* newHead = (DNode<T>*)head->getNext();
        newHead->setPrev(nullptr);
        delete head;
        setHead(newHead);
    }
}

template<class T>
void DoublyLinkedList<T>::deleteFromTail() {
    if (head == nullptr && tail == nullptr) {
        cerr << "List is empty or element not found!";
        return;
    } else if (head == tail) {
        delete tail;
        head = tail = nullptr;
    } else {
        DNode<T>* newTail = tail->getPrev();
        newTail->setNext(nullptr);
        delete tail;
        setTail(newTail);
    }
}

template<class T>
void DoublyLinkedList<T>::deleteNode(T element) {
    DNode<T>* givenNode = searchElement(element);

    if ((head == nullptr && tail == nullptr) && givenNode == nullptr) {
        cerr << "List is empty or element not found!";
        return;
    } else if (head == tail && head->getInfo() == element) {
        deleteFromHead();
    } else if (head->getInfo() == element) {
        deleteFromHead();
    } else if (tail->getInfo() == element) {
        deleteFromTail();
    } else {
        DNode<T>* prevNode = givenNode->getPrev();
        DNode<T>* nextNode = (DNode<T>*)givenNode->getNext();
        if (prevNode) prevNode->setNext(nextNode);
        if (nextNode) nextNode->setPrev(prevNode);
        delete givenNode;
    }
}