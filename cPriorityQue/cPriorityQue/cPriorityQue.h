#pragma once
#include "cQueue.h"
#include <iostream>

using namespace std;

class cPriorityQue:protected cQueue{
public:
	cPriorityQue();
	cPriorityQue(cNode *& ptr);

	bool isEmpty() const;
	bool isNotEmpty() const;
	cPriorityQue & addInPriorityQue(cNode *&ptr);
	cNode * removeFromPriorityQue();
	cPriorityQue(const cPriorityQue & src);
	cPriorityQue operator = (const cPriorityQue & robj);
	void print() const;
	~cPriorityQue();
};

