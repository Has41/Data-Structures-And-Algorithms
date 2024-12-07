#include <iostream>
using namespace std;

template <class T>
class CircularQueue {
private:
    int rear;
    int front;
    int size;
    T* arr;
public:
    CircularQueue(int size = 5) {
        this->rear = -1;
        this->front = -1;
        this->size = size;
        arr = new T(this->size);
    }
    void enqueue(T element);
    T dequeue();
    bool isEmpty();
    bool isFull();
    T rearValue();
    T frontValue();
};

template <class T>
void CircularQueue<T>::enqueue(T element) {
    if ((front == 0 && rear == size - 1) || rear == front - 1) {
        cerr << "Queue is full!";
        return;
    } else if (front == -1 && rear == -1) {
        rear++;
        front++;
        arr[rear] = element;
    } else if (front > 0 && rear == size - 1) {
        rear = 0;
        arr[rear] = element;
    } else {
        rear++;
        arr[rear] = element;
    }
}

template <class T>
T CircularQueue<T>::dequeue() {
    if (front == -1 && rear == -1) {
        cerr << "Queue is empty!";
        return T();
    } else if (front == rear) {
        T element = arr[front];
        front = rear = -1;
        return element;
    } else if (front == size - 1 && front > rear) {
        T element = arr[front];
        front = 0;
        return element;
    } else {
        T element = arr[front];
        front++;
        return element;
    }
}

template <class T>
bool CircularQueue<T>::isEmpty() {
    return front == -1 && rear == -1;
}

template <class T>
bool CircularQueue<T>::isFull() {
    return (front == 0 && rear == size - 1) || rear == front - 1;
}

template <class T>
T CircularQueue<T>::frontValue() {
    if (isEmpty()) {
        cerr << "No front value because queue is empty";
        return T();
    }
    return arr[front];
}

template <class T>
T CircularQueue<T>::rearValue() {
    if (isEmpty()) {
        cerr << "No rear value because queue is empty";
        return T();
    }
    return arr[rear];
}