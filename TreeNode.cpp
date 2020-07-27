/*************************************************
* ADS Praktikum 2.2
* TreeNode.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "TreeNode.h"
#include <iostream>
#include <string>
using namespace std;


////////////////////////////////////
// Ihr Code hier:
	TreeNode::TreeNode(int NodePosID, int NodeID, string Name, int Alter, double Einkommen, int PLZ)
	{
		this->NodePosID = NodePosID;
		this->NodeID = NodeID;
		this->Name = Name;
		this->Alter = Alter;
		this->Einkommen = Einkommen;
		this->PLZ = PLZ;
		left = nullptr;
		right = nullptr;
	}
	int TreeNode::getNodePosID(void) { return NodePosID; }
	int TreeNode::getNodeID(void) { return NodeID; }
	//void TreeNode::setNodePosID(int NodePosID) { this->getNodePosID = NodePosID; }
	string TreeNode::getName(void) { return Name; }
	void TreeNode::setName(string name) { Name = name; }
	int TreeNode::getAlter(void) { return Alter; }
	void TreeNode::setAlter(int alter) { Alter = alter; }
	double TreeNode::getEinkommen(void) { return Einkommen; }
	void TreeNode::setEinkommen(double einkommen) { Einkommen = einkommen; }
	int TreeNode::getPLZ(void) { return PLZ; }
	void TreeNode::setPLZ(int plz) { PLZ = plz; }

	void TreeNode::setLeft(TreeNode* Left)
	{
		this->left = Left;
	}
	void TreeNode::setRight(TreeNode* Right)
	{
		this->right = Right;
	}
	void TreeNode::print(){}
//
////////////////////////////////////
