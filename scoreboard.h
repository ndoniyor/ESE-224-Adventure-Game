#include <iostream>
#include <string>
using namespace std;


class scoreboard
{
private:
    string SB_Name;            //This should hold the player’s name
    int SB_score;              // score of player
    string SB_difficulty;       //dif of game
    int SB_difficultyMod;
    int SB_Floor;
public:
    scoreboard();
    scoreboard(string n, int s, string d, int dm, int f);
    void setName(string n);
    void setScore(int s);
    void setDiff(string d);
    void setDiffMod(int dm);
    void setFloor(int f);

    string getName();
    int getScore();
    string getDiff();
    int getFloor();

    void AddScore(int s);

    void SB_out();

    friend ostream& operator <<(ostream& os, const scoreboard& p); //needs to be implemented
};