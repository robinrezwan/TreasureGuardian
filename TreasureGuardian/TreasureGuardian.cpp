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

		iShowImage(0, 0, 2512, SCREEN_HIGHT, background_one0); //Shows the most inner still background (the sky).
		for (int i = 0; i < 2; i++)
		{
			iShowImage(background_one1_x[i], 0, 2512, SCREEN_HIGHT, background_one1[i]); //Shows the inner moving background (the clouds).
		}
		for (int i = 0; i < 2; i++)
		{
			iShowImage(background_one2_x[i], 0, 2512, SCREEN_HIGHT, background_one2[i]); //Shows the second inner moving background (the trees).
		}
		for (int i = 0; i < 2; i++)
		{
			iShowImage(background_one3_x[i], 0, 2512, SCREEN_HIGHT, background_one3[i]); //Shows the front moving background (the ground).
		}

		/*________________________________________________Showing characters for level one.________________________________________________*/

		if (player1.condition == 0) //If standing.
		{
			iShowImage(player1.x, player1.y, 160, 160, player1.image_idle[player_idle_index]); /*Showing idle images from an array.
			The image index is being changed by calling void changeIdleImage() from a timer when no key is pressed.*/
		}

		else if (player1.condition == 1) //If standing backward.
		{
			iShowImage(player1.x, player1.y, 160, 160, player1.image_idleback[player_idleback_index]); /*Showing backward idle images from an array.
			The image index is being changed by calling void changeIdleImage() from a timer when no key is pressed.*/
		}

		else if (player1.condition == 2) //If running.
		{
			iShowImage(player1.x, player1.y, 160, 160, player1.image_running[player_running_index]); /*Showing running images from an array.
			The image index is being changed by calling void changeRunningImage() from void iSpecialKeyboard() when no right key is pressed.*/

			player1.condition_changer++;
			if (player1.condition_changer >= 200)
			{
				player1.condition_changer = 0;
				player1.condition = 0;
			}
		}

		else if (player1.condition == 3) //If running backward.
		{
			iShowImage(player1.x, player1.y, 160, 160, player1.image_runningback[player_runningback_index]); /*Showing running backward images from an array.
			The image index is being changed by calling void changeRunningBackImage() from void iSpecialKeyboard() when left key is pressed.*/

			player1.condition_changer++;
			if (player1.condition_changer >= 200)
			{
				player1.condition_changer = 0;
				player1.condition = 1;
			}
		}

		else if (player1.condition == 4 || player1.condition == 6) //If jumping.
		{
			iShowImage(player1.x, player1.y + jumping_height, 160, 160, player1.image_jumping[player_jumping_index]); /*Showing jumping images from an array.
			The image index is being changed by calling void Jump() from void iSpecialKeyboard() when up key is pressed.*/

			/*if (jumping_height <= 0)
			{
				player1.condition = 0;
			}*/
		}

		else if (player1.condition == 5 || player1.condition == 7) //If jumping back.
		{
			iShowImage(player1.x, player1.y + jumping_height, 160, 160, player1.image_jumpingback[player_jumping_index]); /*Showing jumping back images from an array.
			The image index is being changed by calling void Jump() from void iSpecialKeyboard() when up key is pressed.*/

			/*if (jumping_height <= 0)
			{
				player1.condition = 1;
			}*/
		}

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

		/*__________________________________Showing life potion, cecking collision & counting score.______________________________________*/

		if (life_gem1.x % 2 == 0 || life_gem1.x % 3 == 0)
		{
			if (life_gem1.state)
			{
				iShowImage(life_gem1.x, life_gem1.y, life_gem1.dimension_x, life_gem1.dimension_y, life_gem1.image);

				if (checkCollison(player1.x + player1.extended_x, player1.y + player1.extended_y + jumping_height, 80, 130, life_gem1.x, life_gem1.y, 48, 40))
				{
					cout << "Boom!" << endl;
					life_gem1.state = false;
				}
			}
		}

		/*________________________________________________________Showing enemy._________________________________________________________*/

		showEnemy();
	}

	/*________________________________________________Level two codes start from here.____________________________________________________*/
	/**************************************************************************************************************************************/

	else if (level == 2)
	{
		//cout << "Level two codes running!" << endl;

		/*_______________________________________________Showing background for level two.______________________________________________*/

		iShowImage(0, 0, 2512, SCREEN_HIGHT, background_two0); //Shows the most inner still background (the sky).
		for (int i = 0; i < 2; i++)
		{
			iShowImage(background_two1_x[i], 0, 2512, SCREEN_HIGHT, background_two1[i]); //Shows the inner moving background (the clouds and the sea).
		}
		for (int i = 0; i < 2; i++)
		{
			iShowImage(background_two2_x[i], 0, 2512, SCREEN_HIGHT, background_two2[i]); //Shows the second inner moving background (the lands).
		}
		for (int i = 0; i < 2; i++)
		{
			iShowImage(background_two3_x[i], 0, 2512, SCREEN_HIGHT, background_two3[i]); //Shows the front moving background (the front ground).
		}

		/*_______________________________________________________Showing goblins.__________________________________________________________*/


		/*____________________________________________________Flipping the plane.__________________________________________________________*/


		/*_______________________________________________________Throwing fireball.________________________________________________________*/


		/*________________________________________Checking collision, showing fire & counting score._______________________________________*/


	}

	/*________________________________________________Game over codes start from here.____________________________________________________*/
	/**************************************************************************************************************************************/

	if (player1.life <= 0 && menu_option != 0) //Checking if the game is over.
	{
		game_over = true;
		level = 0;
	}

	if (game_over)
	{
		//cout << "Game over codes running!" << endl;

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

		printf("%d, %d\n", menu_x, menu_y);

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
		throw_fireball = 1;
		fireball_x = plane_x + 40;
		fireball_y = plane_y;
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

	if (key == 'f')
	{
		
	}

	if (key == 'o')
	{
		level = 0;
		player1.life = 0;
		player1.score = 2260;
		high_score.score = player1.score;
	}

	if (key == 'u')
	{
		flip = 1;
	}

	if (key == 't')
	{
		flip = 2;
	}

	if (key == 'y')
	{
		flip = 3;
	}

	if (key == '2')
	{
		level = 2;
		//menu_option = 6;
	}

	if (key == '3')
	{

	}

	if (key == '4')
	{

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
		plane_x -= 5;

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
	}

	if (key == GLUT_KEY_RIGHT)
	{
		plane_x += 10;

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
	}

	if (key == GLUT_KEY_DOWN)
	{
		plane_y -= 5;
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

	iSetTimer(10, changeEnemyPosition);

	plane_timer = iSetTimer(20, movePlane);
	//fireball_timer = iSetTimer(40, moveFireball);

	controlSound(play_sound, 0);

	iInitialize(SCREEN_WIDTH, SCREEN_HIGHT, "TreasureGuardian");
	dpx = 5;
	dpy = 0;

	plane_x = 1520;
	plane_y = 580;

	dfx = 0;
	dfy = 1;

	fireball_x = -160;
	fireball_y = -160;

	loadImage();

	iStart();

	return 0;
}
