#include <iostream>
#include <iomanip>
#include "BST.h"
#include <fstream>
#include "Team.h"
#include "AVL.h"
#include "utils.h"
#include <string>
#include <cstring>

using namespace std;

BST::BST() {
	root = NULL;
}

void BST::insert(Node* nod, Team team) {
	if ( !nod ) {
		nod = new Node(team);
		root = nod;
    } else {
		if ( team.get_global_score() < nod->team.get_global_score() ) {
			if ( !nod->left ) {
				Node* treeTemp = new Node(team);
				nod->left = treeTemp;
			} else {
				insert(nod->left, team);
            }
		} else if ( team.get_global_score() > nod->team.get_global_score() ) {
			if ( !nod->right ) {
				Node* treeTemp = new Node(team);
				nod->right = treeTemp;
			} else {
				insert(nod->right, team);
            }
            // daca au scoruri egale:
		} else if ( team.get_global_score() == nod->team.get_global_score() ) {
            if ( caseInsensitive(team.getName(), nod->team.getName()) > 0 ) {
                if ( !nod->right ) {
				    Node* treeTemp = new Node(team);
				    nod->right = treeTemp;
			    } else 
				    insert(nod->right, team);
            } else {
                if ( !nod->left ) {
                    Node* treeTemp = new Node(team);
                    nod->left = treeTemp;
                } else {
                    insert(nod->left, team);
                }
            }
        }
	}
}

void BST::deleteBST(Node* nod) {
	if ( !nod ) {
		return;
    }

	Node* curNod = nod;
	Node* leftNod = nod->left;
	Node* rightNod = nod->right;
	delete(curNod);
	deleteBST(leftNod);
	deleteBST(rightNod);
}

BST::~BST() {
	deleteBST(root);
}


void BST::printTeams(Node* nod, ofstream  &rezultate) {
	if ( !nod ) {
		return;
    }
	printTeams(nod->right, rezultate);

	string lines = "                                  -  ";
	string nume = nod->team.getName();
	lines.replace(0, nume.length(), nume);
	rezultate << lines << fixed << setprecision(2) << nod->team.get_global_score() << "\n";
	// inserare nod in avl
	printTeams(nod->left, rezultate);

}

void BST::insert(Team team) {
	insert(root, team);
}

void BST::printTeams(ofstream  &rezultate) {
	rezultate << "\nTOP 8 TEAMS:\n";
	printTeams(root, rezultate);
}

void BST::createAVL(AVL* avl) {
	createAVL(root, avl);
}

void BST::createAVL(Node *nod, AVL* avl) {
	if (nod == NULL) return;
	createAVL(nod->right, avl);
	avl->insert(nod->team);
	createAVL(nod->left, avl);

}