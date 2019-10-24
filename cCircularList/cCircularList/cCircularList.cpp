/*
Implementation file for cCircularList
*/
#include "cCircularList.h"
#include <iostream>
using namespace std;


cCircularList::cCircularList() :count(0), headNode(NULL){}

cCircularList::cCircularList(cNode *& ptr):headNode(ptr), count(1) {
	headNode->nextNode = NULL;
	ptr = NULL;
}

cCircularList & cCircularList::insert(cNode *&ptr) {
	if (!headNode) {
		headNode = ptr;
		headNode->nextNode = headNode;
	}
	else {
		ptr->nextNode = headNode->nextNode;
		headNode->nextNode = ptr;
	}
	ptr = NULL;
	++count;
	return *this;
}

cCircularList & cCircularList::insertAt(int index, cNode *&ptr) {
	if (index <= 0)	insert(ptr);
	if (index >= count) index = count;
	cNode * rptr = headNode;
	for (int i = 0; i < index; i++) {
		rptr = rptr->nextNode;
	}
	ptr->nextNode = rptr->nextNode;
	rptr->nextNode = ptr;
	if (index == count) {
		headNode = ptr;
	}
	count++;
	ptr = NULL;
	return *this;
}

cNode * cCircularList::remove()
{
	cNode *ptr = headNode->nextNode;
	if (count <= 1) {
		ptr = headNode;
		headNode = NULL;
	}
	else
	{
		headNode->nextNode = ptr->nextNode;
	}
	ptr->nextNode = NULL;
	--count;
	return ptr;
}

//Function to insert at a specific node
cNode* cCircularList::removeAt(int index) {
	if (index <= 0 || count==1) { //when index is less then or equal to zero, deleting the head node
		return remove();
	}
	if (index >= count) { //when index is greater the or equal to count, resetting the index equal to count 
		index = count;
	}
	cNode *ptr, *rptr = headNode; //Runner pointer
	for (int i = 1; i < index; ++i)	rptr = rptr->nextNode; //Moving through the list to find the node to be deleted
	if (rptr->nextNode == headNode) {
		headNode = headNode->nextNode;
	}
	ptr = rptr->nextNode;
	rptr->nextNode = ptr->nextNode;
	ptr->nextNode = NULL;
	--count;
	return ptr;
}

void cCircularList::print() const {
	if (count == 0) {
		cout << "\nLinked List is empty\n";
	}
	else {
		cNode *temp = headNode;
		cout << "\nThe elements in the Link List is: ";
		for (int i = 0; i < count; ++i) {
			temp->print();
			temp = temp->nextNode;
		}
	}
}
	
cCircularList & cCircularList::reverse() {
	if (count < 2) return *this;
	cNode *ptr=headNode;
	cNode **ARR = new cNode *[count];
	for (int i = 0; i < count; i++) {
		ARR[i] = ptr;
		ptr->nextNode;
		cout << "j";
	}

	for (int i = 1; i < count; i++) {
		ARR[i]->nextNode = ARR[i - 1];

		cout << "j";
	}
	headNode = ARR[count - 1];
	ARR[0]->nextNode = ARR[count];
	delete [] ARR;
	return *this;
}

cCircularList::~cCircularList()
{
}
