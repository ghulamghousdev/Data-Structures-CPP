#pragma once
/*
Header file for cNode class
*/
#include<iostream>
#include <iostream>
using namespace std;
#include <fstream>

using namespace std;


class cNode
{
	//Data member to store value
	int data;
public:
	cNode *nextNode;
	cNode();
	cNode(int d);
	cNode(ifstream &inFile);
	cNode(ofstream &oFile);
	void writeNodetoFile(ofstream &outData);
	void readNodefromFile(ifstream &inData);
	void setData(int d);
	int getData();
	void print() const;
};

