
#include "Driver.h"
using namespace std;
// constructor
int Driver::nextID = 1;
Driver::Driver(const string &name, const Location &location) : Entity(code, nextID, name, location)
{
    this->nextID++;
}
// if the driver is free, true is returned else false is returned
bool Driver::isFree() const
{
    if (orders.size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// gets the location
Location Driver::getLocation()
{
    return location;
}
// prints the driver details
void Driver::print() const
{
    cout << "Driver Name: " << this->name << endl;
    cout << "Driver ID: " << this->id << endl;
    cout << "Location: ";
    this->location.print();
    cout << endl;
    cout << "number of orders: " << orders.size() << endl;
    cout << endl;
}