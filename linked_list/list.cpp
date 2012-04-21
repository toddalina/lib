/*
	Copyright 2012 by Toddalina
	Licensed under ...
	Date: 4-20-12
*/
/*		Provides the implementation for the linked list class		*/
#include "list.h"

/* list::~list()
	Default Destructor for the list class. Just call Deleter().
	Preconditions: none
	Postconditions: none
*/
list::~list()
{
	/*	Destruction is done in the Deleter method, since when passing around the set, 
			destructors are called that delete all of the items, and stuff disappears.	*/
}

/* void list::Deleter()
	Deletes a linked list
	Preconditions: none
	Postconditions: The list is deleted.
*/
void list::Deleter()
{
	node * current = root;
	if (current != NULL)
	{
		node * temp = current;
		while (current != NULL)
		{
			current = current->right;
			delete temp;
			temp = current;
			--size;
		}
	}
}

/* void list::Insert(int item)
	Inserts a new item into the linked list
	Preconditions: Valid int is passed to enter into the linked list
	Postconditions: The item is added to the list. As items are added to the list, they are automatically sorted. (Basically finds where the int would go and sticks it there.)
*/
void list::Insert(int item)
{
	if (root == NULL)								// If the list is empty...
	{
		root = new node(item);
		root->left = NULL;
		root->right = NULL;
		++size;
	}
	else											// The list is not empty
	{
		if (root->data == item)						// Check and see if the item is already in the list
			return;
		node * current = root;
		while (item > current->data)				// Find the spot to insert the item
		{
			if (current->right == NULL)
				break;
			current = current->right;
		}
		node * new_node = new node(item);
		++size;
		if (item > current->data)					// Insert the new node
		{
			current->right = new_node;
			new_node->left = current;
			new_node->right = NULL;
		}
		else
		{
			new_node->left = current->left;
			new_node->right = current;
			if (new_node->left != NULL)
				new_node->left->right = new_node;
			if (new_node->right != NULL)
				new_node->right->left = new_node;
			if (current == root)
			{
				root = new_node;
				root->left = NULL;
			}
		}
	}
}

/* void list::Erase(int item)
	Removes an item from the linked list
	Preconditions: Valid int is passed to remove from the linked list
	Postconditions: The item is removed from the list.
*/
void list::Erase(int item)
{
	if (root == NULL)
		return;
	node * current = root;
	bool removed = false;					// Used to check for whether to break out of the loop or not.

	while (!removed)
	{
		if (current == NULL)
			removed = true;
		if (current->data == item)			// If the item is found, remove it.
		{
			if (current == root)
			{
				if (current->right == NULL)		// The root node is the only node.
				{
					delete root;
					root = NULL;
					removed = true;
					size = 0;
				}
				else							// The root node is to be deleted but there are other elements in the tree.
				{
					current = current->right;
					delete root;
					root = current;
					root->left = NULL;
					removed = true;
					--size;
				}
			}
			else if (current->right != NULL)	// Node is in the middle of the list.
			{
				if (current->left != NULL)		// Might not need this statement
				{
					current->left->right = current->right;
					current->right->left = current->left;
					delete current;
					removed = true;
					--size;
				}
			}
			else								// The last node in the list is to be deleted.
			{
				if (current->left != NULL)
					current->left->right = NULL;
				delete current;
				removed = true;
				--size;
			}
		}
		else									// Item does not match the current node, go to the next node.
			current = current->right;
	}
}

/* bool list::Find()
	Finds an item in the linked list
	Preconditions: Valid int is to be searched for
	Postconditions: A boolean is returned stating whether the item was found or not
*/
bool list::Find(int item)
{
	node * current = root;
	while (current != NULL)
	{
		if (current->data == item)
			return true;
		else 
			current = current->right;
	}
	return false;
}

/* void list::Print()
	Prints the linked list
	Preconditions: none
	Postconditions: The list is printed
*/
void list::Print() const
{
	node * current = root;
	while (current != NULL)
	{
		cout << current->data << "->";
		current = current->right;
	}
}