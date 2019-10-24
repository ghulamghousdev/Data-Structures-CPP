/*
Driver Program for cList
*/
#include"cList.h"
#include<iostream>
#include <fstream>

using namespace std;

int main() {

	cList list;
	cNode node;
	
	//Checking if the LINKED LIST is empty by using isEmpty function
	cout << "Checking if the LINKED LIST is empty by using isEmpty function\n";
	if (list.isEmpty()) {
		cout << "LINKED LIST is empty\n\n";
	}
	else {
		cout << "LINKED LIST is not Empty\n\n";
	}

	
	//Checking if the LINKED LIST is empty by using isNotEmpty function
	cout << "Checking if the LINKED LIST is empty by using isNotEmpty function\n";
	if (list.isNotEmpty()) {
		cout << "LINKED LIST is not empty\n\n";
	}
	else {
		cout << "LINKED LIST is Empty\n\n";
	}

	
	//Checking all the elements present in the LINKED LIST by printing them
	cout << "Checking all the elements present in the LINKED LIST by printing them\n";
	list.print();
	cout << "\n";

	
	//Declaring a node and setting the data
	cNode *ptr = new cNode(826);
	
	//Pushing the new node whose address is stored in ptr into the STACK
	list.insert(ptr);

	
	//Now checking that if LINKED LIST is empty or not using empty function
	cout << "\nNow checking that if LINKED LIST is empty or not using empty function\n";
	if (list.isEmpty()) {
		cout << "LINKED LIST is empty\n\n";
	}
	else {
		cout << "LINKED LIST is not Empty\n\n";
	}

	
	//Now printing the data present in the LINKED LIST
	cout << "\nNow printing the data present in the LINKED LIST using print function\n";
	list.print();

	
	//Deleting the head node from the LINKED LIST using pop function when only one node is present in the LINKED LIST
	list.remove();

	
	//After Deleting first node from LINKED LIST, printing the stack
	cout << "\nAfter Deleting first latest node from LINKED LIST, printing the LINKED LIST\n";
	if (list.isNotEmpty())	list.print();

	
	//Now declaring a node and setting data using setData fuction
	cNode *node1 = new cNode();
	node1->setData(100);
	list.insert(node1);
	cout << "\nNow declaring a node and setting data using setData fuction\n";
	list.print();

	
	//Now declaring few more nodes and setting data using set Data function and pushing them to list
	cNode *node2 = new cNode();
	node2->setData(200);

	cNode *node3 = new cNode();
	node3->setData(300);

	cNode *node4 = new cNode();
	node4->setData(400);

	cNode *node5 = new cNode();
	node5->setData(500);

	cNode *node6 = new cNode();
	node6->setData(600);

	cNode *node7 = new cNode();
	node7->setData(700);
	list.insert(node2).insert(node3).insert(node4).insert(node5).insert(node6).insert(node7);

	
	//Now printing LINKED LIST after pushing 7 new nodes is isNotEmpty function returns true
	cout << "\nNow printing LINKED LIST  after pushing 7 new nodes is isNotEmpty function returns true\n";
	if (list.isNotEmpty()) list.print();

	//inserting new node at 4th index
	cNode *node8 = new cNode(5);
	list.insertAt(4, node8);

	//Now printing LINKED LIST after inserting new node at 4th index
	cout << "\nNow printing LINKED LIST after inserting new node at 4th index\n";
	if (list.isNotEmpty()) list.print();

	//Now deleting top of LINKED LIST  when more then one nodes is present
	cout << "\nNow deleting top of LINKED LIST when more then one nodes is present\n";
	list.remove();
	if (list.isNotEmpty()) list.print();

	//Now deleting 3rd node from the LINKED LIST
	cout << "\nNow deleting 3rd node from the LINKED LIST\n";
	list.removeAt(3);
	if (list.isNotEmpty()) list.print();

	//Swapping the nodes present at  index 1 and 3
	cout << "\nSwapping the nodes present at  index 1 and 3\n";
	list.swapNodesAt(1, 3);
	if (list.isNotEmpty()) list.print();

	
	

	//Now getting value of a node using getValue function
	cNode *node11 = new cNode();
	node11->setData(800);
	cout << "\nNow getting value of a node11 using getData function: ";
	cout << node11->getData() << "\n";

	//reversing the list
	cout << "\n\nAfter reversing the list";
	list.reverse();
	if (list.isNotEmpty()) list.print();
	
	//Checking copy constructor 
	cList list1(list);
	cout << "\nList after copying contents of one list into another using copyconstructor: \n";
	 list1.print();

	 //Copying contents of one list to another using assignment operator
	 cList list2 = list1;
	 cout << "\nCopying contents of one list to another using assignment operator\n";
	 if (list2.isNotEmpty()) 
		list2.print();
	 //Opeing file for write operation
	 ofstream outFile;
	 outFile.open("C:/Users/Ghous/Documents/MID TERM PROJECT DSA/Linked_List/Linked_List/data.txt");

	 if (outFile.is_open()) {
		 cout << "\nStarted writing to file !" << endl;
		 list.writeListToFile(outFile);
		 cout << "Done writing to file !" << endl;
	 }
	 else {
		 cout << "File not opened for writing !" << endl;
	 }

	 outFile.close();

	

	 ifstream inFile;
	 inFile.open("C:/Users/Ghous/Documents/MID TERM PROJECT DSA/Linked_List/Linked_List/data.txt");
	 cList linkList;

	 if (inFile.is_open()) {
		 cout << "\nReading data of linkList from file data.txt" << endl;
		 linkList.readListFromFile(inFile);
		 cout << "Done Reading from file !\n";
	 }
	 else {
		 cout << "The file is not opened for the Read operation !" << endl;
	 }

	 cout << "Printing list object Read from file" << endl;
	 linkList.print();

	 inFile.close();
	 
	 //reversing the list
	 cout << "\n\nAfter reversing the list";
	 list.reverse();
	 if (list.isNotEmpty()) list.print();


	system("pause");

	return 0;

}