#include "cNode.h"
#include <iostream>

using namespace std;



cNode::cNode():nextNode(0),data(0){}

cNode::cNode(int d):data(d){}
/*
//Constructors for File Handling
cNode::cNode(ifstream &inFile) { inFile.read((char*)this, sizeof(this)); }
cNode::cNode(ofstream &oFile) { oFile.write((char*)this, sizeof(this)); }

//Functions for File Handling
void  cNode::writeNodetoFile(ofstream &outData) { outData.write((char*)this, sizeof(this)); }
void  cNode::readNodefromFile(ifstream &inData) { inData.read((char*)this, sizeof(this)); }
*/

cNode& cNode::setData(int d) {
	this->data = d;
	return *this;
}

int cNode::getData() {
	return data;
}

void cNode::print() const {
	cout << data << " ";
}



