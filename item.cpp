#include "item.h"
#include "Stats.h"


Item::Item(string name, string ID, const Stats& itemStat){
    itemName = name;
    itemID = ID;
    itemStats = itemStat;
    
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

Stats& Item::getStats() {
    return itemStats;
}