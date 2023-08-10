#pragma once
#include <iostream>

// 'D' for data
template<typename D>
class Node
{
private:
	// Binary tree navigation pointers
	Node<D>* left;
	Node<D>* right;
	Node<D>* parent;

	// Node content variable
	D data;

public:
	// Default constructor
	Node<D>() {
		std::cout << "Node default constructor built." << std::endl;
		left = nullptr;
		right = nullptr;
	};

	Node<D>(D value) {
		data = value;
	};

	// Destructor
	~Node<D>() {
		/*if (this != nullptr) {
			Scrub();
		}*/
	};

	bool HasLeft() {
		// Return true if left node is NOT a null pointer
		return (left != nullptr);
	};

	bool HasRight() {
		// Return true if right node is NOT a null pointer
		return (right != nullptr);
	};

	D GetData() {
		return data;
	};

	Node<D>* GetLeft() {
		// Set existing left pointer equal to passed-in pointer
		return left;
	};

	Node<D>* GetRight() {
		// Set existing right pointer equal to passed-in pointer
		return right;
	};

	Node<D>* GetParent() {
		// Set existing parent pointer equal to passed-in pointer
		return parent;
	};

	void SetData(D newData) {
		// Overloaded operator found in data object definition
		data = newData;
	};

	void SetLeft(Node<D>* newLeft) {
		// Set existing left pointer equal to passed-in pointer
		left = newLeft;
	};

	void SetRight(Node<D>* newRight) {
		// Set existing right pointer equal to passed-in pointer
		right = newRight;
	};

	void SetParent(Node<D>* newParent) {
		parent = newParent;
	}

	void Scrub() {
		if (left != nullptr) {
			delete left;
			left = nullptr;
		}		

		if (right != nullptr) {
			delete right;
			right = nullptr;
		}

		if (parent != nullptr) {
			delete parent;
			parent = nullptr;
		}		
	};
};