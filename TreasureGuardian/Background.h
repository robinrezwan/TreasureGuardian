#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED

//#include "Variables.h"
#include "Enemy.h"

/*________________________________________Level one background moving codes start from here.___________________________________________*/
/***************************************************************************************************************************************/

/*_________________________________________________________Moves background.___________________________________________________________*/

//Function for the inner moving background.
void changeBackgroundOne1()
{
	for (int i = 0; i < 2; i++)
	{
		background_one1_x[i] -= 1; //left slide
		if (background_one1_x[i] + 2512 < 0) //left slide out of frame
			background_one1_x[i] = background_one1_x[(i + 1) % 2] + 2511;
	}
}

//Function for the second inner moving background.
void changeBackgroundOne2()
{
	for (int i = 0; i < 2; i++)
	{
		background_one2_x[i] -= 1; //left slide
		if (background_one2_x[i] + 2512 < 0) //left slide out of frame
			background_one2_x[i] = background_one2_x[(i + 1) % 2] + 2510;
	}
}

//Function for the front moving background.
void changeBackgroundOne3()
{
	for (int i = 0; i < 2; i++)
	{
		background_one3_x[i] -= 2; //left slide
		if (background_one3_x[i] + 2512 < 0) //left slide out of frame
		{
			background_one3_x[i] = background_one3_x[(i + 1) % 2] + 2510;
		}

		//To make the other objects move with the background.
		health_gem1.x -= 1;
		health_gem2.x -= 1;
		shield.x -= 1;

		enemy_one1.x -= 1;
		enemy_one2.x -= 1;
		enemy_one3.x -= 1;

		if (magic_stone.state)
		{
			magic_stone.x -= 1;
		}
		if (magic_chest.state)
		{
			magic_chest.x -= 1;
		}
		if (magic_key.state)
		{
			magic_key.x -= 1;
		}

		bomb_x--;
	}
}

/*______________________________________________________Moves background Back._________________________________________________________*/

//Function to move back the inner background
void changeBackgroundOneBack1()
{
	for (int i = 0; i < 2; i++)
	{
		background_one1_x[i] += 1; //right slide
		if (background_one1_x[i] > 2512) //right slide out of frame
			background_one1_x[i] = background_one1_x[(i + 1) % 2] - 2511;
	}
}

//Function to move back the second inner background.
void changeBackgroundOneBack2()
{
	for (int i = 0; i < 2; i++)
	{
		background_one2_x[i] += 1; //right slide
		if (background_one2_x[i] > 2512) //right slide out of frame
			background_one2_x[i] = background_one2_x[(i + 1) % 2] - 2510;
	}
}

//Function to move back the front background.
void changeBackgroundOneBack3()
{
	for (int i = 0; i < 2; i++)
	{
		background_one3_x[i] += 2; //right slide
		if (background_one3_x[i] > 2512) //right slide out of frame
		{
			background_one3_x[i] = background_one3_x[(i + 1) % 2] - 2510;
		}

		//To make the other objects move with the background.
		health_gem1.x += 1;
		health_gem2.x += 1;
		shield.x += 1;

		enemy_one1.x += 1;
		enemy_one2.x += 1;
		enemy_one3.x += 1;

		if (magic_stone.state)
		{
			magic_stone.x += 1;
		}
		if (magic_chest.state)
		{
			magic_chest.x += 1;
		}
		if (magic_key.state)
		{
			magic_key.x += 1;
		}

		bomb_x++;
	}
}

/*__________________________________________________To move all the three layers.______________________________________________________*/

/*This is the main forward background moving function which will call the other three forward background moving functions.
This will be called from void iSpecialKeyboard() when right key is pressed.*/
void moveBackground()
{
	if (level == 1)
	{
		changeBackgroundOne1();
		for (int i = 0; i < 4; i++)
		{
			changeBackgroundOne2();
		}
		for (int i = 0; i < 6; i++)
		{
			changeBackgroundOne3();
		}
	}
}

/*This is the main backward background moving function which will call the other three backward background moving functions.
This will be called from void iSpecialKeyboard() when left key is pressed.*/
void moveBackgroundBack()
{
	if (level == 1)
	{
		changeBackgroundOneBack1();
		for (int i = 0; i < 4; i++)
		{
			changeBackgroundOneBack2();
		}
		for (int i = 0; i < 6; i++)
		{
			changeBackgroundOneBack3();
		}
	}
}

/*________________________________________________For showing background from iDraw()._________________________________________________*/

void showBackgroundOne()
{
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
}

/*________________________________________Level two background moving codes start from here.___________________________________________*/
/***************************************************************************************************************************************/

//Function for the inner moving background.
void changeBackgroundTwo1()
{
	for (int i = 0; i < 2; i++)
	{
		background_two1_x[i] -= 1; //left slide
		if (background_two1_x[i] + 2512 < 0) //left slide out of frame
			background_two1_x[i] = background_two1_x[(i + 1) % 2] + 2511;
	}
}

//Function for the second inner moving background.
void changeBackgroundTwo2()
{
	for (int i = 0; i < 2; i++)
	{
		background_two2_x[i] -= 1; //left slide
		if (background_two2_x[i] + 2512 < 0) //left slide out of frame
			background_two2_x[i] = background_two2_x[(i + 1) % 2] + 2510;
	}
}

//Function for the front moving background.
void changeBackgroundTwo3()
{
	for (int i = 0; i < 2; i++)
	{
		background_two3_x[i] -= 2; //left slide
		if (background_two3_x[i] + 2512 < 0) //left slide out of frame
		{
			background_two3_x[i] = background_two3_x[(i + 1) % 2] + 2510;
		}

		//health_gem1.x -= 1; //To make the health potion move with the background.
	}
}

/*_______________________________________________For showing background from iDraw().__________________________________________________*/

void showBackground2()
{
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
}

#endif // !BACKGROUND_H_INCLUDED
