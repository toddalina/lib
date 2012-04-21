/*
	Copyright 2012 by Toddalina
	Licensed under ...
	Date: 4-20-12
*/

/*		Provides the methods and data for the linked list class		*/
#include "node.h"

struct list
{
	/*	Methods	 */
	list() { root = NULL; size = 0; };			// Constructor for the linked list
	~list();									// Destructor for the linked list
	void Insert(int item);						// Inserts a new item into the list
	void Erase(int item);						// Removes an item from the linked list
	bool Find(int item);						// Determines whether an item is in the linked list or not
	int Size() const { return size; }			// Returns the size of the linked list
	void Print() const;							// Prints the linked list
	void Deleter();								// Provides the functions normally provided by ~Set()

	/*	Data	*/
	node * root;								// root node for the linked list
	int size;									// Number of elements in the linked list
};