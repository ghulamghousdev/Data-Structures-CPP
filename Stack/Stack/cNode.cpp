/*
Function definations of cNode class
*/

#include "cNode.h"
#include <iostream>
#include <fstream>
using namespace std;


//default constructor
cNode::cNode():data(0){}

/*
Parameterized constructor used to assign value passed 
by the user to the data member named as data
*/
cNode::cNode(int d): data(d){}

void cNode::readNodeFromFile(ifstream &inFile) { inFile.read((char*)this, sizeof(this)); }

void cNode::writeNodeToFile(ofstream &oFile) { oFile.write((char*)this, sizeof(this)); }
cNode::cNode (ifstream &inFile){ inFile.read((char*)this, sizeof(this)); }

cNode::cNode(ofstream &oFile) { oFile.write((char*)this, sizeof(this)); }
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
