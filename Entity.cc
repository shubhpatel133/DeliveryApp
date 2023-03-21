
#include "Entity.h"
using namespace std;
Entity::Entity(char idChar, int idNum, const string &name, Location location)
    : id(idChar + to_string(idNum)), name(name), location(location) {}
// getter
int Entity::getNumOrders()
{
    return orders.size();
}
// removes and returns the order at the front of the queue, should it not exist then reurns null
Order *Entity::getNextOrder()
{
    if (orders.size() == 0)
    {
        return nullptr;
    }
    else
    {
        Order *order = orders.peekFirst(); // get the order at the front of the queue
        orders.popFirst();
        return order;
    }
}
// adds an order to the back of the queue
void Entity::addOrder(Order *order)
{
    orders.addLast(order);
}
// equals the id
bool Entity::equals(string id)
{
    return this->id == id;
}
// setter
void Entity::setLocation(Location location)
{
    this->location = location;
}
// prints the entity details
void Entity::print()
{
    cout << "ID: " << this->id << endl;
    cout << "Name: " << this->name << endl;
    cout << "Location: ";
    this->location.print();
    cout << endl;
    cout << "Number of orders: " << orders.size() << endl;
}
