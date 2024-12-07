#include <iostream>
#include "D:\Data Structures & Algorithms\LinearDataStructures\LinkedLists\SinglyLinkedList/Node.h"
using namespace std;

template <class T>
class PNode : public Node<T> {
private:
    int priority;
public:
    PNode(T info, int priority, PNode<T>* next = nullptr) : Node<T>(info, next) {
        this->priority = priority;
    }
    void setPriority(int priority);
    int getPriority();
    void displayNode();
};

template<class T>
void PNode<T>::setPriority(int priority) {
    this->priority = priority;
}

template<class T>
int PNode<T>::getPriority() {
    return this->priority;
}

template<class T>
void PNode<T>::displayNode() {
    cout << " | " << this->getInfo() << " | " << this->getPriority() << "|" << this->getNext() << " |" << endl;
}
