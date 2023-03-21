
#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include "Location.h"
#include "Queue.h"
#include "Order.h"

using namespace std;

class Entity
{

public:
	// constructor
	Entity(char idChar, int idNum, const string &name, Location location);
	// setter
	void setLocation(Location location);
	// other
	int getNumOrders();
	Order *getNextOrder();
	void addOrder(Order *order);
	void print();
	bool equals(string id);

protected:
	string id;
	string name;
	Location location;
	Queue orders;
};
#endif