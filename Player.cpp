#include <iostream>
#include <fstream>
#include <string>
#include "Player.h"

// METODE


Player::Player() {
	this->firstName = "";
	this->secondName = "";
	this->points = 0;
}

Player::Player(std::string _firstName, std::string _secondName, int _points) {
	this->firstName = _firstName;
	this->secondName = _secondName;
	this->points = _points;
}

std::string Player::getFirstName() {
	return firstName;
}

std::string Player::getSecondName() {
	return secondName;
}

int Player::getPoints() {
	return this->points;
}
