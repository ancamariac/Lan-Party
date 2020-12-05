#include <iostream>
#include <iomanip>
#include "AVL.h"
#include "BST.h"
#include <fstream>
#include "Team.h"
#include "utils.h"
#include <string>
#include <cstring>
#include <vector>

using namespace std;

AVL::AVL() {
   root = NULL;
}

AVL::~AVL() {
   clearTree(root);
}


void AVL::clearTree(AVLTreeNode *node) {
    if ( node != NULL ) {
        clearTree(node->left);   
        clearTree(node->right);   
        delete node;         
    }
}

int AVL::height(AVLTreeNode* N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

AVLTreeNode *createNewNode(Team team) {
	AVLTreeNode* node = new AVLTreeNode();
	node->team = team;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return(node);
} 

AVLTreeNode* AVL::rightRotate(AVLTreeNode* y)
{
	AVLTreeNode* x = y->left;
	AVLTreeNode* T2 = x->right;

	// Perform rotation  
	x->right = y;
	y->left = T2;

	// Update heights  
	y->height = max(height(y->left),
		height(y->right)) + 1;
	x->height = max(height(x->left),
		height(x->right)) + 1;

	// Return new root  
	return x;
}

AVLTreeNode* AVL::leftRotate(AVLTreeNode*x)
{  
	AVLTreeNode*y = x->right;
	AVLTreeNode*T2 = y->left;
  
    // Perform rotation  
    y->left = x;  
    x->right = T2;  
  
    // Update heights  
    x->height = max(height(x->left),     
                    height(x->right)) + 1;  
    y->height = max(height(y->left),  
                    height(y->right)) + 1;  
  
    // Return new root  
    return y;  
}

int AVL::getBalance(AVLTreeNode* N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

AVLTreeNode* AVL::insert(AVLTreeNode* node, Team team)
{
	/* 1. Perform the normal BST insertion */
	if (node == NULL) {
		return(createNewNode(team));
	}

	if (team.get_global_score() < node->team.get_global_score()) {
		node->left = insert(node->left, team);
	}
	else if (team.get_global_score() > node->team.get_global_score()) {
		node->right = insert(node->right, team);
	}
	else if (team.get_global_score() == node->team.get_global_score()) {
		if (caseInsensitive(team.getName(), node->team.getName()) > 0) {
			node->right = insert(node->right, team);
		}
		else {
			node->left = insert(node->left, team);
		}
	}

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left),
		height(node->right));

	/* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
	int balance = getBalance(node);

	// If this node becomes unbalanced, then  
	// there are 4 cases  

	// Left Left Case  
	if (balance > 1 && team.get_global_score() <= node->left->team.get_global_score())
		return rightRotate(node);

	// Right Right Case  
	if (balance < -1 && team.get_global_score() >= node->right->team.get_global_score())
		return leftRotate(node);

	// Left Right Case  
	if (balance > 1 && team.get_global_score() >= node->left->team.get_global_score())
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case  
	if (balance < -1 && team.get_global_score() <= node->right->team.get_global_score())
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}

void AVL::insert(Team team) {
	root = insert(root, team);
}

void AVL::printAVL(ofstream  &rezultate) {
	Team team;
	rezultate << "THE LEVEL 2 TEAMS ARE:" << endl;
	if (root->right->right) {
		team = root->right->right->team;
		rezultate << team.getName() << endl;
	}
	if (root->right->left) {
		team = root->right->left->team;
		rezultate << team.getName() << endl;
	}
	if (root->left->right) {
		team = root->left->right->team;
		rezultate << team.getName() << endl;
	}
	if (root->left->left) {
		team = root->left->left->team;
		rezultate << team.getName() << endl;
	}
	
}

