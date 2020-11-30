#ifndef LISTOFTEAMS_H
#define LISTOFTEAMS_H
#include <string>
#include <iostream>
#include <fstream>
#include "Team.h"
#include "Queue.h"
using namespace std;

struct node {
	Team team;
	struct node* next;
	struct node* prev;
};

class ListOfTeams { 
	private:
		node* head, * tail;
	public:
		ListOfTeams();
		~ListOfTeams();

		void addTeam(Team team);
		void printTeamNames(char *argv[]);
		void printReverseTeamNames(char *argv[]);
		void removeTeam(string name);
		void removeNodes();
		Queue* TeamsQueue(Queue* queue); // metoda care pune echipele in coada
};

#endif

