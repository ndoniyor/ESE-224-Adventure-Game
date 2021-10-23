#include <iostream>
using namespace std;

void PlayerOptions (player& p, FileOperations &f, scoreboard& s){
    int x;
    cout << "Options:"<<endl
    << "--------" << endl
    << "1 - Examine self" << endl
    << "2 - Continue" << endl
    << "3 - Scoreboard" << endl
    << "4 - Quit" << endl //needs to be implemented after save feature is added
    << "5 - Shop" << endl;
    cin >> x;
    switch (x){
        case 1:
            cout << "You ponder upon you physique, you feel at max you could take " << p.getMaxHP() <<
            ". Right now you feel you could probably take " << p.getHP <<
            " more hits. To keep yourself as not dead as you currently find yourself you can deal " << p.getDMG() << "damage."
            break;
        case 2:
            break;
        case 3:
            cout << "Score: " << s.getScore() << endl
            << "Difficulty :" << s.getDiff() << endl
            << "Floor: " << s.getFloor() << endl;
            break;
        case 4:
            //add save functions
            exit(0);
        case 5:
            //add shop
        default:
            break;
    }
}
