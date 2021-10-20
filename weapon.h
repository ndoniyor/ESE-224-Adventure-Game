#include <string>
using namespace std;

class weapon
{
	private:
		string W_item;
		int W_damage;
		int W_uses;
		int W_cost;
	public:
		weapon();
		weapon(string i, int d);
		void setItem(string);
		void setDMG(int);
		void setUses(int);
		void setCost(int);
		string getItem();
		int getDMG();
		int getUses();
		int getCost();
		bool degradation();