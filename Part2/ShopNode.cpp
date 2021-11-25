#include <iostream>
#include <iomanip>
#include "ShopNode.h"
using namespace std;

ShopNode::ShopNode(string name, int damage, int uses, double cost) {
	this->name = name;
	this->damage = damage;
	this->uses = uses;
	this->cost = cost;
}
void ShopNode::setNext(ShopNode* next) {
	this->next = next;
}
void ShopNode::setPrev(ShopNode* prev) {
	this->prev = prev;
}
ShopNode* ShopNode::getNext() {
		return next;
}
ShopNode* ShopNode::getPrev() {
		return prev;
}
string ShopNode::getName() {
	return name;
}
int ShopNode::getDMG() {
	return damage;
}
int ShopNode::getUses() {
	return uses;
}
double ShopNode::getCost() {
	return cost;
}
void ShopNode::print() {
	cout << setw(25) << left << name << setw(5) << left << damage;
	cout << setw(5) << left << uses << left << "$" << cost << endl;
}
