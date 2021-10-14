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

void enemy::ModifyHealth(int x){
    HealthPoints += x;
}

void enemy::ModifyDamage(int x){
    AttackDamage += x;
}

