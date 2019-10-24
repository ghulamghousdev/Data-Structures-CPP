/*
Header file for cQueue class
*/
#pragma once
#include "cNode.h"
#include "cStack.h"
#include <iostream>

using namespace std;

class cQueue :protected cStack
{
protected:
	cNode *tail;
public:
	cQueue();
	cQueue(cNode* &Ptr);
	cQueue(const cQueue &Source);
	cQueue& operator=(const cQueue &Source);
	cQueue& add(cNode* &Ptr);
	~cQueue();
	cNode* remove();
	bool isEmpty() const;
	bool isNotEmpty() const;
	void print() const;
};