#pragma once

class cNode
{
	int data;
public:
	cNode *nextNode;

	cNode();
	cNode(int d);
	//cNode(ifstream &inFile);
	//cNode(ofstream &oFile);
	//void writeNodetoFile(ofstream &outData);
	//void readNodefromFile(ifstream &inData);
	cNode & setData(int d);
	int getData();
	void print() const;
};

