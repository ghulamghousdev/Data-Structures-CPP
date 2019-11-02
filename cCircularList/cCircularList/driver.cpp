/*
Driver program for cCircularList
*/
#include<iostream>
#include "cCircularList.h"
using namespace std;

int main() {

	cCircularList list;
	cNode* n1 = new cNode(10);
	cNode* n2 = new cNode(120);
	cNode* n3 = new cNode(302);
	cNode* n4 = new cNode(40);
	cNode* n5 = new cNode(222);
	cNode* n6 = new cNode(42);
	cNode* n7 = new cNode(701); 

	list.insert(n1).insert(n2).insert(n3).insert(n4).insert(n5).insert(n6).insert(n7);
	//list.print();
	//list.swapNodesAt(3, 4);
	list.print();
	list.sorting();
	list.print();
	list.reverse();
	list.print();
	list.flip();
	list.print();
	cout << endl << endl;
	system("pause");
}