#include "header.h"
#include <iostream>
using namespace std;

void playerCombat(player& p, enemy& e, scoreboard& s);
bool enemyCombat(player& p, enemy& e, scoreboard& s);
void PlayerOptions(player& p, FileOperations& f, scoreboard& s);




int main(){
	player p1("test", 20, 18, 2, 1);
	enemy e1("bad", 30, 15, 3, 2);
    enemy e2("bad", 30, 15, 3, 2);
    enemy e3("bad", 30, 15, 3, 2);
    enemy e4("bad", 30, 15, 3, 2);
	scoreboard s1("testscore", 200, "hardcore", 2 ,3);
	FileOperations f1();
	playerCombat(p1, e1, s1);
    int floorNum;
    bool gaming = true;
    while (gaming) {
        for (floorNum < 5; floorNum++;) {
            PlayerOptions(p1,s1);
            if (floorNum = 1) {
                playerCombat(p1, e1, s1);
            }
            if (floorNum = 2) {
                playerCombat(p1, e1, s1);
            }
            if (floorNum = 3) {
                playerCombat(p1, e1, s1);
            }
            if (floorNum = 4) {
                playerCombat(p1, e1, s1);
            }
            if (floorNum != 4) {
                cout << "Congratulations champion you have slain your foe and may proceed to floor " << (floorNum + 1) << endl;
            }
            if (floorNum == 4) {
                cout << "COngratulations brave hero you have cast the evil from this realm and saved the world" << endl;
            }
        }
    }


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

void PlayerOptions(player& p, FileOperations& f, scoreboard& s) {
    weapon w1("Moonlight Greatsword", 120, 30, 500);
    weapon w2("Whirligig Saw", 100, 50, 500);
    weapon w3("Pyromancy Flame", 75, 25, 200);
    weapon w4("Leviathan Axe", 200, 30, 700);
    weapon w5("Master Sword", 1000, 1, 1000);
    int x;
    bool running = true;
    bool picking = true;
    while (running) {
        cout << "Options:" << endl
            << "--------" << endl
            << "1 - Examine self" << endl
            << "2 - Continue" << endl
            << "3 - Scoreboard" << endl
            << "4 - Quit" << endl
            << "5 - Shop" << endl;
        cin >> x;
        switch (x) {
        case 1:
            cout << "You ponder upon you physique, you feel at max you could take " << p.getMaxHP() <<
                ". Right now you feel you could probably take " << p.getHP() <<
                " more hits. To keep yourself as not dead as you currently find yourself you can deal " << p.getDMG() << "damage.";
            break;
        case 2:
            break;
        case 3:
            s.SB_out();
            break;
        case 4:
            f.Save2FileP(p);
            f.Save2FileS(s);
            cout << "Progress saved." << endl;
            exit(0);
        case 5:
            int wep;
            while (picking == true) {
                cout << "Shopkeeper's Wares:" << endl
                    << "X - Name, Damage, Uses, Cost" << endl
                    << "1 - Moonlight Greatsword, 120, 30, 500" << endl
                    << "2 - Whirligig Saw, 100, 50, 500" << endl
                    << "3 - Pyromancy Flame ,75, 25, 200" << endl
                    << "4 - Leviathan Axe, 200, 30, 700" << endl
                    << "5 - Master Sword, 1000, 1, 1000" << endl;
                    cin >> wep;
                    switch (wep) {
                    case 1:
                        if (p.getCurrency() - w1.getCost() < 0) {
                            cout << "You do not have enough money to purchase this weapon" << endl;
                        }
                        else {
                            p.setCurrency(p.getCurrency() - w1.getCost());
                            p.setDMG(w1.getDMG());
                            p.setDurability(w1.getUses());
                        }
                        picking = false;
                        break;
                    case 2:
                        if (p.getCurrency() - w2.getCost() < 0) {
                            cout << "You do not have enough money to purchase this weapon" << endl;
                        }
                        else {
                            p.setCurrency(p.getCurrency() - w2.getCost());
                            p.setDMG(w2.getDMG());
                            p.setDurability(w2.getUses());
                        }
                        picking = false;
                        break;
                    case 3:
                        if (p.getCurrency() - w3.getCost() < 0) {
                            cout << "You do not have enough money to purchase this weapon" << endl;
                        }
                        else {
                            p.setCurrency(p.getCurrency() - w3.getCost());
                            p.setDMG(w3.getDMG());
                            p.setDurability(w3.getUses());
                        }
                        picking = false;
                        break;
                    case 4:
                        if (p.getCurrency() - w4.getCost() < 0) {
                            cout << "You do not have enough money to purchase this weapon" << endl;
                        }
                        else {
                            p.setCurrency(p.getCurrency() - w4.getCost());
                            p.setDMG(w4.getDMG());
                            p.setDurability(w4.getUses());
                        }
                        picking = false;
                        break;
                    case 5:
                        if (p.getCurrency() - w5.getCost() < 0) {
                            cout << "You do not have enough money to purchase this weapon" << endl;
                        }
                        else {
                            p.setCurrency(p.getCurrency() - w5.getCost());
                            p.setDMG(w5.getDMG());
                            p.setDurability(w5.getUses());
                        }
                        picking = false;
                        break;
                    default:
                        cout << "Invalid choice" << endl;
                        break;
                    }
            }
                break;

        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }

}
