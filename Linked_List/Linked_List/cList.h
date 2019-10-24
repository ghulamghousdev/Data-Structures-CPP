/*
Header file for cList class
*/
#pragma once
#include "cNode.h"
#include<iostream>
#include <fstream>

using namespace std;

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
	//File handling constructors
	cList(ifstream &inFile);
	cList(ofstream &outFile);
	//Function for writing in file
	void writeListToFile(ofstream &oFile);
	//Function for reading from file
	void readListFromFile(ifstream &inFile);
	//Functios to check if list is empty or not
	bool isEmpty();
	bool isNotEmpty();
	//Function to insert at the start of the Link List
	cList & insert(cNode *& ptr);
	//Function to insert at a specific index
	cList & insertAt(int index, cNode *& ptr);
	//Removing the first node from the list
	cNode* remove();
	//Function to delete a node from a specific index
	cNode* removeAt(int index);
	//Function to swap two nodes
	cList & swapNodesAt(int index1, int index2);
	//Function to reverse the list
	cList & reverse();
	//Cancatenating one list with another list
	cList & operator +(const cList & robj);
	//Printing all the nodes in the cList
	void print() const;
	//Function to delete nodes from list
	void deleteNode(cNode *&ptr);
	//Copy Constructor of LIST class
	cList(const cList & src);
	//Assignment operator overloaded
	cList& operator =(const cList & robj);
	//Destructor
	~cList();
};

