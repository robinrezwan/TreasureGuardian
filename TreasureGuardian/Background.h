#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED

//#include "Variables.h"
#include "Enemy.h"

/*________________________________________Level one background moving codes start from here.____________________________________________*/
/****************************************************************************************************************************************/

/*_________________________________________________________Moves background._____________________________________________________________*/

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

		life_gem1.x -= 1; //To make the life potion move with the background.
		enemy1.x -= 1;
		enemy2.x -= 1;
		enemy3.x -= 1;
		enemy4.x -= 1;
	}
}

/*______________________________________________________Moves background Back._________________________________________________________*/

//Function to move back the inner background
void changeBackgroundOneBack1()
{
	for (int i = 0; i < 2; i++)
	{
		background_one1_x[i] += 1; //left slide
		if (background_one1_x[i] > 2512) //left slide out of frame
			background_one1_x[i] = background_one1_x[(i + 1) % 2] - 2511;
	}
}

//Function to move back the second inner background.
void changeBackgroundOneBack2()
{
	for (int i = 0; i < 2; i++)
	{
		background_one2_x[i] += 1; //left slide
		if (background_one2_x[i] > 2512) //left slide out of frame
			background_one2_x[i] = background_one2_x[(i + 1) % 2] - 2510;
	}
}

//Function to move back the front background.
void changeBackgroundOneBack3()
{
	for (int i = 0; i < 2; i++)
	{
		background_one3_x[i] += 2; //left slide
		if (background_one3_x[i] > 2512) //left slide out of frame
		{
			background_one3_x[i] = background_one3_x[(i + 1) % 2] - 2510;
		}

		life_gem1.x += 1; //To make the life potion move with the background.
		enemy1.x += 1;
		enemy2.x += 1;
		enemy3.x += 1;
		enemy4.x += 1;
	}
}

/*___________________________________________________To move all the three layers.__________________________________________________________*/

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

/*________________________________________Level two background moving codes start from here.____________________________________________*/
/****************************************************************************************************************************************/

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

		//life_gem1.x -= 1; //To make the life potion move with the background.
	}
}



#endif // !BACKGROUND_H_INCLUDED
