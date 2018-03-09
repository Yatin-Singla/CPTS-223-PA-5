#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <string>
using std::cin;
using std::cout;
using std::pair;
using std::map;
using std::iterator;
using std::endl;
using std::make_pair;
using std::fstream;
using std::string;

//typedef struct position
//{
//	int x;
//	int y;
//} Position;

class Player
{
public:
	explicit Player(int ID, int x, int y) :ID(ID), PlayerPos(x,y){};
	/*{
		this->ID = ID;
		PlayerPos.first = x;
		PlayerPos.second = y;
	}*/

	int getID();
	pair<int, int> getPlayerPos();

private:
	int ID;
	//Position PlayerPos;
	pair<int, int> PlayerPos;
};