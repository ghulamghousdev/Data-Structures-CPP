/*
Implementation file for cCircularList
*/
#include "cCircularList.h"
#include <iostream>
using namespace std;


cCircularList::cCircularList() :count(0), headNode(NULL) {}

cCircularList::cCircularList(cNode*& ptr) : headNode(ptr), count(1) {
	headNode->nextNode = ptr;
	ptr = NULL;
}

cCircularList& cCircularList::insert(cNode*& ptr) {
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

cCircularList& cCircularList::insertAt(int index, cNode*& ptr) {
	if (index <= 0)	insert(ptr);
	if (index >= count) index = count;
	cNode* rptr = headNode->nextNode;
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

cNode* cCircularList::remove()
{
	cNode* ptr;
	if (count <= 1) {
		ptr = headNode;
		headNode = NULL;
	}
	else
	{
		ptr = headNode->nextNode;
		headNode->nextNode = ptr->nextNode;
	}
	ptr->nextNode = NULL;
	--count;
	return ptr;
}

//Function to insert at a specific node
cNode* cCircularList::removeAt(int index) {
	if (index <= 0 || count == 1) { //when index is less then or equal to zero, deleting the head node
		return remove();
	}
	if (index >= count) { //when index is greater the or equal to count, resetting the index equal to count 
		index = count - 1;
	}
	cNode* ptr, * rptr = headNode->nextNode; //Runner pointer
	for (int i = 0; i < index; ++i)	rptr = rptr->nextNode; //Moving through the list to find the node to be deleted
	if (rptr->nextNode == headNode) {
		headNode = rptr;
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
		cNode* temp = headNode->nextNode;
		cout << "\nThe elements in the Link List is: ";
		for (int i = 0; i < count; ++i) {
			temp->print();
			temp = temp->nextNode;
		}
	}
}

cCircularList& cCircularList::swapNodesAt(int index1, int index2)
{
	if (index1 < 0) index1 = 0;
	if (index2 < 0) index2 = 0;
	if (index1 >= count) index1 = count - 1;
	if (index2 >= count) index2 = count - 1;
	if (index1 == index2) return *this;
	if (index1 < index2) { //when index1 is less then index2
		cNode* ptr = removeAt(index1);
		insertAt((index2 - 1), ptr);			//removig the node from index1 and iserting at index2-1 
		cNode* ptr1 = removeAt(index2);
		insertAt(index1, ptr1);		 //removing node from index2 and inserting it at index1	
	}
	else {									//when index 1 is greater then index2
		cNode* ptr = removeAt(index2);
		insertAt((index1 - 1), ptr);			//removig the node from index2 and iserting at index1-1 
		cNode* ptr1 = removeAt(index1);
		insertAt(index2, ptr1);	//removig the node from index1 and iserting at index2 
	}
	return *this;
}


void cCircularList::sorting() {

	cNode* temp;
	int index;
	temp = headNode->nextNode;
	for (int i = 0; i < count - 1; i++) {
		cNode* rptr = temp->nextNode;

		for (int j = i + 1; j < count; j++) {

			if (temp->getData() > rptr->getData()) {

				index = temp->getData();
				temp->setData(rptr->getData());
				rptr->setData(index);
			}

			rptr = rptr->nextNode;
		}

		temp = temp->nextNode;
	}

}

cCircularList& cCircularList::reverse() {
	if (count < 2) return *this; //When only one node is present in the list 

	cNode* ptr;
	cNode** ARR = new cNode * [count];
	ptr = headNode->nextNode;
	for (int i = 0; i < count; ++i) {
		ARR[i] = ptr;
		ptr = ptr->nextNode;
	}
	for (int i = 1; i < count; ++i) {
		ARR[i]->nextNode = ARR[i - 1];
	}
	ARR[0]->nextNode = ARR[count - 1];
	headNode = ARR[0];
	delete[] ARR;
	return *this;
}

cCircularList& cCircularList::flip()
{
	reverse();
	if (count % 2 != 0) {
		headNode = headNode->nextNode;
	}
	return *this;
}

cNode& cCircularList::operator[](int Index)           // First element is 0.
{
	if (Index <= 0)
		return *headNode;                          // If Index is smaller than one we return Top;

	if (Index >= count)
		Index = count - 1;

	cNode* ptr = headNode->nextNode;

	for (int i = 0; i < Index; ++i)
		ptr = ptr->nextNode;

	return *ptr;
}


cCircularList::cCircularList(const cCircularList& src) {
	this->headNode = src.headNode;
	this->count = src.count;
	if (count > 0) {
		cNode* sptr, * dptr;
		dptr = headNode = new cNode(*src.headNode);
		sptr = src.headNode->nextNode;
		for (int i = 1; i < count; ++i) {
			dptr->nextNode = new cNode(*sptr);
			sptr = sptr->nextNode;
			dptr = dptr->nextNode;
		}
		dptr->nextNode = headNode;
	}
}



cCircularList::~cCircularList()
{
	cNode* ptr;
	ptr = headNode;
	for (int i = 0; i < count; i++) {
		ptr = ptr->nextNode;
		delete headNode;
		headNode = ptr;
	}
}