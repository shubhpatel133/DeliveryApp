
#ifndef PIERRES_H
#define PIERRES_H

#include <iostream>
#include <string>
#include "Entity.h"
#include "Location.h"
#include "Order.h"
#include "Franchise.h"
#include "Driver.h"
#include <vector>
#include "Queue.h"
using namespace std;

class Pierres
{

public:
	// constructor
	void addDriver(const string &name, const Location &location);
	void addFranchise(const string &name, const Location &location);
	void takeOrder(const string &customerName, int menuItem, const Location &customerLocation);
	void driverPickup(const string &franchiseId, int numOrders);
	void driverDeliver(const string &driverId, int numOrders);
	void printFranchises() const;
	void printDrivers() const;
	Driver *findClosestDriver(Location);

private:
	Driver *drivers[MAX_DRIVERS];
	Franchise *franchises[MAX_FRANCHISES];
	int numDrivers = 0;
	int numFranchises = 0;
};
#endif