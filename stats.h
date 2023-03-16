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
        void setStrength(int newStr);
        void setHealth(int newHp);
        void setCharisma(int newChr);
        void setIntelligence(int newIq);
        void setStamina(int newStm);
        int getStrength();
        int getHealth();
        int getCharisma();
        int getIntelligence();
        int getStamina();
      //  void printStats(Stats* stats);       


};



#endif