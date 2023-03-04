#ifndef STATS_H
#define STATS_H


class Stats{

    private: 
        int health;
        int strength;
        int intelligence;
        int charisma;
        int stamina;

    public:
        Stats(int hp = 0, int str = 0, int iq = 0, int chr = 0, int stm = 0);
        int getStrength();
        int getHealth();
      //  void printStats(Stats* stats);       


};



#endif