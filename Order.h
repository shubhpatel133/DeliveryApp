
#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include <string>
#include "Location.h"

using namespace std;

class Order
{

public:
	// constructor
	Order(const string &name, int menuItem, Location location);
	// getter
	const Location &getLocation() const;
	// other
	void print();

private:
	string name;
	int menuItem;
	Location location;
};
#endif