#ifndef STATS_H
#define STATS_H
#include <iostream>


class Stats{

    private: 
        int health;
        int strength;
        int intelligence;
        int charisma;
        int stamina;

    public:
        // Stats(int hp = 0, int str = 0, int iq = 0, int chr = 0, int stm = 0);
        Stats();
        void setHealth(int hp);
        int getHealth();
        int getStrength();
        void setStrength(int str);
        void setIntelligence(int iq);
        int getIntelligence();
        void setStamina(int stm);
        int getStamina();
        void setCharisma(int chr);
        int getCharisma();


        // int getStrength();
        // int getHealth();
      //  void printStats(Stats* stats);       


};


#endif