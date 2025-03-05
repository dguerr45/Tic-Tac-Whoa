/*********************************************************/
/* Title: Replay.c										 */
/* Author: Daniel Guerra-Rojas							 */
/*														 */
/* Modifications:										 */
/* 03/14/21  DGR  added prints to tell user what file	 */
/*				  hold the replay						 */
/* 03/13/21  DGR  Initial version						 */
/*********************************************************/
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "Replay.h"
#include "BoardStruct.h"

//allows user to save replay of last game played
void Replay(LIST *list, int aiLevel, char player1_char, char player2_char, char player1_color, char player2_color)
{
	int userChoice;
	char fileName[60] = {};
	FILE *replayFile;

	//prompts user if they'd like to save replay
	printf("\nWould you like to save the replay of this game?\n");
	printf("1. Yes\n");
	printf("2. No\n");
	printf("Choose Option: ");
	scanf(" %d", &userChoice);

	if(userChoice == 1){
		printf("\nWhat would you like to name the file: ");
		scanf(" %s", fileName);
		strcat(fileName, ".txt");

		//intializes data for data and time prints
		struct tm *currentTime;
		time_t temp = time(0);
		currentTime = localtime(&temp);

		//begins writing to file process
		replayFile = fopen(fileName, "w");
		fprintf(replayFile, "#TicTacWowWeeWow\n");
		fprintf(replayFile, "Version: v2.0\n");
		fprintf(replayFile, "Filename: %s\n", fileName);

		//prints the year
		fprintf(replayFile, "Date: %d/", currentTime->tm_year + 1900);

		//prints the month
		if((currentTime->tm_mon + 1) < 10){
			fprintf(replayFile, "0%d/", currentTime->tm_mon + 1);
		} else {
			fprintf(replayFile, "%d/", currentTime->tm_mon + 1);
		}
		//prints the day
		if(currentTime->tm_mday < 10){
			fprintf(replayFile, "0%d ", currentTime->tm_mday);
		} else {
			fprintf(replayFile, "%d ", currentTime->tm_mday);
		}
		//prints the hour of the time
		if(currentTime->tm_hour == 0){
			fprintf(replayFile, "%d:", 12);
		} else if(currentTime->tm_hour < 13){
			fprintf(replayFile, "%d:", currentTime->tm_hour);
		} else {
			fprintf(replayFile, "%d:", currentTime->tm_hour - 12);
		}
		//prints the minute of the time
		if(currentTime->tm_min < 10){
			fprintf(replayFile, "0%d", currentTime->tm_min);
		} else {
			fprintf(replayFile, "%d", currentTime->tm_min);
		}
		//prints am or pm
		if(currentTime->tm_hour < 12){
			fprintf(replayFile, "am\n");
		} else {
			fprintf(replayFile, "pm\n");
		}

		fprintf(replayFile, "\n#Settings\n");
		switch(player1_color)
		{
			case 'r':
				fprintf(replayFile, "Player 1 (Human): '%c', 'Red'\n", player1_char);
				break;
			case 'g':
				fprintf(replayFile, "Player 1 (Human): '%c', 'Green'\n", player1_char);
				break;
			case 'y':
				fprintf(replayFile, "Player 1 (Human): '%c', 'Yellow'\n", player1_char);
				break;
			case 'b':
				fprintf(replayFile, "Player 1 (Human): '%c', 'Blue'\n", player1_char);
				break;
			case 'd':
				fprintf(replayFile, "Player 1 (Human): '%c', 'White'\n", player1_char);
				break;
		}
		if(aiLevel == 0){
			switch(player2_color)
			{
				case 'r':
					fprintf(replayFile, "Player 2 (Human): '%c', 'Red'\n", player2_char);
					break;
				case 'g':
					fprintf(replayFile, "Player 2 (Human): '%c', 'Green'\n", player2_char);
					break;
				case 'y':
					fprintf(replayFile, "Player 2 (Human): '%c', 'Yellow'\n", player2_char);
					break;
				case 'b':
					fprintf(replayFile, "Player 2 (Human): '%c', 'Blue'\n", player2_char);
					break;
				case 'd':
					fprintf(replayFile, "Player 2 (Human): '%c', 'White'\n", player2_char);
					break;
			}
		} else if(aiLevel == 1){
			switch(player2_color)
			{
				case 'r':
					fprintf(replayFile, "Player 2 (AI - Inky): '%c', 'Red'\n", player2_char);
					break;
				case 'g':
					fprintf(replayFile, "Player 2 (AI - Inky): '%c', 'Green'\n", player2_char);
					break;
				case 'y':
					fprintf(replayFile, "Player 2 (AI - Inky): '%c', 'Yellow'\n", player2_char);
					break;
				case 'b':
					fprintf(replayFile, "Player 2 (AI - Inky): '%c', 'Blue'\n", player2_char);
					break;
				case 'd':
					fprintf(replayFile, "Player 2 (AI - Inky): '%c', 'White'\n", player2_char);
					break;
			}
		} else if(aiLevel == 2){
			switch(player2_color)
			{
				case 'r':
					fprintf(replayFile, "Player 2 (AI - Blinky): '%c', 'Red'\n", player2_char);
					break;
				case 'g':
					fprintf(replayFile, "Player 2 (AI - Blinky): '%c', 'Green'\n", player2_char);
					break;
				case 'y':
					fprintf(replayFile, "Player 2 (AI - Blinky): '%c', 'Yellow'\n", player2_char);
					break;
				case 'b':
					fprintf(replayFile, "Player 2 (AI - Blinky): '%c', 'Blue'\n", player2_char);
					break;
				case 'd':
					fprintf(replayFile, "Player 2 (AI - Blinky): '%c', 'White'\n", player2_char);
					break;
			}
		} else if(aiLevel == 3){
			switch(player2_color)
			{
				case 'r':
					fprintf(replayFile, "Player 2 (AI - Pinky): '%c', 'Red'\n", player2_char);
					break;
				case 'g':
					fprintf(replayFile, "Player 2 (AI - Pinky): '%c', 'Green'\n", player2_char);
					break;
				case 'y':
					fprintf(replayFile, "Player 2 (AI - Pinky): '%c', 'Yellow'\n", player2_char);
					break;
				case 'b':
					fprintf(replayFile, "Player 2 (AI - Pinky): '%c', 'Blue'\n", player2_char);
					break;
				case 'd':
					fprintf(replayFile, "Player 2 (AI - Pinky): '%c', 'White'\n", player2_char);
					break;
			}
		}
		fprintf(replayFile, "\n#Winner\n");
		if(list->last->board->tie == 1){
			fprintf(replayFile, "Tie\n");
		} else {
			fprintf(replayFile, "Player %d\n", list->last->board->playerNum);
		}
		fprintf(replayFile, "\n#MovesList\n");

		//prints the MovesList
		ENTRY *entry = list->first->next;
		while(entry){
			fprintf(replayFile, "Player %d: %s\n", entry->board->playerNum, entry->board->playerMove);
			entry = entry->next;
		}
		
		fprintf(replayFile, "\n#Replay\n");

		//prints replay of the game
		entry = list->first->next;
		while(entry){
			fprintf(replayFile, "Player %d chooses %s\n", entry->board->playerNum, entry->board->playerMove);
			FilePrintBoard(replayFile, entry->board->loggedBoard, player1_char, player2_char, player1_color, player2_color);
			entry = entry->next;
		}

		//prints who won at end of replay
		if(list->last->board->tie == 1){
			fprintf(replayFile, "The game is a tie!\n");
		} else {
			fprintf(replayFile, "Player %d wins!\n", list->last->board->playerNum);
		}

		fprintf(replayFile, "\n#EOF\n");
		
		//closes the file
		fclose(replayFile);

		//prints message to tells user name of file created
		printf("\nGame has been saved as \"%s\"\n\n", fileName);
	} else {
		printf("Replay was not saved!\n\n");
	}
}

//prints board to replay file
void FilePrintBoard(FILE *file, int board[3][3], char player1_char, char player2_char, char player1_color, char player2_color)
{
    // start with row
    for(int i=0;i<3;i++)
	{
        // print out vertical legend
		if(i==0)
			fprintf(file, "C ");
		if(i==1)
			fprintf(file, "B ");
		if(i==2)
			fprintf(file, "A ");
	
        // find corresponding column    
		for(int j=0;j<3;j++)
		{
			if(board[i][j]==0) // empty space
				fprintf(file, " ");
			else if (board[i][j]==1) // player 1
			{
				if (player1_color== 'r')
				{
					fprintf(file, "\x1b[31m%c\x1b[0m",player1_char); //Red
				}
				else if (player1_color== 'g')
				{
					fprintf(file, "\x1b[32m%c\x1b[0m",player1_char); //Green
				}
				else if (player1_color== 'y')
				{
					fprintf(file, "\x1b[33m%c\x1b[0m",player1_char); // Yellow
				}
				else if (player1_color== 'b')
				{
					fprintf(file, "\x1b[34m%c\x1b[0m",player1_char); // Blue
				}
				else
				{
					fprintf(file, "%c\x1b[0m",player1_char); // Default color (theme dependent)
				}
			}
			else if (board[i][j]==2) // player 2
			{
				if (player2_color== 'r')
				{
					fprintf(file, "\x1b[31m%c\x1b[0m",player2_char); //Red
				}
				else if (player2_color== 'g')
				{
					fprintf(file, "\x1b[32m%c\x1b[0m",player2_char); //Green
				}
				else if (player2_color== 'y')
				{
					fprintf(file, "\x1b[33m%c\x1b[0m",player2_char); // Yellow
				}
				else if (player2_color== 'b')
				{
					fprintf(file, "\x1b[34m%c\x1b[0m",player2_char); // Blue
				}
				else
				{
					fprintf(file, "%c\x1b[0m",player2_char); // Default color (theme dependent)
				}
			}
				
			// print out lines in between columns 
            if(j!=2)
				fprintf(file, "|");
		}
		if(i!=2) // print out lines between rows
			fprintf(file, "\n  -----\n");
		else if(i==2) // prints out horizontal legend
			fprintf(file, "\n  1 2 3\n\n");
	}
}
