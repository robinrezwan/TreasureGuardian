#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#include "Variables.h"

/*______________________________________________Changing character images for level one._______________________________________________*/
/***************************************************************************************************************************************/

//Function for changing the index of player’s image in idle condition where multiple images are stored in an array.
void changeIdleImage() //When standing or standing backward.
{
	player_idle_index++; //Player’s idle image index while facing right side.

	if (player_idle_index > 11)
	{
		player_idle_index = 0;
	}

	player_idleback_index++; //Player’s idle image index while facing left side.

	if (player_idleback_index > 11)
	{
		player_idleback_index = 0;
	}
}

//Function for for changing the index of player’s image in running condition(to right side) where multiple images are stored in an array.
void changeRunningImage()
{
	static int change = 0;

	if (change % 3 == 0)
	{
		player_running_index++;
	}

	if (player_running_index > 7)
	{
		player_running_index = 0;
	}

	change++;

	if (change >= 30)
	{
		change = 0;
	}
}

//Function for for changing the index of player’s image in running condition(to left side) where multiple images are stored in an array.
void changeRunningBackImage()
{
	static int change = 0;

	if (change % 3 == 0)
	{
		player_runningback_index++;
	}

	if (player_runningback_index > 7)
	{
		player_runningback_index = 0;
	}

	change++;

	if (change >= 30)
	{
		change = 0;
	}
}

/*____________________________________Funtion for jumping up and coming down. Called from a timer._____________________________________*/

//Function for jumping. This will be called from void iSpecialKeyboard() when up key is pressed.
void Jump()
{
	if (jump) //It is true while the player is already in a jump and turned false when he touches the ground.
	{
		if (jumping) //While jumping is true (when the up key is pressed). It will be false when the player reaches his maximum jump height.
		{
			jumping_height += 5;

			if (jumping_height >= JUMPLIMIT)
			{
				jumping = false; //The player has reached his maximum jump height.
			}

			if (player_jumping_index < 7) //When jumping up.
			{
				player_jumping_index++;
			}
		}
		else //This is for when player his falling down from his maximum jump height.
		{
			jumping_height -= 5;

			if (jumping_height <= 0)
			{
				jump = false; //Player has come down to the ground.
				jumping_height = 0;

				if (ground_player.condition == 4 || ground_player.condition == 6)
				{
					ground_player.condition = 0;
					intro_player.condition = 0;
				}
				else if (ground_player.condition == 5 || ground_player.condition == 7)
				{
					ground_player.condition = 1;
					intro_player.condition = 1;
				}
			}

			if (player_jumping_index > 0) //When coming down.
			{
				player_jumping_index--;
			}
		}
	}
}

/*________________________________________________For showing character from iDraw().__________________________________________________*/

void showPlayerOne()
{
	if (ground_player.condition == 0) //If standing.
	{
		iShowImage(ground_player.x, ground_player.y, 160, 160, ground_player.image_idle[player_idle_index]); /*Showing idle images from an array.
		The image index is being changed by calling void changeIdleImage() from a timer when no key is pressed.*/
	}

	else if (ground_player.condition == 1) //If standing backward.
	{
		iShowImage(ground_player.x, ground_player.y, 160, 160, ground_player.image_idleback[player_idleback_index]); /*Showing backward idle images from an array.
		The image index is being changed by calling void changeIdleImage() from a timer when no key is pressed.*/
	}

	else if (ground_player.condition == 2) //If running.
	{
		iShowImage(ground_player.x, ground_player.y, 160, 160, ground_player.image_running[player_running_index]); /*Showing running images from an array.
		The image index is being changed by calling void changeRunningImage() from void iSpecialKeyboard() when no right key is pressed.*/

		ground_player.condition_changer++;
		if (ground_player.condition_changer >= 200)
		{
			ground_player.condition_changer = 0;
			ground_player.condition = 0;
		}
	}

	else if (ground_player.condition == 3) //If running backward.
	{
		iShowImage(ground_player.x, ground_player.y, 160, 160, ground_player.image_runningback[player_runningback_index]); /*Showing running backward images from an array.
		The image index is being changed by calling void changeRunningBackImage() from void iSpecialKeyboard() when left key is pressed.*/

		ground_player.condition_changer++;
		if (ground_player.condition_changer >= 200)
		{
			ground_player.condition_changer = 0;
			ground_player.condition = 1;
		}
	}

	else if (ground_player.condition == 4 || ground_player.condition == 6) //If jumping.
	{
		iShowImage(ground_player.x, ground_player.y + jumping_height, 160, 160, ground_player.image_jumping[player_jumping_index]); /*Showing jumping images from an array.
		The image index is being changed by calling void Jump() from void iSpecialKeyboard() when up key is pressed.*/
	}

	else if (ground_player.condition == 5 || ground_player.condition == 7) //If jumping back.
	{
		iShowImage(ground_player.x, ground_player.y + jumping_height, 160, 160, ground_player.image_jumpingback[player_jumping_index]); /*Showing jumping back images from an array.
		The image index is being changed by calling void Jump() from void iSpecialKeyboard() when up key is pressed.*/
	}

	//If the player is on the screen.
	if (ground_player.x >= 40 && ground_player.x <= 1360)
	{
		ground_player.visible = true;
	}
	else
	{
		ground_player.visible = false;
	}
}

/*_______________________________________________Changing character images for level two.______________________________________________*/
/***************************************************************************************************************************************/

//Changes plane image index.
void changePlaneImage()
{
	player_plane_index++;

	if (player_plane_index > 7)
	{
		player_plane_index = 0;
	}
}

void movePlane()
{
	static int call = 0;

	if (plane_direction == 1)
	{
		if (flying_player.x + flying_player.extended_x >= 3)
		{
			flying_player.x -= 4;
		}
	}
	if (plane_direction == 2)
	{
		if (flying_player.x + flying_player.extended_x + flying_player.dimension_x <= 1517)
		{
			flying_player.x += 4;
		}
	}
	if (plane_direction == 3)
	{
		if (flying_player.y + flying_player.extended_y + flying_player.dimension_y <= 789)
		{
			flying_player.y += 4;
		}
	}
	if (plane_direction == 4)
	{
		if (flying_player.y + flying_player.extended_y >= 3)
		{
			flying_player.y -= 4;
		}
	}

	call++;

	if (call >= 75)
	{
		plane_direction = 0;
		call = 0;
	}
}

#endif // !CHARACTER_H_INCLUDED
