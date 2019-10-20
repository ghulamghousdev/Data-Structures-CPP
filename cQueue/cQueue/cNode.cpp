/*
Function definations of cNode class
*/

#include <iostream>
#include "cNode.h"
using namespace std;


//default constructor
cNode::cNode() :data(0) {}

/*
Parameterized constructor used to assign value passed
by the user to the data member named as data
*/
cNode::cNode(int d) : data(d) {}

/*
Function used to set data passed by the user in node of STACK
*/
cNode& cNode::setData(int number) {
	this->data = number;
	return *this;
}

/*
Function used to get data and return it from a node of STACK
*/
int cNode::getData() {
	return data;
}

/*
Print function is used to print all the elements of the STACK
*/
void cNode::print() const {
	cout << data << " ";
}
/*
Default desstructor wouldn't delete the memory allocated on HEAP
*/
cNode::~cNode()
{
}
#pragma once