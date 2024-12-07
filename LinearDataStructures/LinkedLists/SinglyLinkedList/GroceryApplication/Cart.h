#include <iostream>
#include "Item.h"
using namespace std;

class Cart {
private:
    int itemId;
    string itemName;
    string itemDetail;
    double itemPrice;
    int itemQuantity;
public:
    Cart(int itemId = 0, string itemName = "", string itemDetail = "", double itemPrice = 0, int itemQuantity = 0) {
        this->itemId = itemId;
        this->itemName = itemName;
        this->itemDetail = itemDetail;
        this->itemPrice = itemPrice;
        this->itemQuantity = itemQuantity;
    }
    int getItemId();
    string getItemName();
    string getItemDetail();
    double getItemPrice();
    int getItemQuantity();
    void setItemId(int itemId);
    void setItemName(string itemName);
    void setItemDetail(string itemDetail);
    void setItemPrice(double itemPrice);
    void setItemQuantity(int quantity);
    void displayCart();

};

void Cart::setItemId(int itemId) {
    this->itemId = itemId;
}

void Cart::setItemName(string itemName) {
    this->itemName = itemName;
}

void Cart::setItemDetail(string itemDetail) {
    this->itemDetail = itemDetail;
}

void Cart::setItemPrice(double itemPrice) {
    this->itemPrice = itemPrice;
}

void Cart::setItemQuantity(int itemQuantity) {
    this->itemQuantity = itemQuantity;
}

int Cart::getItemId() {
    return this->itemId;
}

string Cart::getItemName() {
    return this->itemName;
}

string Cart::getItemDetail() {
    return this->itemDetail;
}

double Cart::getItemPrice() {
    return this->itemPrice;
}

int Cart::getItemQuantity() {
    return this->itemQuantity;
}

void Cart::displayCart() {
    cout << endl;
    cout << "Item Id is: " << this->itemId << endl;
    cout << "Item Name is: " << this->itemName << endl;
    cout << "Item Detail is: " << this->itemDetail << endl;
    cout << "Item Price is: " << this->itemPrice << endl;
    cout << "Item Quantity is: " << this->itemQuantity << endl;
    cout << endl;
}
