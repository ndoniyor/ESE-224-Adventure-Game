#include <iostream>
#include <iomanip>
#include "ShopList.h"
using namespace std;

ShopList::ShopList() {
	head = NULL;
	tail = NULL;
	current = NULL;
}
void ShopList::addWeapon(ShopNode* weapon) {
	if (head == NULL)
		head = tail = current = weapon;
	else {
		tail->setNext(weapon);
		tail->getNext()->setPrev(tail);
		tail = tail->getNext();
	}
}
void ShopList::moveToNext() {
	if (current->getNext() != NULL) {
		current = current->getNext();
	}
	else
		cout << "Last weapon selectected!\n";
}
void ShopList::moveToPrev() {
	if (current->getPrev() != NULL) {
		current = current->getPrev();
	}
	else
		cout << "First weapon selectected!\n";
}
void ShopList::moveToHead() {
	if (head != NULL) {
		current = head;
	}
	else
		cout << "No weapons in shop.\n";
}
void ShopList::moveToTail() {
	if (tail != NULL) {
		current = tail;
	}
	else
		cout << "No weapons in shop.\n";
}
void ShopList::printAll() {
	ShopNode* temp = head;
	cout << setw(25) << left << "Name" << setw(5) << left << "Dmg";
	cout << setw(5) << left << "Uses" << left << " Cost" << endl;
	if (temp == NULL) {
		cout << "There are no weapons in the shop.\n";
		return;
	}
	while (temp != NULL) {
		if(temp->getName().compare(current->getName())==0)
			cout << "*";
		temp->print();
		temp = temp->getNext();
	}
}
void ShopList::setTail(ShopNode* tail) {
	this->tail = tail;
}
ShopNode* ShopList::getCurrent() {
	return current;
}

void ShopList::loadAll(int floorNum) {
	if (floorNum == 1)
		addWeapon(new ShopNode("Moonlight_Greatsword", 6, 4, 7));
	if (floorNum == 2)
		addWeapon(new ShopNode("Whirligig_Saw", 5, 6, 7));
	if (floorNum == 3)
		addWeapon(new ShopNode("Pyromancy_Flame", 4, 6, 12));
	if (floorNum == 4) {
		addWeapon(new ShopNode("Leviathan_Axe", 7, 5, 8));
		addWeapon(new ShopNode("Master_Sword", 10, 10, 20));
	}
}

void ShopList::remove() {
	ShopNode* temp = current;
	if (temp == head) {
		if (head->getNext() == NULL)
			head = NULL;
		else{
			temp->getNext()->setPrev(NULL);
			current = temp->getNext();
			head = current;
			delete temp;
		}
	}
	else if (temp == tail) {
		temp->getPrev()->setNext(NULL);
		current = temp->getPrev();
		tail = current;
		delete temp;
	}
	else {
		temp->getPrev()->setNext(temp->getNext());
		temp->getNext()->setPrev(temp->getPrev());
		current = current->getNext();
		delete temp;
	}
}

void ShopList::clearAll() {
	ShopNode* temp = head;
	ShopNode* next;
	while (temp != NULL) {
		next = temp->getNext();
		delete temp;
		temp = next;
	}
	head = NULL;
}