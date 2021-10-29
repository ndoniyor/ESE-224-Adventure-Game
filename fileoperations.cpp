#include "FileOperations.h"
#include "scoreboard.h"
#include <of

void FileOperations::Save2File(player&) {
	cout << "Which file would you like to save to?";
	cin >> P_file_name;
	p_myFile.open(P_file_name);
	if (p_myFile.fail()) {
		cerr << "Player file could not be opened";
		exit(1);
	}

	p_myFile << player.getMaxHP() << "\n";
	p_myFile << player.getHP() << "\n";
	p_myFile << player.getDMG() << "\n";
    p_myFile << player.getCurrecy() << "\n";
}

void FileOperations::Save2File(scoreboard&) {

	SB_myFile.open(SB_file_name, app);
	if (SB_myFile.fail()) {
		cerr << "Scoreboard file could not be opened";
		exit(1);
	}

	SB_myFile << "Name: " << scoreboard.getName() << "\n";
	SB_myFile << "Score: " << scoreboard.getScore() << "\n";
	SB_myFile << scoreboard.getDiff() << "\n";
	SB_myFile << scoreboard.getDiffMod() << "\n";
	SB_myFile << scoreboard.getFloor() << "\n";

	if (sortedScores.size() == 0 && sortedNames.size() == 0) {
		sortedScores.push_back(scoreboard.getScore());
		sortedNames.push_back(scoreboard.getName());
	}
	else {
		for (int i = 0; i < sortedScores.size(); i++) {
			if (scoreboard.getScore() < sortedScores[i]) {
				;
			}
			else {
				sortedScores.insert(sortedScores.begin() + i, scoreboard.getScore());
				sortedNames.insert(sortedNames.begin() + i, scoreboard.getName());
			}
		}
	}

}

void FileOperations::ChooseFile(scoreboard&, player&) {
	char oper;
	string name;
	fstream file1;
	cout << "Would you like to create a new file (n) or open an existing one (e)." << endl;
	cin >> oper;
	if (oper == 'n') {
		cout << "What would you like to call this file?";
		cin >> name;
		file1.open(name);
		cout << "New file successfully created."
	}
	else if (oper == 'e') {
		cout << "Which existing file would you like to choose?";
		cin >> name;
		file1.open(name);
		if (file1.fail()) {
			cerr << "This file does not exist.";
		}
	}
}
void FileOperations::CloseFile() {
	SB_myFile.close();
	p_myFile.close();
}

void FileOperations::ScoreRank() {
	for (int i = 0; i < sortedScores.size(); i++) {
		cout << "Player: " << sortedNames[i] << endl;
		cout << "Score: " << sortedScores[i] << endl;
	}
}
