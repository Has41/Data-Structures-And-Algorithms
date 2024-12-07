#include <iostream>
#include "PriorityQueue.h"
using namespace std;

int main() {
    PriorityQueue<string> pq;
    pq.enqueue("Task A", 2);
    pq.enqueue("Task B", 1);
    pq.enqueue("Task C", 3);
    pq.enqueue("Task D", 1);

    cout << "Dequeued: " << pq.dequeue() << endl; // Task D
    cout << "Dequeued: " << pq.dequeue() << endl; // Task B
    cout << "Dequeued: " << pq.dequeue() << endl; // Task A
    cout << "Dequeued: " << pq.dequeue() << endl; // Task C
    return 0;
}