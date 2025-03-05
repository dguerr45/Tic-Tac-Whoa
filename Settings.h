/*********************************************************/
/* Title: Settings.h									 */
/*														 */
/* Author: Daniel Guerra-Rojas							 */
/*														 */
/* Modifications:										 */
/* 03/10/21  DGR  Initial version						 */
/*********************************************************/
#ifndef SETTINGS_H
#define SETTINGS_H

// handle settings for the game
void settings(char *player1_char, char *player2_char, char *player1_color, char *player2_color);

// players can choose their characters.
void choose_char(char *player1_char, char *player2_char);

// players can choose their colors.
void choose_color(char *player1_color, char *player2_color);

#endif /* SETTINGS_H */

/* EOF */
