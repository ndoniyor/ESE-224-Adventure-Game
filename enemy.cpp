#include "enemy.h"
#include <iostream>
using namespace std;

enemy::enemy(string n, int mh, int hp, int ad, int lvl){
    Name = n;
    MaxHealth = mh;
    HealthPoints = hp;
    AttackDamage = ad;
    Level = lvl;
}

string enemy::getName(){
    return Name;
}

int enemy::getMaxHP(){
    return MaxHealth;
}

int enemy::getHP(){
    return HealthPoints;
}

int enemy::getDMG(){
    return AttackDamage;
}

int enemy::getCurrency(){
    return Currency;
}

void enemy::setName(string n){
    Name = n;
}

void enemy::setMaxHP(int mh){
    MaxHealth = mh;
}

void enemy::setHP(int hp){
    HealthPoints = hp;
}

void enemy::setDMG(int ad){
    AttackDamage = ad;
}

void setCurrency(int c){
    Currency = c;
}
void enemy::ModifyHealth(int x){
    HealthPoints += x;
}

void enemy::ModifyDamage(int x){
    AttackDamage += x;
}

friend player::ostream& operator<<(ostream& os, const player& p)
{
    os <<"OS "<<p.Name << " " << p.MaxHealth << " " << p.HealthPoints << " " << p.AttackDamage << " " << p.Level << " " << p.Currency << endl;
    return os;
    
}

