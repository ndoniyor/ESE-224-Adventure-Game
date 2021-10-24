#include <iostream>
#include <string>
using namespace std;


class player
{
    private:
        string Name;            //This should hold the player’s name
        int MaxHealth;          //This should hold the maximum health of the player
        int HealthPoints;       //This should hold the current health of the player
        int AttackDamage;       //This should hold the attack damage of the player
        int Currency;
        int Durability;
    public:
        player(string n, int mh, int hp, int ad);               //default constructor
        string getName();
        int getMaxHP();         //returns the maximum health
        int getHP();            //returns the current health
        int getDMG();           //returns the current damage
        int getCurrency();
        int getDurability();
        void setName(string n);
        void setMaxHP(int mh);
        void setHP(int hp);        //sets the current health
        void setDMG(int ad);       //sets the current damage
        void ModifyHealth(int x); //Increments or decrements the player’s health by the input value
        void ModifyDamage(int x); //Increments or decrements the player’s attack damage by the input value
        void setCurrency(int c);
        void setDurability(int d);
 
        friend ostream& operator <<(ostream& os, const player& p);
};
