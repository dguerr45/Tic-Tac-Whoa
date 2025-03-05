/*********************************************************/
/* Title: GameControl.c									 */
/* Author: Daniel Guerra-Rojas							 */
/*														 */
/* Modifications:										 */
/* 03/14/21  DGR  modified how boards are logged into	 */
/*				  double-linked list					 */
/* 03/13/21  DGR  added support for Take Back			 */
/* 03/12/21  DGR  added support to log game				 */
/* 03/11/21  DGR  Initial version						 */
/*********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "GameControl.h"
#include "AI.h"
#include "BoardStruct.h"

// This function prints the board
void print_fun(int board[3][3], char player1_char, char player2_char, char player1_color, char player2_color)
{
    // start with row
    for(int i=0;i<3;i++)
	{
        // print out vertical legend
		if(i==0)
			printf("C ");
		if(i==1)
			printf("B ");
		if(i==2)
			printf("A ");
	
        // find corresponding column    
		for(int j=0;j<3;j++)
		{
			if(board[i][j]==0) // empty space
				printf(" ");
			else if (board[i][j]==1) // player 1
			{
				if (player1_color== 'r')
				{
					printf("\x1b[31m%c\x1b[0m",player1_char); //Red
				}
				else if (player1_color== 'g')
				{
					printf("\x1b[32m%c\x1b[0m",player1_char); //Green
				}
				else if (player1_color== 'y')
				{
					printf("\x1b[33m%c\x1b[0m",player1_char); // Yellow
				}
				else if (player1_color== 'b')
				{
					printf("\x1b[34m%c\x1b[0m",player1_char); // Blue
				}
				else
				{
					printf("%c\x1b[0m",player1_char); // Default color (theme dependent)
				}
			}
			else if (board[i][j]==2) // player 2
			{
				if (player2_color== 'r')
				{
					printf("\x1b[31m%c\x1b[0m",player2_char); //Red
				}
				else if (player2_color== 'g')
				{
					printf("\x1b[32m%c\x1b[0m",player2_char); //Green
				}
				else if (player2_color== 'y')
				{
					printf("\x1b[33m%c\x1b[0m",player2_char); // Yellow
				}
				else if (player2_color== 'b')
				{
					printf("\x1b[34m%c\x1b[0m",player2_char); // Blue
				}
				else
				{
					printf("%c\x1b[0m",player2_char); // Default color (theme dependent)
				}
			}
				
			// print out lines in between columns 
            if(j!=2)
				printf("|");
		}
		if(i!=2) // print out lines between rows
			printf("\n  -----\n");
		else if(i==2) // prints out horizontal legend
			printf("\n  1 2 3\n");
	}
}

//This function checks if there is empty place in board.
int is_there_empty_cell(int board[3][3])
{
	int count=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
				if(board[i][j]==0)
					count++;	
		}
	}
	if (count!=0)
		return 1; // we have empty cell
	else
		return 0; // we do not have empty cell
}

// win condition
int IsWin(int board[3][3])
{
	
	int win_flag=0;
	if(((board[0][0]==1)&&(board[1][0]==1)&&(board[2][0]==1))||
		((board[0][1]==1)&&(board[1][1]==1)&&(board[2][1]==1))||
		((board[0][2]==1)&&(board[1][2]==1)&&(board[2][2]==1))||
		((board[0][0]==1)&&(board[0][1]==1)&&(board[0][2]==1))||
		((board[1][0]==1)&&(board[1][1]==1)&&(board[1][2]==1))||
		((board[2][0]==1)&&(board[2][1]==1)&&(board[2][2]==1))||
		((board[0][0]==1)&&(board[1][1]==1)&&(board[2][2]==1))||
		((board[0][2]==1)&&(board[1][1]==1)&&(board[2][0]==1)))
		{
			win_flag =1;
		}
	
	else if(((board[0][0]==2)&&(board[1][0]==2)&&(board[2][0]==2))||
				((board[0][1]==2)&&(board[1][1]==2)&&(board[2][1]==2))||
				((board[0][2]==2)&&(board[1][2]==2)&&(board[2][2]==2))||
				((board[0][0]==2)&&(board[0][1]==2)&&(board[0][2]==2))||
				((board[1][0]==2)&&(board[1][1]==2)&&(board[1][2]==2))||
				((board[2][0]==2)&&(board[2][1]==2)&&(board[2][2]==2))||
				((board[0][0]==2)&&(board[1][1]==2)&&(board[2][2]==2))||
				((board[0][2]==2)&&(board[1][1]==2)&&(board[2][0]==2)))
				{
					win_flag =2;
				}

	return win_flag;		
}

// enters int 1 or 2 in desired position.
void entered_one_char(int board [3][3], int player_num, char *letters_num)
{
	int valid_entered = 0;
	int c;
	int r;
	while(valid_entered == 0)
	{
		c=0;
		r=0;
		scanf("%s",letters_num);
		
		if (letters_num[0]=='A')
		{
			r=2;
		}
		else if(letters_num[0]=='B')
		{
			r=1;
		}
		else if(letters_num[0]=='C')
		{
			r=0;
		}
		
		if (letters_num[1]=='1')
		{
			c=0;
		}
		else if(letters_num[1]=='2')
		{
			c=1;
		}
		else if(letters_num[1]=='3')
		{
			c=2;
		}

		if (board[r][c] == 0)
		{
			valid_entered = 1;
		}
		else
		{
			printf("The entered position is not available! Please try again...\n");
		}
	}
	board [r][c]=player_num;
}

// Handle a Human v. Human game
void HumanVsHuman(LIST *list, int board[3][3], char player1_char, char player2_char, char player1_color, char player2_color)
{
	//intialized to use in while loop (to log data of game)
	BOARD *logBoard;
	ENTRY *entry;

	//creates a board and stores empty board
	//inputs 0's since no players have made any moves yet
	entry = CreateEntry();
	logBoard = CreateBoard(entry, 0, board, "00");
	Append(list, entry);

	//used to store moves of player's
	char PlayerMove[3];

	printf("Human v. Human game started\n");
	print_fun(board, player1_char, player2_char, player1_color, player2_color);
	int tie=1;
	while((is_there_empty_cell(board)))
	{
		printf("Player 1, please choose your move:");

		//PlayerMove use to record where player moves
		entered_one_char(board, 1, PlayerMove);

		//creates log of board and stores it
		//used to capture player 1's move
		entry = CreateEntry();
		logBoard = CreateBoard(entry, 1, board, PlayerMove);
		Append(list, entry);

		print_fun(board, player1_char, player2_char, player1_color, player2_color);
		int win_flag = IsWin(board);
		if(win_flag != 0)
		{
			if (win_flag == 1)
			{
				printf("\nPlayer 1 wins! Game Over!\n");
			}
			else if (win_flag == 2)
			{
				printf("\nPlayer 2 wins! Game Over!\n");
			}
			tie=0;
			logBoard->tie = 0;
			break;
		}
		else if (is_there_empty_cell(board)==0)
			break;
	
		printf("Player 2, please choose your move:");

		//PlayerMove used to record where player moves
		entered_one_char(board, 2, PlayerMove);

		//creates log of board and stores it
		//this log is to capture Player 2's move
		entry = CreateEntry();
		logBoard = CreateBoard(entry, 2, board, PlayerMove);
		Append(list, entry);

		print_fun(board, player1_char, player2_char, player1_color, player2_color);
		win_flag = IsWin(board);
		if(win_flag != 0)
		{
			if (win_flag == 1)
			{
				printf("\nPlayer 1 wins! Game Over!\n");
			}
			else if (win_flag == 2)
			{
				printf("\nPlayer 2 wins! Game Over!\n");
			}
			tie=0;
			logBoard->tie = 0;
			break;
		}
	}
	if (tie==1)
		printf("The game is a tie!\n");
}

// Handle a Human v. AI game
// Human is always player1 and AI is player2
// Returns level of AI to be used for replay feature
int Human_Vs_AI(LIST *list, int board[3][3], char player1_char, char player2_char, char player1_color, char player2_color)
{
	/* to be used to determine which AI is playing */
	int aiLevel;

	//intialized to use in while loop (to log data of game)
	BOARD *logBoard;
	ENTRY *entry;

	//creates a new BOARD and stores current game board
	//inputs 0's since no players have made any moves yet
	entry = CreateEntry();
	logBoard = CreateBoard(entry, 0, board, "00");
	Append(list, entry);

	char PlayerMove[3];

	/* asks user which AI they want to play against */
	printf("\nWhich AI would you like to play against?\n");
	printf("1. Inky   (Level 1)\n");
	printf("2. Blinky (Level 2)\n");
	printf("3. Pinky  (Level 3)\n");
	printf("Choose Option: ");
	scanf(" %d", &aiLevel);

	printf("\nHuman v. AI game started\n");
	print_fun(board, player1_char, player2_char, player1_color, player2_color);
	int tie=1;

	while((is_there_empty_cell(board)))
	{
		printf("Player 1, please choose your move:");

		//PlayerMove records where player moves
		entered_one_char(board, 1, PlayerMove);

		//initializes board struct
		//this log is to capture Player 1's move
		entry = CreateEntry();
		logBoard = CreateBoard(entry, 1, board, PlayerMove);
		Append(list, entry);

		print_fun(board, player1_char, player2_char, player1_color, player2_color);
		int win_flag = IsWin(board);
		if(win_flag != 0)
		{
			if (win_flag == 1)
			{
				printf("\nPlayer 1 wins! Game Over!\n");
			}
			else if (win_flag == 2)
			{
				printf("\nAI wins! Game Over!\n");
			}
			tie=0;
			logBoard->tie = 0;
			break;
		}
		else if (is_there_empty_cell(board)==0)
			break;

		printf("AI is choosing its move:\n");
		
		//calls AI to move based on which one is playing
		if(aiLevel == 1){

			//calls Inky AI to move
			//logBoard->playerMove records where AI moves
			Inky(board, PlayerMove);

			//creates log for this turn
			entry = CreateEntry();
			logBoard = CreateBoard(entry, 2, board, PlayerMove);
			Append(list, entry);
		} else if(aiLevel == 2){
			
			//calls Blinky AI to move
			//logBoard->playerMove records where AI moves
			Blinky(board, PlayerMove);

			//creates log for this turn
			entry = CreateEntry();
			logBoard = CreateBoard(entry, 2, board, PlayerMove);
			Append(list, entry);
		} else if(aiLevel == 3){

			//calls Blinky AI to move
			//logBoard->playerMove records where AI moves
			Pinky(board, PlayerMove);

			//creates log for this turn
			entry = CreateEntry();
			logBoard = CreateBoard(entry, 2, board, PlayerMove);
			Append(list, entry);
		}
		print_fun(board, player1_char, player2_char, player1_color, player2_color);

		//prompts users if they want to perform "Take Back"
		TakeBack(list, board, player1_char, player2_char, player1_color, player2_color);

		win_flag = IsWin(board);
		if(win_flag != 0)
		{
			if (win_flag == 1)
			{
				printf("\nPlayer 1 wins! Game Over!\n");
			}
			else if (win_flag == 2)
			{
				printf("\nAI wins! Game Over!\n");
			}
			tie=0;
			logBoard->tie = 0;
			break;
		}
		else if (is_there_empty_cell(board)==0)
			break;
	}
	if (tie==1)
	{
		printf("The game is a tie!\n");
	}
	return aiLevel;
}

//allows human player to take back their last move and the AI's last move
//this can be repeated until blank board is reached
void TakeBack(LIST *list, int board[3][3], char player1_char, char player2_char, char player1_color, char player2_color)
{
	//checks if list is valid
	if(!list){
		perror("Out of memory! Aborting...");
		exit(10);
	}

	//used to decide if Undo is done or not
	int userChoice = 1;

	int x = 0, y = 0;

	//runs until there are no more moves to take back unless user
	//says otherwise
	while(list->length != 1 && userChoice == 1){
		
		//prints message only when AI has just made winning move
		if(IsWin(board) == 2){
			printf("\nAI has just made a winning move!");
		}
		printf("\nWould you like to Undo the AI's and your most recent move?\n");
		printf("1. Yes\n");
		printf("2. No\n");
		printf("Choose Option: ");
		scanf(" %d", &userChoice);
		if(userChoice == 1){

			//if yes, then AI and player's most recent move both get removed
			DeleteLastEntry(list);
			DeleteLastEntry(list);

			//sets active game board to older version
			for(x = 0; x < 3; x++){
				for(y = 0; y < 3; y++){
					board[x][y] = list->last->board->loggedBoard[x][y];
				}
			}
		}
		//prints board for player to see if they want to Undo again
		print_fun(board, player1_char, player2_char, player1_color, player2_color);
	}
}

/* EOF */
