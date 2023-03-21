
#include "Franchise.h"
using namespace std;
int Franchise::nextID = 1;
// set the menu items
const string Franchise::menu[MENU_ITEMS] = {"1. Large Poutine", "2. Medium Poutine", "3. Small Poutine"};

// constructor
Franchise::Franchise(const string &name, const Location &location) : Entity(code, nextID, name, location)
{
    this->nextID++;
}
// print the franchise details
void Franchise::print()
{
    cout << "Franchise Name: " << this->name << endl;
    cout << "ID: " << this->id << endl;
    cout << "Location: ";
    this->location.print();
    cout << endl;
    cout << "number of orders: " << orders.size() << endl;
}
// print the menu
void Franchise::printMenu()
{
    for (int i = 0; i < MENU_ITEMS; i++)
    {
        cout << menu[i] << endl;
    }
}
// get the menu item, if out of bound then return unknown menu item
string Franchise::getMenu(int index)
{
    if (index < 0 || index >= MENU_ITEMS)
    {
        return "unknown menu item";
    }
    return menu[index];
}
// get the location
Location Franchise::getLocation()
{
    return location;
}