
#include "Action.h"

#include <iostream>
#include <random>


using namespace std;



void Action::studyAtLibrary(Stats & playerStats) {
    
    cout << "You have decided to go to the library to study for your exams. Doing so has granted you a boost in your intelligence by 10. " << endl;
    int increaseIQ =  playerStats.getIntelligence() + 10;
    
    playerStats.setIntelligence(increaseIQ);
    
    cout << "By going to to the library, you weren't able to go to Glassgow to eat or go to the SRC for a workout. In addition, there was party that you were invited, but you didn't attend.  " << endl;
    cout << "All of these actions result in a loss of 10 points to your strength, stamina, and charisma. " << endl;

    int decreasestr =  playerStats.getStrength() - 10;
    
    playerStats.setStrength(decreasestr);

    int decreasestam =  playerStats.getStamina() - 10;
    
    playerStats.setStamina(decreasestam);

    int decreasechr =  playerStats.getCharisma() - 10;
    
    playerStats.setCharisma(decreasechr);

}


void Action::goToParty(Stats & playerStats) {

    cout << "You have decided to go to the party that your friends invited you to. Doing so has granted you a boost in your charisma by 10. " << endl;
    int increasechr =  playerStats.getCharisma() + 10;
    
    playerStats.setCharisma(increasechr);
    
    cout << "By going to to the party, you weren't able to go to Glassgow to eat or go to the SRC for a workout. In addition, you have an exam tommorow, but you didn't study for it. " << endl;
    cout << "All of these actions result in a loss of 10 points to your strength, stamina, and intelligence. " << endl;

    int decreasestr =  playerStats.getStrength() - 10;
    
    playerStats.setStrength(decreasestr);

    int decreasestam =  playerStats.getStamina() - 10;
    
    playerStats.setStamina(decreasestam);

    int decreaseiq =  playerStats.getIntelligence() - 10;
    
    playerStats.setIntelligence(decreaseiq); 
}

void Action::eatAtGlassgow(Stats & playerStats) {

    cout << "You have decided to go to eat at Glassgow. Doing so has granted you a boost in your stamina by 10. " << endl;
    int increasestm =  playerStats.getStamina() + 10;
    
    playerStats.setStamina(increasestm);
    
    cout << "By going to to Glassgow, you weren't able to go to the party that your frineds invited you to eat or go to the SRC for a workout. In addition, you have an exam tommorow, but you didn't study for it. " << endl;
    cout << "All of these actions result in a loss of 10 points to your strength, charisma, and intelligence. " << endl;

    int decreasestr =  playerStats.getStrength() - 10;
    
    playerStats.setStrength(decreasestr);

    int decreasechr =  playerStats.getCharisma() - 10;
    
    playerStats.setCharisma(decreasechr);

    int decreaseiq =  playerStats.getIntelligence() - 10;
    
    playerStats.setIntelligence(decreaseiq); 

}

void Action::workoutAtSRC(Stats & playerStats) {

    cout << "You have decided to go to the SRC and workout. Doing so has granted you a boost in your strength by 10. " << endl;
    int increasestr =  playerStats.getStrength() + 10;
    
    playerStats.setStrength(increasestr);
    
    cout << "By going to to the SRC, you weren't able to go to the party that your frineds invited you  or go eat at Glassgow. In addition, you have an exam tommorow, but you didn't study for it. " << endl;
    cout << "All of these actions result in a loss of 10 points to your stamina, charisma, and intelligence. " << endl;

    int decreasestam =  playerStats.getStamina() - 10;
    
    playerStats.setStamina(decreasestam);

    int decreasechr =  playerStats.getCharisma() - 10;
    
    playerStats.setCharisma(decreasechr);

    int decreaseiq =  playerStats.getIntelligence() - 10;
    
    playerStats.setIntelligence(decreaseiq); 
}




