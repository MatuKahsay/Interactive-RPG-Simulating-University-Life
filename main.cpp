#include "Player.h"
#include "Enemy.h"
#include "Action.h"
#include "Stats.h"
#include "Combat.h"
#include "Item.h"
#include "Inventory.h"

#include <iostream>
#include <random>

using namespace std;

int main() {

    string major = "Health";

    Stats playerStats;

    Player player1;

    player1.setMajor(major);

    player1.setStats(playerStats);

    player1.showStats(playerStats);

    cout << endl;


    Enemy enemy1;

    Stats enemyStats;

    enemy1.setDiff(2);

    enemy1.setStats(enemyStats);

    enemy1.showStats(enemyStats);

    // cout << endl;

    // Combat combat;

    // Action action;

    // combat.Fight(player1, playerStats, enemy1, enemyStats);

    // cout << endl;

    // player1.showStats(playerStats);

    // cout << endl;

    // enemy1.showStats(enemyStats);

    // cout << endl;

    // combat.Run(playerStats);

    // cout << endl;

    // combat.Talk(playerStats);

    // cout << endl;

    // combat.Examine(playerStats);

    // cout << endl;

    // action.goToParty(playerStats);

    // cout << endl;

    // player1.showStats(playerStats);

    // cout << endl;

    // action.studyAtLibrary(playerStats);

    // cout << endl;

    // player1.showStats(playerStats);

    // cout << endl;


    // action.workoutAtSRC(playerStats);

    // cout << endl;

    

    // action.eatAtGlassgow(playerStats);

    // cout << endl;

    // player1.showStats(playerStats);

    // cout << endl;


    Inventory firstInv(20);

    Stats itemStats;

    int changehealht = itemStats.getStrength() + 10;

    itemStats.setStrength(changehealht);

    Item firstItem("pencil", "iq", itemStats);

    firstInv.addItem(firstItem);

    firstInv.displayInventory();

    player1.showStats(playerStats);

    cout << endl;

    player1.equipItem(playerStats, firstItem);

    cout << endl;


    player1.showStats(playerStats);

    cout << endl;

    firstItem.getStats();









    return 0;

}