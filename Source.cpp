#include "Header.h"
#include <iostream>
using namespace std;
#include <fstream>
#include <string>



int main()
{
	string name;
	cout << "what would you like to name your player" << endl;
	cin >> name;
	string d;
	cout << "type the difficulty  you like to play the game";
	cout << " easy,  normal, hard" << endl;
	cin >> d;
	player one(name, 100, 100, 20);
	FileOperations four;
	if (d == "easy") {
		
		scoreboard two(name, 0, "easy", 0.5, 1);
		four.ChooseFile(two, one);
	}
	if (d == "normal") {
		scoreboard two(name, 0, "normal", 1, 1);
		four.ChooseFile(two, one);
	}
	if (d == "hard") {
		scoreboard two(name, 0, "hard", 1.5, 1);
		four.ChooseFile(two, one);
	}
	else {
		cout << " ";
	}

	//floor 1


	
	
	
	

	//four.Save2FileP(one);
	


}