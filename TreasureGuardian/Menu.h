#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "ScoreSave.h"
#include "GameSave.h"
#include "Sound.h"

/*______________________________________________________Menu option selection._________________________________________________________*/

//This function selects which option of the menu is clicked.
void selectMenuOption(int menu_x, int menu_y)
{
	if (menu_option == 0 && !game_over && level != 1 && level != 2)
	{
		if (menu_x >= 552 && menu_x <= 968 && menu_y >= 490 && menu_y <= 547)
		{
			menu_option = 1; //For start menu.
		}

		if (menu_x >= 552 && menu_x <= 968 && menu_y >= 429 && menu_y <= 486)
		{
			menu_option = 2; //For high scores.
		}

		if (menu_x >= 552 && menu_x <= 968 && menu_y >= 368 && menu_y <= 426)
		{
			menu_option = 3; //For instructions.
		}

		if (menu_x >= 552 && menu_x <= 968 && menu_y >= 305 && menu_y <= 364)
		{
			menu_option = 4; //For options.
		}

		if (menu_x >= 552 && menu_x <= 968 && menu_y >= 244 && menu_y <= 302)
		{
			menu_option = 5; //For about.
		}

		if (menu_x >= 552 && menu_x <= 968 && menu_y >= 181 && menu_y <= 240)
		{
			exit(0); //For exit.
		}
	}

	else if (menu_option == 1)
	{
		if (menu_x >= 552 && menu_x <= 968 && menu_y >= 490 && menu_y <= 547)
		{
			intro_level = 1; //For new game.
			menu_option = 6; //To stop running menu codes.

			eraseGame(); //Erasing saved game.

			controlSound(true); //For playing sound.
		}

		if (menu_x >= 552 && menu_x <= 968 && menu_y >= 429 && menu_y <= 486)
		{
			loadGame(); //To continue.

			controlSound(true); //For playing sound.
		}
	}

	if (menu_option >= 1 && menu_option <= 5 && level != 1 && level != 2)
	{
		if (menu_x >= 552 && menu_x <= 968 && menu_y >= 60 && menu_y <= 116)
		{
			menu_option = 0; //To go back.
		}
	}
}

/*________________________________________________________Showing menu pages.__________________________________________________________*/

//This function runs all the codes for menu.
void showMenu()
{
	//cout << "Menu codes running!" << endl;

	iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HIGHT, menu_image[menu_option]); /*Shows all the menu pages from an arry of images.
	The image index changes due to calling int selectOption() from void iMouse().*/

	if (menu_option == 0 && highlight_index <= 5 && highlight_index >= 0)
	{
		iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HIGHT, menu_highlight_image[highlight_index]);
	}

	else if (menu_option == 1 && start_highlight_index <= 1 && start_highlight_index >= 0)
	{
		iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HIGHT, start_highlight_image[start_highlight_index]);
	}

	if (menu_option >= 1 && menu_option <= 5 && back_highlight_index >= 0 && back_highlight_index <= 4)
	{
		iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HIGHT, back_highlight_image[back_highlight_index]);
	}

	if (menu_option == 2) //If the high score page is openned.
	{
		showHighScores(); //Showing the high score list.
	}
}

#endif // !MENU_H_INCLUDED
