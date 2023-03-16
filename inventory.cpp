#include "inventory.h" 


Inventory::Inventory(int size, int currentSize) {
    maxSize = size; 
    this->currentSize = currentSize;
   // items.push_back(Item("Sword", "weapon")); // manually inserting weapon for now
   // items.push_back(Item("Test", "test"));
}

void Inventory::addItem(Item item){   
    int inventorySize = 20;
    if(currentSize < inventorySize){
        items.push_back(item);
        currentSize++;
      //  cout << items[2].getName() << endl;
    } else {
        cout << "Inventory is full. Discard Items to gain this item." << endl;
    }

}

void Inventory::displayInventory(){
    for(int i = 0; i < currentSize; i++){
        cout << items[i].getName() << " | Type:" << items[i].getID() << endl; 
    }


}
