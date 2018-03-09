#pragma once

#include "Player.h"

class Board
{
public:
	explicit Board(int m) :sizeM(m), PlayersN(0) 
	{
		outputFile.open("Test-Results-Output.txt");
	};

	~Board();

	// i) n< m, ii) x and y in bounds, iii) unique id check 
	bool Insert(int ID, int x, int y);

	bool BoundCheck(int x, int y);

	// returns false if player not found else deletes the player from both maps
	bool Remove(int ID);

	// returns true if player was found
	bool Find(int ID);
	bool Find(pair<int, int> Pos);

	// i) in bound check, ii) if a player is present at that spot remove that player, 
	// iii) if a player is removed display which player was removed
	// iv) if moveTo fails state the reason why
	bool MoveTo(int ID, int x2, int y2);

	// Argument 1 = Initial Position.........Argument 2 = Destination
	void RecursiveMoveTo(pair<int, int> Loc, pair<int, int> Des);

	// inorder traversal(ID) of red and black tree
	void PrintByID();

	//prints to outfile
	void Print(string DisplayText);

private:
	//size of board
	int sizeM;
	// number of players
	int PlayersN;
	//map<ID, Pos(x,y)>
	map<int, pair<int, int>> getValuePos;
	//map<Pos(x,y), ID>
	map<pair<int, int>, int> getValueUniqueID;
	fstream outputFile;
};