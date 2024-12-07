#include <iostream>
using namespace std;

template <class T>
class Queue {
private:
    int rear;
    int front;
    int size;
    T* arr;
public:
    Queue(int size = 5) {
        this->front = -1;
        this->rear = -1;
        this->size = size;
        arr = new T(size);
    }
    void enqueue(T element);
    T dequeue();
    bool isFull();
    bool isEmpty();
    T rearValue();
    T frontValue();
};

template <class T>
void Queue<T>::enqueue(T element) {
    if (rear == size - 1) {
        cerr << "There is no vacant slot!";
        return;
    } else if (rear == -1 && front == -1) {
        rear++;
        front++;
        arr[rear] = element;
    } else {
        rear++;
        arr[rear] = element;
    }
}

template <class T>
T Queue<T>::dequeue() {
    if (rear == -1 && front == -1) {
        cerr << "Queue is empty";
        return;
    } else if (rear == front) {
        T element = arr[front];
        rear = front = -1;
        return element;
    } else {
        T element = arr[front];
        front++;
        return element;
    }
}

template <class T>
bool Queue<T>::isEmpty() {
    return front == -1 && rear == -1;
}

template <class T>
bool Queue<T>::isFull() {
    return rear == size - 1;
}

template <class T>
T Queue<T>::frontValue() {
    if (front == -1 && rear == -1) {
        cerr << "Queue is empty!";
        return;
    }
    return arr[front];
}

template <class T>
T Queue<T>::rearValue() {
    if (front == -1 && rear == -1) {
        cerr << "Queue is empty!";
        return;
    }
    return arr[rear];
}