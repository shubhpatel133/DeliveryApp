
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
#include "Order.h"

using namespace std;

class Queue
{
	class Node
	{
	public:
		Order *data;
		Node *next;
	};

public:
	// constructor
	Queue();
	// destructor
	~Queue();
	// other
	bool empty() const;
	int size() const;
	Order *peekFirst() const;
	Order *popFirst();
	void addLast(Order *order);

private:
	Node *head;
	Node *tail;
	int numOrders;
};
#endif