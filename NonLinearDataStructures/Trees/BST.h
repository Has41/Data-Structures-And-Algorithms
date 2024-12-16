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
    void preOrderTraversal(TNode<T>* tRoot);
    void inOrderTraversal(TNode<T>* tRoot);
    void postOrderTraversal(TNode<T>* tRoot);
    void findMinimum(TNode<T>* tRoot);
    TNode<T>* leftSuccessor(TNode<T>* t_root);
    TNode<T>* getParent(T element);
    void deleteNode(T element);
    TNode<T>* searchElement(T element);
    TNode<T>* getRoot();
};

template <class T>
void BST<T>::insert(T element) {
    TNode<T>* newNode = new TNode<T>(element);
    if (root == nullptr) {
        root = newNode;
    } else {
        TNode<T>* curr = root;
        while (curr != nullptr) {
            if (curr->getInfo() == element) {
                cerr << "Duplicates are not allowed";
            } else if (element < curr->getInfo()) {
                if (curr->getLeft() != nullptr) {
                    curr = curr->getLeft();
                } else {
                    curr->setLeft(newNode);
                    return;
                }
            } else {
                if (curr->getRight() != nullptr) {
                    curr = curr->getRight();
                } else {
                    curr->setRight(newNode);
                    return;
                }
            }
        }
    }
}

template <class T>
TNode<T>* BST<T>::getRoot() {
    return this->root;
}

template <class T>
void BST<T>::preOrderTraversal(TNode<T>* tRoot) {
    if (tRoot != nullptr) {
        cout << tRoot->getInfo() << "\t";
        preOrderTraversal(tRoot->getLeft());
        preOrderTraversal(tRoot->getRight());
    }
}

template <class T>
void BST<T>::inOrderTraversal(TNode<T>* tRoot) {
    if (tRoot != nullptr) {
        inOrderTraversal(tRoot->getLeft());
        cout << tRoot->getInfo() << "\t";
        inOrderTraversal(tRoot->getRight());
    }
}

template <class T>
void BST<T>::postOrderTraversal(TNode<T>* tRoot) {
    if (tRoot != nullptr) {
        postOrderTraversal(tRoot->getLeft());
        postOrderTraversal(tRoot->getRight());
        cout << tRoot->getInfo() << "\t";
    }
}

template <class T>
TNode<T>* BST<T>::searchElement(T element) {
    TNode<T>* node = root;
    while (node != nullptr) {
        if (node == element->getInfo()) {
            return node;
        } else if (element < node->getInfo()) {
            node = node->getLeft();
        } else {
            node = node->getRight();
        }
    }
    return nullptr;
}

template<class T>
void BST<T>::findMinimum(TNode<T>* tRoot) {
    while (tRoot->getLeft() != nullptr) {
        tRoot = tRoot->getLeft();
    }
    cout << "Minimum is : " << tRoot->getInfo() << endl;
}

template<class T>
TNode<T>* BST<T>::leftSuccessor(TNode<T>* tRoot) {
    if (tRoot != nullptr) {
        tRoot = tRoot->getLeft();

        while (tRoot->getRight() != nullptr) {
            tRoot = tRoot->getRight();
        }
        //cout<<"Left Successor is : "<<t_root->getInfo()<<endl;
        return tRoot;
    } else {
        return tRoot;
    }
}

template<class T>
TNode<T>* BST<T>::getParent(T element) {
    TNode<T>* parent = nullptr;
    TNode<T>* ptr = root;

    while (ptr != nullptr && ptr->getInfo() != element) {
        parent = ptr;
        if (element < ptr->getInfo()) {
            ptr = ptr->getLeft();
        } else {
            ptr = ptr->getRight();
        }
    }
    if (ptr == nullptr) {
        return nullptr;
    } else {
        return parent;
    }
}

template<class T>
void BST<T>::deleteNode(T element) {
    if (root == nullptr) {
        cerr << "Tree is empty \n";
        return;
    } else {
        TNode<T>* node = searchElement(element);
        if (node == nullptr) {
            cerr << "Element does not exist \n";
            return;
        } else {
            if (node->getLeft() == nullptr && node->getRight() == nullptr) {
                TNode<T>* parent = getParent(element);
                if (node == parent->getLeft())
                    parent->setLeft(nullptr);
                else
                    parent->setRight(nullptr);
                delete node;
            } else if ((node->getLeft() != nullptr && node->getRight() == nullptr) || (node->getLeft() == nullptr && node->getRight() != nullptr)) {
                TNode<T>* singleChild = nullptr;
                if ((node->getLeft() != nullptr && node->getRight() == nullptr))
                    singleChild = node->getLeft();
                else
                    singleChild = node->getRight();

                TNode<T>* parent = getParent(element);

                if (node == parent->getLeft())
                    parent->setLeft(singleChild);
                else
                    parent->setRight(singleChild);

                delete node;
            } else {
                TNode<T>* parent = getParent(element);
                TNode<T>* successor = leftSuccessor(node);
                TNode<T>* successorParent = getParent(successor->getInfo());
                if (successor->getLeft() == nullptr && successor->getRight() == nullptr)
                    successorParent->getRight(nullptr);
                else
                    successorParent->getRight(successor->getLeft());

                successor->setLeft(node->getLeft());
                successor->setRight(node->getRight());

                if (node == parent->getLeft())
                    parent->setLeft(successor);
                else
                    parent->setRight(successor);
            }
        }
    }
}