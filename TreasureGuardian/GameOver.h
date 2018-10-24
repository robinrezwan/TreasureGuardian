#ifndef GAMEOVER_H_INCLUDED
#define GAMEOVER_H_INCLUDED

//#include <iostream>
//using namespace std;

//#include "Variables.h"
#include "Score.h"

/*______________________________________________Function for checking score rank.______________________________________________________*/

/*Checks if the player has achieved a position in the high score list comparing his score with the previously saved high scores reading from a file.
Doing so, it sets the rank value. It also sets the values for the indexes of game over page image and star badge image.*/
void checkRank()
{
	//cout << "Checking player rank!" << endl;

	FILE *fp = fopen("high_scores.bin", "rb");

	if (fp == NULL)
	{
		player_rank = 1;
		game_over_index = 1;
		star_index = 0;

		//cout << "File not found." << endl;
	}

	else
	{
		HighScore high_score_temp;
		int i = 1;

		while (fread(&high_score_temp, sizeof(struct HighScore), 1, fp) == 1)
		{
			if (player1.score > high_score_temp.score)
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

#endif // !GAMEOVER_H_INCLUDED
