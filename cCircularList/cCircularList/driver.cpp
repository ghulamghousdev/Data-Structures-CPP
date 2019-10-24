/*
Driver program for cCircularList
*/
#include<iostream>
#include "cCircularList.h"
using namespace std;

int main() {

	cCircularList list;
	cNode* n1 = new cNode(10);
	cNode* n2 = new cNode(20);
	cNode* n3 = new cNode(30);
	cNode* n4 = new cNode(40);
	cNode* n5 = new cNode(50);
	cNode* n6 = new cNode(60);
	cNode* n7 = new cNode(70);

	list.insert(n1).insert(n2).insert(n3);
	list.print();
	list.insertAt(5, n4);
	list.print();
	list.reverse();
	list.print();

	system("pause");
}