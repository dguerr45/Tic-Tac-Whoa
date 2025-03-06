# General Overview of Tic-Tac-Whoa Files

## Special Features Descriptions
After every move the AI makes, the user is prompted if they’d like to 
Take Back the most recent moves (takes back one move for
the user and one for the AI). This feature is a work in progress and will
be updated in the future. The Save Replay feature is prompted at the
end of the game for any game type, shows the user a message
asking what the name of the save file should be, then creates the save file
with that name and adds the extension “.txt”. If a file exists with the
same name as the input the user gives, the previous file is automatically
overwritten.

## All .h Files
These files hold function declarations for their respective .c files.

## TicTacWhoa.c
Holds the main function and another that prints the 
Menu Screen and then asks the user to choose one of the menu options. The
main function then calls one of three functions depending on the menu 
option the user chose, unless the user chose to exit the game.
If that’s the case, a goodbye message appears and then the program ends.
The three possible functions are for the HumanVsHuman game mode, the HumanVsAI
game mode, and the Settings Menu inside the game.

## AI.c
Inky is level 1 and chooses the first location that is available starting from
the top left and scans for open spaces moving to the right. If no open spaces
are available in the first row, it moves down one and continues a similar
process of scanning for open spaces. Blinky is level 2 and randomly selects a
location on the board. The function for Blinky checks if the randomly chosen
location is available, and if it is, then it moves to that location.
Otherwise, it just picks another random location. Pinky is level 3 and acts
like the Blinky AI and chooses a random location, unless there is possible
winning move the user can make in his next turn. If that is the case,
then Pinky goes ahead and blocks that winning move.

## BoardStruct.c
Holds functions for allocating memory and creating the double-linked
list that records all data necessary for creating the Replay at
the end of the game, if the user decides to save the Replay.

## Replay.c
Holds functions two functions where the first is the primary function
that prompts the user if they’d like to save the most recent finished 
game. If the user choose yes, then the saving process begins and writes
to a file in the directory under a name that the user inputs with the extension
“.txt” appended. Otherwise, a message appears saying that the replay is
not saved. The second function is just a helper for the primary function
to write the saved Tic-Toe-Toe game boards into the new file that is being
created.

## Settings.c
Holds the functions that control the settings menu along with the logic
behind changing either player’s character and/or color.
