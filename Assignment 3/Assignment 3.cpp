// Assignment 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "memory.h"
#include "BinaryTree.h"

using namespace std;

int main()
{
    BinaryTree* tree = new BinaryTree;

    tree->Insert(5);
    tree->Insert(11);
    tree->Insert(1);
    tree->Insert(7);
    tree->Insert(20);
    tree->Insert(75);
    tree->Insert(100);
    tree->Insert(150);
    tree->Insert(15);
    tree->Insert(1500);
    tree->Insert(4);
    tree->Insert(3);
    tree->Insert(6);
    tree->Insert(9);
    tree->Insert(8);
    tree->Insert(10);

    tree->Remove(7);
    tree->Remove(7);

    tree->Insert(8);

    tree->Remove(3);

    std::cout << "\nPre-ordered tree: "; tree->PrintPreOrdered(tree->GetRoot());
    std::cout << "\nOrdered tree: ";  tree->PrintOrdered(tree->GetRoot());
    std::cout << "\nPost-Ordered tree: ";  tree->PrintPostOrdered(tree->GetRoot());
    std::cout << "\nReverse-Ordered tree: ";  tree->PrintReverseOrdered(tree->GetRoot());

    delete tree;
    tree = nullptr;
}