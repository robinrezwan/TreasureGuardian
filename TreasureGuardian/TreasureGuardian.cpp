/*
	Treasure Guardian
	A single player 2D action-adventure game.

	Version: 2.5.0

	Original Authors:

	Robin Rezwan
	Samiul Islam Niloy
	Al Noman Limon

	Project GitHub: http://github.com/robinrezwan/TreasureGuardian
*/

#define _CRT_SECURE_NO_WARNINGS

#include "iGraphics.h"
#include "Variables.h"
#include "LoadImage.h"
#include "Menu.h"
#include "Background.h"
#include "Player.h"
#include "Enemy.h"
#include "Character.h"
#include "Objects.h"
#include "Collision.h"
#include "GameOver.h"
#include "GameSave.h"
#include "ScoreSave.h"
#include "Sound.h"
#include "IntroLevels.h"
#include "LevelOne.h"
#include "LevelTwo.h"

#include <iostream>
using namespace std;

void iDraw()
{
	iClear();

	/*_____________________________________________________Showing menu pages._________________________________________________________*/

	if (menu_option >= 0 && menu_option <= 5)
	{
		showMenu(); //This function runs all the codes for menu.
	}

	/*_____________________________________________Intro level one codes run from here.________________________________________________*/

	else if (intro_level == 1)
	{
		introLevelOne(); //This function runs all the codes for intro level one.
	}

	/*______________________________________________________Showing map one.__________________________________________________________*/

	else if (show_map == 1)
	{
		iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HIGHT, map_screen[0]);
	}

	/*________________________________________________Level one codes run from here.___________________________________________________*/

	else if (level == 1)
	{
		levelOne(); //This function runs all the codes for level one.
	}

	/*____________________________________________________Showing gift screen.________________________________________________________*/

	else if (show_gift == 1)
	{
		iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HIGHT, gift_screen);

		if (!gift_taken)
		{
			iShowImage(1240, 34, 240, 100, gift_plane[0]);
			showIntroPlayer();
		}
		else
		{
			iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HIGHT, invite);
			iShowImage(1200, 15, 200, 178, gift_plane[1]);
		}
	}

	/*_____________________________________________Intro level two codes run from here._______________________________________________*/

	else if (intro_level == 2)
	{
		introLevelTwo(); //This function runs all the codes for intro level two.
	}

	/*______________________________________________________Showing map two.__________________________________________________________*/

	else if (show_map == 2)
	{
		iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HIGHT, map_screen[1]);
	}

	/*________________________________________________Level two codes run from here.__________________________________________________*/

	else if (level == 2)
	{
		levelTwo(); //This function runs all the codes for level two.
	}

	/*________________________________________________Game over codes start from here.________________________________________________*/

	gameOver(); //This function runs all the codes regarding game over.

	/*____________________________________________________Showing pause screen.______________________________________________________*/

	if (pause)
	{
		iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HIGHT, pause_screen);
	}
}

/*_________________________________________________________Mouse Controls._____________________________________________________________*/

void iMouseMove(int mx, int my)
{

}

void iPassiveMouse(int mx, int my)
{
	if (!pause)
	{
		//cout << mx << ", " << my << endl;
		if (menu_option >= 0 && menu_option <= 5)
		{
			if (mx >= 552 && mx <= 968 && my >= 490 && my <= 547)
			{
				highlight_index = 0;
			}
			else if (mx >= 552 && mx <= 968 && my >= 429 && my <= 486)
			{
				highlight_index = 1;
			}
			else if (mx >= 552 && mx <= 968 && my >= 368 && my <= 426)
			{
				highlight_index = 2;
			}
			else if (mx >= 552 && mx <= 968 && my >= 305 && my <= 364)
			{
				highlight_index = 3;
			}
			else if (mx >= 552 && mx <= 968 && my >= 244 && my <= 302)
			{
				highlight_index = 4;
			}
			else if (mx >= 552 && mx <= 968 && my >= 181 && my <= 240)
			{
				highlight_index = 5;
			}
			else
			{
				highlight_index = 6;
			}

			//For highlighting new game and continue button.
			if (menu_option == 1)
			{
				if (mx >= 552 && mx <= 968 && my >= 490 && my <= 547)
				{
					start_highlight_index = 0;
				}
				else if (mx >= 552 && mx <= 968 && my >= 429 && my <= 486)
				{
					start_highlight_index = 1;
				}
				else
				{
					start_highlight_index = 2;
				}
			}

			//For highlighting back button.
			if (mx >= 552 && mx <= 968 && my >= 60 && my <= 116)
			{
				back_highlight_index = menu_option - 1;
			}
			else
			{
				back_highlight_index = 5;
			}

			game_over_highlight_index = 3;
		}

		//For highlighting home button in game over screen.
		else if (game_over)
		{
			if (mx >= 552 && mx <= 968 && my >= 60 && my <= 116)
			{
				game_over_highlight_index = game_over_index;
			}
			else
			{
				game_over_highlight_index = 3;
			}
		}

		//For apple collector ring.
		if (intro_level == 2)
		{
			mouse_x = mx - 35;
			mouse_y = my;
		}
	}
}

void iMouse(int button, int state, int mx, int my)
{
	if (!pause)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
		{
			//cout << mx << ", " << my << endl;

			if (menu_option >= 0 && menu_option <= 5) //If the game is on the menu page.
			{
				selectMenuOption(mx, my);
			}
			else if (show_map == 1)
			{
				if (mx >= 700 && mx <= 755 && my >= 473 && my <= 533)
				{
					level = 1; //For starting level one.
					show_map = 0; //To stop running show_map codes.

					saveGame(); //To save the game progress.
				}
			}
			else if (show_gift == 1 && gift_taken)
			{
				if (mx >= 630 && mx <= 882 && my >= 468 && my <= 645)
				{
					intro_level = 2; //For starting intro level two.
					show_gift = 0; //To stop running show_gift codes.

					saveGame(); //To save the game progress.
				}
			}
			else if (show_map == 2)
			{
				if (mx >= 925 && mx <= 980 && my >= 495 && my <= 555)
				{
					level = 2; //For starting level two.
					show_map = 0; //To stop running show_map codes.

					saveGame(); //To save the game progress.
				}
			}

			if (game_over_index == 0 || game_over_index == 1 || game_over_index == 2) //If high score is achieved.
			{
				if (game_over_index == 1 || game_over_index == 2) //If high score is achieved.
				{
					activateTextBox(mx, my); //This will activate the text box to enter high scorer's name.
				}

				//Clicking home button in game over screen.
				if (mx >= 552 && mx <= 968 && my >= 60 && my <= 116)
				{
					menu_option = 0; //To go to home.
					controlSound(true); //For playing sound.
					sound_playing = false;

					level = 0;
					intro_level = 0;
					show_map = 0;
					show_gift = 0;

					ground_player.score = 0;
					ground_player.health = 100;
					player_distance = 0;
					gift_taken = false;

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

					game_over = false;
					player_rank = 0;
					game_over_index = 3;
					memset(high_score.name, NULL, sizeof(high_score.name)); //Clearing the name.
					name_index = 0;
				}
			}
		}

		if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		{

		}
	}
}

/*_______________________________________________________Keyboard controls.____________________________________________________________*/

void iKeyboard(unsigned char key)
{
	if (!pause)
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
				ground_player.health = 100;
				ground_player.score = 0;
				game_over = false;
				menu_option = 0;
			}
		}

		if (key == ' ')
		{
			fire = true;
		}

		if (key == 'e' || key == 'E')
		{
			if (intro_level == 1)
			{
				if (intro_player.x + intro_player.extended_x + 35 >= stair_top.x && intro_player.x + intro_player.extended_x + intro_player.dimension_x - 35 <= stair_top.x + stair_top.dimension_x && intro_player.y + intro_player.extended_y + jumping_height >= stair_top.y + stair_top.dimension_y)
				{
					show_map = 1; //For showing map after intro level one.
					intro_level = 0; //To stop running intro level one codes.

					saveGame(); //To save the game progress.
				}
			}
			else if (show_gift == 1)
			{
				if (intro_player.x + intro_player.extended_x + 35 >= 1320 && intro_player.x + intro_player.extended_x + intro_player.dimension_x - 35 <= 1480)
				{
					gift_taken = true;
				}
			}
		}

		if (key == 'm' || key == 'M')
		{
			if (!field_active)
			{
				if (!mute)
				{
					controlSound(false);
					mute = true;
				}
				else
				{
					mute = false;
					controlSound(true);
				}
			}
		}

		if (key == 's' || key == 'S')
		{
			if ((level == 1 || level == 2) && shield_count > 0)
			{
				if (!active_shield)
				{
					active_shield = true;
				}
				else
				{
					active_shield = false;
				}
			}
		}

		if (key == '$')
		{
			cheatcode_active = true;
			//cout << "Cheatcode activated!" << endl;
		}

		else if (cheatcode_active)
		{
			//cout << "Cheatcode used!" << endl;
			if (key == '1')
			{
				show_map = 1;
				intro_level = 0;
				level = 0;
				show_gift = 0;
				menu_option = 6;
				game_over = false;
			}

			if (key == '2')
			{
				level = 1;
				intro_level = 0;
				show_map = 0;
				show_gift = 0;
				menu_option = 6;
				game_over = false;
			}

			if (key == '3')
			{
				show_gift = 1;
				intro_level = 0;
				level = 0;
				show_map = 0;
				menu_option = 6;
				game_over = false;

				intro_player.x = 160;
				intro_player.y = 30;
			}

			if (key == '4')
			{
				intro_level = 2;
				level = 0;
				show_map = 0;
				show_gift = 0;
				menu_option = 6;
				game_over = false;
			}

			if (key == '5')
			{
				show_map = 2;
				intro_level = 0;
				level = 0;
				show_gift = 0;
				menu_option = 6;
				game_over = false;
			}

			if (key == '6')
			{
				level = 2;
				show_map = 0;
				intro_level = 0;
				show_gift = 0;
				menu_option = 6;
				game_over = false;

				shield_count = 0;
				active_shield = false;

				flying_player.x = 160;
				flying_player.y = 520;
			}

			cheatcode_active = false;
		}
	}

	if (key == 'p' || key == 'P')
	{
		if (intro_level != 0 || level != 0 || show_gift != 0)
		{
			if (!pause)
			{
				pause = true;

				iPauseTimer(timer_ten_mili);
				iPauseTimer(timer_twenty_mili);
				iPauseTimer(timer_forty_mili);
				iPauseTimer(timer_hundred_mili);
				iPauseTimer(timer_one_sec);
				iPauseTimer(timer_four_sec);
			}
			else
			{
				pause = false;

				iResumeTimer(timer_ten_mili);
				iResumeTimer(timer_twenty_mili);
				iResumeTimer(timer_forty_mili);
				iResumeTimer(timer_hundred_mili);
				iResumeTimer(timer_one_sec);
				iResumeTimer(timer_four_sec);
			}
		}
	}
}

void iSpecialKeyboard(unsigned char key)
{
	if (!pause)
	{
		if (key == GLUT_KEY_LEFT)
		{
			if (intro_level == 1 || show_gift == 1) //Moving character for intro levels.
			{
				if (jumping_height == 0)
				{
					intro_player.condition = 3;
				}

				if (intro_player.x > -34)
				{
					intro_player.x -= 4;
				}

				changeRunningBackImage();
			}

			if (level == 1) //Moving character and background for level one.
			{
				if (jumping_height == 0)
				{
					ground_player.condition = 3;
				}

				if (ground_player.x > -34)
				{
					ground_player.x -= 3;
				}

				player_distance--;

				moveBackgroundBack();
				changeRunningBackImage();
			}

			if (level == 2 && flying_player.x + flying_player.extended_x > 15) //Moves player for level two.
			{
				plane_direction = 1;
			}
		}

		if (key == GLUT_KEY_RIGHT)
		{
			if (intro_level == 1 || show_gift == 1) //Moving character for intro levels.
			{
				if (jumping_height == 0)
				{
					intro_player.condition = 2;
				}

				if (intro_player.x < 1395)
				{
					intro_player.x += 4;
				}

				changeRunningImage();
			}

			if (level == 1) //Moving character and background for level one.
			{
				if (jumping_height == 0)
				{
					ground_player.condition = 2;
				}

				if (ground_player.x < 1485)
				{
					if (ground_player.x < 1100)
					{
						ground_player.x += 3;
					}
					else
					{
						ground_player.x += 8;
					}

					player_distance++;
					//cout << player_distance << endl;

					if (player_distance == 1000 && !magic_stone.taken)
					{
						magic_stone.state = true;
					}
					else if (player_distance == 1520 && !magic_chest.taken)
					{
						magic_chest.state = true;
					}
					else if (player_distance == 1950 && !magic_key.taken)
					{
						magic_key.state = true;
					}
				}
				else
				{
					ground_player.x = -125;
				}

				moveBackground();
				changeRunningImage();
			}

			if (level == 2 && flying_player.x + flying_player.extended_x + flying_player.dimension_x < 1505) //Moves player for level two.
			{
				plane_direction = 2;
			}
		}

		if (key == GLUT_KEY_UP)
		{
			if (intro_level == 1 || show_gift == 1) //Moving character for intro levels.
			{
				if (intro_player.condition <= 3)
				{
					intro_player.condition += 4;
				}

				if (!jump)
				{
					jump = true;
					jumping = true;
				}
			}

			if (level == 1) //Moving character for level one.
			{
				if (ground_player.condition <= 3)
				{
					ground_player.condition += 4;
				}

				if (!jump)
				{
					jump = true;
					jumping = true;
				}
			}

			if (level == 2 && flying_player.y + flying_player.extended_y + flying_player.dimension_y < 777) //Moves player for level two.
			{
				plane_direction = 3;
			}
		}

		if (key == GLUT_KEY_DOWN)
		{
			if (level == 2 && flying_player.y + flying_player.extended_y > 15) //Moves player for level two.
			{
				plane_direction = 4;
			}
		}

		if (key == GLUT_KEY_HOME)
		{
			//Resetting conditions.
			menu_option = 0; //To go to home.
			controlSound(true); //For playing sound.
			sound_playing = false;

			level = 0;
			intro_level = 0;
			show_map = 0;
			show_gift = 0;

			ground_player.score = 0;
			ground_player.health = 100;
			player_distance = 0;
			shield_count = 0;
			active_shield = false;
			gift_taken = false;

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

			game_over = false;
			player_rank = 0;
			game_over_index = 3;
			memset(high_score.name, NULL, sizeof(high_score.name)); //Clearing the name.
			name_index = 0;
		}
	}

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
}

/*________________________________________________________Timer functions._____________________________________________________________*/

void tenMiliSec()
{
	if (intro_level == 1)
	{
		moveStairs();
	}

	if (level == 1)
	{
		changeEnemyPosition();
		changeBombPosition();
	}

	if (level == 1 || level == 2 || explosion)
	{
		changeFire();
	}

	if (level == 2)
	{
		changeBackgroundTwo3();
		changeEnemyPosition2();

		if (plane_direction > 0)
		{
			movePlane();
		}
	}
}

void twentyMiliSec()
{
	if (intro_level == 1 || level == 1 || show_gift == 1)
	{
		Jump();
	}

	if (level == 2)
	{
		changeBackgroundTwo2();
	}
}

void fortyMiliSec()
{
	if (level == 1 || level == 2)
	{
		moveCoin();
	}

	if (level == 2)
	{
		changeBackgroundTwo1();
	}
}

void hundredMiliSec()
{
	if (intro_level == 1 && goblin.state)
	{
		changeGoblinImage();

		if (!cannon_fire)
		{
			cannonFire();
		}
	}
	if (intro_level == 1 || level == 1 || show_gift == 1)
	{
		changeIdleImage();
	}

	if (level == 1 || level == 2)
	{
		shieldPositionChange();
	}

	if (level == 2)
	{
		changePlaneImage();
	}
}

void oneSec()
{
	if (level == 1 || level == 2)
	{
		//bombRandom();
		positionHealthGem2();
	}

	if (intro_level == 2)
	{
		showApple();
	}
}

void fourSec()
{
	if (level == 1 || level == 2)
	{
		positionHealthGem();
	}

	if (level == 2)
	{
		enemyFire();
	}
}

/*_________________________________________________________Main function.______________________________________________________________*/
/***************************************************************************************************************************************/

int main()
{
	timer_ten_mili = iSetTimer(10, tenMiliSec);
	timer_twenty_mili = iSetTimer(20, twentyMiliSec);
	timer_forty_mili = iSetTimer(40, fortyMiliSec);
	timer_hundred_mili = iSetTimer(100, hundredMiliSec);
	timer_one_sec = iSetTimer(1000, oneSec);
	timer_four_sec = iSetTimer(4000, fourSec);

	system("Color 0C"); //For only windows platform.
	cout << "Treasure Guardian is loading! Please, wait!" << endl;

	iInitialize(SCREEN_WIDTH, SCREEN_HIGHT, "TreasureGuardian");

	loadImage();

	controlSound(true); //For playing sound.

	iStart();

	return 0;
}
