#include <iostream>
#include "LinkedQueue.h"
using namespace std;

int main(int argc, char** argv) {
// Create an empty LinkedQueue of type int
    LinkedQueue<int> LQ;
    // Enqueing some elements
    LQ.enqueue(7);
    LQ.enqueue(8);
    LQ.enqueue(0);
    LQ.enqueue(0);
    cout << "\n===================================\n";
    cout << "\tDequeing Elements\n";
    cout << "===================================\n\n";
    // Loop will be executed till the
    // Queue becomes empty
    while (!LQ.isEmpty()) {
    // Dequeing Elements
        cout << LQ.dequeue();
    } // while
} // main