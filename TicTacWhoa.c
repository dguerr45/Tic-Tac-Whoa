/**********************************************************/
/* Title: TicTacWhoa.c								  */
/*														  */
/* Authors: Mozhgan Moradiganjeh, QV Dang,				  */
/*			Daniel Guerra-Rojas							  */
/*														  */
/* Modifications:									      */
/* 03/14/21  DGR  modified how Replay is called			  */
/* 03/13/21  DGR  added support for saving replay of game */
/* 03/12/21  DGR  made player info into structs and made  */
/*				  boards to use structs.				  */
/* 03/11/21  DGR  Took out game control from file		  */
/* 03/10/21  DGR  Took out Settings from file			  */
/* 01/18/21   QV  AI, function, and comment updates		  */
/* 01/13/21   MM  Initial version						  */
/**********************************************************/
#include <stdio.h>
#include "Settings.h"
#include "GameControl.h"
#include "PlayerStruct.h"
#include "BoardStruct.h"
#include "Replay.h"

// Handle Menu Options
int print_menu()
{
	int select=0;
	printf("1. Start New Game (Human v. Human)\n");
	printf("2. Start New Game (Human v. AI)\n");
	printf("3. Game Settings\n");
	printf("4. Exit Game\n");
	printf("Choose Option: ");
	scanf("%d",&select);
	getchar(); // one solution for clearing the "\n" char from the input
	return select;
}

// Main Program for Tic-Tac-Whoa
int main()
{
	//for replay function
	int aiLevel;

    // initialize players
	PLAYER player1 = {1, 'X', 'd'};
	PLAYER player2 = {2, 'O', 'd'};

	//intialize list pointer
	LIST *list;
	list = NULL;

	printf("Welcome to Secure-Tic-Tac-Whoa!\n");
	int done=0;
	while(done==0)
	{
		if(list){

			//asks user if they would like to save replay of game
			//only saves most recent game
			Replay(list, aiLevel, player1.Char, player2.Char, player1.Color, player2.Color);

			DeleteList(list);
		}

		int board[3][3]={{0,0,0},{0,0,0},{0,0,0}};
		int option = print_menu();
		switch(option)
		{
			case 1:
				list = CreateList();
				HumanVsHuman(list, board, player1.Char, player2.Char, player1.Color, player2.Color);
				aiLevel = 0;
				break;
			case 2:
				list = CreateList();
				aiLevel = Human_Vs_AI(list, board,player1.Char,player2.Char,player1.Color,player2.Color);
				break;
			case 3:
				settings(&player1.Char, &player2.Char, &player1.Color, &player2.Color);
				break;
			case 4:
				printf("Thanks for playing. Exiting game...\n");
				done=1;
				break;
		}

	}
	return 0;
}

/* EOF */
