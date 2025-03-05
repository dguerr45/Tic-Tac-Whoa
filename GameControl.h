/*********************************************************/
/* Title: GameControl.h									 */
/* Author: Daniel Guerra-Rojas							 */
/*														 */
/* Modifications:										 */
/* 03/13/21  DGR  added support for Take Back and		 */
/*				  modified HumanVsAI parameters			 */
/* 03/11/21  DGR  Initial version						 */
/*********************************************************/
#ifndef GAMECONTROL_H
#define GAMECONTROL_H

#include "BoardStruct.h"

// This function prints the board
void print_fun(int board[3][3],char player1_char,char player2_char,char player1_color, char player2_color);

//This function checks if there is empty place in board.
int is_there_empty_cell(int board[3][3]);

// win condition
int IsWin(int board[3][3]);

// enters int 1 or 2 in desired position.
void entered_one_char(int board [3][3],int player_num, char *letters_num);

// Handle a Human v. Human game
void HumanVsHuman(LIST *list, int board[3][3], char player1_char, char player2_char, char player1_color, char player2_color);

// Handle a Human v. AI game
// Human is always player1 and AI is player2
// Returns level of AI to be used for replay feature
int Human_Vs_AI(LIST *list, int board[3][3], char player1_char, char player2_char, char player1_color, char player2_color);

//allows human player to take back their last move and the AI's last move
//this can be repeated until blank board is reached
void TakeBack(LIST *list, int board[3][3], char player1_char, char player2_char, char player1_color, char player2_color);

#endif /* GAMECONTROL_H */

/* EOF */
