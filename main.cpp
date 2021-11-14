#include "header.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

void playerCombat(player& p, enemy& e, scoreboard& s);
bool enemyCombat(player& p, enemy& e, scoreboard& s);
void PlayerOptions(player& p, FileOperations& f, scoreboard& s, vector<vector<weapon>>& weapons);
void initializeWeapons(player& p, vector<vector<weapon>>& weapons, vector<string> ws);
void chooseWeapon(player& p, vector<vector<weapon>>& w);



int main() {
    srand(time(NULL));
    FileOperations file;
    //create and assign weapons
    vector<vector<weapon>> weapons;
    vector<weapon> owned;
    vector<weapon> shop;
    weapon w1("Moonlight_Greatsword", 6, 4, 7);
    shop.push_back(w1);
    weapon w2("Whirligig_Saw", 5, 6, 7);
    shop.push_back(w2);
    weapon w3("Pyromancy_Flame", 4, 6, 12);
    shop.push_back(w3);
    weapon w4("Leviathan_Axe", 7, 5, 8);
    shop.push_back(w4);
    weapon w5("Master_Sword", 10, 10, 20);
    shop.push_back(w5);
    weapons.push_back(shop);
    weapons.push_back(owned);

    //creat objects used in game such as player scoreboard and randomevents
    RandomEvent re;
    scoreboard s1("dummy", 200, "hardcore", 2, 3);
    player p1("dummy", 20, 18, 2, 1);

    //load or create save data
    vector<string> list;
    list = file.ChooseFile(s1, p1);
    s1.setName(p1.getName());

    //create enemies and assign them arandom weapons
    int i;
    int j;
    i = rand() % 4;
    j = rand() % 10;
    //config enemy1
    enemy e1("skeleton", 4, 4, 1, 2);
    e1.setLevel(1);
    e1.setCurrency(j+2);
    e1.ModifyDamage(shop[i].getDMG());
    i = rand() % 4;
    j = rand() % 8;
    //config enemy2
    enemy e2("gnome", 8, 8, 2, 2);
    e2.setLevel(2);
    e2.ModifyDamage(shop[i].getDMG());
    e2.setCurrency(j+3);
    i = rand() % 4;
    j = rand() % 8;
    //config enemy3
    enemy e3("necromancer", 12, 12, 3, 2);
    e3.setLevel(3);
    e3.ModifyDamage(shop[i].getDMG());
    e3.setCurrency(j+4);
    i = rand() % 4;
    j = rand() % 8;
    //config enemy4
    enemy e4("wraith", 18, 18, 4, 2);
    e4.setLevel(4);
    e4.setCurrency(j+6);
    e4.ModifyDamage(shop[i].getDMG());
    //set up main loop
    initializeWeapons(p1, weapons, list);
    int floorNum = 0;
    floorNum = (s1.getFloor());
    bool gaming = true;

    //main gameplay loop
    while (gaming) {
        while (floorNum < 5 && gaming) {
            if (floorNum == 1) {
                s1.setFloor(1);
                cout << "You enter the first floor of the dungeon" << endl << endl;
                PlayerOptions(p1, file, s1, weapons);
                re.getEvent(p1, s1);
                playerCombat(p1, e1, s1);
                if (p1.getHP() <= 0) {
                    gaming = false;
                    cout << "GAME OVER" << endl;
                    file.Save2FileS(s1, p1);
                }
                file.Save2FileP(p1, s1, owned);
            }
            if (floorNum == 2) {
                s1.setFloor(2);
                cout << "You enter the second floor of the dungeon" << endl << endl;
                PlayerOptions(p1, file, s1, weapons);
                re.getEvent(p1, s1);
                playerCombat(p1, e2, s1);
                if (p1.getHP() <= 0) {
                    gaming = false;
                    cout << "GAME OVER" << endl;
                    file.Save2FileS(s1, p1);
                }
                file.Save2FileP(p1, s1, owned);
            }
            if (floorNum == 3) {
                s1.setFloor(3);
                cout << "You enter the third floor of the dungeon" << endl << endl;
                PlayerOptions(p1, file, s1, weapons);
                re.getEvent(p1, s1);
                playerCombat(p1, e3, s1);
                if (p1.getHP() <= 0) {
                    gaming = false;
                    cout << "GAME OVER" << endl;
                    file.Save2FileS(s1, p1);
                }
                file.Save2FileP(p1, s1, owned);
            }
            if (floorNum == 4) {
                s1.setFloor(4);
                cout << "You enter the fourth floor of the dungeon" << endl << endl;
                PlayerOptions(p1, file, s1, weapons);
                re.getEvent(p1, s1);
                playerCombat(p1, e4, s1);
                if (p1.getHP() <= 0) {
                    gaming = false;
                    cout << "GAME OVER" << endl;
                    file.Save2FileS(s1, p1);
                }
                file.Save2FileP(p1, s1, owned);
            }
            if (floorNum != 4 && p1.getHP() > 0) {
                cout << "Congratulations champion you have slain your foe and may proceed to floor " << (floorNum + 1) << endl;
            }
            if (floorNum == 4) {
                cout << "Congratulations brave hero you have cast the evil from this realm and saved the world" << endl;
                file.Save2FileS(s1, p1);
                gaming = false;
            }
            floorNum++;
        }
    }
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
        case 's':
            cout << "You ponder upon you phisique, you feel at max you could take " << p.getMaxHP() << " hits. Right now you feel you could probably take " << p.getHP() << " more hits. To keep yourself as not dead as you currently find yourself you can deal " << p.getDMG() << " damage." << endl;
            break;
        case 'E':
            cout << "You cast your eyes upon your foe, their craven body looks no stronger than a max of " << e.getMaxHP() << "hits. They appear to only be able to take " << e.getHP() << " more hits. They bear their weapon at you, attempting to intimidate you with a weapon that can easily deal " << (e.getDMG() * s.getDiffMod()) << " damage. A fitting weapon for a level " << e.getLevel() << "enemy." << endl;
            break;
        case 'e':
            cout << "You cast your eyes upon your foe, their craven body looks no stronger than a max of " << e.getMaxHP() << "hits. They appear to only be able to take " << e.getHP() << " more hits. They bear their weapon at you, attempting to intimidate you with a weapon that can easily deal " << (e.getDMG() * s.getDiffMod()) << " damage. A fitting weapon for a level " << e.getLevel() << "enemy." << endl;
            break;
        case 'A':
            cout << "You attack the enemy for " << p.getDMG() << " damage." << endl;
            e.setHP(e.getHP() - p.getDMG());
            if (!enemyCombat(p, e, s)) {
                fighting = false;
                p.setCurrency(p.getCurrency() + e.getCurrency());
                if (p.getHP() > 0) {
                    s.AddScore(100 * s.getFloor());
                    p.setCurrency(p.getCurrency() + e.getCurrency());
                }

            }
            if (p.getDurability() == 0) {
                cout << "Your weapon shatters, you pull out your trusty sword" << endl << endl;
                p.setDMG(2);
                p.setDurability(1000);

            }
            break;
        case 'a':
            cout << "You attack the enemy for " << p.getDMG() << " damage." << endl;
            e.setHP(e.getHP() - p.getDMG());
            p.setDurability(p.getDurability() -1);
            if (!enemyCombat(p, e, s)) {
                fighting = false;
                if (p.getHP() > 0) {
                    p.setCurrency(p.getCurrency() + e.getCurrency());
                    s.AddScore(100 * s.getFloor());
                }

            }
            if (p.getDurability() == 0) {
                cout << "Your weapon shatters, you pull out your trusty sword" << endl << endl;
                p.setDMG(2);
                p.setDurability(1000);
            }
            break;
        default:
            cout << "Invalid character please select again." << endl << endl;
        }
    }
}

bool enemyCombat(player& p, enemy& e, scoreboard& s) {
    cout << "The enemy attacks you for " << e.getDMG() << " damage" << endl;;
    p.setHP(p.getHP() - (e.getDMG() * s.getDiffMod()));
    if (p.getHP() <= 0) {
        cout << "You have been slain by the enemy." << endl;
        return false;
    }
    if (e.getHP() <= 0) {
        cout << "You have slain your enemy." << endl;
        return false;
    }
    else {
        return true;
    }

}

void chooseWeapon(player& p, vector<vector<weapon>>& w) {
    int x;
    for (int i = 0; i < w.at(1).size(); i++) {
        if (w.at(1).at(i).getDMG() == p.getDMG()) {
            w.at(1).at(i).setUses(p.getDurability());
       }
    }
        cout << "1 - basic sword Damage: 2 Uses: infinite " << endl;
        for (int i = 0; i < w.at(1).size(); i++) {
            cout << (i + 2) << " - " << w.at(1).at(i).getItem() << " Damage: "
                << w.at(1).at(i).getDMG() << " Uses: "
                << w.at(1).at(i).getUses() << endl;
        }
        cout << endl << "Select weapon:" << endl;
        cin >> x;
        cout << endl;
        switch (x) {
        case 1:
            p.setDMG(2);
            p.setDurability(1000);
            break;
        case 2:
  
            p.setDMG(w.at(1).at(0).getDMG());
            p.setDurability(w.at(1).at(0).getUses());
            break;
        case 3:
            p.setDMG(w.at(1).at(1).getDMG());
            p.setDurability(w.at(1).at(1).getUses());
            break;
        case 4:
            p.setDMG(w.at(1).at(2).getDMG());
            p.setDurability(w.at(1).at(2).getUses());
            break;
        case 5:
            p.setDMG(w.at(1).at(3).getDMG());
            p.setDurability(w.at(1).at(3).getUses());
            break;
        case 6:
            p.setDMG(w.at(1).at(3).getDMG());
            p.setDurability(w.at(1).at(3).getUses());
            break;
      
        }
}


void PlayerOptions(player& p, FileOperations& f, scoreboard& s, vector<vector<weapon>>& w) {
    weapon temp("SOLD OUT", 0, 0, 0);
    int x;
    bool running = true;
    bool picking = true;
    bool found = false;
    while (running) {
        cout << "Options:" << endl
            << "--------" << endl
            << "1 - Examine self" << endl
            << "2 - Continue on your journey" << endl
            << "3 - Scoreboard" << endl
            << "4 - Quit" << endl
            << "5 - Shop" << endl
            << "6 - Switch weapon" << endl
            << "Please pick: ";
        cin >> x;
        cout << endl;
        switch (x) {
        case 1:
            cout << "You ponder upon you physique, you feel at max you could take " << p.getMaxHP() << " hits. Right now you feel you could probably take " << p.getHP() << " more hits. To keep yourself as not dead as you currently find yourself you can deal " << p.getDMG() << " damage. You feel the weight of " << p.getCurrency() << " gold in your pocket." << endl << endl;
            break;
        case 2:
            running = false;
            break;
        case 3:
            s.SB_out();
            break;
        case 4:
            f.Save2FileP(p, s, w[1]);
            f.Save2FileS(s, p);
            cout << "Progress saved." << endl;
            running = false;
            exit(0);
        case 5:
            char wep;
            picking = true;
            while (picking == true) {
                cout << "Shopkeeper's wares: (Item, damage, uses, cost)" << endl;
                for (int i = 0; i < w.at(0).size(); i++) {
                    cout << i + 1 << " - " << w.at(0).at(i).getItem() << " "
                        << w.at(0).at(i).getDMG() << " "
                        << w.at(0).at(i).getUses() << " $"
                        << w.at(0).at(i).getCost() << endl;
                }
                cout << "h - Health potion (heals for 10 damage) $3" << endl;
                cout << "x - back" << endl << "Please pick: ";

                cin >> wep;
                switch (wep) {
                case '1':
                    if (w.at(0).at(0).getItem() == temp.getItem()) {
                        cout << "Weapon is sold out" << endl;
                    }
                    else {
                        if (p.getCurrency() - w.at(0).at(0).getCost() < 0) {
                            cout << "You do not have enough money to purchase this weapon" << endl;
                        }
                        else {
                            p.setCurrency(p.getCurrency() - w.at(0).at(0).getCost());
                            p.setDMG(w.at(0).at(0).getDMG());
                            p.setDurability(w.at(0).at(0).getUses());
                            w.at(1).push_back(w.at(0).at(0));
                            w.at(0).at(0).setItem(temp.getItem());
                        }
                    }
                    picking = false;
                    break;
                case '2':
                    if (w.at(0).at(1).getItem() == temp.getItem()) {
                        cout << "Weapon is sold out" << endl;
                    }
                    else {
                        if (p.getCurrency() - w.at(0).at(1).getCost() < 0) {
                            cout << "You do not have enough money to purchase this weapon" << endl;
                        }
                        else {
                            p.setCurrency(p.getCurrency() - w.at(0).at(1).getCost());
                            p.setDMG(w.at(0).at(1).getDMG());
                            p.setDurability(w.at(0).at(1).getUses());
                            w.at(1).push_back(w.at(0).at(1));
                            w.at(0).at(1).setItem(temp.getItem());
                        }
                    }
                    picking = false;
                    break;
                case '3':
                    if (w.at(0).at(2).getItem() == temp.getItem()) {
                        cout << "Weapon is sold out" << endl;
                    }
                    else {
                        if (p.getCurrency() - w.at(0).at(2).getCost() < 0) {
                            cout << "You do not have enough money to purchase this weapon" << endl;
                        }
                        else {
                            p.setCurrency(p.getCurrency() - w.at(0).at(2).getCost());
                            p.setDMG(w.at(0).at(2).getDMG());
                            p.setDurability(w.at(0).at(2).getUses());
                            w.at(1).push_back(w.at(0).at(2));
                            w.at(0).at(3).setItem(temp.getItem());
                        }
                    }
                    picking = false;
                    break;
                case '4':
                    if (w.at(0).at(3).getItem() == temp.getItem()) {
                        cout << "Weapon is sold out" << endl;
                    }
                    else {
                        if (p.getCurrency() - w.at(0).at(3).getCost() < 0) {
                            cout << "You do not have enough money to purchase this weapon" << endl;
                        }
                        else {
                            p.setCurrency(p.getCurrency() - w.at(0).at(3).getCost());
                            p.setDMG(w.at(0).at(3).getDMG());
                            p.setDurability(w.at(0).at(3).getUses());
                            w.at(1).push_back(w.at(0).at(3));
                            w.at(0).at(3).setItem(temp.getItem());
                        }
                    }
                    picking = false;
                    break;
                case '5':
                    if (w.at(0).at(4).getItem() == temp.getItem()) {
                        cout << "Weapon is sold out" << endl;
                    }
                    else {
                        if (p.getCurrency() - w.at(0).at(4).getCost() < 0) {
                            cout << "You do not have enough money to purchase this weapon" << endl;
                        }
                        else {
                            p.setCurrency(p.getCurrency() - w.at(0).at(4).getCost());
                            p.setDMG(w.at(0).at(4).getDMG());
                            p.setDurability(w.at(0).at(4).getUses());
                            w.at(1).push_back(w.at(0).at(4));
                            w.at(0).at(4).setItem(temp.getItem());
                        }
                    }
                    picking = false;
                    break;
                case 'h':
                    if (p.getCurrency() < 3) {
                        cout << "You do not have enough money to purchase this weapon" << endl;
                    }
                    else {
                        p.setCurrency(p.getCurrency() - 3);
                        cout << "You drink the potion and feel stronger" << endl << endl;
                        p.setHP(p.getHP() + 10);
                    }
                    break;
                case 'x':
                    picking = false;
                    break;
                default:
                    cout << "Invalid choice" << endl;
                    break;
                }
            }
            break;

         case 6:
             chooseWeapon(p, w);
             break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }

}


void initializeWeapons(player& p, vector<vector<weapon>>& weapons, vector<string> ws) {
    weapon temp("SOLD OUT", 0,0,0);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < ws.size(); j++) {
            if (weapons[0][i].getItem() == ws[j]) {
                weapons.at(1).push_back(weapons.at(0).at(i));
                weapons.at(0).at(0).setItem(temp.getItem());
            }
        }
    }
}