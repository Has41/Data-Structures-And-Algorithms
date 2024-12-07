#include <iostream>
#include "D:\Data Structures & Algorithms\LinearDataStructures\LinkedLists\SinglyLinkedList\SinglyLinkedList.h"
using namespace std;

template <class T>
class CourseLinkedList :public SinglyLinkedList<T> {
public:
    void traverse();
};

template<class T>
void CourseLinkedList<T>::traverse() {
    Node<T>* index = this->getHead();

    while (index != nullptr) {
        index->getInfo()->displayCourse();
        index = index->getNext();
    }
}
