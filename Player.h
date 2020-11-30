#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <fstream>


// data de cerinta:
class Player {
protected:
    std::string firstName;
    std::string secondName;
    int points;
public:

	Player();
	Player(std::string _firstName, std::string _secondName, int _points);

	std::string getFirstName();
	std::string getSecondName();	
	int getPoints();
};


#endif 