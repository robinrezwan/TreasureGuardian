#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

//#include "Variables.h"

int selectOption(int menu_option, int menu_x, int menu_y)
{
	if (/*!(menu_option >= 1 && menu_option <= 6)*/ menu_option == 0 && !game_over)
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

	else if (menu_option >= 1 && menu_option <= 5)
	{
		if (menu_x >= 547 && menu_x <= 968 && menu_y >= 60 && menu_y <= 116)
		{
			menu_option = 0; //To go back.
		}
	}

	/*else if (menu_option == 6)
	{
		
	}*/

	return menu_option;
}

#endif // !MENU_H_INCLUDED
