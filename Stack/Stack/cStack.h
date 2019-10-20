#pragma once
#include <iostream>
#include "cNode.h"
using namespace std;

class cStack
{
	//This is a pointer used to point to the top element of STACK
	cNode *top;

public:
	//Default constructor
	cStack(); 

	/*
	Parameterized Class Constructor
	Generating a single node stack using pointer Reference to avoid multiple pointer to same node
	*/
	cStack(cNode *&ptr); 

	//Checking that if the STACK is empty or not
	bool isEmpty() const; 
	bool isNotEmpty() const;
	/*
	Push a node at the end of the STACK using a node pointer
	Returning Reference will allow cascadeability use
	*/
	cStack & push(cNode *&ptr);
	/*
	Extracting the first node from the STACK
	*/
	cNode * pop();
	/*
	This function is used to print all the elements in the STACK
	*/
	void print() const;
	/*
	Copy constructor used to copy contents of one STACK to other STACK
	*/
	cStack(const cStack & src);
	/*
	Overloading the assignment operator for the STACK class
	*/
	cStack & operator = (const cStack & rObj);
	/*
	Default desstructor wouldn't delete the stack allocated on HEAP so the self defined deletes all nodes in STACK
	*/
	~cStack(); 
};

