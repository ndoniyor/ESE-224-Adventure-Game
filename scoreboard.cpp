#include "scoreboard.h"
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;

scoreboard::scoreboard()
{
     SB_Name = "enter name";            //This should hold the player’s name
     SB_score = 0;              // score of player
     SB_difficulty = "easy";       //dif of game
     SB_difficultyMod = 1;
     SB_Floor = 1;
}

scoreboard::scoreboard(string n, int s, string d, int dm, int f)
{
    SB_Name = n;
    SB_score = s;
    SB_difficulty = d;
    SB_difficultyMod = dm;
    SB_Floor = f;
}

void scoreboard::setName(string n)
{
    SB_Name = n;
}

void scoreboard::setScore(int s)
{
    SB_score = s;
}

void scoreboard::setDiff(string d)
{
    SB_difficulty = d;
}

void scoreboard::setDiffMod(int dm)
{
    SB_difficultyMod = dm;
}

void scoreboard::setFloor(int f)
{
    SB_Floor = f;
}

string scoreboard::getName()
{
    return SB_Name;
}

int scoreboard::getScore()
{
    return SB_score;
}

string scoreboard::getDiff()
{
    return SB_difficulty;
}

int scoreboard::getFloor()
{
    return SB_Floor;
}

void scoreboard::AddScore(int s)
{
     SB_score +=s;
     
}

void scoreboard::SB_out()
{
    cout << "player name:" << SB_Name << endl;
    cout << "Difficulty:" << SB_difficulty << endl;
    cout << "Floor is:" << SB_Floor << endl;

}

ostream& operator<<(ostream& os, const scoreboard& p)
{
    os <<"OS "<<p.SB_Name << " " << p.SB_difficulty << " " << p.SB_Floor << " " << p.SB_score << " " << p.SB_difficultyMod << endl;
    return os;
    
}
