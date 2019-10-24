#pragma once
/*
Header file for cNode class
*/
#include <iostream>
#include <fstream>
using namespace std;
class cNode
{
	
	//Variable used to carry value of every node in the STACK
	int data;

public:
	
	//Reference to next cNode Object
	cNode* nextNode;
	
	//Default constructor
	cNode();

	//Parameterized Constuctor
	cNode(int d);

	//Class constructor for imput from File
	cNode(ifstream &inFile); 

	//Member function for input from File
	void readNodeFromFile(ifstream &inFile);

	cNode(ofstream &oFile);
	//Memeber function for wrirting output to File
	void writeNodeToFile(ofstream &oFile);
	
	//Function to set data in the node of a STACK
	cNode & setData(int number);

	//Function to get data of a node 
	int getData();

	//Print Function is used to print all the elements in the STACK
	void print() const;

	//Default desstructor wouldn't delete the memory allocated on HEAP
	~cNode();
};

