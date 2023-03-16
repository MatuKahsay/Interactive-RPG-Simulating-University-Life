#include "Character.h"

Character::Character() {

}
Character::Character(int health, int strength, int intelligence, int stamina, int charisma){
    this->health = health;
    this->strength = strength;
    this->intelligence = intelligence;
    this->stamina = stamina;
    this->charisma = charisma;
}