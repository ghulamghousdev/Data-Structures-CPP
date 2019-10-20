#include <iostream>
#include "cNode.h"
#include "cStack.h"

using namespace std;

int main() {
	cStack stack;
	cNode node;
	/*
	Checking if the Stack is empty by using isEmpty function
	*/
	cout << "Checking if the Stack is empty by using isEmpty function\n";
	if (stack.isEmpty()) {
		cout << "Stack is empty\n\n";
	}
	else {
		cout << "Stack is not Empty\n\n";
	}

	/*
	Checking if the Stack is empty by using isEmpty function
	*/
	cout << "Checking if the Stack is empty by using isEmpty function\n";
	if (stack.isNotEmpty()) {
		cout << "Stack is not empty\n\n";
	}
	else {
		cout << "Stack is Empty\n\n";
	}
	
	/*
	Checking all the elements present in the STACK by printing them
	*/
	cout << "Checking all the elements present in the STACK by printing them\n";
	stack.print();
	cout << "\n";

	/*
	Declaring a node and setting the data
	*/
	cNode *ptr = new cNode(826); 
	/*
	Pushing the new node whose address is stored in ptr into the STACK
	*/
	stack.push(ptr);

	/*
	Now checking that if Stack is empty or not using empty function
	*/
	cout << "Now checking that if Stack is empty or not using empty function\n";
	if (stack.isEmpty()) {
		cout << "Stack is empty\n\n";
	}
	else {
		cout << "Stack is not Empty\n\n";
	}

	/*
	Now printing the data present in the STACK
	*/
	cout << "Now printing the data present in the STACK using print function\n";
	stack.print();

	/*
	Deleting the latest node from the STACK using pop function when only one node is present in the STACK
	*/
	stack.pop();

	/*
	After Deleting first latest node from STACK, printing the stack
	*/
	cout << "After Deleting first latest node from STACK, printing the stack\n";
	stack.print();

	/*
	Now declaring a node and setting data using setData fuction
	*/
	cNode *node1 = new cNode();
	node1->setData(100);
	stack.push(node1);
	cout << "Now declaring a node and setting data using setData fuction\n";
	stack.print();

	/*
	Now declaring few more nodes and setting data using set Data function and pushing them to 
	*/
	cNode *node2 = new cNode();
	node2->setData(200);
	stack.push(node2);

	cNode *node3 = new cNode();
	node3->setData(300);
	stack.push(node3);
	
	cNode *node4 = new cNode();
	node4->setData(400);
	stack.push(node4);
	
	cNode *node5 = new cNode();
	node5->setData(500);
	stack.push(node5);
	
	cNode *node6 = new cNode();
	node6->setData(600);
	stack.push(node6);
	
	cNode *node7 = new cNode();
	node7->setData(700);
	stack.push(node7);

	/*
	Now printing STACK after pushing 7 new nodes is isNotEmpty function returns true
	*/
	cout << "Now printing STACK after pushing 7 new nodes is isNotEmpty function returns true\n";
	if(stack.isNotEmpty()) stack.print();
	
	/*
	Now deleting top of STACK when more then one nodes is present
	*/
	cout << "Now deleting top of STACK when more then one nodes is present\n";
	stack.pop();
	if (stack.isNotEmpty()) stack.print();

	/*
	Now getting value of a node using getValue function
	*/
	cNode *node8 = new cNode();
	node8->setData(800);
	cout << "Now getting value of a node8 using getData function: ";
	cout<< node8->getData() <<"\n";

	system("pause");
}