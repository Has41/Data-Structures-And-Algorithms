#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
    Queue<int> queue;
    int choice;

    do {
        cout << endl;
        cout << "Press 1 to add value in queue";
        cout << "Press 2 to remove value in queue";
        cout << "\nPress 0 to Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int element;
                cout << "\nEnter the value to add to queue: ";
                cin >> element;
                queue.enqueue(element);
                cout << endl;
                break;
            }
            case 2: {
                int result = queue.dequeue();
                cout << "Removed value from queue is: " << result << endl;
                break;
            }
            case 0:
                exit(0);
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    while (true);
    return 0;
}