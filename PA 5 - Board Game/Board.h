#pragma once

#include "Player.h"

class Board
{
public:
	explicit Board(int m) :sizeM(m), PlayersN(0) {};

	// i) n< m, ii) x and y in bounds, iii) unique id check 
	bool Insert(int ID, int x, int y);

	// returns false if player not found else deletes the player from both maps
	bool Remove(int ID);

	// returns true if player was found
	bool Find(int ID);

	// i) in bound check, ii) if a player is present at that spot remove that player, 
	// iii) if a player is removed display which player was removed
	// iv) if moveTo fails state the reason why
	bool MoveTo(int ID, int x2, int y2);

	// inorder traversal(ID) of red and black tree
	void PrintByID();

private:
	int sizeM;
	int PlayersN;
	//map<ID, Pos(x,y)>
	map<int, pair<int, int>> Pos;
	//map<Pos(x,y), ID>
	map<pair<int, int>, int> UniqueID;
};