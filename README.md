# ESE-224-Adventure-Game
ESE 224 Midterm Project - Text Based Adventure Game

1 Introduction 
You will have two projects this semester: a midterm project and a final project. The final 
project will build off the work that you do in the midterm portion of this project. You must submit 
the first part in the middle of the semester and the second part by the end of the semester. The 
final project will be handed out at a later date.  
 
2 Teamwork 
This project should be completed in a group of 4 students maximum. The workload must 
be divided amongst the group equally or else the group will have to be changed. In the report 
you will have to detail the work done by each student. 
Each group should only submit one copy with a list of names of every member in the 
group report file name. 
 
3 Design Tasks 
 Before the modern video games as we know today, there was the text-based adventure. 
The text adventure is the earliest form of interactive fiction to exist on a personal computer. The 
first one of these was created in 1975 by William Crowther called Colossal Cave Adventure. 
Games like Zork or The Hitchhiker's Guide to the Galaxy would follow. Your task for this project 
will be to develop a text-based adventure game in C++ using your knowledge of everything that 
we have discussed so far.  
 
Project Objectives 
• Practice analyzing and debugging techniques. 
• Develop good coding habits: 
– Use separate code files for the declarations and implementations of different classes. 
– Use techniques to make the code concise and modular. 
– Use comments where necessary. 
– Use proper indentation. 
• Read/write data from/to files. 
• Basic interface design with user selections. 
• Implement object-oriented programming concepts such as inheritance, overloading. 
• Work with a team 
 
4 Coding / Code Design 
You will create a text-adventure game with some very simple and basic features. In the 
final project you will continue working on this project. You will add more features to make this 
project more complicated as well as change some features later using more advanced theory.  
 
 This game will have you create a player character to fight enemies and advance through 
4 floors to reach the end. You can add whatever theme you want to the game you create, as 
long as you meet the minimum requirements mentioned. The overall structure of this project 
should be the same, but the experience for each game made can be made as creatively as you 
want. You may feel free to make any modifications you like, so long as the basic structure 
remains unchanged. 
 
4.1 Classes: 
Player Class 
This class should contain information about the player.  
You should create the following member variables: 
  • Player Name 
  • Player Maximum Health 
  • Player Current Health 
  • Player Attack Damage 
    The member functions should do the following: 
  • Setters for all the member values. This will allow you to change the member 
    value through this member function. 
  • Getters for all the member values. This will allow you to view the value through 
    this member function. 
  • A member function to add an inputted value to the player’s current health 
  • A member function to add an inputted value to the player’s attack damage 
  • Operator overload of the operator<< to print out all the member variables from 
    the player class.  
 
class player 
{ 
    private: 
      string Name; 
        //This should hold the player’s name 
        int MaxHealth; 
        //This should hold the maximum health of the player 
        int HealthPoints; 
        //This should hold the current health of the player 
        int AttackDamage; 
        //This should hold the attack damage of the player 
 
 
 
    public: 
        player(); 
        //default constructor 
 
        string getName(); 
        int getMaxHP(); 
        //returns the maximum health 
        int getHP(); 
        //returns the current health 
        int getDMG(); 
        
        //returns the current damage 
 
        void setName(string); 
        void setMaxHP(int); 
        void setHP(int); 
        //sets the current health 
        void setDMG(int); 
        //sets the current damage 
 
        void ModifyHealth(int); 
        //Increments or decrements the player’s health by the input value 
        void ModifyDamage(int); 
        //Increments or decrements the player’s attack damage by the input value 
 
        friend ostream& operator <<(ostream& os, const player& p); 
}; 
 
Enemy Class 
The enemy class should have all the features as the player class, except the enemy 
should also have a level member variable. This class should contain all the information about 
the enemy. 
You should create the following member variables: 
  • Enemy Name 
  • Enemy Maximum Health 
  • Enemy Current Health 
  • Enemy Attack Damage 
  • Enemy Level. Level should correspond to the expected difficulty of the enemy.  
The member functions should do the following: 
  • Setters for all the member values. This will allow you to change the member 
    value through this member function. 
  • Getters for all the member values. This will allow you to view the value through 
    this member function. 
  • A member function to add an inputted value to the enemy’s current health 
  • A member function to add an inputted value to the enemy’s attack damage 
  • Operator overload of the operator<< to print out all the member variables from 
  the enemy class.  
 
 
class enemy 
{ 
 private:  
        string Name; 
        //This should hold the player’s name 
        int MaxHealth; 
        //This should hold the maximum health of the player 
        int HealthPoints; 
        //This should hold the current health of the player 
        int AttackDamage; 
        //This should hold the attack damage of the player
        int level = 0; 
 
 public:  
  enemy(); 
        enemy(string, int, int, int, int); 
     
        string getName(); 
        int getMaxHP(); 
        //returns the maximum health 
        int getHP(); 
        //returns the current health 
        int getDMG(); 
        //returns the current damage 
        int getLVL(); 
        //returns the level 
 
        void setName(string); 
        void setMaxHP(int); 
        void setHP(int); 
        //sets the current health 
        void setDMG(int); 
        //sets the current damage 
        void setLVL(int); 
        //sets the level 
 
        void ModifyHealth(int); 
        //Increments or decrements the player’s health by the input value 
        void ModifyDamage(int); 
        //Increments or decrements the player’s attack damage by the input value 
 
 friend ostream& operator <<(ostream& os, const enemy& e); 
}; 
 
Weapon Class 
This class is to hold information relating to a weapon that you should be able to equip 
and use later. You will have to make a 2D matrix using vectors using the Weapon class. 
You should create the following member variables: 
  • Weapon Name 
  • Weapon Damage 
The member functions should do the following: 
  • Setter member functions 
  • Getter member functions 
 
class weapon 
{ 
    private: 
        string W_item; 
        //Name of the weapon item 
        int W_damage; 
        //Attack damage to the item. This can be added or removed by the player 
 
    public:  
        weapon(); 
        weapon(string i, int d); 
 
5 
 
        void setItem(string); 
        void setDMG(int); 
 
        string getItem(); 
        int getDMG(); 
 
         
}; 
 
Scoreboard Class 
This class should hold information about the score the player has gained over the course 
of the game. This information should be updated whenever the player defeats an enemy or 
changes to a new floor. Remember, the scoreboard information needs to be stored onto a file. 
, the, the difficulty, and floor. 
You should create the following member variables: 
  • Player Name. Set at the beginning of the program. 
  • Score of the player. Score should increase after defeating enemies. 
  • Difficulty. Set at the beginning of the program. Overall difficulty of the game is 
    stored here. 
  • Difficulty Modifier. Depending on the selected difficulty, this modifier should be a 
    factor that multiplies the standard base health and damage of an enemy. 
  • Floor. Floor denotes the area or zone that the player is at. Higher floors imply 
    more difficult enemies. 
The member functions should do the following: 
  • Setter member functions 
  • Getter member functions 
  • A function to add points to the overall player score by passing in a value. 
  • A function that ONLY outputs: Player Name, Difficulty, and Floor. Not the 
    Difficulty Modifier. 
  • Operator overload of the operator<< to print out ALL the member variables.  
 
class scoreboard  
{ 
 private:  
  string SB_Name; 
  //Name of the player 
  int SB_Score; 
  //score of the player. Score should increase after the player defeats an 
enemy or through some custom method designed by you.  
  //(*Note: Higher level enemies should give more points.) 
  string SB_Difficulty; 
  int SB_DifficultyMod; 
  //Difficulty of the game. 
  int SB_Floor; 
  //keeps track of the area in the game the player is currently at 
 
 
 public: 
  scoreboard(); 
