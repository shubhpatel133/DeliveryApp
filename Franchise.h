
#ifndef FRANCHISE_H
#define FRANCHISE_H

#include <iostream>
#include <string>
#include "Entity.h"
#include "Location.h"
#include "Order.h"
#include "defs.h"

using namespace std;

class Franchise : public Entity
{

public:
	// constructor
	Franchise(const string &name = "", const Location &location = Location());
	void print();
	static void printMenu();
	static string getMenu(int index);
	Location getLocation();

private:
	static const char code = 'F';
	static int nextID;
	static const string menu[MENU_ITEMS];
};
#endif