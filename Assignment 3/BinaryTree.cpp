#include "BinaryTree.h"

// Default constructor
BinaryTree::BinaryTree() {
	
#ifndef NDEBUG
	std::cout << "\nBinary tree default constructor built." << std::endl;
#endif

	rootNode = nullptr;
	currentNode = nullptr;
};

// Default destructor
BinaryTree::~BinaryTree() {
	#ifndef NDEBUG
	std::cout << "\nBinary tree destructor started." << std::endl;
	#endif

	Clear(rootNode);

	delete rootNode;
	rootNode = nullptr;

	delete currentNode;
	currentNode = nullptr;

	#ifndef NDEBUG
	std::cout << "\nBinary tree destruction complete." << std::endl;
	#endif
};

// A function for returning true/false whether the tree is empty
const bool BinaryTree::IsEmpty()
{
#ifndef NDEBUG
	std::cout << "TREE DEBUG: The binary tree will be checked for whether it is empty." << std::endl;
#endif
	if (rootNode == nullptr) {
		std::cout << "TREE DEBUG: The binary tree is empty." << std::endl;
	return true;
	}

#ifndef NDEBUG
	std::cout << "TREE DEBUG: The binary tree is not empty." << std::endl;
#endif
	return false;
}

// A function to find a node by its value, and copy that node and its parent to an empty node and parent.
bool BinaryTree::FindNode(int searchValue, Node<int>*& outNode, Node<int>*& outParent) {
	#ifndef NDEBUG
	std::cout << "\nTREE DEBUG: A request to find a node with value ("<< searchValue << ") has been made." << std::endl;
	#endif

	// If the binary tree is empty, then do nothing.
	if (IsEmpty()) {
		#ifndef NDEBUG
		std::cout << "TREE DEBUG: The binary tree was empty - there is nothing to search. Find process complete." << std::endl;
		#endif

		return false;
	}

	else {
		// Set the current node to the root
		currentNode = rootNode;
		#ifndef NDEBUG
		std::cout << "TREE DEBUG: The iterator has been set to the root node (" << currentNode->GetData() << ")." << std::endl;
		#endif

		// And while the current node is not null...
		while (currentNode != nullptr) {
			// If the search value equals the current node value...
			if (searchValue == currentNode->GetData()) {
				#ifndef NDEBUG
				std::cout << "TREE DEBUG: The iterator has found the value being searched for (" << searchValue << ")." << std::endl;
				#endif

				// return the current node and its parent
				outNode = currentNode;
				outParent = currentNode->GetParent();

				// Exit the function and return 'true' (that the value was found)
				return true;
			}

			// otherwise if the search value is less than the current node...
			else if (searchValue < currentNode->GetData()) {
				#ifndef NDEBUG
				std::cout << "TREE DEBUG: The iterator has not yet found the value being searched for. The searched value (" << searchValue << ") is lower than the iterator's (" << currentNode->GetData()<< "), so moving to the left node." << std::endl;
				#endif

				// set the current node to the left child.
				currentNode = currentNode->GetLeft();
			}

			// Otherwise set the current node to the right child
			else if (searchValue > currentNode->GetData()) {
				#ifndef NDEBUG
				std::cout << "TREE DEBUG: The iterator has not yet found the value being searched for. The searched value (" << searchValue << ") is higher than the iterator's (" << currentNode->GetData() << "), so moving to the right node." << std::endl;
				#endif

				currentNode = currentNode->GetRight();
			}
		};

		#ifndef NDEBUG
		std::cout << "TREE DEBUG: The iterator did not find the searched value in the tree. Search ended." << std::endl;
		#endif

		// If the loop exits, then a match was not found, so return false
		return false;
	};
};

// A function for inserting a node based upon its value 
void BinaryTree::Insert(int value) {
	#ifndef NDEBUG
	std::cout << "\nTREE DEBUG: A node insert request has been made." << std::endl;
	#endif

	// If the tree is empty, the value is inserted at the root
	if (IsEmpty()) {
		// Create a node at the root
		rootNode = new Node<int>(value);
		#ifndef NDEBUG
		std::cout << "TREE DEBUG: A new node was created at the root. The new node at the root has been assigned value [" << rootNode->GetData() << "]. Insertion complete." << std::endl;
		#endif
		return;
	}

	else {
		// Set the tree navigator / iterator pointer to the root
		currentNode = rootNode;
		// Create a temporary pointer to store the parent of the current node so its relative position can be used beyond when it becomes a null pointer
		Node<int>* temp = currentNode;

		#ifndef NDEBUG
		std::cout << "TREE DEBUG: The node insertion iterator has begun at the root." << std::endl;
		#endif

		int debugCounter = 0;

		// While the iterator node has not yet found an empty node...
		while (currentNode != nullptr) {
			// ... If the value to be inserted is less than the value in the current node...
			if (value < currentNode->GetData()) {
				#ifndef NDEBUG
				std::cout << "TREE DEBUG: The insertion value (" << value << ") was less than the value in the node (" << currentNode->GetData() << ")." << std::endl;
				#endif
				// Set the temp node to the node currently being examined before navigating away
				temp = currentNode;
				// Set the current node to the left child and continue.
				currentNode = currentNode->GetLeft();

				#ifndef NDEBUG
				std::cout << "TREE DEBUG:\tThe node insertion iterator has moved to the left." << std::endl;
				#endif

				debugCounter++;
			}

			// ... If the value to be inserted is greater than the current node...
			else if (value > currentNode->GetData()) {
				#ifndef NDEBUG
				std::cout << "TREE DEBUG: The insertion value (" << value << ") was greater than the value in the node (" << currentNode->GetData() << ")." << std::endl;
				#endif

				// Set the temp node to the node currently being examined before navigating away
				temp = currentNode;
				// Set the current node to the right child and continue.
				currentNode = currentNode->GetRight();

				#ifndef NDEBUG
				std::cout << "TREE DEBUG:\tThe node insertion iterator has moved to the right." << std::endl;
				#endif

				debugCounter++;
			}

			// ... If the value to be inserted is the same as the value in the current node...
			else if (value = currentNode->GetData()) {
				#ifndef NDEBUG
				std::cout << "TREE DEBUG: The insertion value (" << value << ") was identical to the value in the node (" << currentNode->GetData() << "), so the insert has been disregarded." << std::endl;
				#endif

				// The value is already in the tree, so exit.
				return;
			}
		}

		#ifndef NDEBUG
		std::cout << "TREE DEBUG: The current node has become a null pointer at level " << debugCounter << "." << std::endl;
		#endif

		// If value to be inserted is less than parent data...
		if (value < temp->GetData()) {
			// Create a new node there with the passed-in value...
			currentNode = new Node<int>(value);
			
			// Place the current node in the parent's left node pointer
			temp->SetLeft(currentNode);

			#ifndef NDEBUG
			std::cout << "TREE DEBUG: Value (" << value << ") has been inserted in the 'left' node of (" << temp->GetData() << ") on level [" << debugCounter << "]. Insertion complete." << std::endl;
			#endif

			currentNode->SetParent(temp);
			return;
		}

		else {
			// Create a new node there with the passed-in value...
			currentNode = new Node<int>(value);
			
			// Place the current node in the parent's right node pointer
			temp->SetRight(currentNode);

			#ifndef NDEBUG
			std::cout << "TREE DEBUG: Value (" << value << ") has been inserted in the 'right' node of (" << temp->GetData() << ") on level [" << debugCounter << "]. Insertion complete." << std::endl;
			#endif

			currentNode->SetParent(temp);
			return;
		}

		delete temp;
		temp = nullptr;
	}	
};

// A function for removing a node based upon its value 
void BinaryTree::Remove(int value) {
	#ifndef NDEBUG
	std::cout << "\nTREE DEBUG: A node removal request has been made for (" << value << ")." << std::endl;
	#endif

	// If the binary tree is empty, then do nothing.
	if (IsEmpty()) {
		#ifndef NDEBUG
		std::cout << "TREE DEBUG: The binary tree was empty - there is nothing to remove. Removal process complete." << std::endl;
		#endif

		return;
	}

	// Else if the binary tree is not empty...
	else {
		// Step 1: Find whether the value exists in the tree
		#ifndef NDEBUG
		std::cout << "TREE DEBUG: The binary tree was not empty - Removal process starting with a node lookup." << std::endl;
		#endif

		// Create some temporary pointers for use in node traversal and removal
		Node<int>* nodePtr = currentNode;
		Node<int>* nodePtrParent = currentNode;
				
		// Run the 'find' function and if the value is found, store the node where it was found and also that node's parent in two pointers
		if (FindNode(value, nodePtr, nodePtrParent)) {
			// If the current node (the one where the value was found) has a right branch, then...
			if (nodePtr->GetRight() != nullptr) {
				// Find the minimum value in the right branch by iterating down the left branch of the current node’s right child until there are no more left branch nodes. So...
				// i: Navigate right once.
				currentNode = nodePtr->GetRight();

				#ifndef NDEBUG
				std::cout << "TREE DEBUG: Now searching for the smallest number which is greater than " << value << ". Navigated right (" << currentNode->GetData() << ")." << std::endl;
				#endif

				// ii: Navigate left until the final node is reached.
				while (currentNode != nullptr) {
					// If the left child is not empty then keep moving left
					if (currentNode->GetLeft() != nullptr) {
						currentNode = currentNode->GetLeft();

						#ifndef NDEBUG
						std::cout << "TREE DEBUG: Smallest number not yet found. Navigated left (" << currentNode->GetData() << ")." << std::endl;
						#endif
					}

					// ... But if the left child IS a null pointer then we've reached the end; stop.
					else {
						// iii: Copy the value of this left-most node into the node to be deleted
						nodePtr->SetData(currentNode->GetData());

						#ifndef NDEBUG
						std::cout << "TREE DEBUG: Smallest number larger than (" << value << ") found: (" << currentNode->GetData() << "). Stopped navigation. Smallest number larger than (" << value << ") copied (" << nodePtr->GetData() << ")." << std::endl;
						#endif

						// exit the while loop
						break;
					}
				}

				#ifndef NDEBUG
				std::cout << "TREE DEBUG: ""Current"" node is (" << currentNode->GetData() << "), ""nodePtr"" is (" << nodePtr->GetData() << "), parent of ""Current"" node is " << currentNode->GetParent()->GetData() << "." << std::endl;
				#endif

				// find the minimum node’s parent node (the parent of the node being deleted) and
				// a) if you are deleting the parent’s left node
				if (currentNode = currentNode->GetParent()->GetLeft()) {
					//set this left child of the parent to the right child of the minimum node
					currentNode->GetParent()->SetLeft(currentNode->GetRight());

					#ifndef NDEBUG
					std::cout << "TREE DEBUG: The left child of (" << currentNode->GetParent()->GetData() << "), (" << currentNode->GetData() << ") will now be deleted." << std::endl;
					#endif

					delete currentNode;
					currentNode = nullptr;
					return;
				}

				// b) if you are deleting the parent’s right node
				else if (currentNode = currentNode->GetParent()->GetRight()) {
					// set the right child of the parent to the minimum node’s right child
					currentNode->GetParent()->SetRight(currentNode->GetRight());

					#ifndef NDEBUG
					std::cout << "TREE DEBUG: The right child of (" << currentNode->GetParent()->GetData() << "), (" << currentNode->GetData() << ") will now be deleted." << std::endl;
					#endif

					delete currentNode;
					currentNode = nullptr;
					return;
				}
			}

			//If the current node has no right branch
			else if (nodePtr->GetRight() == nullptr) {
				// a) if we are deleting the parent’s left child, set the left child of the parent to the left child of the current node
				if (nodePtr == nodePtrParent->GetLeft()) {
					#ifndef NDEBUG
					std::cout << "TREE DEBUG: The left child of (" << nodePtrParent->GetData() << "), (" << nodePtr->GetData() << ") will now be deleted." << std::endl;
					#endif

					nodePtrParent->SetLeft(nodePtr->GetLeft());

					delete nodePtr;
					nodePtr = nullptr;

					return;
				}

				// b) If we are deleting the parent’s right child, set the right child of the parent to the left child of the current node
				if (nodePtr == nodePtrParent->GetRight()) {
					#ifndef NDEBUG
					std::cout << "TREE DEBUG: The right child of (" << nodePtrParent->GetData() << "), (" << nodePtr->GetData() << ") will now be deleted." << std::endl;
					#endif

					nodePtrParent->SetRight(nodePtr->GetLeft());

					delete nodePtr;
					nodePtr = nullptr;

					return;
				}

				// c) If we are deleting the root, the root becomes the left child of the current node
				if (nodePtr == rootNode) {
					#ifndef NDEBUG
					std::cout << "TREE DEBUG: The root (" << rootNode->GetData() << ") will now be deleted." << std::endl;
					#endif

					nodePtr->SetLeft(rootNode);

					delete nodePtr;
					nodePtr = nullptr;

					return;
				}
			}
		}

		else {
			// The value IS NOT in the tree
#ifndef NDEBUG
			std::cout << "TREE DEBUG: The value to be deleted (" << value << ") was not in the binary tree. Removal process complete." << std::endl;
#endif

			return;
		}
	};
}

void BinaryTree::PrintPreOrdered(Node<int>* node) {
	if (node == nullptr) {
		//std::cout << "." << std::endl;

		return;
	}

	else {
		std::cout << "[" << node->GetData() << "] ";
		PrintPreOrdered(node->GetLeft());
		PrintPreOrdered(node->GetRight());
	}
};

void BinaryTree::PrintOrdered(Node<int>* node) {
	if (node == nullptr) {
		//std::cout << "." << std::endl;

		return;
	}

	else {
		PrintOrdered(node->GetLeft());
		std::cout << "[" << node->GetData() << "] ";
		PrintOrdered(node->GetRight());
	}
};

void BinaryTree::PrintPostOrdered(Node<int>* node) {
	if (node == nullptr) {
		//std::cout << "." << std::endl;

		return;
	}

	else {
		PrintPostOrdered(node->GetLeft());
		PrintPostOrdered(node->GetRight());
		std::cout << "[" << node->GetData() << "] ";
	}
}

void BinaryTree::PrintReverseOrdered(Node<int>* node) {
	if (node == nullptr) {
		//std::cout << "." << std::endl;

		return;
	}

	else {
		PrintReverseOrdered(node->GetRight());
		std::cout << "[" << node->GetData() << "] ";
		PrintReverseOrdered(node->GetLeft());
	}
}

void BinaryTree::Clear(Node<int>* node) {
	if (node == nullptr) {
		//std::cout << "." << std::endl;

		return;
	}

	else {
		Clear(node->GetLeft());
		Clear(node->GetRight());
		delete node;
		node = nullptr;
	}
}

 Node<int>* BinaryTree::GetRoot() {
	return rootNode;
};