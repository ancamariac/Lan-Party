#include <iostream>
#include <fstream>
#include <string>
#include "Team.h"

Team::Team() {
	this->name = "";
	this->nr_players = 0;
	this->global_score = 0;	
}

Team::Team(std::string name, int nr_players, float global_score, Player **players) {
	this->name = name;
	this->nr_players = nr_players;
	this->global_score = global_score;
	this->players = players;
}

std::string Team::getName() {
	return name;
}

int Team::get_nr_players() {
	return nr_players;
}

void Team::set_global_score() {
	this->global_score += 1;
}

float Team::get_global_score() {
	return global_score;
}

Player* Team::get_players(int i) {
	return players[i];
}

Player** Team::get_all_players() {
	return players;
}

// media aritmetică a punctelor jucatorilor
float Team::initialScore() {

    float sum = 0;
    float medie = 0;
    //assert (head->next == NULL);
    
    for ( int i = 0; i < nr_players; i++ ) {
        sum = sum + get_players(i)->getPoints();
    }

	sum += this->global_score; // pentru a se actualiza scorul de echipa dupa castig

    medie = sum/(nr_players);

    return medie;
}