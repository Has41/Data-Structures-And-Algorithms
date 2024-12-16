#include <iostream>
#include "BST.h"
using namespace std;
//cd NonLinearDataStructures/Trees
int main() {
    BST<int> t1;
    t1.insert(20);
    t1.insert(50);
    t1.insert(25);
    t1.insert(31);
    t1.insert(26);
    t1.insert(41);
    t1.insert(37);
    t1.insert(72);
    t1.preOrderTraversal(t1.getRoot());
    return 0;
}