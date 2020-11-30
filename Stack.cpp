#include <iostream>
#include <fstream>
#include <string>
#include "Stack.h"
#include "Queue.h"
#include "Team.h"
#include <assert.h>
#include <string>
#include <cstring>

using namespace std;

Stack::Stack() {
    top = NULL;
}

void Stack::push(Team echipa) {
    struct stackNode *newNode = new stackNode;

    newNode->res_echipa = echipa;
    newNode->next = top;

    top = newNode;
}

Team Stack::pop() {

    /*if ( top == NULL ) {
        return;
    }*/

    struct stackNode *newNode = new stackNode;
    newNode = top;
    top = top->next;

    return newNode->res_echipa; 
}

void Stack::display(char *argv[]) {
    ofstream rezultate(argv[3]);

    string s = "                                  -  ";
    int size = s.length();
    string nume;

    if ( top == NULL ) {
        return;
    }

    struct stackNode *temp = top;

    while ( temp != NULL ) {
        s = "                                  -  ";
        nume = temp->res_echipa.getName();
        s.replace(0, nume.length(), nume);
        rezultate << s << temp->res_echipa.initialScore() << "\n";
        temp = temp->next;
    }

    rezultate.close();
}

int Stack::isEmpty() {
    return (top == NULL); 
}