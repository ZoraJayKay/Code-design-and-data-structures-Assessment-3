#pragma once
#include "Node.h"
#include "DataObject.h"
#include <iostream>

class BinaryTree
{
private:
	// Find a node with a specific value
	// These are node pointer references, not node object references. We do this so that we can change the value of the pointer, and this change persists after the function exits (we’re changing the value of the pointer).
	bool FindNode(int searchValue, Node<int>*& outNode, Node<int>*& outParent);

	// The root of the binary tree
	Node<int>* rootNode;

	// An iterator to navigate the tree
	Node<int>* currentNode;

public:
	// Default constructor
	BinaryTree();

	// Default destructor
	~BinaryTree();

	//A function for returning true/false whether the tree is empty
	const bool IsEmpty();

	// A function for inserting a node into the tree
	void Insert(int value);

	// A function for removing a node from the tree
	void Remove(int value);

	// A function to return all of the values of the binary tree in the order they are
	void PrintPreOrdered(Node<int>* node);

	// A function to return all of the values of the binary tree in ascending order
	void PrintOrdered(Node<int>* node);
	
	// A function to return the nodes from the outermost leaves inward
	void PrintPostOrdered(Node<int>* node);

	// A function to return all of the values of the binary tree in reverse order
	void PrintReverseOrdered(Node<int>* node);

	// A function to return the root node
	Node<int>* GetRoot();

	// A function to clear the binary tree from the leaves inward
	void Clear(Node<int>* node);
};

