
#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include <string>
#include "Entity.h"

using namespace std;

class Driver : public Entity
{

public:
	// constructor
	Driver(const string &name = "", const Location &location = Location());
	bool isFree() const;
	void print() const;
	Location getLocation();
	// private member variables
private:
	static const char code = 'D';
	static int nextID;
};
#endif