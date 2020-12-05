#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "Player.h"
#include "ListOfTeams.h"
#include "Team.h"
#include "Queue.h"
#include "Stack.h"
#include "utils.h"
#include "BST.h"
#include "AVL.h"

using namespace std;

int main(int argc, char *argv[]) {

	ifstream cerinte(argv[1]), data(argv[2]);
	ofstream rez(argv[3]);

	int nr_echipe = 0, nr_jucatori = 0, nr_deletes = 0, nr_echipe_ramase = 0, puncte = 0;
	string name_team, primul_nume, al_doilea_nume;
	char empty;
	Team echipa;

	// creare lista de echipa
	ListOfTeams echipe = ListOfTeams();
	// citire din fisier a numarului de echipe
	data >> nr_echipe;

	Player*** jucatori = new Player * *[nr_echipe];

	for (int i = 0; i < nr_echipe; i++) { // se parcurge fiecare echipa 
		data >> nr_jucatori; // citire nr de jucatori pt fiecare echipa
		// alocare numar de jucatori pentru vectorul jucatori
		jucatori[i] = new Player * [nr_jucatori];
		empty = data.get();
		getline(data, name_team); // se citeste numele fiecarei echipe 
		for (int j = 0; j < nr_jucatori; j++) { // se parcurge fiecare jucator
			// realizare echipa de jucatori
			data >> primul_nume;
			data >> al_doilea_nume;
			data >> puncte;
			jucatori[i][j] = new Player(primul_nume, al_doilea_nume, puncte);
		}
		if (name_team[name_team.length() - 1] == ' ') {
			
			name_team = name_team.substr(0, name_team.size() - 1);
		}
		// adaugare in lista de echipe a fiecarei echipe formate cu ajutorul constr. cu param
		echipa = Team(name_team, nr_jucatori, 0, jucatori[i]);
		echipe.addTeam(echipa);
	}
	int task = 0, sum = 0;

	for (int i = 0; i < 5; i++) {
		cerinte >> task;
		sum += task;
	}
	Stack winners, loosers, winnerStack4;
	Team echipa1, echipa2, pop_team;
	string spaces = "                                 -                                 ";
	string nume1, nume2;
	int size_ = spaces.length(), count = 0;

	if ( sum == 1 ) {
		echipe.printTeamNames(rez);
	}
	
	if ( sum >= 2 ) {
		nr_deletes = nr_echipe - closestPow2(nr_echipe);
		for (int i = 0; i < nr_deletes; i++) {
			echipe.removeNodes(); //eliminarea echipelor
		}
		echipe.printTeamNames(rez);
	}

	if ( sum >= 3 ) {
		int numRounds = intlog(2, closestPow2(nr_echipe));
		nr_echipe_ramase = nr_echipe - nr_deletes;
		// se creaza coada de meciuri
		Queue* teamsQueue = createQueue(nr_echipe_ramase);
		teamsQueue = echipe.TeamsQueue(teamsQueue);
		// se incep duelurile:
		for (int i = 0; i < numRounds; i++) {
			rez << "\n--- ROUND NO:" << i + 1 << "\n";
			winners = Stack();
			loosers = Stack();
			while (!isEmpty(teamsQueue)) {
				spaces = "                                 -                                 ";
				echipa1 = deQueue(teamsQueue);
				echipa2 = deQueue(teamsQueue);
				nume1 = echipa1.getName();
				nume2 = echipa2.getName();
				spaces.replace(0, nume1.length(), nume1);
				spaces.replace(size_ - nume2.length(), nume2.length(), nume2);
				rez << spaces;
				rez << "\n";

				if (echipa1.initialScore() > echipa2.initialScore()) {
					echipa1.set_global_score();
					winners.push(echipa1);
					loosers.push(echipa2);
				}
				else {
					echipa2.set_global_score();
					winners.push(echipa2);
					loosers.push(echipa1);
				}
			}

			rez << "\n"; rez << "WINNERS OF ROUND NO:" << i + 1 << "\n";
			winners.display(rez);

			// se sterge stiva loosers 
			while (!loosers.isEmpty()) {
				loosers.pop();
				count++;
			}

			if ( count == 8 ) {
				// se face o copie pt winnerStack
				winnerStack4 = winners;
			}
			count = 0;

			// se pune stiva de castigatori iar in coada
			while ( !winners.isEmpty() ) {
				pop_team = winners.pop();
				enQueue(teamsQueue, pop_team);
			}
		}
	}

	BST root = BST();

	if ( sum >= 4 ) {
		while ( !winnerStack4.isEmpty() ) {
			pop_team = winnerStack4.pop();
			root.insert(pop_team);
		}
		root.printTeams(rez);
	}

	AVL* avl = new AVL();

	if ( sum == 5 ) {
		rez << "\n";
		root.createAVL(avl);
		avl->printAVL(rez);
	}
	

	for (int i = 0; i < nr_echipe; i++) {
		for (int j = 0; j < nr_jucatori; j++) {
			delete jucatori[i][j];
		}
		delete[] jucatori[i];
	}
	delete[] jucatori;

	data.close();
	cerinte.close();
	return 0;
}