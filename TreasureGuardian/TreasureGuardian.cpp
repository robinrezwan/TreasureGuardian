#define _CRT_SECURE_NO_WARNINGS

#include "iGraphics.h"
#include "Variables.h"
#include "LoadImage.h"
#include "Player.h"
#include "Menu.h"
#include "Collision.h"
#include "Sound.h"
#include "Background.h"
#include "Character.h"
#include "LifeGem.h"
#include "LevelTwo.h"
#include "GameOver.h"
#include "Score.h"
#include "Enemy.h"

#include <iostream>
using namespace std;

void iDraw()
{
	iClear();

	/*______________________________________________________Showing menu pages.___________________________________________________________*/
	/**************************************************************************************************************************************/

	if (menu_option != 1) //No image ID for index 1. Because we have level one in that option.
	{
		//cout << "Menu codes running!" << endl;

		iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HIGHT, menu_image[menu_option]); /*Shows all the menu pages from an arry of images.
		The image index changes due to calling int selectOption() from void iMouse().*/

		if (menu_option == 2) //If the high score page is openned.
		{
			showHighScores(); //Showing the high score list.
		}
	}

	/*________________________________________________Level one codes start from here.____________________________________________________*/
	/**************************************************************************************************************************************/

	else if (level == 1)
	{
		//cout << "Level one codes running!" << endl;

		/*_______________________________________________Showing background for level one.______________________________________________*/

		showBackground1();

		/*________________________________________________Showing characters for level one.________________________________________________*/

		showPlayer1();

		/*_________________________________________________Showing player's firing._______________________________________________________*/

		if (fire && (player1.condition == 0 || player1.condition == 2))
		{
			iShowImage(bullet_x, player1.y + 40, 20, 10, bullet_image);
			bullet_x += 10;
			if (bullet_x > 1520)
			{
				fire = false;
				bullet_x = player1.x + 110;
			}
		}

		if (fire && (player1.condition == 1 || player1.condition == 3))
		{
			iShowImage(bullet_back_x, player1.y + 40, 20, 20, bullet_back_image);
			bullet_back_x -= 10;
			if (bullet_back_x < -20)
			{
				fire = false;
				bullet_back_x = player1.x;
			}
		}

		/*__________________________________Showing life potion, cecking collision & counting life score.____________________________________*/

		if (life_gem1.x % 2 == 0 || life_gem1.x % 3 == 0)
		{
			if (life_gem1.state)
			{
				iShowImage(life_gem1.x, life_gem1.y, life_gem1.dimension_x, life_gem1.dimension_y, life_gem1.image);

				if (checkCollision(player1.x + player1.extended_x, player1.y + player1.extended_y + jumping_height, 80, 130, life_gem1.x, life_gem1.y, 48, 40))
				{
					//cout << "Boom!" << endl;
					life_gem1.state = false;
					player1.life += 10;
				}
			}
		}

		/*________________________________________________________Showing enemy._________________________________________________________*/

		showEnemy();

		/*_________________________________________________Player, Fire and enemy collision.______________________________________________*/

		fireEnemyCollision();
		playerEnemyCollision();

		/*__________________________________________________Showing life and score bar.____________________________________________________*/

		iSetColor(255, 0, 0);
		iText(50, 760, "Life: ", GLUT_BITMAP_HELVETICA_18);
		iRectangle(95, 755, 100, 25);
		iFilledRectangle(95, 755, player1.life, 26);

		iText(50, 730, "Score: ", GLUT_BITMAP_HELVETICA_18);
		sprintf(score_string, "%d", player1.score);
		iText(120, 730, score_string, GLUT_BITMAP_HELVETICA_18);

		if (player1.score >= 200)
		{
			level = 2;
			player2.x = 460;
			player2.y = 600;
		}
	}

	/*________________________________________________Level two codes start from here.____________________________________________________*/
	/**************************************************************************************************************************************/

	else if (level == 2)
	{
		//cout << "Level two codes running!" << endl;

		/*________________________________________________Showing background for level two.________________________________________________*/

		showBackground2();

		/*__________________________________Showing life potion, cecking collision & counting score.______________________________________*/
		
		if (life_gem2.x % 2 == 0 || life_gem2.x % 3 == 0)
		{
			if (life_gem2.state)
			{
				iShowImage(life_gem2.x, life_gem2.y, life_gem2.dimension_x, life_gem2.dimension_y, life_gem1.image);

				if (checkCollision(player2.x + player2.extended_x, player2.y + player2.extended_y, 140, 90, life_gem2.x, life_gem2.y, 48, 40))
				{
					//cout << "Boom!" << endl;
					life_gem2.state = false;
					player1.life += 10;
				}
			}
		}

		/*________________________________________________Showing characters for level two.________________________________________________*/

		iShowImage(player2.x, player2.y, 160, 160, player2.image_plane[player_plane_index]);

		/*_________________________________________________Showing player's firing._______________________________________________________*/

		if (fire)
		{
			bullet_y = player2.y + 20;
			iShowImage(bullet_x, bullet_y, 20, 10, bullet_image);
			bullet_x += 10;
			if (bullet_x > 1520)
			{
				fire = false;
				bullet_x = player2.x + 110;
			}
		}

		/*___________________________________________________Showing enemy for level two.__________________________________________________*/

		showEnemy2();

		/*_________________________________________________Player, Fire and enemy collision.______________________________________________*/

		fireEnemyCollision2();
		playerEnemyCollision2();

		/*__________________________________________________Showing life and score bar.____________________________________________________*/

		iSetColor(255, 0, 0);
		iText(50, 760, "Life: ", GLUT_BITMAP_HELVETICA_18);
		iRectangle(95, 755, 100, 25);
		iFilledRectangle(95, 755, player1.life, 26);

		iText(50, 730, "Score: ", GLUT_BITMAP_HELVETICA_18);
		sprintf(score_string, "%d", player1.score);
		iText(120, 730, score_string, GLUT_BITMAP_HELVETICA_18);
	}

	/*________________________________________________Game over codes start from here.____________________________________________________*/
	/**************************************************************************************************************************************/

	if ((player1.life <= 0) && menu_option != 0) //Checking if the game is over.
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

/*_______________________________________________________Mouse Controls.______________________________________________________________*/
/**************************************************************************************************************************************/

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
		menu_x = mx;
		menu_y = my;

		//printf("%d, %d\n", menu_x, menu_y);

		menu_option = selectOption(menu_option, menu_x, menu_y);

		if (menu_option == 1) //For sound.
		{
			level = 1;
			controlSound(true, 1);
		}

		activateTextBox(mx, my); //If high score is achieved.
	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}

/*______________________________________________________Keyboard controls.____________________________________________________________*/
/**************************************************************************************************************************************/

void iKeyboard(unsigned char key)
{
	inputName(key); //If high score is achieved.

	if (key == '\r')
	{
		if (game_over && player_rank != 0) //Parts of this block are being used temporarily.
		{
			field_active = false; //To deactivate the name input text box.
			saveScore();
			game_over = false;
			player1.life = 100;
			player1.score = 0;
			menu_option = 0;
		}
	}

	if (key == ' ')
	{
		/*throw_fireball = 1;
		fireball_x = plane_x + 40;
		fireball_y = plane_y;*/
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
		plane_y += 5;

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

/*________________________________________________________Main function.______________________________________________________________*/
/**************************************************************************************************************************************/

int main()
{
	background_two1_timer = iSetTimer(40, changeBackgroundTwo1);
	background_two2_timer = iSetTimer(20, changeBackgroundTwo2);
	background_two3_timer = iSetTimer(10, changeBackgroundTwo3);

	player_timer1 = iSetTimer(100, changeIdleImage);
	iSetTimer(20, Jump);

	iSetTimer(5000, positionLifeGem);

	iSetTimer(10, enemyPosition);

	plane_timer = iSetTimer(100, changePlaneImage);

	controlSound(play_sound, 0);

	iInitialize(SCREEN_WIDTH, SCREEN_HIGHT, "TreasureGuardian");

	loadImage();

	iStart();

	return 0;
}
