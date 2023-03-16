#ifndef ENEMY_H
#define ENEMY_H


class Character{

    public:
        Character();
        Character(int health, int strength, int intelligence, int stamina, int charisma);


    private:
        int health;
        int strength;
        int intelligence;
        int stamina;
        int charisma;        

};






#endif