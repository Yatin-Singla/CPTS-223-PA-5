#include "Board.h"

bool Board::BoundCheck(int x, int y)
{
	bool returnValue = false;

	if (x <= sizeM && y <= sizeM)
	{
		returnValue = true;
	}
	return returnValue;
}

Board::~Board()
{
	outputFile.close();
}

bool Board::Insert(int ID, int x, int y)
{
	bool returnValue = false;
	int PlayerCount = PlayersN;
	if (++PlayerCount <= sizeM)
	{
		if (BoundCheck(x, y))
		{
			//check for unique ID
			map<int, pair<int, int>>::iterator itrUniqueID = getValuePos.find(ID);
			if (itrUniqueID == getValuePos.end())
			{
				// check for unique pos
				map<pair<int, int>, int>::iterator itrUniquePos = getValueUniqueID.find(make_pair(x, y));
				if (itrUniquePos == getValueUniqueID.end())
				{
					//Inserting a Player
					getValuePos.insert(make_pair(ID, make_pair(x,y)));
					getValueUniqueID.insert(make_pair(make_pair(x, y), ID));

					// Player count on board being updated
					PlayersN++;
					returnValue = true;
				}
				else
				{
					cout << "ERROR: Player Insertion Failed: Position on board being accommodated by another Player." << endl;
					Print("ERROR: Player Insertion Failed: Position on board being accommodated by another Player.");

				}
			}
			else
			{
				cout << "ERROR: Player Insertion Failed: Player ID not unique" << endl;
				Print("ERROR: Player Insertion Failed: Player ID not unique");
			}
		}
		else
		{
			cout << "ERROR: Player cannot be inserted because the destination location is out of bounds." << endl;
			Print("ERROR: Player cannot be inserted because the destination location is out of bounds.");
		}
	}	
	else
	{
		cout << "ERROR: Player Insertion failed because the number players on board exceed the Length of the Board" << endl;
		Print("ERROR: Player Insertion failed because the number players on board exceed the Length of the Board");
	}
	return returnValue;

}

bool Board::Remove(int ID)
{
	bool returnVal = false;
	map<int, pair<int,int>>::iterator itr = getValuePos.find(ID);
	if (itr != getValuePos.end()) // Value was found
	{
		//now I have to delete the two values from both the maps
		getValuePos.erase(itr->first);
		//delete from second map
		getValueUniqueID.erase(itr->second);
		// decreasing number of players
		PlayersN--;
		returnVal = true;
	}
	else
	{/*not found*/}

	return returnVal;
}

bool Board::Find(int ID)
{
	bool returnValue = false;
	map<int, pair<int, int>>::iterator itr = getValuePos.find(ID);
	if (itr != getValuePos.end())
	{// Player Found
		returnValue = true;
	}
	
	return returnValue;
}

bool Board::Find(pair <int, int> Pos)
{
	if (getValueUniqueID.find(Pos) != getValueUniqueID.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Board::MoveTo(int ID, int x2, int y2)
{	
	bool returnValue = false;
	if (BoundCheck(x2, y2))
	{
		if (Find(make_pair(x2, y2)))
		{	//deletes a player if they occupy the coordinates of destination
			map<pair<int, int>, int>::iterator itr = getValueUniqueID.find(make_pair(x2, y2));
			cout << "A Player with uniqueID = " << itr->second;
			//writing to the outfile
			outputFile << "A Player with uniqueID = " << itr->second;
			
			cout << " occupying coordinates (" << itr->first.first << "," << itr->first.second << ") was removed from the Board" << endl;
			outputFile << " occupying coordinates (" << itr->first.first << "," << itr->first.second << ") was removed from the Board" << endl;

			//deleting the Player from the Board
			Board(itr->second);
		}
		// Player with specified ID has to exist
		if (Find(ID))
		{
			//moves the player diagonally, along the row or column
			RecursiveMoveTo((getValuePos.find(ID))->second, make_pair(x2, y2));
			(getValuePos.find(ID))->second = make_pair(x2, y2);
			//deletes the player from second map to update the location of the unique ID associated with it.
			getValueUniqueID.erase(make_pair(x2, y2));
			getValueUniqueID.insert(make_pair(make_pair(x2, y2), ID));
			returnValue = true;
		}
		else
		{
			cout << "Sorry the Player with ID does not exist" << endl;
			Print("Sorry the Player with ID does not exist");
		}
		
	}
	else
	{
		cout << "ERROR: MoveTo Function failed because the destination is out of bounds." << endl;
		Print("ERROR: MoveTo Function failed because the destination is out of bounds.");
	}

	return returnValue;
}

void Board::RecursiveMoveTo(pair<int, int> Loc, pair<int, int> Des)
{
	if (Loc == Des)
	{
		return;
	}
	else
	{
		// To the Upper Right Half (I Quadrant)
		if (Des.first > Loc.first && Des.second > Loc.second)
		{
			Loc.first++;
			Loc.second++;
			RecursiveMoveTo(Loc, Des);
		}
		// To the Lower Right Bottom (IV Quadrant)
		else if(Des.first > Loc.first && Des.second < Loc.second )
		{
			Loc.first++;
			Loc.second--;
			RecursiveMoveTo(Loc, Des);
		}
		// II Quadrant 
		else if(Des.first < Loc.first && Des.second > Loc.first)
		{
			Loc.first--;
			Loc.second++;
			RecursiveMoveTo(Loc, Des);
		}
		// III Quadrant 
		else if (Des.first < Loc.first && Des.second < Loc.first)
		{
			Loc.first--;
			Loc.second--;
			RecursiveMoveTo(Loc, Des);
		}
		// Along +X axis -> 
		else if (Des.first > Loc.first)
		{
			Loc.first++;
			RecursiveMoveTo(Loc, Des);
		}
		// Along -X axis <-
		else if (Des.first < Loc.first)
		{
			Loc.first--;
		}
		//              ^  
		//Along +Y axis |
		else if (Des.second > Loc.second)
		{
			Loc.second++;
		}
		// Along -Y axis |
		//               V
		else if (Des.second < Loc.second)
		{
			Loc.second--;
		}
	}
}

void Board::PrintByID()
{
	cout << "Player:" << endl;
	Print("Player:");
	for (map<int, pair<int, int>>::iterator itr = getValuePos.begin(); itr != getValuePos.end(); itr++)
	{
		cout << "Unique ID: " << itr->first << " -> (" << itr->second.first << ", " << itr->second.second << ") " << endl;
		outputFile << "Unique ID: " << itr->first << " -> (" << itr->second.first << ", " << itr->second.second << ") " << endl;
	}
}

void Board::Print(string DisplayText)
{
	outputFile << DisplayText << endl;	
}