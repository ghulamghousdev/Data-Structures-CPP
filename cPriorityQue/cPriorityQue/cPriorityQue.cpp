/*
Implementation file for cPriorityQue class
*/
#include "cPriorityQue.h"
#include <iostream>
using namespace std;

//Default constructor
cPriorityQue::cPriorityQue(){}

//Parameterized constructor
cPriorityQue::cPriorityQue(cNode *& ptr) : cQueue(ptr) {}

/*
Function to check if Priority Queue is empty
*/
bool cPriorityQue::isEmpty() const { 
	bool flag;
	flag=cStack::isEmpty(); 
	return flag;
}

/*
Function to check if Priority Queue is not empty
*/
bool cPriorityQue::isNotEmpty() const { return cStack::isNotEmpty(); }

/*
Add function to add a new node in the list according to priority in the queue 
*/
cPriorityQue& cPriorityQue::addInPriorityQue(cNode *&ptr) {
	if (!top) {
		top = tail = ptr;
		tail->nextNode = ptr = NULL;
	}
	else if (top->getPriority() < ptr->getPriority())
	{
		cStack::push(ptr);
	}
	else if (tail->getPriority() >= ptr->getPriority()) {
		cQueue::add(ptr);
	}
	else {
		cNode *rptr,*bptr;
		bptr = rptr = top;
		while (rptr->getPriority() >= ptr->getPriority()) {
			bptr = rptr;
			rptr = rptr->nextNode;
		}
		ptr->nextNode = rptr;
		bptr->nextNode = ptr;
		ptr = NULL;
	}
	return *this;
}

cNode* cPriorityQue::removeFromPriorityQue() {
	return cQueue::remove();
}

/*
Self Defined Copy Constructor to avoid shallow copy
*/
cPriorityQue::cPriorityQue(const cPriorityQue & src) :cQueue((cQueue&)src) {}; //inheriting copy constructor of base class

/*
Assignment operator overloaded
*/
cPriorityQue cPriorityQue::operator = (const cPriorityQue & robj) {
	((cQueue*)this)->operator=((cQueue&)robj);		//Inheriting Assignment operator  of cQueue class
	return *this;

	//code commented below will use in that case if we do not inherit assignment operator of cQueue class

	/*if (this == &src) { return *this; }
	if(true) { cPriorityQue temp; temp.top = this->top ; temp.tail = this->tail; }
	if(true) { cPriorityQue temp; top = temp.top; tail = temp.tail; temp.top=tail=NULL ;}
	return *this;*/
}

/*
Printing all the elements of cPriority queue
*/
void cPriorityQue::print() const {
	cQueue::print();
}

cPriorityQue::~cPriorityQue()
{
	cNode *ptr = top;

	tail = NULL;                   // Tail is going to NULL and we can make remaining code.

	while (ptr)
	{
		ptr = ptr->nextNode;
		delete top;
		top = ptr;                   // In last loop Top will become Null. 
	}
}