CPTS 223: PA 5.

Simulated a Board Game using Standard Template Library Data Structures.

A m x m square matrix board was defined with an initial count of players (N) = 0. It is assumed that throughout the game user doesn't change the size of the board however the user can insert or remove a player from the board as they deem fit.
A Board class was created with a size m x m with n players. The value of m is user specified. As the game progresses 'n' is allowed to change. 
A Player Class was implemented. Each Player Object has a UniqueID and a position associated with them. At any given time no two players can have the same ID or occupy the same position (Unless MoveTo function is being implemented) 

Functions within Board Class: 

Insert Method: this method allows the user to add a new Player on the board. The method takes a UniqueID along with desired (x,y) coordinates as its input. The method returns true if insertion was successfully implemented otherwise it states the reason for failure to insert.

Remove method: Allows the user to remove a plater from the board. The method takes Player ID as its input. It returns true if a player was successfully removed from the board, false otherwise.

Find Method: Returns true if a player was found, false otherwise. The method takes Player's ID as input.

MoveTo method: Allows the user to move a player to a new destination.The method takes Player's ID as input and destination coordinates (x,y) as input. If a player is located at the destination it is first removed from the board. The movement of the player is always along the same row or same column or same diagonal in any direction. Method returns true upon a successful move. If any player was removed from the board during the process the method prints a message to indicate which player was removed.If a move fails, the method displays an error message stating the reason for the failure and returns false.

PrintByID method: Prints all the players along with their IDs and (x,y) positions in the increasing order of their IDs.



Design:

2 maps were created namely

map<int, pair<int,int>. getValuePos
map<pair<int,int>, int> getValueUniqueID

first map has the player's ID as its key and returns the position of the player.
Second map has the player's pos as its key and returns the unique ID of the player.
Since find method's runtime complexity is log(n) therefore it makes more sense to spend a little bit more memory to keep a copy of the data but obtain higher efficiency. To make up for the memory expenditure instead of creating a new player object every time, maps have been implemented in such a way that they have player's uniqueID and position as their key and value or vice versa. Board class has a variable sizeM set the board size = m and PlayersN = n (number of players on the board).

RunTime and Memory Analysis:

Insert method: runtime complexity = O(log(n)).

BoundCheck Method: runtime complexity = O(1).

Remove Method: runtime complexity = O(log(N)).

Overloaded Find Method: runtime complexity = O(log(n)).

RecursiveMoveTo method: runtime complexity = O(n).

PrintByID method: runtime complexity = O(n).

Memory Complexity: O(n).



