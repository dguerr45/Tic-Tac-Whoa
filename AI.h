/*********************************************************/
/* Title: AI.h											 */
/* Author: Daniel Guerra-Rojas							 */
/*														 */
/* Modifications:										 */
/* 03/14/21  DGR  added Pinky AI						 */
/* 03/12/21  DGR  added support to log game				 */
/* 03/11/21  DGR  Initial version						 */
/*********************************************************/
#ifndef AI_H
#define AI_H

//function for Inky AI movement
void Inky(int board[3][3], char *AImove);

//function for Blinky AI movement
void Blinky(int board[3][3], char *AImove);

//function for Pinky AI movement
void Pinky(int board[3][3], char *AImove);

#endif /* AI_H */

/* EOF */
