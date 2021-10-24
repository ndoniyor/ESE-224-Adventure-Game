#include "player.h"
#include <iostream>
using namespace std;

player::player(string n, int mh, int hp, int ad, int d){
    Name = n;
    MaxHealth = mh;
    HealthPoints = hp;
    AttackDamage = ad;
    Durability = d;
}

string player::getName(){
    return Name;
}

int player::getMaxHP(){
    return MaxHealth;
}

int player::getHP(){
    return HealthPoints;
}

int player::getDMG(){
    return AttackDamage;
}
int player::getCurrency(){
    return Currency;
}
int player::getDurability(){
    return Durability;
}
void player::setName(string n){
    Name = n;
}

void player::setMaxHP(int mh){
    MaxHealth = mh;
}

void player::setHP(int hp){
    HealthPoints = hp;
}

void player::setDMG(int ad){
    AttackDamage = ad;
}

void player::setCurrency(int c){
    Currency = c;
}

void player::ModifyHealth(int x){
    HealthPoints += x;
}

void player::ModifyDamage(int x){
    AttackDamage += x;
}
void player::setDurability(int d){
    Durability=d;
}
friend player::ostream& operator<<(ostream& os, const player& p)
{
    os <<"OS "<<p.Name << " " << p.MaxHealth << " " << p.HealthPoints << " " << p.AttackDamage << " " << p.Currency << endl;
    return os;
    
}

