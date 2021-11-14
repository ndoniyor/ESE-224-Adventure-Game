#include <iostream>
using namespace std;

void PlayerOptions (player& p, FileOperations &f, scoreboard& s){
    int x;
    optionmenu:
    cout << "Options:"<<endl
    << "--------" << endl
    << "1 - Examine self" << endl
    << "2 - Continue" << endl
    << "3 - Scoreboard" << endl
    << "4 - Quit" << endl
    << "5 - Shop" << endl;
    cin >> x;
    switch (x){
        case 1:
            cout << "You ponder upon you physique, you feel at max you could take " << p.getMaxHP() <<
            ". Right now you feel you could probably take " << p.getHP <<
            " more hits. To keep yourself as not dead as you currently find yourself you can deal " << p.getDMG() << "damage."
            goto optionmenu;
        case 2:
            return;
        case 3:
            s.SB_out();
            goto optionmenu;
        case 4:
            f.Save2FileP(p);
            f.Save2FileS(s);
            cout << "Progress saved." << endl;
            exit(0);
        case 5:
            int flr = s.getFloor();
            int wep;
            cout << "Shopkeeper's Wares:" << endl;
            for(int i = 0; i < flr; i++){
                
                cout << weapons[2]
            }
            
                <<  "X - Name, Damage, Uses, Cost" << endl
                <<  "1 - Moonlight Greatsword, 120, 30, 500" << endl
                <<  "2 - Whirligig Saw, 100, 50, 500" << endl
                <<  "3 - Pyromancy Flame ,75, 25, 200" << endl
                <<  "4 - Leviathan Axe, 200, 30, 700" << end;
                <<  "5 - Master Sword, 1000, 1, 1000") << endl;
            cin >> wep;
            switch(wep){
                case 1:
                    if(p.getCurrency()-w1.getCost()<0){
                        cout<< "You do not have enough money to purchase this weapon" << endl;
                    }
                    else{
                        p.setCurrency(p.getCurrency()-w1.getCost());
                        p.setDMG(w1.getDMG());
                        p.setDurability(w1.getUses());
                    }
                    break;
                case 2:
                    if(p.getCurrency()-w2.getCost()<0){
                        cout<< "You do not have enough money to purchase this weapon" << endl;
                    }
                    else{
                        p.setCurrency(p.getCurrency()-w2.getCost());
                        p.setDMG(w2.getDMG());
                        p.setDurability(w2.getUses());
                    }
                    break;
                case 3:
                    if(p.getCurrency()-w3.getCost()<0){
                        cout<< "You do not have enough money to purchase this weapon" << endl;
                    }
                    else{
                        p.setCurrency(p.getCurrency()-w3.getCost());
                        p.setDMG(w3.getDMG());
                        p.setDurability(w3.getUses());
                    }
                    break;
                case 4:
                    if(p.getCurrency()-w4.getCost()<0){
                        cout<< "You do not have enough money to purchase this weapon" << endl;
                    }
                    else{
                        p.setCurrency(p.getCurrency()-w4.getCost());
                        p.setDMG(w4.getDMG());
                        p.setDurability(w4.getUses());
                    }
                    break;
                case 5:
                    if(p.getCurrency()-w5.getCost()<0){
                        cout<< "You do not have enough money to purchase this weapon" << endl;
                    }
                    else{
                        p.setCurrency(p.getCurrency()-w5.getCost());
                        p.setDMG(w5.getDMG());
                        p.setDurability(w5.getUses());
                    }
                    break;
                default:
                    cout << "Invalid choice" <<endl;
                    goto choice;
                goto optionmenu;
            }
                
        default:
            cout << "Invalid choice" << endl;
            goto optionmenu;
    }
}
