#include "node.h"

struct list
{
	list() { root = NULL; size = 0; };
	~list();
	void Insert(int item);
	void Erase(int item);
	bool Find(int item);						// Might not need...
	int Size() const { return size; }
	void Print() const;
	void Deleter();

	//node * next();

	node * root;
	int size;
};