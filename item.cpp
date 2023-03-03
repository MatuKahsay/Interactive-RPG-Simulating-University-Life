#include "item.h"


Item::Item(string name, string ID){
    itemName = name;
    itemID = ID;
}

void Item::setName(string name){
    itemName = name;
}

string Item::getName() const {
    return itemName;
}

void Item::setID(string ID){
    itemID = ID;
}

string Item::getID() const {
    return itemID;
}



