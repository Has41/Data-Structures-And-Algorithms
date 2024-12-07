#include <iostream>
#include "TNode.h"
using namespace std;

template <class T>

class BST {
private:
    TNode<T>* root;
public:
    BST() {
        this->root = nullptr;
    }
    void insert(T element);
    TNode<T>* getRoot();
};

template <class T>
void BST<T>::insert(T element) {
    TNode<T>* newNode = new TNode<T>;
    if (root == nullptr) {
        root = newNode;
    } else {
        TNode<T>* curr = root;
        TNode<T>* prev = nullptr;
        while (curr != nullptr) {
            if (curr->getInfo() == element) {
                cerr << "Duplicates are not allowed";
            } else if (element < curr->getInfo()) {
                curr = curr->getLeft();
            } else {
                curr = curr->getRight();
            }
        }
    }
}

template <class T>
TNode<T>* BST<T>::getRoot() {
    return this->root;
}