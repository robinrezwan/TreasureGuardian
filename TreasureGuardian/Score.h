#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED

#include <iostream>
using namespace std;

/*__________________________________________________Structure for saving high scores.__________________________________________________*/

struct HighScore
{
	char name[20];
	int score;

	HighScore()
	{
		;
	}

	HighScore(char* _name, int _score)
	{
		strcpy(name, _name);
		score = _score;
	}
} high_score;

/*__________________________________________________Function for showing high scores.__________________________________________________*/

//Shows high scores on the high score page reading from a file.
void showHighScores()
{
	FILE *fp = fopen("high_scores.bin", "rb");

	if (fp == NULL)
	{
		cout << "File not found!" << endl;
	}

	else
	{
		HighScore high_score_temp;
		char score_string[10];

		for (int text_y = 475; fread(&high_score_temp, sizeof(struct HighScore), 1, fp) == 1; text_y -= 65)
		{
			//cout << high_score_temp.name << "\t" << high_score_temp.score << endl;
			sprintf(score_string, "%d", high_score_temp.score);

			iSetColor(0, 0, 0);
			iText(200, text_y, high_score_temp.name, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(1020, text_y, score_string, GLUT_BITMAP_TIMES_ROMAN_24);
		}

		fclose(fp);
	}
}

/*________________________________________________Function for setting player's name.__________________________________________________*/

//Shows the player's name on the screen which is being taken input from the keyboard by the function void inputName().
void setPlayerName()
{
	if (field_active)
	{
		iSetColor(0, 0, 0);
		iRectangle(525, 290, 470, 58);
		iText(600, 310, high_score.name, GLUT_BITMAP_TIMES_ROMAN_24); //Gets the value from void inputName() function.
		//cout << "Taking input." << endl;
	}

	else
	{
		iSetColor(0, 0, 0);
		iText(600, 297, high_score.name, GLUT_BITMAP_HELVETICA_18);
	}
}

/*___________________________________Function for text box activation to take player's name input._____________________________________*/

//To activate text box for name input.
void activateTextBox(int mx, int my)
{
	if (game_over && player_rank >= 1 && player_rank <= 5)
	{
		if (mx >= 525 && mx <= 995 && my >= 290 && my <= 348)
		{
			field_active = true;
			cout << "Text box activated." << endl;
		}
	}
}

/*_________________________________Function for writing in the text box to take player's name input.___________________________________*/

//For taking input the player's name through the text box.
void inputName(unsigned char key)
{
	if (game_over && player_rank >= 1 && player_rank <= 5)
	{
		//cout << "Entering text at index: " << name_index << endl;
		if (field_active && name_index < 18)
		{
			if (key == '\b')
			{
				if (name_index > 0)
				{
					high_score.name[--name_index] = NULL;
				}
			}
			else if(key != '\r' && (key >= 'A' && key <= 'Z' || key >= 'a' && key <= 'z' || key >= '0' && key <= '9' || key == ' '))
			{
				high_score.name[name_index++] = key;
				//cout << high_score.name << endl;
			}
		}
	}
}

/*___________________________________Function for saving high score and the player's name in a file.___________________________________*/

//This function saves the player's name and score in a binary file.
void saveScore()
{
	FILE *fp = fopen("high_scores.bin", "rb");

	if (fp == NULL)
	{
		//cout << "File not found!" << endl;
		fp = fopen("high_scores.bin", "wb");
		fclose(fp);

		fp = fopen("high_scores.bin", "rb");
	}

	HighScore high_score_temp[6];
	HighScore high_score_temp2;

	int element_index = 0;

	while (fread(&high_score_temp2, sizeof(struct HighScore), 1, fp) == 1)
	{
		high_score_temp[element_index] = high_score_temp2;
		element_index++;
	}

	fclose(fp);

	if (element_index > 4)
	{
		element_index = 4;
	}

	/*Shifting array elements to right to make space for the new entry.*/
	for (int i = element_index; i >= player_rank; i--)
	{
		high_score_temp[i] = high_score_temp[i - 1];
	}

	/*Inserting new element at given position according to player rank.*/
	high_score_temp[player_rank - 1] = high_score;

	/*for (int i = 0; i <= element_index; i++)
	{
		cout << high_score_temp[i].name << "\t" << high_score_temp[i].score << endl;
	}*/

	fp = fopen("high_scores.bin", "wb");

	if (fp == NULL)
	{
		cout << "Error in opening file! Score could not be saved!" << endl;
	}

	else
	{
		fwrite(&high_score_temp, sizeof(struct HighScore), (element_index + 1), fp);
		//cout << "Score saved!" << endl;
	}

	fclose(fp);
}

#endif // !SCORE_H_INCLUDED
