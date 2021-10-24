#include "Header.h"



void FileOperations::Save2FileP(player p) {
	cout << "Which file would you like to save to?";
	cin >> P_file_name;
	p_myFile.open(P_file_name);
	if (p_myFile.fail()) {
		cerr << "Player file could not be opened";
		exit(1);
	}

	p_myFile << p.getMaxHP() << "\n";
	p_myFile << p.getHP() << "\n";
	p_myFile << p.getDMG() << "\n";
}

void FileOperations::Save2FileS(scoreboard s) {

	SB_myFile.open(SB_file_name);
	if (SB_myFile.fail()) {
		cerr << "Scoreboard file could not be opened";
		exit(1);
	}

	SB_myFile << "Name: " << s.getName() << "\n";
	SB_myFile << "Score: " << s.getScore() << "\n";
	SB_myFile << s.getDiff() << "\n";
	SB_myFile << s.getDiff() << "\n";
	SB_myFile << s.getFloor() << "\n";

	if (sortedScores.size() == 0 && sortedNames.size() == 0) {
		sortedScores.push_back(s.getScore());
		sortedNames.push_back(s.getName());
	}
	else {
		for (int i = 0; i < sortedScores.size(); i++) {
			if (s.getScore() < sortedScores[i]) {
				;
			}
			else {
				sortedScores.insert(sortedScores.begin() + i, s.getScore());
				sortedNames.insert(sortedNames.begin() + i, s.getName());
			}
		}
	}

}

void FileOperations::ChooseFile(scoreboard&, player&) {
	char oper;
	string name;
	ofstream file1;
	cout << "Would you like to create a new file (n) or open an existing one (e)." << endl;
	cin >> oper;
	if (oper == 'n') {
		cout << "What would you like to call this file?";
		cin >> name;
		file1.open(name);
		cout << "New file successfully created.";
		
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