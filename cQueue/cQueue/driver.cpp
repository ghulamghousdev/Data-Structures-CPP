/*
Driver program for cQueue
*/
#include <iostream>
#include "cNode.h"
#include "cStack.h"
#include "cQueue.h"

using namespace std;

int main() {
	cQueue queue;
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
	/*
	Pushing the new node whose address is stored in ptr into the Queue
	*/
	queue.add(ptr);

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
	queue.remove();
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
	queue.add(node1);
	cout << "Now declaring a node and setting data using setData fuction\n";
	queue.print();
	/*
	Now declaring few more nodes and setting data using set Data function and pushing them to queue
	*/
	cNode *node2 = new cNode();
	node2->setData(200);
	queue.add(node2);

	cNode *node3 = new cNode();
	node3->setData(300);
	queue.add(node3);

	cNode *node4 = new cNode();
	node4->setData(400);
	queue.add(node4);

	cNode *node5 = new cNode();
	node5->setData(500);
	queue.add(node5);

	cNode *node6 = new cNode();
	node6->setData(600);
	queue.add(node6);

	cNode *node7 = new cNode();
	node7->setData(700);
	queue.add(node7);

	/*
	Now printing Queue after pushing 7 new nodes
	*/
	cout << "Now printing Queue after pushing 7 new nodes if isNotEmpty function returns true\n";
	if (queue.isNotEmpty()) queue.print();

	/*
	Now deleting top of queue when more then one nodes is present
	*/
	cout << "Now deleting top of Queue when more then one nodes is present\n";
	queue.remove();
	if (queue.isNotEmpty()) queue.print();

	/*
	Now getting value of a node using getValue function
	*/
	cNode *node8 = new cNode();
	node8->setData(800);
	cout << "Now getting value of a node8 using getData function: ";
	cout << node8->getData() << "\n";

	/*
	Copying content of one queue to another queue using copy constructor
	*/
	cQueue queueDestination(queue);
	/*
	Printing the contents of queue destination
	*/
	cout << "Copying content of one queue to another queue using copy constructor and Printing the contents of queue destination\n";
	queueDestination.print();


	/*
	Copying content of one queue to another queue using assignment constructor
	*/
	cQueue queueDestination1=queue;
	/*
	Printing the contents of queue destination
	*/
	cout << "Copying content of one queue to another queue using assignment operator and Printing the contents of queue destination1\n";
	queueDestination1.print();
	

	system("pause");
}