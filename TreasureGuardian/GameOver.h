#ifndef GAMEOVER_H_INCLUDED
#define GAMEOVER_H_INCLUDED

//#include <iostream>
//using namespace std;

//#include "Variables.h"
#include "ScoreSave.h"
#include "Sound.h"

/*______________________________________________Function for checking score rank.______________________________________________________*/

/*Checks if the player has achieved a position in the high score list comparing his score with the previously saved high scores reading from a file.
Doing so, it sets the rank value. It also sets the values for the indexes of game over page image and star badge image.*/
void checkRank()
{
	//cout << "Checking player rank!" << endl;

	FILE *fp = fopen("high_scores.bin", "rb");

	if (fp == NULL)
	{
		if (ground_player.score > 0)
		{
			player_rank = 1;
			game_over_index = 1;
			star_index = 0;
		}
		else
		{
			player_rank = 0;
			game_over_index = 0;
		}
		//cout << "File not found." << endl;
	}

	else
	{
		HighScore high_score_temp;
		int i = 1;

		while (fread(&high_score_temp, sizeof(struct HighScore), 1, fp) == 1)
		{
			if (ground_player.score > high_score_temp.score)
			{
				player_rank = i;
				break;
			}

			i++;
		}

		if (player_rank == 0) //If the file has less then five high scores saved and the new score is not higher than any of them.
		{
			if (i > 5)
			{
				game_over_index = 0;
			}
			else
			{
				player_rank = i;
				game_over_index = 2;
				star_index = player_rank - 1;
			}
		}

		else if (player_rank == 1)
		{
			game_over_index = 1;
			star_index = 0;
		}

		else if (player_rank >= 2 && player_rank <= 5)
		{
			game_over_index = 2;
			star_index = player_rank - 1;
		}

		fclose(fp);
	}
}

/*________________________________________________Game over codes start from here.________________________________________________*/

//This function checks if game is over, then runs all the codes regarding game over.
void gameOver()
{
	if (ground_player.health <= 0 && menu_option != 0) //Checking if the game is over.
	{
		game_over = true;

		//Resetting conditions.
		level = 0;
		intro_level = 0;
		show_map = 0;
		show_gift = 0;

		ground_player.health = 100;
		player_distance = 0;
		shield_count = 0;
		active_shield = false;

		intro_player.x = 160;
		intro_player.y = 30;

		ground_player.x = 160;

		flying_player.x = 160;
		flying_player.y = 520;

		jump = false;
		jumping = false;
		jumping_height = 0;

		intro_player.condition = 0;
		ground_player.condition = 0;

		goblin.reset(1390, 662, true, 24, 0);

		magic_stone.resetMagicObject(1600, 45, 89, 120, false, false);
		magic_chest.resetMagicObject(1600, 48, 132, 195, false, false);
		magic_key.resetMagicObject(1600, 65, 72, 120, false, false);

		eraseGame(); //Erasing saved game.
	}

	if (game_over)
	{
		//cout << "Game over codes running!" << endl;

		if (!sound_playing)
		{
			controlSound(true);
			sound_playing = true;
		}

		level = 0;
		ground_player.health = 0;
		high_score.score = ground_player.score;

		checkRank(); //Checks the players rank according to his score.

		//cout << "Player rank: " << player_rank << endl;

		iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HIGHT, game_over_image[game_over_index]); //Shows the game over screen.

		if (game_over_highlight_index <= 2)
		{
			iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HIGHT, game_over_highlight_image[game_over_index]); //Highlights the home button in game over screen.
		}

		//Shows the score on the game over screen.
		char score_string[20];
		sprintf(score_string, "%d", ground_player.score);
		iSetColor(255, 0, 0);
		iText(790, 409, score_string, GLUT_BITMAP_TIMES_ROMAN_24);

		if (game_over_index != 0) //If the player has acquired a position in the high score list.
		{
			iShowImage(0, 0, 0, 0, star_image[star_index]); //Shows star badge for the palyer.

			setPlayerName(); //Shows the player's name in the text box while it's being taken input.
		}
	}
}

#endif // !GAMEOVER_H_INCLUDED
