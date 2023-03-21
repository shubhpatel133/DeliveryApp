
#include "Pierres.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// addDriver(string name, Location) - add a new Driver with the given parameters.
void Pierres::addDriver(const string &name, const Location &location)
{
    if (numDrivers < MAX_DRIVERS)
    {
        drivers[numDrivers] = new Driver(name, location);
        numDrivers++;
        cout << "new driver added" << endl;
    }
    else
    {
        cout << "Max number of drivers reached" << endl;
    }
}
void Pierres::addFranchise(const string &name, const Location &location)
{
    if (numFranchises < MAX_FRANCHISES) // if the number of franchises is less than the max number of franchises
    {
        franchises[numFranchises] = new Franchise(name, location); // add a new franchise
        numFranchises++;
        cout << "new franchise added" << endl;
    }
    else
    {
        cout << "Max number of franchises reached" << endl;
    }
}
// makes a new order and adds it to the franchise that is closest to the given location
void Pierres::takeOrder(const string &customerName, int menuItem, const Location &customerLocation)
{
    int minDistance = 999999; //
    int minIndex = 0;
    for (int i = 0; i < numFranchises; i++)
    {
        int distance = franchises[i]->getLocation().getDistance(customerLocation); // get the distance between the franchise and the location
        if (distance < minDistance)
        {
            minDistance = distance;
            minIndex = i;
        }
    }
    franchises[minIndex]->addOrder(new Order(customerName, menuItem, customerLocation)); // add the order to the closest franchise
    cout << "new order added" << endl;
}
Driver *Pierres::findClosestDriver(Location location)
{
    int minDistance = 999999;
    int minIndex = 0;
    for (int i = 0; i < numDrivers; i++)
    {
        int distance = drivers[i]->getLocation().getDistance(location); // get the distance between the driver and the location
        if (distance < minDistance)                                     // if the distance is less than the minimum distance
        {
            minDistance = distance;
            minIndex = i;
        }
    }
    return drivers[minIndex]; // return the closest driver
}

void Pierres::driverPickup(const string &franchiseId, int numOrders)
{
    bool trueFranchise = true; // boolean flag to check if the franchise id is found
    for (int i = 0; i < numFranchises; i++)
    {
        if (franchises[i]->equals(franchiseId)) // if the franchise id is found
        {
            trueFranchise = false;
            Driver *driver = findClosestDriver(franchises[i]->getLocation()); // find the closest driver
            driver->setLocation(franchises[i]->getLocation());                // set the driver's location to the franchise's location
            for (int j = 0; j < numOrders; j++)
            {
                driver->addOrder(franchises[i]->getNextOrder());
            }
        }
    }
    if (trueFranchise == true)
    {
        cerr << "no franchise with given id" << endl;
    }
}

void Pierres::driverDeliver(const string &driverId, int numOrders)
{
    bool trueDeliver = true; // boolean flag to check if the driver id is found
    for (int i = 0; i < numDrivers; i++)
    {
        if (drivers[i]->equals(driverId)) // if the driver id is found
        {
            numOrders = min(numOrders, drivers[i]->getNumOrders()); // get the minimum of the number of orders
            trueDeliver = false;
            for (int j = 0; j < numOrders; j++)
            {
                Order *currNextOrder = drivers[i]->getNextOrder(); // get the next order
                drivers[i]->setLocation(currNextOrder->getLocation());
                cout << "Delivering: " << endl;
                currNextOrder->print();
                delete currNextOrder;
            }
        }
    }
    if (trueDeliver == true)
    {
        cerr << "driver not found" << endl;
    }
}
// print all franchise
void Pierres::printFranchises() const
{
    for (int i = 0; i < numFranchises; i++)
    {
        franchises[i]->print();
    }
}
// print all driver
void Pierres::printDrivers() const
{
    for (int i = 0; i < numDrivers; i++)
    {
        drivers[i]->print();
    }
}
