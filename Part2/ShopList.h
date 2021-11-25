#pragma once
#include "ShopNode.h"
class ShopList {
private:
	typedef ShopNode* nodeptr;
	nodeptr head, tail, current;
	bool flag = true;
public:
	ShopList();
	void addWeapon(ShopNode* weapon);
	void moveToNext();
	void moveToPrev();
	void moveToHead();
	void moveToTail();
	void printAll();
	void setTail(ShopNode* tail);
	ShopNode* getCurrent();
	void loadAll(int floorNum);
	void clearAll();
	void remove();
};