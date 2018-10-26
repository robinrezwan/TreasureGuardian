#define _CRT_SECURE_NO_WARNINGS

#include "iGraphics.h"
#include "Variables.h"
#include "LoadImage.h"
#include "Menu.h"
#include "Background.h"
#include "Player.h"
#include "Enemy.h"
#include "Character.h"
#include "LifeGem.h"
#include "Collision.h"
#include "GameOver.h"
#include "Score.h"
#include "Sound.h"
#include "LevelOne.h"
#include "LevelTwo.h"

#include <iostream>
using namespace std;

void iDraw()
{
	iClear();

	/*_____________________________________________________Showing menu pages._________________________________________________________*/

	if (menu_option == 0 || (menu_option >= 2 && menu_option <= 5))
	{
		showMenu(); //This function runs all the codes for menu.
	}

	/*________________________________________________Level one codes runs from here.__________________________________________________*/

	else if (level == 1)
	{
		levelOne(); //This function runs all the codes for level one.
	}

	/*_______________________________________________Level two codes runs from here.___________________________________________________*/

	else if (level == 2)
	{
		levelTwo(); //This function runs all the codes for level two.
	}

	/*_________________________________________________Game over codes start from here.________________________________________________*/

	if (player1.life <= 0 && menu_option != 0) //Checking if the game is over.
	{
		game_over = true;
		level = 0;
	}

	if (game_over)
	{
		//cout << "Game over codes running!" << endl;

		level = 0;
		player1.life = 0;
		high_score.score = player1.score;

		checkRank(); //Checks the players rank according to his score.

		//cout << "Player rank: " << player_rank << endl;

		iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HIGHT, game_over_image[game_over_index]); //Shows the game over screen.

		//Shows the score on the game over screen.
		char score_string[20];
		sprintf(score_string, "%d", player1.score);
		iSetColor(0, 0, 0);
		iText(810, 408, score_string, GLUT_BITMAP_TIMES_ROMAN_24);

		if (game_over_index != 0) //If the player has acquired a position in the high score list.
		{
			iShowImage(0, 0, 0, 0, star_image[star_index]); //Shows star badge for the palyer.

			setPlayerName(); //Shows the player's name in the text box while it's being taken input.
		}
	}
}

/*_________________________________________________________Mouse Controls._____________________________________________________________*/

void iMouseMove(int mx, int my)
{

}

void iPassiveMouse(int mx, int my)
{

}

void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//printf("%d, %d\n", mx, my);

		if (menu_option == 0 || (menu_option >= 2 && menu_option <= 5)) //If the game is on the menu page.
		{
			menu_x = mx;
			menu_y = my;
			
			menu_option = selectMenuOption(menu_option, menu_x, menu_y);
		}

		if (menu_option == 1)
		{
			level = 1;
			menu_option = 6; //Because the game is not in the menu state anymore.
			controlSound(true, 1); //For sound.
		}

		if (game_over_index == 1 || game_over_index == 2) //If high score is achieved.
		{
			activateTextBox(mx, my); //This will activate the text box to enter high scorer's name.
		}
	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}

/*_______________________________________________________Keyboard controls.____________________________________________________________*/

void iKeyboard(unsigned char key)
{
	if (field_active) //If high score is achieved and texbox is active for entering name.
	{
		inputName(key);
	}

	if (key == '\r')
	{
		if (field_active && game_over && player_rank != 0) //This block will execute after entering the high scorer's name and pressing Enter.
		{
			field_active = false; //To deactivate the name input text box.
			saveScore();
			memset(high_score.name, NULL, sizeof(high_score.name)); //Clearing the name after saving the high score.
			name_index = 0;
			player1.life = 100;
			player1.score = 0;
			game_over = false;
			menu_option = 0;
		}
	}

	if (key == ' ')
	{
		fire = true;
	}

	if (key == 'a')
	{
		if (play_sound == true)
		{
			play_sound = false;
			controlSound(play_sound, menu_option);
		}
		else
		{
			play_sound = true;
			controlSound(play_sound, menu_option);
		}
	}

	if (key == 'o')
	{
		/*level = 0;
		player1.life = 0;
		player1.score = 2260;
		high_score.score = player1.score;*/
	}

	if (key == '2')
	{
		level = 2;
		player2.score = player1.score;
		player2.life = player1.life;
		//menu_option = 6;
	}

	if (key == 'p')
	{
		iPauseTimer(0);
	}

	if (key == 'r')
	{
		iResumeTimer(0);
	}
}

void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_LEFT)
	{
		/*Moving character and background for level one.*/

		if (jumping_height == 0)
		{
			player1.condition = 3;
		}

		if (player1.x > -34)
		{
			player1.x -= 3;
		}

		moveBackgroundBack();
		changeRunningBackImage();

		/*Moves player for level two.*/

		player2.x -= 10;
	}

	if (key == GLUT_KEY_RIGHT)
	{
		/*Moving character and background for level one.*/

		if (jumping_height == 0)
		{
			player1.condition = 2;
		}

		if (player1.x < 1395)
		{
			player1.x += 3;
		}

		moveBackground();
		changeRunningImage();

		/*Moves player for level two.*/

		player2.x += 10;
	}

	if (key == GLUT_KEY_UP)
	{
		/*Moving character for level one.*/

		if (player1.condition <= 3)
		{
			player1.condition += 4;
		}

		if (!jump)
		{
			jump = true;
			jumping = true;
		}

		/*Moves player for level two.*/

		player2.y += 15;
	}

	if (key == GLUT_KEY_DOWN)
	{
		/*Moves player for level two.*/

		player2.y -= 15;
	}

	if (key == GLUT_KEY_HOME)
	{
		menu_option = 0;
		level = 0;

		if (game_over) //This block is being used temporarily.
		{
			game_over = false;
			player1.life = 100;
			player1.score = 0;
		}
	}

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
}

/*_________________________________________________________Main function.______________________________________________________________*/
/***************************************************************************************************************************************/

int main()
{
	background_two1_timer = iSetTimer(40, changeBackgroundTwo1);
	background_two2_timer = iSetTimer(20, changeBackgroundTwo2);
	background_two3_timer = iSetTimer(10, changeBackgroundTwo3);

	iSetTimer(100, changeIdleImage);
	iSetTimer(20, Jump);

	iSetTimer(5000, positionLifeGem);

	iSetTimer(10, enemyPosition);

	iSetTimer(100, changePlaneImage);

	controlSound(play_sound, 0);

	iInitialize(SCREEN_WIDTH, SCREEN_HIGHT, "TreasureGuardian");

	loadImage();

	iStart();

	return 0;
}
