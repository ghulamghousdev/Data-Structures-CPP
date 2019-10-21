#pragma once
#include<iostream>
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
	cNode & setData(int d);
	int getData();
	void print() const;
};

