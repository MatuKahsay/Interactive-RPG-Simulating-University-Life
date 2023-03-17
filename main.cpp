#include <iostream>
#include <string> 
#include <vector>
#include "inventory.h"
#include "Enemy.h"
using namespace std; 

int main(){
   Inventory inventory1(10); 
   //inventory1.displayInventory();
   Item item("Sword", "weapon",Stats(10, 0, 0,0,0));
   inventory1.addItem(Item("Sword", "weapon",Stats(10, 0, 0,0,0)));
  // inventory1.addItem(Item("Bow", "weapon"));
  // inventory1.addItem(Item("Shield", "weapon"));
   inventory1.displayInventory();

   Enemy enemy1(Stats(5, 5, 5, 5, 5), 30);
   enemy1.getStats().setCharisma(10);
   enemy1.printStats();
   cout << "Testing add item " << endl;
   enemy1.equipItem(item); 
   enemy1.printStats();
   cout << "Testing removing item " << endl;
   enemy1.unequipItem(item);
   enemy1.printStats();
   item.getStats().setHealth(15);
   enemy1.equipItem(item);
   cout << "Testing updated item" << endl;
   enemy1.printStats();


    return 0;
}