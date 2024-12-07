#include <iostream>
using namespace std;

template <class T>
class TNode {
private:
    T info;
    TNode<T>* left;
    TNode<T>* right;
public:
    TNode(T info = 0, TNode<T>* left = nullptr, TNode<T>* right = nullptr) {
        this->info = info;
        this->left = left;
        this->right - right;
    }
    T getInfo();
    void setInfo(T info);
    TNode<T>* getLeft();
    void setLeft(TNode<T>* left);
    TNode<T>* getRight();
    void setRight(TNode<T>* right);
    void display();
};

template <class T>
T TNode<T>::getInfo() {
    return this->info;
}

template <class T>
void TNode<T>::setInfo(T info) {
    this->info = info;
}

template <class T>
TNode<T>* TNode<T>::getLeft() {
    return this->left;
}

template <class T>
void TNode<T>::setLeft(TNode<T>* left) {
    this->left = left;
}

template <class T>
TNode<T>* TNode<T>::getRight() {
    return this->right;
}

template <class T>
void TNode<T>::setRight(TNode<T>* right) {
    this->right = right;
}

template <class T>
void TNode<T>::display() {
    cout << "|" << this->left << "|" << this->info << "|" << this->right << "|" << endl;
}
