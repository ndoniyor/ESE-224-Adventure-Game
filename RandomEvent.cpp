#include "Header.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void RandomEvent::getEvent(player& p, scoreboard& s) {
    srand(time(NULL));
    int event = rand() % 200;
    if (event < 20) {
        int pick = 0;
        cout << "You come across three chests which do you open? (1, 2, or 3)" << endl;
        cin >> pick;
        if (pick == 1) {
            cout << "The chest is rife with riches you gain (gain 15 gold)" << endl;
            p.setCurrency(p.getCurrency() + 15);
            return;
        }
        if (pick == 2) {
            cout << "The has a decent amount of treasure you (gain 10 gold)" << endl;
            p.setCurrency(p.getCurrency() + 10);
            return;
        }
        if (pick == 3) {
            cout << "The chest is empty but could still fetch some gold for the wood (gain 5 gold)" << endl;
            p.setCurrency(p.getCurrency() + 5);
            return;
        }
        else {
            cout << "Invalid input, you are unable to overcome your indecision and move on" << endl;
            return;
        }
    }
    if (event > 19 && event < 40) {
        char pick = ' ';
        cout << "You see some gold burried in a pile of rusted weapons, do you try to grab it?(y/n)" << endl;
        cin >> pick;
        int event2 = rand() % 100;
        if (pick == 'y') {
            if (event2 > 49) {
                cout << "You sucessfully extract the gold (gain 10 gold)" << endl;
                p.setCurrency(p.getCurrency() + 10);
                return;
            }
            if (event < 49) {
                cout << "You cut yourself on the sword and fail to get the gold (lose 1 hp)" << endl;
                p.setHP(p.getHP() - 1);
                return;
            }
        }
        if (pick == 'n') {
            cout << "You move on, grabbing a coin you find at your feet (gain 1 gold)" << endl;
            p.setCurrency(p.getCurrency() + 1);
            return;
        }
        else {
            cout << "Invalid input, you are unable to overcome your indecision and move on" << endl;
            return;
        }

    }
    if (event > 39 && event < 60) {
        char pick = ' ';
        cout << "You happen across table with a mysterious coin, it urges you to flip it. You see the word tails scratched into the table. Flip it? (y/n)" << endl;
        cin >> pick;
        if (pick == 'y') {
            int flip = rand() % 100;
            if (flip > 44) {
                cout << "Heads, you feel a mysterious pain (lose 1 hp)" << endl;
                p.setHP(p.getHP() - 1);
                return;
            }
            if (flip < 44) {
                cout << "Tails, the coin vanishes and a sack of gold appears (gain 15 gold)" << endl;
                p.setCurrency(p.getCurrency() + 15);
                return;
            }
        }
        if (pick == 'n') {
            cout << "You pocket the coin and move on." << endl;
            p.setCurrency(p.getCurrency() + 1);
            return;
        }
        else {
            cout << "Invalid input, you are unable to overcome your indecision and move on" << endl;
            return;
        }

    }
    if (event > 59 && event < 80) {
        char pick = ' ';
        cout << "You see a giant golden helmet, do you try to take it with you? (y/n)" << endl;
        cin >> pick;
        if (pick == 'y') {
            int event2 = rand() % 100;
            if (event2 > 44) {
                cout << "You try to pick up the helmet but it is too heavy (lose 1 hp)" << endl;
                p.setHP(p.getHP() - 1);
                return;
            }
            if (event2 < 44) {
                cout << "You pick up the helmet without injuring yourself, arm day has paid off (gain 5 gold)" << endl;
                p.setCurrency(p.getCurrency() + 5);
                return;
            }
        }
        if (pick == 'n') {
            cout << "You dont try to pick it up, you feel condfident in your decision and your current helmet (gain 2 hp)" << endl;
            p.setHP(p.getHP() + 2);
            return;
        }
        else {
            cout << "Invalid input, you are unable to overcome your indecision and move on" << endl;
            return;
        }
    }
    if (event > 79 && event < 100) {
        char pick = ' ';
        cout << "You come across a mysterious potion, do you drink it? (y/n)" << endl;
        cin >> pick;
        if (pick == 'y' || pick == 'Y') {
            int event2 = rand() % 100;
            if (event2 > 44) {
                cout << "You drink the potion and feel sick (lose 1 hp)" << endl;
                p.setHP(p.getHP() - 1);
                return;
            }
            if (event2 < 44) {
                cout << "You drink the potion and feel stronger (gain 5 hp)" << endl;
                p.setHP(p.getHP() + 5);
                return;
            }
        }
        if (pick == 'n' || pick == 'N') {
            cout << "You take the potion to sell later (gain 10 gold)" << endl;
            p.setCurrency(p.getCurrency() + 10);
            return;
        }
        else {
            cout << "Invalid input, you are unable to overcome your indecision and move on" << endl;
            return;
        }
    }
    if (event > 99 && event < 110) {
        cout << " A man claiming to be the future king of the pirates comes to you asking to join his pirate crew what do you do " << endl;
        cout << "[Yes] - Ill join your crew" << endl;
        cout << "[No] - I wont join you" << endl;
        string choice;
        cin >> choice;
        if (choice == "Yes" || choice == "yes") {
            cout << "You get on his ship and get into a fight with the navy" << endl;
            int event2 = rand() % 100;
            if (event2 > 44) {
                cout << "You fight the navy but forgot your captain accidently knocks you off the ship in the midst of battle. (-1 HP)" << endl;
                p.setHP(p.getHP() - 1);
                return;
            }
            if (event2 < 44) {
                cout << "You and your new allies defeat the navy and you felt like you gained some exp (gain 300 points)" << endl;
                s.AddScore(300);
                return;
            }
        }
        if (choice == "No" || choice == "no") {
            int event2 = rand() % 100;
            if (event2 > 44) {
                cout << "You decline the offer and missed out on joining the future king of the pirate crew. You find a coin the pirate dropped on his way out. (gain 2 gold)" << endl;
                p.setCurrency(p.getCurrency() + 2);

                return;
            }
            if (event2 < 44) {
                cout << "You decline the offer and after parting ways with the pirate you noticed his ship got sunk. (gain 100 points)" << endl;
                s.AddScore(100);
                // p.setHP(p.getHP() - 1);
                return;
            }
        }
        else {
            cout << "Invalid input, you are unable to overcome your indecision and move on" << endl;
            return;
        }
    }

    if (event > 109 && event < 120) {
        string choice;

        cout << "you come across 7 magic orbs. what do you do" << endl;
        cout << "[Yes] to make a wish" << endl;
        cout << "[No] to not make a wish" << endl;
        cin >> choice;
        if (choice == "Yes" || choice == "yes") {
            cout << "You made a wish for immortality" << endl;
            int event2 = rand() % 100;
            if (event2 > 44) {
                cout << "You feel more like you can live forever. (+5 HP)" << endl;

                p.setHP(p.getHP() + 5);
                return;
            }
            if (event2 < 44) {
                cout << "Turns out it was a scam and you wake up in a ditch (-1pts)" << endl;
                s.AddScore(-1);
                return;
            }
        }
        if (choice == "No" || choice == "no") {
            int event2 = rand() % 100;
            if (event2 > 44) {
                cout << "You decide not to do it and ended up not falling for a scam. (gain 10 points)" << endl;
                s.AddScore(10);
                return;
            }
            if (event2 < 44) {
                cout << "You declined but ended up stubbing your toe on one of the orbs (-1 hp)" << endl;
                p.setHP(p.getHP() - 1);
                return;
            }
        }
        else {
            cout << "Invalid input, you are unable to overcome your indecision and move on" << endl;
            return;
        }


    }

    if (event > 119 && event < 150) {
        cout << "You found a skate board and think back to your skate 3 days what do you do " << endl;
        cout << "[Kickflip] of stairs" << endl;
        cout << "[Grind] on rail " << endl;
        cout << "[Nothing] becuase you dont have a helmet" << endl;
        string choice;
        cin >> choice;
        if (choice == "Kickflip" || choice == "kickflip") {
            cout << "You decided to do a kickflip" << endl;
            int event2 = rand() % 100;
            if (event2 > 44) {
                cout << "You succesfully kickflipped. (gain 200 points)" << endl;
                s.AddScore(200);

                return;
            }
            if (event2 < 44) {
                cout << "You fell off your board after a enemy noticed you (-1 hp)" << endl;
                p.setHP(p.getHP() - 1);
                return;
            }
        }
        if (choice == "Grind" || choice == "grind") {
            int event2 = rand() % 100;
            if (event2 > 44) {
                cout << "You succesfully grinded. (gain 100 points)" << endl;
                s.AddScore(100);

                return;
            }
            if (event2 < 44) {
                cout << "You fell off your board after a enemy noticed you (-1 hp)" << endl;
                p.setHP(p.getHP() - 1);
                return;
            }
        }

        if (choice == "nothing" || choice == "Nothing") {
            int event2 = rand() % 100;
            if (event2 > 44) {
                cout << "You decided not to do anything and are confident in your decision. (gain 50 points)" << endl;
                s.AddScore(50);

                return;
            }
            if (event2 < 44) {
                cout << "Becuase you didnt do tricks you ended up avoiding dalling into a pit (+1 hp)" << endl;
                p.setHP(p.getHP() + 1);
                return;
            }
        }
        else {
            cout << "Invalid input, you are unable to overcome your indecision and move on" << endl;
            return;
        }


    }

    if (event > 149 && event < 160) {
        cout << "You decided to take a nap but start to hear a goblin." << endl;
        cout << "Your only options are [Run] or [Hide]" << endl;
        string choice;
        cin >> choice;
        if (choice == "Run" || choice == "run") {
            cout << "You decided to run" << endl;
            int event2 = rand() % 100;
            if (event2 > 44) {
                cout << "You succesfully ran away (gain 50 points)" << endl;

                s.AddScore(5);
                return;
            }
            if (event2 < 44) {
                cout << "You ended up stepping on a trap (- 2 hp)" << endl;
                p.setHP(p.getHP() - 2);
                return;
            }
        }
        if (choice == "Hide" || choice == "hide") {

            int event2 = rand() % 100;
            if (event2 > 44) {
                cout << "You decide to hide in a box and the goblin walked away. Inside you find 5 gold (gain 5 gold)" << endl;
                p.setCurrency(p.getCurrency() + 5);
                return;
            }
            if (event2 < 44) {
                cout << "You try to hide but get caught (-1 hp)" << endl;
                p.setHP(p.getHP() - 1);
                return;
            }
        }
        else {
            cout << "Invalid input, you are unable to overcome your indecision and move on" << endl;
            return;
        }
    }

    if (event > 159 && event < 180) {
        char pick = ' ';
        cout << "You feel a powerful sneeze coming on, do you try to hold it in? (y/n)" << endl;
        cin >> pick;
        if (pick == 'y' || pick == 'Y') {
            int event2 = rand() % 100;
            if (event2 > 44) {
                cout << "Your constitution fails you and you sneeze (lose 1 hp)" << endl;
                p.setHP(p.getHP() - 1);
                return;
            }
            if (event2 < 44) {
                cout << "Your constitution does not fail you and you hold in the sneeze (gain 1 hp)" << endl;
                p.setHP(p.getHP() + 1);
                return;
            }
        }
        if (pick == 'n' || pick == 'N') {
            cout << "You let loose a mighty sneeze (lose 1 hp)" << endl;
            p.setHP(p.getHP() - 1);
            return;
        }
        else {
            cout << "Invalid input, you are unable to overcome your indecision and move on" << endl;
            return;
        }
    }

    if (event > 179 && event < 200) {
        cout << "You play rock paper scissors with a enemy" << endl;
        cout << "what do you choose?" << endl;
        cout << "[R]ock" << endl;
        cout << "[P]aper" << endl;
        cout << "[S]cissors" << endl;
        string choice;
        cin >> choice;
        if (choice == "R" || choice == "r") {
            cout << "You decided to use Rock" << endl;
            int event2 = rand() % 100;
            if (event2 > 44) {
                cout << "You won. (gain 5 gold)" << endl;
                p.setCurrency(p.getCurrency() + 5);

                return;
            }
            if (event2 < 44) {
                cout << "You lost (-1 hp)" << endl;
                p.setHP(p.getHP() - 1);
                return;
            }
        }
        if (choice == "P" || choice == "p") {
            int event2 = rand() % 100;
            if (event2 > 44) {
                cout << "You won. (gain 5 gold)" << endl;
                p.setCurrency(p.getCurrency() + 5);

                return;
            }
            if (event2 < 44) {
                cout << "You lost (-1 hp)" << endl;
                p.setHP(p.getHP() - 1);
                return;
            }
        }

        if (choice == "S" || choice == "s") {
            int event2 = rand() % 100;
            if (event2 > 44) {
                cout << "You won. (gain 5 gold)" << endl;
                p.setCurrency(p.getCurrency() + 10);

                return;
            }
            if (event2 < 44) {
                cout << "You lost (-1 hp)" << endl;
                p.setHP(p.getHP() - 1);
                return;
            }
        }
        else {
            cout << "Invalid input, you are unable to overcome your indecision and move on" << endl;
            return;
        }
    }
}
