#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>
#include "Node.h"

using namespace std;

template<class T>

class SinglyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    SinglyLinkedList() {
        head = tail = nullptr;
    }

    void setHead(Node<T>* head);
    void setTail(Node<T>* tail);
    Node<T>* getHead();
    Node<T>* getTail();

    void addToHead(T element);
    void addToTail(T element);
    void traverse();
    Node<T>* searchElement(T element);
    void findOccurrences(T element);
    void addAfter(T existingVal, T newVal);
    void addBefore(T existingVal, T newVal);
    void deleteFromHead();
    void deleteFromTail();
    void deleteNode(T element);
};

template<class T>
void SinglyLinkedList<T>::setHead(Node<T>* head) {
    this->head = head;
}

template<class T>
void SinglyLinkedList<T>::setTail(Node<T>* tail) {
    this->tail = tail;
}

template<class T>
Node<T>* SinglyLinkedList<T>::getHead() {
    return this->head;
}

template<class T>
Node<T>* SinglyLinkedList<T>::getTail() {
    return this->tail;
}

template<class T>
void SinglyLinkedList<T>::traverse() {
    Node<T>* index = head;

    while (index != nullptr) {
        index->displayNode();
        index = index->getNext();
    }
}

template<class T>
void SinglyLinkedList<T>::addToHead(T element) {
    Node<T>* newNode = new Node<T>(element, nullptr);
    if (head == nullptr && tail == nullptr) {
        head = tail = newNode;
    } else {
        newNode->setNext(head);
        setHead(newNode);
    }
}

template<class T>
void SinglyLinkedList<T>::addToTail(T element) {
    Node<T>* newNode = new Node<T>(element, nullptr);
    if (head == nullptr && tail == nullptr) {
        head = tail = newNode;
    } else {
        tail->setNext(newNode);
        setTail(newNode);
    }
}

template<class T>
Node<T>* SinglyLinkedList<T>::searchElement(T element) {
    Node<T>* index = head;

    while (index != nullptr) {
        if (element == index->getInfo()) {
            break;
        }
        index = index->getNext();
    }
    return index;
}

template<class T>
void SinglyLinkedList<T>::findOccurrences(T element) {
    Node<T>* index = head;
    int count = 0;

    while (index != nullptr) {
        if (element == index->getInfo()) {
            count++;
        }
        index = index->getNext();
    }

    cout << "Number Of Occurrences Of Element: " << count << endl;
}

template<class T>
void SinglyLinkedList<T>::addAfter(T existingVal, T newVal) {
    Node<T>* existingNode = searchElement(existingVal);

    if ((head == nullptr && tail == nullptr) || existingNode == nullptr) {
        cerr << "List is empty or element not found!";
        return;
    } else if (existingVal == tail->getInfo()) {
        addToTail(newVal);
    } else {
        Node<T>* newNode = new Node<T>(newVal, nullptr);
        newNode->setNext(existingNode->getNext());
        existingNode->setNext(newNode);
    }
}

template<class T>
void SinglyLinkedList<T>::addBefore(T existingVal, T newVal) {
    Node<T>* existingNode = searchElement(existingVal);

    if ((head == nullptr && tail == nullptr) || (existingNode == nullptr)) {
        cerr << "List is empty or element not found!";
        return;
    } else if (existingVal == head->getInfo()) {
        addToHead(newVal);
    } else {
        Node<T>* newNode = new Node<T>(newVal, nullptr);
        newNode->setNext(existingNode);
        Node<T>* prevNode = head;

        while (prevNode->getNext()->getInfo() != existingVal) {
            prevNode = prevNode->getNext();
        }
        prevNode->setNext(newNode);
    }
}

template<class T>
void SinglyLinkedList<T>::deleteFromHead() {
    if (head == nullptr && tail == nullptr) {
        cerr << "List is empty!";
        return;
    } else if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        Node<T>* newHead = head->getNext();
        delete head;
        setHead(newHead);
    }
}

template<class T>
void SinglyLinkedList<T>::deleteFromTail() {
    if (head == nullptr && tail == nullptr) {
        cerr << "List is empty!";
        return;
    } else if (head == tail) {
        delete tail;
        head = tail = nullptr;
    } else {
        Node<T>* currentNode = head;
        while (currentNode->getNext() != tail) {
            currentNode = currentNode->getNext();
        }
        delete tail;
        setTail(currentNode);
        tail->setNext(nullptr);
    }
}

template<class T>
void SinglyLinkedList<T>::deleteNode(T element) {
    Node<T>* searchedElement = searchElement(element);

    if (searchedElement == nullptr || (head == nullptr && tail == nullptr)) {
        cerr << "Element not found or List is empty!";
        return;
    } else if (head->getInfo() == element) {
        deleteFromHead();
        return;
    } else if (tail->getInfo() == element) {
        deleteFromTail();
        return;
    } else {
        Node<T>* currentNode = head;
        Node<T>* previousNode = nullptr;

        while (currentNode != nullptr && currentNode->getInfo() != element) {
            previousNode = currentNode;
            currentNode = currentNode->getNext();
        }

        if (currentNode != nullptr) {
            previousNode->setNext(currentNode->getNext());
            delete currentNode;
        }
    }
}

#endif