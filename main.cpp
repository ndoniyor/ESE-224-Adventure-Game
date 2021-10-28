#include "header.h"
#include <iostream>
using namespace std;

void playerCombat(player& p, enemy& e, scoreboard& s);
bool enemyCombat(player& p, enemy& e, scoreboard& s);
void PlayerOptions(player& p, FileOperations& f, scoreboard& s);
void randomEvents(player& p, FileOperations&, scoreboard& s);



int main(){
	player p1("test", 20, 18, 2, 1);
	enemy e1("bad", 30, 15, 3, 2);
    enemy e2("bad", 30, 15, 3, 2);
    enemy e3("bad", 30, 15, 3, 2);
    enemy e4("bad", 30, 15, 3, 2);
	scoreboard s1("testscore", 200, "hardcore", 2 ,3);
	FileOperations file;
	playerCombat(p1, e1, s1);
    int floorNum = 0;
    bool gaming = true;
    while (gaming) {
        for (floorNum < 5; floorNum++;) {
            PlayerOptions(p1, file, s1);
            if (floorNum == 1) {
                randomEvents(p1, file, s1);
                playerCombat(p1, e1, s1);
                file.Save2FileP(p1);
                file.Save2FileS(s1);
            }
            if (floorNum == 2) {
                randomEvents(p1, file, s1);
                playerCombat(p1, e1, s1);
                file.Save2FileP(p1);
                file.Save2FileS(s1);
            }
            if (floorNum == 3) {
                randomEvents(p1, file, s1);
                playerCombat(p1, e1, s1);
                file.Save2FileP(p1);
                file.Save2FileS(s1);
            }
            if (floorNum == 4) {
                randomEvents(p1, file, s1);
                playerCombat(p1, e1, s1);
                file.Save2FileP(p1);
                file.Save2FileS(s1);
            }
            if (floorNum != 4) {
                cout << "Congratulations champion you have slain your foe and may proceed to floor " << (floorNum + 1) << endl;
            }
            if (floorNum == 4) {
                cout << "Congratulations brave hero you have cast the evil from this realm and saved the world" << endl;
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


void randomEvents(player& p, FileOperations&, scoreboard& s) {
    int event = rand() % 100;
    if (event < 24) {
        int pick = 0;
        cout << "You come across three chests which do you open? (1, 2, or 3)";
        cin >> pick;
        if (pick == 1) {
            cout << "The chest is rife with riches you gain (400 points)";
            s.AddScore(400);
            return;
           }
        if (pick == 2) {
            cout << "The has a decent amount of treasure you (gain 200 points)";
            s.AddScore(200);
            return;
           }
        if (pick == 3) {
            cout << "The chest is empty but could still fetch some gold for the wood (gain 50 points)";
            s.AddScore(50);
            return;
           }
        else {
            cout << "Invalid input, you are unable to overcome your indecision and move on";
            return;
        }
    }
    if (event > 23 && event < 54) {
        char pick = ' ';
        cout << "You see some gold burried in a pile of rusted weapons, do you try to grab it?(y/n)";
        cin >> pick;
        int event2 = rand() % 100;
        if (pick == 'y') {
            if (event2 > 49) {
                cout << "You sucessfully extract the gold (gain 400 points)";
                s.AddScore(400);
                return;
            }
            if (event < 49) {
                cout << "You cut yourself on the sword and fail to get the gold (lose 1 hp)";
                p.setHP(p.getHP() - 1);
                return;
            }
        }
        if (pick == 'n') {
            cout << "You move on, grabbing a coin you find at your feet (gain 5 points)";
            s.AddScore(5);
            return;
        }
        else {
            cout << "Invalid input, you are unable to overcome your indecision and move on";
            return;
        }

    }
    if (event > 53 && event < 74) {
        char pick = ' ';
        cout << "You happen across table with a mysterious coin, it urges you to flip it. You see the word tails scratched into the table. Flip it? (y/n)";
            cin >> pick;
            if (pick == 'y') {
                int flip = rand() % 100;
                if (flip > 44) {
                    cout << "Heads, you feel a mysterious pain (lose 1 hp)";
                    p.setHP(p.getHP() - 1);
                    return;
                }
                if (flip < 44) {
                    cout << "Tails, the coin vanishes and a sack of gold appears (gain 200 points)";
                    s.AddScore(200);
                    return;
                }
            }
            if (pick == 'n') {
                "You pocket the coin and move on.";
                return;
            }
            else {
                cout << "Invalid input, you are unable to overcome your indecision and move on";
                return;
            }

    }
    if (event > 73 && event < 99) {
        char pick = ' ';
        cout << "You see a giant golden helmet, do you try to take it with you? (y/n)";
        cin >> pick;
        if (pick == 'y') {
            int event2 = rand() % 100;
            if (event2 > 44) {
                cout << "You try to pick up the helmet but it is too heavy (lose 1 hp)";
                p.setHP(p.getHP() - 1);
                return;
            }
            if (event2 < 44) {
                cout << "You pick up the helmet without injuring yourself, arm day has paid off (gain 500)";
                s.AddScore(500);
                return;
            }
        }
        if (pick == 'n') {
            cout << "You dont try to pick it up, you feel condfident in your decision and your current helmet (gain 1 hp)";
            p.setHP(p.getHP() + 1);
            return;
        }
        else {
            cout << "Invalid input, you are unable to overcome your indecision and move on";
            return;
    }
    }
}