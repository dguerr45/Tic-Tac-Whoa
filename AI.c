/*********************************************************/
/* Title: AI.c											 */
/* Author: Daniel Guerra-Rojas							 */
/*														 */
/* Modifications:										 */
/* 03/14/21  DGR  added Blinky AI						 */
/* 03/12/21  DGR  added support to log game				 */
/* 03/11/21  DGR  Initial version						 */
/*********************************************************/
#include <stdlib.h>
#include <time.h>
#include "GameControl.h"
#include "AI.h"

//function for Inky AI movement
void Inky(int board[3][3], char *AImove)
{
	int foundMove = 0;
	int i, j;
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			if (board[i][j] == 0)
			{
				board[i][j] = 2;
				foundMove = 1;
				break;
			}
		}

		if(foundMove)
		{
			break;
		}
	}

	//records AI's move
	AImove[0] = 67-i;
	AImove[1] = 49+j;
}

//function for Blinky AI movement
void Blinky(int board[3][3], char *AImove)
{
	srand(time(0));
	int x = 0, y = 0;

	//Will continue choosing random spots until empty spot is found
	while(1){

		//selects random coordinate on board
		x = rand() % 3;
		y = rand() % 3;

		//if empty spot is found, AI moves there and loop ends
		if( !(board[x][y]) ){
			board[x][y] = 2;

			//records AI's move
			AImove[0] = 67-x;
			AImove[1] = 49+y;

			break;
		}
	}
}

//function for Pinky AI movement
void Pinky(int board[3][3], char *AImove)
{
	//used to see if there is a winning move that the AI can block
	int blockMove = 0;

	int x, y;

	//looks for potential winning moves to block
	for(x = 0; x < 3; x++){
		for(y = 0; y < 3; y++){
			if(board[x][y] == 0){
				board[x][y] = 1;
				blockMove = IsWin(board);

				//if winning move is found, exits inner for loop
				if(blockMove){
					break;
				} else {
					board[x][y] = 0;
				}
			}
		}
		//if winning move is found, exits outer for loop
		if(blockMove){
			break;
		}
	}

	//if a winning move can be blocked, AI chooses that spot
	if(blockMove){
		board[x][y] = 2;

		//records AI's move
		AImove[0] = 67-x;
		AImove[1] = 49+y;
	} else {
		
		//otherwise, the AI acts like Blinky
		Blinky(board, AImove);
	}

}

/* EOF */
