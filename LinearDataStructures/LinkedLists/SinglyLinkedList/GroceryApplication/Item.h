#include <iostream>
using namespace std;

class Item {
private:
    int itemId;
    string itemName;
    string itemDetail;
    double itemPrice;
public:
    Item(int itemId = 0, string itemName = "", string itemDetail = "", double itemPrice = 0) {
        this->itemId = itemId;
        this->itemName = itemName;
        this->itemDetail = itemDetail;
        this->itemPrice = itemPrice;
    }
    int getItemId();
    string getItemName();
    string getItemDetail();
    double getItemPrice();
    void setItemId(int itemId);
    void setItemName(string itemName);
    void setItemDetail(string itemDetail);
    void setItemPrice(double itemPrice);
    void displayItem();
};

void Item::setItemId(int itemId) {
    this->itemId = itemId;
}

void Item::setItemName(string itemName) {
    this->itemName = itemName;
}

void Item::setItemDetail(string itemDetail) {
    this->itemDetail = itemDetail;
}

void Item::setItemPrice(double itemPrice) {
    this->itemPrice = itemPrice;
}

int Item::getItemId() {
    return this->itemId;
}

string Item::getItemName() {
    return this->itemName;
}

string Item::getItemDetail() {
    return this->itemDetail;
}

double Item::getItemPrice() {
    return this->itemPrice;
}

void Item::displayItem() {
    cout << endl;
    cout << "Item Id is: " << this->itemId << endl;
    cout << "Item Name is: " << this->itemName << endl;
    cout << "Item Detail is: " << this->itemDetail << endl;
    cout << "Item Price is: " << this->itemPrice << endl;
    cout << endl;
}
