#include "Queue.h"
using namespace std;
Queue::Queue() : head(NULL), tail(NULL) {}

// destructor
Queue::~Queue()
{
    Node *currNode = head;
    Node *nextNode = NULL;

    while (currNode != NULL)
    {
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }
}

bool Queue::empty() const
{
    if (head == NULL)
    {
        return true;
    }
    return false;
}
int Queue::size() const
{
    return numOrders;
}
Order *Queue::peekFirst() const
{
    if (head != NULL)
    {
        return head->data;
    }
    else
    {
        return NULL;
    }
}
Order *Queue::popFirst()
{
    Node *nextNode;
    if (head != NULL)
    {
        Order *temp = head->data;
        nextNode = head->next;
        delete head;
        head = nextNode;
        numOrders--;
        return temp;
    }
    else
    {
        return NULL;
    }
}
void Queue::addLast(Order *order)
{
    Node *newNode = new Node;
    newNode->data = order;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    numOrders++;
}