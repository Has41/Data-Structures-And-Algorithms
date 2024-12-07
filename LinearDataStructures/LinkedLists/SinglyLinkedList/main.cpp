#include <iostream>
#include "SinglyLinkedList.h" 
using namespace std;

int main(int argc, char** argv) {
    SinglyLinkedList<int> list;

    int choice;
    int element;

    do {
        cout << endl;
        cout << "Press 1 to Add New Node to Head";
        cout << "\nPress 2 to Add New Node to Tail";
        cout << "\nPress 3 to Display Linked List";
        cout << "\nPress 4 to Search Element In Linked List";
        cout << "\nPress 5 to Find Number Of Occurrences Of Element In Linked List";
        cout << "\nPress 6 to Add Element After The Existing Node";
        cout << "\nPress 7 to Add Element Before The Existing Node";
        cout << "\nPress 8 to Delete From Head";
        cout << "\nPress 9 to Delete From Tail";
        cout << "\nPress 10 to Delete Any Node";
        cout << "\nPress 0 to Exit";
        cout << endl;

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system("cls");
                cout << "Enter the Info to Head: ";
                cin >> element;
                list.addToHead(element);
                break;

            case 2:
                system("cls");
                cout << "Enter the Info to Tail: ";
                cin >> element;
                list.addToTail(element);
                break;

            case 3:
                system("cls");
                list.traverse();
                break;

            case 4:
                system("cls");
                cout << "Enter The Element To Search: ";
                cin >> element;
                cout << "Your element is in node having address: " << list.searchElement(element);
                break;

            case 5:
                system("cls");
                cout << "Enter The Element To Find Its Occurrences: ";
                cin >> element;
                list.findOccurrences(element);
                break;
            case 6: {
                system("cls");
                int existingVal, newVal;
                cout << "Enter The Existing Value Of Node: ";
                cin >> existingVal;
                cout << "Enter The New Value To Add After The Existing Node: ";
                cin >> newVal;
                list.addAfter(existingVal, newVal);
                break;
            }
            case 7: {
                system("cls");
                int existingVal, newVal;
                cout << "Enter The Existing Value Of Node: ";
                cin >> existingVal;
                cout << "Enter The New Value To Add Before The Existing Node: ";
                cin >> newVal;
                list.addBefore(existingVal, newVal);
                break;
            }
            case 8:
                list.deleteFromHead();
                break;
            case 9:
                list.deleteFromTail();
                break;
            case 10: {
                system("cls");
                cout << "Enter The Node Value To Delete It's Node: ";
                cin >> element;
                list.deleteNode(element);
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
