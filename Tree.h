#pragma once
/*************************************************
* ADS Praktikum 2.2
* Tree.h
* Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
*************************************************/
#pragma once
#include <string>
#include "TreeNode.h"
#include "catch.h"

using namespace std;

class Tree {

	private:
		///////////////////////////////////////
		// Ihr Code hier:	
		TreeNode* anker;
		int NodeIDCounter;
		//
		////////////////////////////////////	

	public:
		///////////////////////////////////////
		// Ihr Code hier:	
		Tree();
		void addNode(string Name, int Alter, double Einkommen, int PLZ);
		void deleteNode(int NodePosID);
		bool searchNode(string Name);
		void printAll(void);
		void Preorder_ausgeben(TreeNode* node);
		bool Preorder(TreeNode* node, string Name);
		TreeNode* searchNode_NodePosID(int nodeposid)
		{
			TreeNode* ptr = anker;
			if (Preorder_NodePosID(ptr, nodeposid))
			{
				return ptr;
			}
			else
			{
				return anker;
			}
		}
		bool Preorder_NodePosID(TreeNode* node, int NodePosID);

		/*TreeNode* suchen_nach_parent(int NodePosID)
		{
			TreeNode* tmp_anker = anker;
			TreeNode* tmp_anker_parent = anker;
			while (tmp_anker->getNodePosID() != NodePosID)
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
			if (NodePosID >= tmp_anker_parent->getNodePosID())
			{
				tmp_anker_parent = tmp_anker_parent->getRight();
			}
			else
			{
				tmp_anker_parent = tmp_anker_parent->getLeft();
			}
		}*/

		TreeNode* Max(TreeNode* root)
		{
			if (root == nullptr)
				return nullptr;
	
			while (root->getRight() != nullptr)
			{
				root = root->getRight();
			}
			return root;
		}

		TreeNode* Min(TreeNode* root)
		{
			if (root == nullptr)
				return nullptr;

			while (root->getLeft() != nullptr)
			{
				root = root->getLeft();
			}
			return root;
		}
		////////////////////////////////////
		// friend-Funktionen sind für die Tests erforderlich und müssen unangetastet bleiben! 
		friend TreeNode * get_anker(Tree& TN);
};
