#include <iostream>
#include "Cart.h"
#include "D:\Data Structures & Algorithms\LinearDataStructures\LinkedLists\SinglyLinkedList\SinglyLinkedList.h"
using namespace std;

template <class T>
class CartLinkedList :public SinglyLinkedList<T> {
public:
    void traverse();
    void addItem(int id, int quantity, ItemsLinkedList<Item*> itemList);
    void deleteItem(int id);
    void generateBill();
};

template<class T>
void CartLinkedList<T>::traverse() {
    Node<T>* index = this->getHead();

    if (index == nullptr) {
        cerr << "Your cart is empty!" << endl;
        return;
    }

    while (index != nullptr) {
        index->getInfo()->displayCart();
        index = index->getNext();
    }
}

template <class T>
void CartLinkedList<T>::addItem(int itemId, int quantity, ItemsLinkedList<Item*> itemList) {
    if (itemId <= 0 || quantity <= 0) {
        cerr << "Please input valid item id & quantity." << endl;
        return;
    }

    Node<Item*>* node = itemList.findItemById(itemId);

    if (node == nullptr) {
        cerr << "Item not found!" << endl;
        return;
    }

    Item* item = node->getInfo();

    Cart* cartItem = new Cart(item->getItemId(), item->getItemName(), item->getItemDetail(), item->getItemPrice(), quantity);
    this->addToTail(cartItem);

    cout << "Item added successfully!" << endl;
}


template <class T>
void CartLinkedList<T>::deleteItem(int itemId) {
    if (itemId <= 0) {
        cerr << "Please enter a valid item ID!" << endl;
        return;
    }

    Node<T>* current = this->getHead();
    Node<T>* previous = nullptr;

    while (current != nullptr) {
        if (current->getInfo()->getItemId() == itemId) {
            if (previous == nullptr) {
                this->setHead(current->getNext());
            } else {
                previous->setNext(current->getNext());
            }
            delete current;
            cout << "Item deleted successfully from the cart!" << endl;
            return;
        }
        previous = current;
        current = current->getNext();
    }
    cerr << "Item with ID " << itemId << " not found in the cart!" << endl;
}


template<class T>
void CartLinkedList<T>::generateBill() {
    double totalAmount = 0;
    Node<T>* current = this->getHead();
    while (current != nullptr) {
        cout << "Item name: " << current->getInfo()->getItemName()
            << " & Item Price: " << current->getInfo()->getItemPrice()
            << " & Item quantity: " << current->getInfo()->getItemQuantity() << endl;

        totalAmount += current->getInfo()->getItemPrice() * current->getInfo()->getItemQuantity();
        current = current->getNext();
    }

    cout << "Total amount to pay: " << totalAmount << endl;
}