#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
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
    int floor;
public:
    player(string n, int mh, int hp, int ad, int d);               //default constructor
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

};



class enemy
{
private:
    string Name;            //This should hold the player�s name
    int MaxHealth;          //This should hold the maximum health of the player
    int HealthPoints;       //This should hold the current health of the player
    int AttackDamage;       //This should hold the attack damage of the player
    int Level = 0;
    int Currency = 0;
public:
    enemy(string n, int mh, int hp, int ad, int lvl);  //default constructor
    string getName();
    int getMaxHP();                 //returns the maximum health
    int getHP();                    //returns the current health
    int getDMG();                   //returns the current damage
    int getCurrency();
    int getLevel();
    void setLevel(int l);
    void setName(string n);
    void setMaxHP(int mh);
    void setHP(int hp);             //sets the current health
    void setDMG(int ad);            //sets the current damage
    void setCurrency(int c);
    void ModifyHealth(int x);       //Increments or decrements the player�s health by the input value
    void ModifyDamage(int x);   //Increments or decrements the player�s attack damage by the input value


};



class weapon
{
private:
    string W_item;
    int W_damage;
    int W_uses;
    int W_cost;
public:
    weapon();
    weapon(string i, int d, int u, int c);
    void setItem(string);
    void setDMG(int);
    void setUses(int);
    void setCost(int);
    string getItem();
    int getDMG();
    int getUses();
    int getCost();
    bool degradation();
};


class scoreboard
{
private:
    string SB_Name;            //This should hold the player�s name
    int SB_score;              // score of player
    string SB_difficulty;       //dif of game
    double SB_difficultyMod;
    int SB_Floor;
public:
    scoreboard();
    scoreboard(string n, int s, string d, double dm, int f);
    void setName(string n);
    void setScore(int s);
    void setDiff(string d);
    void setDiffMod(double dm);
    void setFloor(int f);
    double getDiffMod();
    string getName();
    int getScore();
    string getDiff();
    int getFloor();

    void AddScore(int s);

    void SB_out();

    friend ostream& operator <<(ostream& os, const scoreboard& p); //needs to be implemented
};

class RandomEvent {
public:
    void getEvent(player& p, scoreboard& s);
};


class FileOperations {
private:
    //default constructor
    string SB_file_name = "scoreboard.txt";
    //holds the name of the scoredboard file
    fstream SB_myFile;
    //opens the scoreboard file

    string P_file_name;
    //holds the name of the player file
    fstream p_myFile;
    //opens the player file
    vector<int> sortedScores;
    vector<string> sortedNames;



public:
    FileOperations();
    void Save2FileP(player& p, scoreboard& s, vector<weapon>);
    //function Saves player progress into a file
    void Save2FileS(scoreboard& s, player& p);
    //function saves scoreboard progress into a file
    vector<string> ChooseFile(scoreboard& s, player& p);
    //function the asks the user to select the file to use
    void CloseFile();
    //function to close the files
    void ScoreRank(string outs);
    //function to output scores from all the scoreboards
};