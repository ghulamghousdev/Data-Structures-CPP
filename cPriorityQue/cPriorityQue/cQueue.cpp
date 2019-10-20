#include <iostream>
#include "cQueue.h"

using namespace std;

/*
Default constructor of Queue class to make tail data member of queue class NULL
*/
cQueue::cQueue() :tail(NULL) {}

/*
Parameterized Constructor
*/
cQueue::cQueue(cNode *& ptr) : cStack(ptr) { tail = top; }

/*
Function to check if Queue is empty
*/
bool cQueue::isEmpty() const { return cStack::isEmpty(); }

/*
Function to check if Queue is not empty
*/
bool cQueue::isNotEmpty() const { return cStack::isNotEmpty(); }

/*
Cascaded push function which addes a new node in Queue at top
*/
cQueue& cQueue::add(cNode *& ptr) {
	if (tail)
	{
		tail->nextNode = ptr;
		tail = tail->nextNode;
	}
	else  tail = top = ptr;

	tail->nextNode = ptr = NULL;

	return *this;
}

/*
Cascaded remove function which removes the last node from Queue
*/
cNode* cQueue::remove()
{
	if (!(top->nextNode))  tail = NULL;                           // If this is last node so we should make Tail also NULL;

	return cStack::pop();
}
/*
Self Defined Copy Constructor to avoid shallow copy
*/

cQueue::cQueue(const cQueue & src) {
	this->top = src.top;
	this->tail = src.tail;
	if (src.top) {
		cNode *sptr, *dptr;
		dptr = top = new cNode(*src.top);
		sptr = src.top->nextNode;

		while (sptr) {
			dptr->nextNode = new cNode(*sptr);
			dptr = dptr->nextNode;
			sptr = sptr->nextNode;

		}
		tail = dptr;
	}
}

/*
Self Defined Copy Constructor to avoid shallow copy

cQueue::cQueue(const cQueue & src) : cStack((cStack &)src) {
	tail = top; //Handeled empty Queue case
	while (tail) {
		cout << tail->getData();
		if (!(tail->nextNode)) break;
		tail = tail->nextNode;
	}
}*/

/*
Assignment Operator overloaded
*/
cQueue & cQueue::operator =(const cQueue &obj) {
	if (this == &obj) {
		return *this;
	}

	if (true) {
		cQueue temp;
		temp.top = top;
		temp.tail = tail;
	}
	if (true) {
		cQueue temp;
		temp = obj;
		top = temp.top;
		tail = temp.tail;
		temp.top = NULL;
		temp.tail = NULL;
		return *this;
	}
}

/*
Function to print all the elements present in the Stack
*/
void cQueue::print() const {
	cStack::print();
}

cQueue::~cQueue()
{
	cNode *ptr = top;

	tail = NULL;                                              // Tail is going to NULL and we can make remaining code.

	while (ptr)
	{
		ptr = ptr->nextNode;
		delete top;
		top = ptr;                                           // In last loop Top will become Null. 
	}
}
#pragma once