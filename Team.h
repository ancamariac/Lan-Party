#ifndef TEAM_H
#define TEAM_H
#include <iostream>
#include <string>
#include <fstream>
#include "Player.h"

class Team {
protected:
	std::string name;
	int nr_players;
	float global_score;
	Player** players;
public:
	Team();
	Team(std::string name, int nr_players, int global_score, Player** players);

	std::string getName();
	int get_nr_players();
	float get_global_score();
	void set_global_score();
	Player* get_players(int i);
	Player** get_all_players();
	float initialScore();
};


#endif