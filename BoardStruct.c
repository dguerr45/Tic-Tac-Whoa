/*********************************************************/
/* Title: BoardStruct.c									 */
/* Author: Daniel Guerra-Rojas							 */
/*														 */
/* Modifications:										 */
/* 03/14/21  DGR  removed asserts from file				 */
/* 03/13/21  DGR  modified DeleteFirstEntry and			 */
/*				  DeleteLastEntry functions				 */
/* 03/12/21  DGR  Initial version						 */
/*********************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "BoardStruct.h"

//initializes a list header
LIST *CreateList()
{
	LIST *list;
	list = calloc(1, sizeof(LIST));

	//checks if memory was allocated correctly
	if(!list){
		perror("Out of memory! Aborting...");
		exit(10);
	}
	list->length = 0;
	list->first = NULL;
	list->last = NULL;
	return list;
}

//creates an entry for the list
ENTRY *CreateEntry()
{
	ENTRY *entry;
	entry = calloc(1, sizeof(ENTRY));

	//checks if memory was allocated correctly
	if(!entry){
		perror("Out of memory! Aborting...");
		exit(10);
	}
	entry->list = NULL;
	entry->next = NULL;
	entry->previous = NULL;
	entry->board = NULL;
	return entry;
}

//creates a log for one player's move
BOARD *CreateBoard(ENTRY *entry, int playerNum, int gameBoard[3][3], char RecordedMove[3])
{
	//checks if entry is valid
	if(!entry){
		perror("Out of memory! Aborting...");
		exit(10);
	}

	BOARD *board;
	board = calloc(1, sizeof(BOARD));

	//checks if memory was allocated correctly
	if(!board){
		perror("Out of memory! Aborting...");
		exit(10);
	}
	entry->board = board;

	//logs which player moved
	board->playerNum = playerNum;
	board->tie = 1;

	//logs the current board
	int x, y;
	for(x = 0; x < 3; x++){
		for(y = 0; y < 3; y++){
			board->loggedBoard[x][y] = gameBoard[x][y];
		}
	}
	board->playerMove[0] = RecordedMove[0];
	board->playerMove[1] = RecordedMove[1];

	return board;
}

//adds entry to end of list and links list, entry, and board together
void Append(LIST *list, ENTRY *entry)
{
	//checks if pointers are valid
	if(!list){
		perror("Out of memory! Aborting...");
		exit(10);
	}
	if(!entry){
		perror("Out of memory! Aborting...");
		exit(10);
	}

	if(list->length == 0){		//if list is empty
		entry->previous = NULL;
		entry->next = NULL;
		entry->list = list;
		list->first = entry;
		list->last = entry;
	} else {					//if list is not empty
		entry->next = NULL;
		entry->previous = list->last;
		entry->list = list;
		list->last->next = entry;
		list->last = entry;
	}
	list->length += 1;

}

//deletes a list (and any entries if they exist)
void DeleteList(LIST *list)
{
	//checks if list is valid
	if(!list){
		perror("Out of memory! Aborting...");
		exit(10);
	}

	while(list->length){
		DeleteFirstEntry(list);
	}
	free(list);
	list = NULL;
}

//deletes first entry in the list (and board associated with it)
void DeleteFirstEntry(LIST *list)
{
	//checks if list is valid
	if(!list){
		perror("Out of memory! Aborting...");
		exit(10);
	}

	ENTRY *entry = list->first;

	//checks if entry is valid
	if(!entry){
		perror("Out of memory! Aborting...");
		exit(10);
	}

	//checks if board exists in entry
	if(!entry->board){
		perror("Out of memory! Aborting...");
		exit(10);
	}

	free(entry->board);

	//checks if entry being deleted is only entry
	if(list->length != 1){

		//second entry cuts ties with first entry
		entry->next->previous = NULL;

		//second entry nows becomes new first entry in list
		list->first = entry->next;
	} else {
		
		//if it's last entry, then list "first" and "last"
		//pointers are cleared
		list->first = NULL;
		list->last = NULL;
	}
	entry->next = NULL;
	entry->list = NULL;

	//gets rid of original first entry
	free(entry);
	list->length -= 1;
}

//deletes last entry in the list (and board associated with it)
void DeleteLastEntry(LIST *list)
{
	//checks if list is valid
	if(!list){
		perror("Out of memory! Aborting...");
		exit(10);
	}

	ENTRY *entry = list->last;

	//checks if entry is valid
	if(!entry){
		perror("Out of memory! Aborting...");
		exit(10);
	}

	//checks if board exists in entry
	if(!entry->board){
		perror("Out of memory! Aborting...");
		exit(10);
	}

	free(entry->board);

	//checks if entry being deleted is only entry
	if(list->length != 1){

		//second to last entry cuts ties with last entry
		entry->previous->next = NULL;

		//second to last entry nows becomes new last entry
		list->last = entry->previous;
	} else {
		
		//if it's last entry, then list "first" and "last"
		//pointers are cleared
		list->first = NULL;
		list->last = NULL;
	}
	entry->previous = NULL;
	entry->list = NULL;

	//gets rid of original last entry
	free(entry);
	list->length -= 1;
}

/* EOF */
