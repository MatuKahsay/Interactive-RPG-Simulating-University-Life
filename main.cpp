#include <iostream>
#include <string> 
#include <vector>
#include "inventory.h"

using namespace std; 

int main(){
   Inventory inventory1(10); 
   //inventory1.displayInventory();
   inventory1.addItem(Item("Sword", "weapon"));
   inventory1.addItem(Item("Bow", "weapon"));
   inventory1.addItem(Item("Shield", "weapon"));
   inventory1.displayInventory();


    return 0;
}