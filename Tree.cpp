/*************************************************
* ADS Praktikum 2.2
* Tree.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "Tree.h"
#include "TreeNode.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

////////////////////////////////////
// Ihr Code hier:
	Tree::Tree()
	{
		anker = nullptr;
		NodeIDCounter = 0;
	}

	void Tree::addNode(string Name, int Alter, double Einkommen, int PLZ) 
	{
		int NodePosID = Alter + PLZ + Einkommen;
		TreeNode* neuer_eintrag = new TreeNode(NodePosID, NodeIDCounter, Name, Alter, Einkommen, PLZ);
		NodeIDCounter++;
		if (anker == nullptr) // intialisierung
		{
			anker = neuer_eintrag;
		}
		else if (anker != nullptr) // erwachsend
		{
			TreeNode* tmp_anker = anker;
			TreeNode* tmp_anker_parent = anker;
			while (tmp_anker != nullptr)
			{
				if (tmp_anker->getNodePosID() < NodePosID)
				{
					tmp_anker_parent = tmp_anker;
					tmp_anker = tmp_anker->getRight();
				}
				else
				{
					tmp_anker_parent = tmp_anker;
					tmp_anker = tmp_anker->getLeft();
				}
			}
			if (neuer_eintrag->getNodePosID() >= tmp_anker_parent->getNodePosID())
			{
				tmp_anker_parent->setRight(neuer_eintrag);
			}
			else
			{
				tmp_anker_parent->setLeft(neuer_eintrag);
			}
	
		}

	}

	/*void Tree::deleteNode(int NodePosID)
	{
		TreeNode * node = anker;
		TreeNode * parent = anker;
		// node is -1 = root, 0 = left child, 1 = right child
		int direction = -1;
		// search for node, its parent and the direction
		while (node != nullptr && node->getNodePosID() != NodePosID) {
			parent = node;
			if (NodePosID < node->getNodePosID()) {
				node = node->getLeft();
				direction = 0;
			}
			else {
				node = node->getRight();
				direction = 1;
			}
		}
		// node not found?
		if (node == nullptr)
			return;
		if (node->getLeft() == nullptr && node->getRight() == nullptr) {
			// node is leaf
			if (direction == -1) {
				anker = nullptr;
			}
			else if (direction == 0) {
				parent->setLeft(nullptr);
			}
			else {
				parent->setRight(nullptr);
			}
		}
		else if (node->getLeft() == nullptr) {
			// node has no left child
			if (direction == -1) {
				anker = node->getRight();
			}
			else if (direction == 0) {
				parent->setLeft(node->getRight());
			}
			else {
				parent->setRight(node->getRight());
			}
		}
		else if (node->getRight() == nullptr) {
			// node has no right child
			if (direction == -1) {
				anker = node->getLeft();
			}
			else if (direction == 0) {
				parent->setLeft(node->getLeft());
			}
			else {
				parent->setRight(node->getLeft());
			}
		}
		else {
			// node has two children
			// search for minimum in right subtree
			TreeNode * s = node->getRight();
			TreeNode * s_parent = node;
			while (s->getLeft() != nullptr) {
				s_parent = s;
				s = s->getLeft();
			}
			if (s == node->getRight()) {
				s_parent->setRight(s->getRight());
			}
			else {
				s_parent->setLeft(s->getRight());
			}
			s->setLeft(node->getLeft());
			s->setRight(node->getRight());
			if (direction == -1) {
				anker = s;
			}
			else if (direction == 0) {
				parent->setLeft(s);
			}
			else {
				parent->setRight(s);
			}
		}
	}
	*/

	/*bool Tree::searchNode_NodePosID(int nodeposid)
	{
		TreeNode* ptr = anker;
		if (Preorder_NodePosID(ptr, nodeposid))
		{
			return true;
		}
		else
		{
			return false;
		}
	}*/

	bool Tree::searchNode(string Name)
	{ 
		TreeNode* ptr = anker;
		if (Preorder(ptr, Name))
		{
			cout << "Fundstellen:\nNodeID : " << ptr->getNodeID()
				<< ", Name : " << ptr->getName() << ", Alter : " << ptr->getAlter()
				<< ", Einkommen : " << ptr->getEinkommen() << ", PLZ : " << ptr->getPLZ()
				<< ", PosID : " << ptr->getNodePosID();
			return true;
		}
		else
		{
			cout << "Datensatz konnte nicht gefunden werden." << endl << endl;
			return false;
		}
	}

	bool Tree::Preorder(TreeNode* node, string Name)
	{
		if (node == nullptr)
		{
			return false;
		}
		else if (Name.compare(node->getName()) == 0)
		{
			return true;
		}
		return Preorder(node->getLeft(), Name)||
		Preorder(node->getRight(), Name);
	}

	void Tree::Preorder_ausgeben(TreeNode* node)
	{

		if (node != nullptr)
		{
			if (node->getNodeID() != NodeIDCounter)
			{
				cout << node->getNodeID() << " | " << node->getName() << " | " << node->getAlter() << " | " << node->getEinkommen() << " | " << node->getPLZ() << " | " << node->getNodePosID() << "\n";
			}
			Preorder_ausgeben(node->getLeft());
			Preorder_ausgeben(node->getRight());
		};
	}
	
	void Tree::printAll(void)
	{
		TreeNode* ptr = anker;
			cout << "ID | Name | Alter | Einkommen | PLZ | Pos\n";
			cout << "---+------------+-------+-----------+-------+-------\n";
			Preorder_ausgeben(ptr);

	}
//
////////////////////////////////////