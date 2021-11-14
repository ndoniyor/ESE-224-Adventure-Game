#include "Header.h"
#include <fstream>
#include <iostream>
#include <ostream>
using namespace std;

FileOperations::FileOperations() {

}

void FileOperations::Save2FileP(player& p, scoreboard& s, vector<weapon> w) {
	cout << "Which file would you like to save to? (include .txt)" << endl;
	cin >> P_file_name;
	p_myFile.open(P_file_name);
	if (p_myFile.fail()) {
		cerr << "Player file could not be opened";
		Save2FileP(p, s, w);
	}
	p_myFile << "Player: " << p.getName() << " " << p.getMaxHP() << " " << p.getHP() << " " << p.getDMG() << " " << p.getCurrency() << " " << p.getDurability() << " " << w.size() << " ";
	for (int i = 0; i < w.size(); i++ ) {
		p_myFile << " " << w[i].getItem() << " ";
	}
	if (w.size() == 0) {
		cout << " ";
	}
	p_myFile << "Score: " << p.getName() << " " << s.getScore() << " " << s.getDiff() << " " << s.getDiffMod() << " " << s.getFloor();
	p_myFile.close();
	return;

}

void FileOperations::Save2FileS(scoreboard& s, player& p) {
	string outs = "";
	vector<string> names;
	vector<int> scores;
	fstream file1;
	file1.open("scoreboard.txt");
	if (file1.fail()) {
		cerr << "This file does not exist." << endl;
	}
	string name;
	int score;
	while (!file1.fail()) {
		file1 >> name;
		names.push_back(name);
		file1 >> score;
		scores.push_back(score);
	}
	names.pop_back();
	scores.pop_back();
	names.push_back(p.getName());
	scores.push_back(s.getScore());
	int tempScore = 0;
	string tempName = "";
	for (int i = 0; i < scores.size()-1; i++) {
		for (int j = i + 1; j < scores.size(); j++) {
			if (scores[i] < scores[j]) {
				tempScore = scores[i];
				scores[i] = scores[j];
				scores[j] = tempScore;
				tempName = names[i];
				names[i] = names[j];
				names[j] = tempName;
			}
		}
	}

	for (int i = 0; i < scores.size(); i++) {
		outs = outs + names[i] + " " + to_string(scores[i]) + "\n";
	}

	file1 << outs;
	file1.clear();
	file1.close();
	ofstream dataout;
	dataout.open("scoreboard.txt");
	dataout << outs;



	ScoreRank(outs);

}

vector<string> FileOperations::ChooseFile(scoreboard& s, player& p) {
	vector<string> ownedWeapons;
	char oper;
	string charName;
	char difSelect;
	string name;
	ifstream file1;
	ifstream file2;
	cout << "Do you have an existing file?" << endl << "[Y]es or [N]o" << endl;
	cin >> oper;
	if (oper == 'n' || oper == 'N') {
		cout << "What would you like to call this file? (include .txt)" << endl;
		cin >> name;
		ofstream filenew(name);
		cout << "New file successfully created." << endl;
		cout << "Please name your character: ";
		cin >> charName;
		p.setName(charName);
		p.setMaxHP(30);
		p.setHP(30);
		p.setDMG(2);
		p.setDurability(1000);
		p.setCurrency(0);
		cout << "Select difficulty [E]asy [N]ormal [H]ard" << endl;
		cin >> difSelect;
		switch (difSelect) {
		case 'E':
			s.setDiff("Easy");
			s.setDiffMod(1);
			break;
		case 'e':
			s.setDiff("Easy");
			s.setDiffMod(1);
			break;
		case 'N':
			s.setDiff("Normal");
			s.setDiffMod(1.5);
			break;
		case 'n':
			s.setDiff("Normal");
			s.setDiffMod(1.5);
			break;
		case 'H':
			s.setDiff("Hard");
			s.setDiffMod(2);
			break;
		case 'h':
			s.setDiff("Hard");
			s.setDiffMod(2);
			break;
		default:
			cout << "Invalid character please select again." << endl << endl;
		}
		s.setFloor(1);
		s.setName(charName);
		s.setScore(0);
		file2.open("scoreboard.txt");
		if (file2.fail())
		{
			cerr << "File cannot be opened." << endl;
			exit(1);
		}
		return ownedWeapons;
	}
	else if (oper == 'y' || oper == 'Y') {
		cout << "Which existing file would you like to choose?" << endl;
		cin >> name;
		file1.open(name);
		if (file1.fail()) {
			cerr << "This file does not exist." << endl;
		}
		while (!file1.eof()) {
			string weaponName;
			int numItems = 0;
			string name;
			file1 >> name;
			file1 >> name;
			p.setName(name);
			int maxH;
			file1 >> maxH;
			p.setMaxHP(maxH);
			int curHP;
			file1 >> curHP;
			p.setHP(curHP);
			int dmg;
			file1 >> dmg;
			p.setDMG(dmg);
			int currency;
			file1 >> currency;
			p.setCurrency(currency);
			int dur;
			file1 >> dur;
			p.setDurability(dur);
			file1 >> numItems;
			for (int x = 0; x < numItems; x++) {
				file1 >> weaponName;
				ownedWeapons.push_back(weaponName);
			}
			string score;
			file1 >> score;
			file1 >> score;
			s.setName(score);
			int scoreNum;
			file1 >> scoreNum;
			s.setScore(scoreNum);
			string diff;
			file1 >> diff;
			s.setDiff(diff);
			int diffMod;
			file1 >> diffMod;
			s.setDiffMod(diffMod);
			int floor;
			file1 >> floor;
			s.setFloor(floor);
			return ownedWeapons;
		}
	}
}

void FileOperations::CloseFile() {
	SB_myFile.close();
	p_myFile.close();
}

void FileOperations::ScoreRank(string outs) {

	cout << outs;

}