#include <iostream>
#include <fstream>
#include <string>
#include "ListOfTeams.h"
#include "Team.h"
#include "Queue.h"
#include <assert.h>
#include <iomanip>

using namespace std;

ListOfTeams::ListOfTeams() {

	head = NULL;
	tail = NULL;
}

ListOfTeams::~ListOfTeams() {
	
	node *current = head;

    while ( current ) {
        node* next = current->next;
        delete current;
        current = next;
    }

}

// adaugare nod la inceputul listei
void ListOfTeams::addTeam(Team team) {

    // doubly linked list
    node *newnode = new node;
    newnode->team = team;
    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL) {
        head->prev =newnode;
    }
    head = newnode;
}

void ListOfTeams::printTeamNames(char *argv[]) {

	ofstream rezultate(argv[3]);
	// doubly
	node* ptr;
   	ptr = head;
   	while(ptr != NULL) {
      	rezultate << ptr->team.getName() << "\n";// <<"   "<< fixed << setprecision(2) << ptr->team.initialScore()<<"\n";
      	ptr = ptr->next;
   	}
   	rezultate.close();
}

void ListOfTeams::printReverseTeamNames(char *argv[]) {
    
    ofstream rezultate(argv[3]);

    tail = head; 

    while (tail->next != NULL) { 
        tail = tail->next; 
    } 
  
    while (tail != head) { 
        rezultate << tail->team.getName() << "\n"; 
        tail = tail->prev; 
    } 
    rezultate << tail->team.getName() << "\n"; 
    rezultate.close();
} 

// eliminare echipa din lista
void ListOfTeams::removeTeam(string name) {

	if (head->team.getName() == name) {
		node* head_tmp = head;
		head = head->next;
		head->prev = NULL;
		delete head_tmp;
		return;
	}

	node* aux = head->next;

    while ( aux != NULL ) {
		//if (aux == NULL) break;
		if (aux->team.getName() == name) {
			if (aux->prev != NULL) {
				aux->prev->next = aux->next;
			}
			if (aux->next != NULL) {
				aux->next->prev = aux->prev;
			}

			delete aux;
            break;
        }
		aux = aux->next;
    }
}

// eliminare nod 
void ListOfTeams::removeNodes() {
    node *aux = head->next;
    string temp;
    temp = head->team.getName();
    float min = (float)head->team.initialScore();

    while(aux != NULL) {

        if ((float)(aux->team.initialScore()) < min) {
            min = (float)aux->team.initialScore();
            temp = aux->team.getName();
        }
        aux = aux->next;
    }
    if (!temp.empty()) {
        removeTeam(temp); //eliminare nod dupa nume
    }
    free(aux);
}

Queue* ListOfTeams::TeamsQueue(Queue* queue) {
    node* ptr;
   	ptr = head;

   	while(ptr != NULL) {
      	enQueue(queue, ptr->team);
      	ptr = ptr->next;
   	}
    
    return queue;
}

