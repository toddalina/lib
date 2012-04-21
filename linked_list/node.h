/*
	Copyright 2012 by Toddalina
	Licensed under ...
	Date: 4-20-12
*/
/*		Provides the methods and data for the node class		*/
#include <iostream>
using namespace std;

struct node
{
	/*	Methods	 */
	node();															// Default node constructor
	node(int item) { left = NULL; right = NULL; data = item; }		// Parameterized node constructor
	~node() {}														// Node destructor

	/*	Data	*/
	node * right;													// Next node in the linked list
	node * left;													// Previous node in the linked list
	int data;														// Holds the data of the node
};