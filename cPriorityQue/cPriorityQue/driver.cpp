#include <iostream>
#include "cNode.h"
#include "cStack.h"
#include "cQueue.h"
#include "cPriorityQue.h"

using namespace std;

int main() {
	cPriorityQue queue;
	/*
	Checking if the Queue is empty by using isEmpty function
	*/
	cout << "Checking if the Queue is empty by using isEmpty function\n";
	if (queue.isEmpty()) {
		cout << "Queue is empty\n\n";
	}
	else {
		cout << "Queue is not Empty\n\n";
	}

	/*
	Checking if the Queue is empty by using isEmpty function
	*/
	cout << "Checking if the Queue is empty by using isEmpty function\n";
	if (queue.isNotEmpty()) {
		cout << "Queue is not empty\n\n";
	}
	else {
		cout << "Queue is Empty\n\n";
	}

	/*
	Checking all the elements present in the Queue by printing them
	*/
	cout << "Checking all the elements present in the queue by printing them\n";
	queue.print();
	cout << "\n";

	/*
	Declaring a node and setting the data
	*/
	cNode *ptr = new cNode(826);
	ptr->setPriority(2);
	/*
	Pushing the new node whose address is stored in ptr into the Queue
	*/
	queue.addInPriorityQue(ptr);

	/*
	Now checking that if Queue is empty or not using empty function
	*/
	cout << "Now checking that if Queue is empty or not using empty function\n";
	if (queue.isEmpty()) {
		cout << "Queue is empty\n\n";
	}
	else {
		cout << "Queue is not Empty\n\n";
	}

	/*
	Now printing the data present in the Queue
	*/
	cout << "Now printing the data present in the Queue using print function\n";
	queue.print();

	/*
	Deleting the latest node from the Queue using pop function when only one node is present in the Queue
	*/
	queue.removeFromPriorityQue();
	/*
	After Deleting first latest node from Queue, printing the Queue
	*/
	cout << "After Deleting first latest node from Queue, printing the Queue\n";
	queue.print();

	/*
	Now declaring a node and setting data using setData fuction
	*/
	cNode *node1 = new cNode();
	node1->setData(100);
	node1->setPriority(31);
	queue.addInPriorityQue(node1);
	cout << "Now declaring a node and setting data using setData fuction\n";
	queue.print();
	
	/*
	Now declaring few more nodes and setting data using set Data function and pushing them to queue
	*/
	cNode *node2 = new cNode();
	node2->setData(200);
	node2->setPriority(21);
	queue.addInPriorityQue(node2);
	
	cNode *node3 = new cNode();
	node3->setData(300);
	node3->setPriority(23);
	queue.addInPriorityQue(node3);

	cNode *node4 = new cNode();
	node4->setData(400);
	node4->setPriority(5);
	queue.addInPriorityQue(node4);

	cNode *node5 = new cNode();
	node5->setData(500);
	node5->setPriority(4);
	queue.addInPriorityQue(node5);

	cNode *node6 = new cNode();
	node6->setData(600);
	node6->setPriority(13);
	queue.addInPriorityQue(node6);

	cNode *node7 = new cNode();
	node7->setData(700);
	node7->setPriority(3);
	queue.addInPriorityQue(node7);

	cNode *node9 = new cNode();
	node9->setData(900);
	node9->setPriority(6);
	queue.addInPriorityQue(node9);

	cNode *node10 = new cNode();
	node10->setData(5700);
	node10->setPriority(8);
	queue.addInPriorityQue(node10);

	cNode *node11 = new cNode();
	node11->setData(6100);
	node11->setPriority(11);
	queue.addInPriorityQue(node11);

	cNode *node12 = new cNode();
	node12->setData(7300);
	node12->setPriority(14);
	queue.addInPriorityQue(node12);

	/*
	Now printing Queue after pushing 7 new nodes
	*/
	cout << "Now printing Queue after pushing 7 new nodes if isNotEmpty function returns true\n";
	if (queue.isNotEmpty()) queue.print();

	/*
	Now deleting top of queue when more then one nodes is present
	*/
	cout << "Now deleting top of Queue when more then one nodes is present\n";
	queue.removeFromPriorityQue();
	if (queue.isNotEmpty()) queue.print();

	/*
	Now getting value of a node using getValue function
	*/
	cNode *node8 = new cNode();
	node8->setData(800);
	node8->setPriority(5);
	cout << "Now getting value of a node8 using getData function: ";
	cout << node8->getData() << "\n";

	/*
	Copying content of one queue to another queue using copy constructor
	*/
	cPriorityQue queueDestination(queue);
	/*
	Printing the contents of queue destination
	*/
	cout << "Copying content of one queue to another queue using copy constructor and Printing the contents of queue destination\n";
	queueDestination.print();
	/*
	Checking Assignment Operator
	*/
	cout << "\nCopying content of one queue to another queue using copy constructor and Printing the contents of queue destination\n";
	cPriorityQue queue1=queueDestination;
	queue1.print();
	
	system("pause");
}