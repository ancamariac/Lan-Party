#ifndef AVL_H
#define AVL_H
#include <iostream>
#include <fstream>
#include "Team.h"

using namespace std;


struct AVLTreeNode {
   Team team;
   AVLTreeNode *left;
   AVLTreeNode *right;
   int height;
};

class AVL {
	private:
		AVLTreeNode   *root;
		void clearTree(AVLTreeNode *node);

	public:
		AVL();            
		~AVL();           
		int height(AVLTreeNode* N);
		AVLTreeNode* rightRotate(AVLTreeNode* y);
		AVLTreeNode* leftRotate(AVLTreeNode* x);
		int getBalance(AVLTreeNode* N);
		AVLTreeNode* insert(AVLTreeNode* node, Team team);
		void insert(Team team);
		void printAVL(ofstream  &rezultate);
};

AVLTreeNode *createNewNode(Team team);

#endif 