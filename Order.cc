
#include "Order.h"
using namespace std;
// constructor
Order::Order(const string &name, int menuItem, Location location)
{
    this->name = name;
    this->menuItem = menuItem;
    this->location = location;
}
// getter
const Location &Order::getLocation() const
{
    return this->location;
}
// prints the order details
void Order::print()
{
    cout << "Name: " << this->name << endl;
    cout << "Menu Item: " << this->menuItem << endl;
    this->location.print();
    cout << "\n"
         << endl;
}