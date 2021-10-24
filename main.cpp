#include "header.h"
#include <iostream>
using namespace std;

void playerCombat(player& p, enemy& e, scoreboard& s);
bool enemyCombat(player& p, enemy& e, scoreboard& s);

int main(){
	player p1("test", 20, 18, 2);
	enemy e1("bad", 30, 15, 3, 2);
	scoreboard s1("testscore", 200, "hardcore", 2 ,3);
	FileOperations f();
	f.chooseFile(s1, p1);
	playerCombat(p1, e1, s1);
	return 0;

}

void playerCombat(player& p, enemy& e, scoreboard& s) {
	char select = ' '; // char for switch 
	bool alive = true;
	bool fighting = true; // fighting loop
	while (fighting) {
		cout << "[A]ttack" << endl << "Examine [S]elf" << endl << "Examine [E]nemy" << endl; //menu options
		cout << "Please select an option: "; // ask user for input
		cin >> select; //get input
		cout << endl; //spacer
		switch (select)
		{
		case 'S':
			cout << "You ponder upon you phisique, you feel at max you could take " << p.getMaxHP() << " hits. Right now you feel you could probably take " << p.getHP() << " more hits. To keep yourself as not dead as you currently find yourself you can deal " << p.getDMG() << " damage." << endl;
				break;
		case 'E':
			cout << "You cast your eyes upon your foe, their craven body looks no stronger than a max of " << e.getMaxHP() << "hits. They appear to only be able to take " << e.getHP() << " more hits. They bear their weapon at you, attempting to intimidate you with a weapon that can easily deal " << e.getDMG() << " damage. A fighting weapon for a level ";
			break;
		case 'A':
			cout << "You attack the enemy for " << p.getDMG() << " damage." << endl;
			e.setHP(e.getHP() - p.getDMG());
			break;
		default:
			cout << "Invalid character please select again." << endl << endl;
		}
		if(!enemyCombat(p,e,s)){
			fighting = false;
			s.AddScore(100 * s.getFloor());

		}
	}
}


//email TA to see how scoring works

bool enemyCombat(player &p, enemy &e, scoreboard &s) {
	p.setHP(p.getHP() - e.getDMG());
	if (p.getHP() <= 0) {
		return false;
	}
	else {
		return true;
	}

}

//void ChooseWeapon(weapon[][], int n, player& p)