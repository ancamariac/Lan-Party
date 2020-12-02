#ifndef BST_H
#define BST_H
#include <string>
#include <iostream>
#include <fstream>
#include "Team.h"
#include "Queue.h"

class BST {
    Team team; 
    BST *left, *right;

    public:
        BST(Team echipa);
        BST* insert(BST* root, Team team);
        void printBST(BST* root); 
};

#endif