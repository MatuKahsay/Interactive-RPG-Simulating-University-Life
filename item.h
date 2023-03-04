
#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string> 
#include <vector>

using namespace std;

class Item{
    private:
        string itemID;
        string itemName;


    public:
        Item(string name, string ID);
        string getName() const;
        string getID() const;
        void setID(string ID);
        void setName(string name);


};

#endif 