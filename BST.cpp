#include <iostream>
#include <fstream>
#include <string>
#include "BST.h"
#include "Team.h"
#include "Queue.h"
#include <assert.h>
#include <iomanip>

using namespace std;

BST::BST(Team echipa) { 
    team = echipa; 
    left = right = NULL; 
} 

BST* BST::insert(BST* root, Team team) { 
    if ( !root ) { 
        // daca root e NULL se insereaza primul nod
        return new BST(team); 
    } 
  
    if (team.get_global_score() > root->team.get_global_score()) { 
        root->right = insert(root->right, team); 
    } else { 
        root->left = insert(root->left, team); 
    } 

    return root; 
} 

void BST::printBST(BST* root) { 
    if ( !root ) { 
        return; 
    } 
    printBST(root->right); 
    cout << root->team.get_global_score() << endl; 
    printBST(root->right); 
} 