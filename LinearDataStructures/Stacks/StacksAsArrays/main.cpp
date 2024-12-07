#include <iostream>
#include "ArrayStack.h"
using namespace std;

void decimalToBinary(int number);

int main() {
    int choice;

    do {
        cout << endl;
        cout << "Press 1 to convert decimal to binary";
        cout << "\nPress 0 to Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int element;
                cout << "\nEnter the decimal number: ";
                cin >> element;
                cout << "\nThe decimal number is: ";
                decimalToBinary(element);
                cout << endl;
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
}

void decimalToBinary(int number) {
    ArrayStack<int> stack;

    while (number != 0) {
        stack.push(number % 2);
        number /= 2;
    }

    while (!stack.isEmpty()) {
        cout << stack.pop();
    }

}