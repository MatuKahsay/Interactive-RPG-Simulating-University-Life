#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string> 
#include <vector>
#include "Stats.h"



using namespace std;

class Item{
    private:
        string itemID;
        string itemName;
        Stats itemStats;


    public:
        Item(string name, string ID, const Stats& itemStat);
        string getName() const;
        string getID() const;
        void setID(string ID);
        void setName(string name);
        Stats& getStats();


};

#endif 