#pragma once
#include <iostream>
#include <string>
using namespace std;
class ShopNode {
private:
	string name;
	int damage, uses;
	double cost;
	ShopNode* next;
	ShopNode* prev;
public:
	ShopNode(string name, int damage, int uses, double cost);
	void setNext(ShopNode* next);
	void setPrev(ShopNode* prev);
	ShopNode* getNext();
	ShopNode* getPrev();
	string getName();
	int getDMG();
	int getUses();
	double getCost();
	void print();
};