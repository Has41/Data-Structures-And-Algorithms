#include <iostream>
using namespace std;

template <class T>
class ArrayStack {
private:
    int top;
    int size;
    T* arr;

public:
    ArrayStack(int size = 5) {
        top = -1;
        size = size;
        arr = new T(size);
    }

    void push(T element);
    T pop();
    bool isEmpty();
    bool isFull();
    T topValue();
};

template <class T>
void ArrayStack<T>::push(T element) {
    if (top == size - 1) {
        cerr << "Stack Overflow \n";
    } else {
        top++;
        arr[top] = element;
    }
}

template <class T>
T ArrayStack<T>::pop() {
    if (top == -1) {
        cerr << "Stack Underflow \n";
        return T();
    } else {
        T element = arr[top];
        top--;
        return element;
    }
}

template <class T>
bool ArrayStack<T>::isEmpty() {
    return top == -1;
}

template <class T>
bool ArrayStack<T>::isFull() {
    return top == size - 1;
}

template <class T>
T ArrayStack<T>::topValue() {
    if (isEmpty()) {
        cerr << "Stack Underflow \n";
    } else {
        return arr[top];
    }
}