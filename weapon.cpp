#include "header.h"
#include <string>
using namespace std;

weapon::weapon() {
	W_item = "default";
	W_damage = 1;
	W_uses = 1;;
	W_cost = 1;
}

weapon::weapon(string i, int d, int u, int c) {
	W_item = i;
	W_damage = d;
	W_uses = u;
	W_cost = c;
}

void weapon::setItem(string n) {
	W_item = n;
}

void weapon::setDMG(int d) {
	W_damage = d;
}

void weapon::setUses(int u) {
	W_uses = u;
}

void weapon::setCost(int c) {
	W_cost = c;
}

string weapon::getItem() {
	return W_item;
}

int weapon::getDMG() {
	return W_damage;
}

int weapon::getUses() {
	return W_uses;
}

int weapon::getCost() {
	return W_cost;
}

bool weapon::degradation() {
	W_uses--;
	if (W_uses == 0) {
		return true; //is it broken?
	}
	return false;
}