#include "string"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class FileOperations {
private:
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
	void Save2File(player&);
	//function Saves player progress into a file
	void Save2File(scoreboard&);
	//function saves scoreboard progress into a file
	void ChooseFile(scoreboard&, player&);
	//function the asks the user to select the file to use
	void CloseFile();
	//function to close the files
	void ScoreRank();
	//function to output scores from all the scoreboards
};