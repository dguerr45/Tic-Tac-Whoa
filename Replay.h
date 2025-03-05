/*********************************************************/
/* Title: Replay.h										 */
/* Author: Daniel Guerra-Rojas							 */
/*														 */
/* Modifications:										 */
/* 03/13/21  DGR  Initial version						 */
/*********************************************************/
#ifndef REPLAY_H
#define REPLAY_H

#include "BoardStruct.h"

//allows user to save replay of last game played
void Replay(LIST *list, int aiLevel, char player1_char, char player2_char, char player1_color, char player2_color);

//prints board to replay file
void FilePrintBoard(FILE *file, int board[3][3], char player1_char, char player2_char, char player1_color, char player2_color);

#endif /* REPLAY_H */

/* EOF */
