#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "Score.h"

/*______________________________________________________Menu option selection._________________________________________________________*/

//This function selects which option of the menu is clicked.
int selectMenuOption(int menu_option, int menu_x, int menu_y)
{
	if (menu_option == 0 && !game_over && level != 1 && level != 2)
	{
		if (menu_x >= 537 && menu_x <= 952 && menu_y >= 490 && menu_y <= 547)
		{
			menu_option = 1; //For level one.
		}

		if (menu_x >= 537 && menu_x <= 952 && menu_y >= 429 && menu_y <= 486)
		{
			menu_option = 2; //Fore high scores.
		}

		if (menu_x >= 537 && menu_x <= 952 && menu_y >= 368 && menu_y <= 426)
		{
			menu_option = 3; //For instructions.
		}

		if (menu_x >= 537 && menu_x <= 952 && menu_y >= 305 && menu_y <= 364)
		{
			menu_option = 4; //For options.
		}

		if (menu_x >= 537 && menu_x <= 952 && menu_y >= 244 && menu_y <= 302)
		{
			menu_option = 5; //For about.
		}

		if (menu_x >= 537 && menu_x <= 952 && menu_y >= 181 && menu_y <= 240)
		{
			exit(0); //For exit.
		}
	}

	else if (menu_option > 1 && menu_option <= 5 && level != 1 && level != 2)
	{
		if (menu_x >= 547 && menu_x <= 968 && menu_y >= 60 && menu_y <= 116)
		{
			menu_option = 0; //To go back.
		}
	}

	return menu_option;
}

/*________________________________________________________Showing menu pages.__________________________________________________________*/

//This function runs all the codes for menu.
void showMenu()
{
	//cout << "Menu codes running!" << endl;

	iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HIGHT, menu_image[menu_option]); /*Shows all the menu pages from an arry of images.
	The image index changes due to calling int selectOption() from void iMouse().*/

	if (menu_option == 0 && menu_highlight <= 5 && menu_highlight >= 0)
	{
		iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HIGHT, highlight_image[menu_highlight]);
	}

	if (menu_option == 2) //If the high score page is openned.
	{
		showHighScores(); //Showing the high score list.
	}
}

#endif // !MENU_H_INCLUDED
