//#include <iostream>
#include "list.h"
//using namespace std;

list::~list()
{
	/*	Destruction is done in the Deleter method, since when passing around the set, 
			destructors are called that delete all of the items, nad stuff disappears.	*/
}


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


void list::Insert(int item)
{
	if (root == NULL)
	{
		root = new node(item);
		root->left = NULL;
		root->right = NULL;
		++size;
	}
	else
	{
		if (root->data == item)
			return;
		node * current = root;
		while (item > current->data)
		{
			if (current->right == NULL)
				break;
			current = current->right;
		}
		node * new_node = new node(item);
		++size;
		if (item > current->data)
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

// Might not need this... Actually, implement it.
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


void list::Print() const
{
	node * current = root;
	while (current != NULL)
	{
		cout << current->data << "->";
		current = current->right;
	}
}