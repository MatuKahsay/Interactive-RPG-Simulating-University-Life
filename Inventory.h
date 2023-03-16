#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>
#include "Item.h" 

using namespace std;

class Inventory{
    private: 
        int inventoryID;
        int maxSize; 
        int currentSize;

    public:
        vector<Item> items;
        Inventory(int maxSize, int currentSize = 0);
        void addItem(Item item);
        void displayInventory();


};

#endif