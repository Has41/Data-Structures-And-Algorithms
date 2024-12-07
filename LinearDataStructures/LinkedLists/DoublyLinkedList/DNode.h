#include <iostream>
#include "D:\Data Structures & Algorithms\LinearDataStructures\LinkedLists\SinglyLinkedList/Node.h"
using namespace std;

template <class T>
class DNode : public Node<T> {
private:
    DNode<T>* prev;
public:
    DNode(DNode<T>* prev = nullptr, T info = 0, DNode<T>* next = nullptr) : Node<T>(info, next) {
        this->prev = prev;
    }

    void setPrev(DNode<T>* prev);
    DNode<T>* getPrev();
    void displayNode();
};

template<class T>
void DNode<T>::setPrev(DNode<T>* prev) {
    this->prev = prev;
}

template<class T>
DNode<T>* DNode<T>::getPrev() {
    return this->prev;
}

template<class T>
void DNode<T>::displayNode() {
    cout << "(" << this << ") | " << prev << " | " << this->getInfo() << " | " << this->getNext() << " |" << endl;
}
