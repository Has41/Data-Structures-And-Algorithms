#include <iostream>
#include "D:\Data Structures & Algorithms\LinearDataStructures\LinkedLists\SinglyLinkedList\SinglyLinkedList.h"
using namespace std;

template <class T>
class ItemsLinkedList :public SinglyLinkedList<T> {
public:
    void traverse();
    Node<T>* findItemById(int itemId);
};

template<class T>
void ItemsLinkedList<T>::traverse() {
    Node<T>* index = this->getHead();

    while (index != nullptr) {
        index->getInfo()->displayItem();
        index = index->getNext();
    }
}

template<class T>
Node<T>* ItemsLinkedList<T>::findItemById(int itemId) {
    Node<T>* current = this->getHead();

    while (current != nullptr) {
        if (current->getInfo()->getItemId() == itemId) {
            return current;
        }
        current = current->getNext();
    }

    return nullptr;
}