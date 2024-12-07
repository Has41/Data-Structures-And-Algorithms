#include <iostream>
#include <fstream>
#include <sstream>
#include "ItemsLinkedList.h"
#include "CartLinkedList.h"
using namespace std;

void loadItems(string filename, ItemsLinkedList<Item*>& itemsList);

int main() {
    ItemsLinkedList<Item*> itemsList;
    CartLinkedList<Cart*> cart;
    loadItems("Items.txt", itemsList);
    int choice;

    do {
        cout << endl;
        itemsList.traverse();
        cout << "Press 1 to Add Item To Cart." << endl;
        cout << "Press 2 to Delete Item From Cart" << endl;
        cout << "Press 3 to Display Your Items" << endl;
        cout << "Press 4 to Exit" << endl;
        cout << "Press 0 to Generate Bill" << endl;

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id, quantity;
                cout << "Enter item ID: ";
                cin >> id;
                cout << "Enter item quantity: ";
                cin >> quantity;
                cart.addItem(id, quantity, itemsList);
                break;
            }
            case 2: {
                int itemId;
                cout << "Enter the ID of the item to delete: ";
                cin >> itemId;
                cart.deleteItem(itemId);
                break;
            }
            case 3: {
                cout << "The items are: " << endl;
                itemsList.traverse();
                // cart.traverse();
                break;
            }
            case 4:
                cout << "Exiting program......." << endl;
                return 0;
            case 0: {
                cart.generateBill();
                break;
            }
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    while (true);
    return 0;
}

void loadItems(string filename, ItemsLinkedList<Item*>& itemsList) {
    ifstream inFile(filename); //Open file

    if (!inFile) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        Item* newItem = new Item;
        string priceStr;

        getline(ss, priceStr, ',');
        newItem->setItemId(stoi(priceStr));
        getline(ss, priceStr, ',');
        newItem->setItemName(priceStr);
        getline(ss, priceStr, ',');
        newItem->setItemDetail(priceStr);
        getline(ss, priceStr);
        newItem->setItemPrice(stof(priceStr));

        itemsList.addToTail(newItem);
    }

    inFile.close(); // Close the file
}
