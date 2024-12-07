#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

int main(int argc, char** argv) {
    DoublyLinkedList<int> list;
    int choice;

    do {
        cout << endl;
        cout << "\nPress 1 to Forward Traversing";
        cout << "\nPress 2 to Reverse Traversing";
        cout << "\nPress 3 to Search Your Node";
        cout << "\nPress 4 to Add New Node to Head";
        cout << "\nPress 5 to Add New Node to Tail";
        cout << "\nPress 6 to Add New Node After The Given Node";
        cout << "\nPress 7 to Add New Node Before The Given Node";
        cout << "\nPress 8 to Remove Given Node From Head";
        cout << "\nPress 9 to Remove Given Node From Tail";
        cout << "\nPress 10 to Remove Given Node From Anywhere";
        cout << "\nPress 0 to Exit";
        cout << endl;

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Forward Traversing" << endl;
                list.forwardTraverse();
                break;
            case 2:
                cout << "Reverse Traversing" << endl;
                list.reverseTraverse();
                break;
            case 3: {
                int element;
                cout << "Enter Value To Search: ";
                cin >> element;
                list.searchElement(element);
                break;
            }
            case 4: {
                int element;
                cout << "Enter Value To Add To Head: ";
                cin >> element;
                list.addToHead(element);
                break;
            }
            case 5: {
                int element;
                cout << "Enter Value To Add To Tail: ";
                cin >> element;
                list.addToTail(element);
                break;
            }
            case 6: {
                int existingVal, newVal;
                cout << "Enter The Existing Value Of Node: ";
                cin >> existingVal;
                cout << "Enter The New Value To Add After The Existing Node: ";
                cin >> newVal;
                list.addAfter(existingVal, newVal);
                break;
            }
            case 7: {
                int givenVal, newVal;
                cout << "Enter The Existing Value Of Node: ";
                cin >> givenVal;
                cout << "Enter The New Value To Add Before The Existing Node: ";
                cin >> newVal;
                list.addBefore(givenVal, newVal);
                break;
            }
            case 8:
                list.deleteFromHead();
                break;
            case 9:
                list.deleteFromTail();
                break;
            case 10: {
                int element;
                cout << "Enter The Node Value To Delete: ";
                cin >> element;
                list.deleteNode(element);
                break;
            }
            case 0:
                exit(0);
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    while (true);
    return 0;
}