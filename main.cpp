#include <iostream>
#include <string> 
#include <vector>
#include "inventory.h"
#include "Enemy.h"
#include "Item.h"
#include "Player.h"
#include <cassert>

#include "Stats.h"
using namespace std; 

int main(){
   Inventory inventory1(10); 
   //inventory1.displayInventory();
   Stats itemObject;
   itemObject.setStrength(10);
   itemObject.setHealth(10);
   Item item("Sword", "weapon", itemObject);
   inventory1.addItem(item);
  // inventory1.addItem(Item("Bow", "weapon"));
  // inventory1.addItem(Item("Shield", "weapon"));
   inventory1.displayInventory();
   Enemy enemy("easy");


   //Player mock

   Player player;

   player.setMajor("Computer Science");
   Stats playerStats;
   player.setStats(playerStats);

   player.equipItem(playerStats, item);
   player.showStats(playerStats);
   player.unequipItem(playerStats, item);
   player.showStats(playerStats);

   // Enemy mock

   // Test getDiff method
    cout << enemy.getDiff();
    enemy.setDiff("medium");
    assert(enemy.getDiff() == "medium");
    Stats enemyStats;
    enemy.setStats(enemyStats, "hard");

    // Testing setStats method
    assert(enemyStats.getHealth() == 100);
    assert(enemyStats.getStrength() == 60);

    // Testing showStats method
    enemy.showStats(enemyStats);

    //Stats for player
    Stats playerStats1;
    playerStats1.setHealth(100);
    playerStats1.setStrength(50);

    // Test attack method
    enemy.attack(playerStats1, enemyStats);
    cout << endl;
    player.attack(playerStats1, enemyStats);
    cout << endl;
    player.showStats(playerStats1);
    enemy.showStats(enemyStats);




  
   


    return 0;
}