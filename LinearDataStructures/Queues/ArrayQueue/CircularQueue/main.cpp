#include <iostream>
#include "CircularQueue.h"
using namespace std;

//? cd LinearDataStructures/Queues/ArrayQueue/CircularQueue

int main() {
    CircularQueue<char> q(4);
    q.enqueue('a');
    q.enqueue('b');
    q.enqueue('c');
    q.enqueue('d');
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    q.enqueue('e');
    while (!q.isEmpty()) {
        cout << q.dequeue() << "\t";
    }
    return 0;
}