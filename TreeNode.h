/*************************************************
* ADS Praktikum 2.2
* TreeNode.h
* Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
*************************************************/
#pragma once
#include <string>

using namespace std;

class TreeNode {

private:
	///////////////////////////////////////
	// Ihr Code hier:	
	int NodePosID;
	int NodeID;
	string Name;
	int Alter;
	double Einkommen;
	int PLZ;
	TreeNode* left;
	TreeNode* right;
	//
	////////////////////////////////////

public:
	///////////////////////////////////////
	// Ihr Code hier:
	TreeNode(int NodePosID, int NodeID, string Name, int Alter, double Einkommen, int PLZ);
	int getNodePosID(void);
	//void setNodePosID(int NodePosID);
	int getNodeID(void);
	string getName(void);
	void setName(string name);
	int getAlter(void);
	void setAlter(int alter);
	double getEinkommen(void);
	void setEinkommen(double einkommen);
	int getPLZ(void);
	void setPLZ(int plz);

	TreeNode* getLeft(void) { return left; }
	TreeNode* getRight(void) { return right; }
	void setLeft(TreeNode* Left);
	void setRight(TreeNode* Right);
	void print();


	//
	////////////////////////////////////
};
