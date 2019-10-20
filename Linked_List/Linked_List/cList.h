#pragma once
#include "cNode.h"

class cList
{
	//The HEAD reference of LIST object
	cNode *headNode;
	
public:
	//Keep record of the number of elements of LIST class
	int count;

	//Link List constructors
	cList();
	cList(cNode *& ptr);
	/*cList(ifstream &inFile);
	cList(ofstream &outFile);
	
	void writeListToFile(ofstream &oFile);
	void readListFromFile(ifstream &inFile);*/
	bool isEmpty();
	bool isNotEmpty();
	cList & insert(cNode *& ptr);
	cList & insertAt(int index, cNode *& ptr);
	cNode* remove();
	cNode* removeAt(int index);
	cList & swapNodesAt(int index1, int index2);
	cList & reverse();
	cList & operator +(const cList & robj);
	void print() const;
	void deleteNode(cNode *&ptr);
	//Copy Constructor of LIST class
	cList(const cList & src);
	cList& operator =(const cList & robj);
	~cList();
};

