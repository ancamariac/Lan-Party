#ifndef BST_H
#define BST_H
#include <iostream>
#include <fstream>
#include "Team.h"
#include "AVL.h"
using namespace std;

struct Node {
	Node(Team value) : team(value), left(NULL), right(NULL) {}
	Team team;
	Node* left;
	Node* right;
};

class BST {
private:
	Node* root;
	void insert(Node* nod, Team team);
	void deleteBST(Node* nod);
	void printTeams(Node* nod, ofstream  &rezultate);
	void createAVL(Node* nod, AVL* avl);

public:

	BST();
	~BST();

	void insert(Team team);
	void printTeams(ofstream  &rezultate);
	void createAVL(AVL* avl);
};

#endif 