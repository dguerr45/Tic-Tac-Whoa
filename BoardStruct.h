/*********************************************************/
/* Title: BoardStruct.h									 */
/* Author: Daniel Guerra-Rojas							 */
/*														 */
/* Modifications:										 */
/* 03/12/21  DGR  Initial version						 */
/*********************************************************/
#ifndef BOARDSTRUCT_H
#define BOARDSTRUCT_H

typedef struct List LIST;
typedef struct BoardEntry ENTRY;
typedef struct BoardLog BOARD;

struct List{
	int length;
	ENTRY *first;
	ENTRY *last;
};

struct BoardEntry{
	LIST *list;
	ENTRY *next;
	ENTRY *previous;
	BOARD *board;
};

struct BoardLog{
	int loggedBoard[3][3];
	int playerNum;
	char playerMove[3];
	int tie;
};

/* initializes a list header */
LIST *CreateList();

//creates an entry for the list
ENTRY *CreateEntry();

//creates a log for one player's move
BOARD *CreateBoard(ENTRY *entry, int playerNum, int gameBoard[3][3], char RecordedMove[3]);

//adds entry to end of list and links list, entry, and board together
void Append(LIST *list, ENTRY *entry);

/* deletes a list (and any entries if they exist) */
void DeleteList(LIST *list);

/* deletes first entry in the list (and board associated with it) */
void DeleteFirstEntry(LIST *list);

/* deletes last entry in the list (and board associated with it) */
void DeleteLastEntry(LIST *list);

#endif /* BOARDSTRUCT_H */

/* EOF */
