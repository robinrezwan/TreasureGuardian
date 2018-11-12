#ifndef INTROLEVELS_H_INCLUDED
#define INTROLEVELS_H_INCLUDED

/*___________________________________________________Structure for intro level one.____________________________________________________*/

struct Stair
{
	int x, y;
	int dimension_x, dimension_y;
	int direction; //Moving left or right.

	Stair()
	{
		;
	}

	Stair(int _x, int _y, int _dimension_x, int _dimension_y, int _direction)
	{
		x = _x;
		y = _y;
		dimension_x = _dimension_x;
		dimension_y = _dimension_y;
		direction = _direction;

	}
} stair1(0, 130, 135, 35, 0), stair2(347, 260, 135, 35, 0), stair3(695, 390, 135, 35, 0), stair4(1042, 520, 135, 35, 0), stair_top(1300, 620, 185, 46, 0);

/*________________________________________________________Moving the stairs.___________________________________________________________*/

//This function moves the stairs back and forth.
void moveStairs()
{
	static int choose_call = 0;

	if (choose_call % 1 == 0)
	{
		if (stair4.direction == 0)
		{
			//Instead of once, these are incremented multiple times for smoothness.
			stair4.x++;
			stair4.x++;

			if (stair4.x >= 1390)
			{
				stair4.direction = 1;
			}

			if (move_intro_player == 4)
			{
				intro_player.x++;
				intro_player.x++;
			}
		}

		else if (stair4.direction == 1)
		{
			stair4.x--;
			stair4.x--;

			if (stair4.x <= 0)
			{
				stair4.direction = 0;
			}

			if (move_intro_player == 4)
			{
				intro_player.x--;
				intro_player.x--;
			}
		}
	}

	if (choose_call % 2 == 0)
	{
		if (stair3.direction == 0)
		{
			stair3.x++;
			stair3.x++;
			stair3.x++;

			if (stair3.x >= 1390)
			{
				stair3.direction = 1;
			}

			if (move_intro_player == 3)
			{
				intro_player.x++;
				intro_player.x++;
				intro_player.x++;
			}
		}

		else if (stair3.direction == 1)
		{
			stair3.x--;
			stair3.x--;
			stair3.x--;

			if (stair3.x <= 0)
			{
				stair3.direction = 0;
			}

			if (move_intro_player == 3)
			{
				intro_player.x--;
				intro_player.x--;
				intro_player.x--;
			}
		}
	}

	if (choose_call % 2 == 0)
	{
		if (stair2.direction == 0)
		{
			stair2.x++;
			stair2.x++;

			if (stair2.x >= 1390)
			{
				stair2.direction = 1;
			}

			if (move_intro_player == 2)
			{
				intro_player.x++;
				intro_player.x++;
			}
		}

		else if (stair2.direction == 1)
		{
			stair2.x--;
			stair2.x--;

			if (stair2.x <= 0)
			{
				stair2.direction = 0;
			}

			if (move_intro_player == 2)
			{
				intro_player.x--;
				intro_player.x--;
			}
		}
	}

	if (choose_call % 2 == 0)
	{
		if (stair1.direction == 0)
		{
			stair1.x++;
			stair1.x++;
			stair1.x++;

			if (stair1.x >= 1390)
			{
				stair1.direction = 1;
			}

			if (move_intro_player == 1)
			{
				intro_player.x++;
				intro_player.x++;
				intro_player.x++;
			}
		}

		else if (stair1.direction == 1)
		{
			stair1.x--;
			stair1.x--;
			stair1.x--;

			if (stair1.x <= 0)
			{
				stair1.direction = 0;
			}

			if (move_intro_player == 1)
			{
				intro_player.x--;
				intro_player.x--;
				intro_player.x--;
			}
		}

	}

	choose_call++;

	if (choose_call >= 2520)
	{
		choose_call = 0;
	}
}

/*_____________________________________________Showing character for intro level one.__________________________________________________*/

void showIntroPlayer()
{
	if (intro_player.condition == 0) //If standing.
	{
		iShowImage(intro_player.x, intro_player.y, 160, 160, ground_player.image_idle[player_idle_index]); /*Showing idle images from an array.
		The image index is being changed by calling void changeIdleImage() from a timer when no key is pressed.*/
	}

	else if (intro_player.condition == 1) //If standing backward.
	{
		iShowImage(intro_player.x, intro_player.y, 160, 160, ground_player.image_idleback[player_idleback_index]); /*Showing backward idle images from an array.
		The image index is being changed by calling void changeIdleImage() from a timer when no key is pressed.*/
	}

	else if (intro_player.condition == 2) //If running.
	{
		iShowImage(intro_player.x, intro_player.y, 160, 160, ground_player.image_running[player_running_index]); /*Showing running images from an array.
		The image index is being changed by calling void changeRunningImage() from void iSpecialKeyboard() when no right key is pressed.*/

		intro_player.condition_changer++;
		if (intro_player.condition_changer >= 200)
		{
			intro_player.condition_changer = 0;
			intro_player.condition = 0;
		}
	}

	else if (intro_player.condition == 3) //If running backward.
	{
		iShowImage(intro_player.x, intro_player.y, 160, 160, ground_player.image_runningback[player_runningback_index]); /*Showing running backward images from an array.
		The image index is being changed by calling void changeRunningBackImage() from void iSpecialKeyboard() when left key is pressed.*/

		intro_player.condition_changer++;
		if (intro_player.condition_changer >= 200)
		{
			intro_player.condition_changer = 0;
			intro_player.condition = 1;
		}
	}

	else if (intro_player.condition == 4 || intro_player.condition == 6) //If jumping.
	{
		iShowImage(intro_player.x, intro_player.y + jumping_height, 160, 160, ground_player.image_jumping[player_jumping_index]); /*Showing jumping images from an array.
		The image index is being changed by calling void Jump() from void iSpecialKeyboard() when up key is pressed.*/

		/*if (jumping_height <= 0)
		{
			intro_player.condition = 0;
		}*/
	}

	else if (intro_player.condition == 5 || intro_player.condition == 7) //If jumping back.
	{
		iShowImage(intro_player.x, intro_player.y + jumping_height, 160, 160, ground_player.image_jumpingback[player_jumping_index]); /*Showing jumping back images from an array.
		The image index is being changed by calling void Jump() from void iSpecialKeyboard() when up key is pressed.*/

		/*if (jumping_height <= 0)
		{
			intro_player.condition = 1;
		}*/
	}
}

/*__________________________________________________Intro level one codes are here.____________________________________________________*/

void introLevelOne()
{
	iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HIGHT, intro_one_background);
	iShowImage(stair1.x, stair1.y, stair1.dimension_x, stair1.dimension_y, stair);
	iShowImage(stair2.x, stair2.y, stair2.dimension_x, stair2.dimension_y, stair);
	iShowImage(stair3.x, stair3.y, stair3.dimension_x, stair3.dimension_y, stair);
	iShowImage(stair4.x, stair4.y, stair4.dimension_x, stair4.dimension_y, stair);

	iShowImage(stair_top.x, stair_top.y, stair_top.dimension_x, stair_top.dimension_y + 128, stair_top_map);

	if (intro_player.x + intro_player.extended_x + 35 >= stair1.x && intro_player.x + intro_player.extended_x + intro_player.dimension_x - 35 <= stair1.x + stair1.dimension_x && intro_player.y + intro_player.extended_y + jumping_height <= stair1.y + stair1.dimension_y + 10 && intro_player.y + intro_player.extended_y + jumping_height >= stair1.y + stair1.dimension_y - 10)
	{
		if (jump && !jumping /*&& falling_down*/)
		{
			//cout << "Stepped on stair." << endl;
			//cout << intro_player.y + intro_player.extended_y + jumping_height << "\t" << stair1.y + stair1.dimension_y << endl;
			intro_player.y = stair1.y + stair1.dimension_y - 4;
			move_intro_player = 1;
			jump = false;
			jumping_height = 0;
			player_jumping_index = 0;
			//falling_down = false;
		}
	}

	else if (intro_player.x + intro_player.extended_x + 35 >= stair2.x && intro_player.x + intro_player.extended_x + intro_player.dimension_x - 35 <= stair2.x + stair2.dimension_x && intro_player.y + intro_player.extended_y + jumping_height <= stair2.y + stair2.dimension_y + 10 && intro_player.y + intro_player.extended_y + jumping_height >= stair2.y + stair2.dimension_y - 10)
	{
		if (jump && !jumping /*&& falling_down*/)
		{
			//cout << "Stepped on stair." << endl;
			//cout << intro_player.y + intro_player.extended_y + jumping_height << "\t" << stair2.y + stair2.dimension_y << endl;
			intro_player.y = stair2.y + stair2.dimension_y - 4;
			move_intro_player = 2;
			jump = false;
			jumping_height = 0;
			player_jumping_index = 0;
			//falling_down = false;
		}
	}

	else if (intro_player.x + intro_player.extended_x + 35 >= stair3.x && intro_player.x + intro_player.extended_x + intro_player.dimension_x - 35 <= stair3.x + stair3.dimension_x && intro_player.y + intro_player.extended_y + jumping_height <= stair3.y + stair3.dimension_y + 10 && intro_player.y + intro_player.extended_y + jumping_height >= stair3.y + stair3.dimension_y - 10)
	{
		if (jump && !jumping /*&& falling_down*/)
		{
			//cout << "Stepped on stair." << endl;
			//cout << intro_player.y + intro_player.extended_y + jumping_height << "\t" << stair3.y + stair3.dimension_y << endl;
			intro_player.y = stair3.y + stair3.dimension_y - 4;
			move_intro_player = 3;
			jump = false;
			jumping_height = 0;
			player_jumping_index = 0;
			//falling_down = false;
		}
	}

	else if (intro_player.x + intro_player.extended_x + 35 >= stair4.x && intro_player.x + intro_player.extended_x + intro_player.dimension_x - 35 <= stair4.x + stair4.dimension_x && intro_player.y + intro_player.extended_y + jumping_height <= stair4.y + stair4.dimension_y + 10 && intro_player.y + intro_player.extended_y + jumping_height >= stair4.y + stair4.dimension_y - 10)
	{
		if (jump && !jumping /*&& falling_down*/)
		{
			//cout << "Stepped on stair." << endl;
			//cout << intro_player.y + intro_player.extended_y + jumping_height << "\t" << stair4.y + stair4.dimension_y << endl;
			intro_player.y = stair4.y + stair4.dimension_y - 4;
			move_intro_player = 4;
			jump = false;
			jumping_height = 0;
			player_jumping_index = 0;
			//falling_down = false;
		}
	}

	else if (intro_player.x + intro_player.extended_x + 35 >= stair_top.x && intro_player.x + intro_player.extended_x + intro_player.dimension_x - 35 <= stair_top.x + stair_top.dimension_x && intro_player.y + intro_player.extended_y + jumping_height <= stair_top.y + stair_top.dimension_y + 10 && intro_player.y + intro_player.extended_y + jumping_height >= stair_top.y + stair_top.dimension_y - 10)
	{
		if (jump && !jumping /*&& falling_down*/)
		{
			//cout << "Stepped on stair." << endl;
			//cout << intro_player.y + intro_player.extended_y + jumping_height << "\t" << stair_top.y + stair_top.dimension_y << endl;
			intro_player.y = stair_top.y + stair_top.dimension_y - 4;
			jump = false;
			jumping_height = 0;
			player_jumping_index = 0;
			//falling_down = false;
		}
	}

	else if (!jumping)
	{
		//cout << "Falling." << endl;
		//falling_down = true;
		if (intro_player.y > 30)
		{
			intro_player.y -= 0.2;
		}
		move_intro_player = 0;
	}

	/*____________________________________________Showing goblin with cannon guarding the map._________________________________________*/

	if (goblin.state)
	{
		iShowImage(goblin.x, goblin.y, 120, 120, goblin.image[goblin.index]);

		//Cannon firing.
		iShowImage(fireball_x, 700, 16, 16, fireball);

		if (!pause) //Fireball doesn't move when game is paused.
		{
			fireball_x -= 2;
		}

		if (fireball_x < -16)
		{
			cannon_fire = false;
		}

		iShowImage(1380, 662, 90, 60, cannon);

		//Player, cannon-fire collision.
		if (checkCollision(intro_player.x + intro_player.extended_x, intro_player.y + intro_player.extended_y + jumping_height, intro_player.dimension_x, intro_player.dimension_y, fireball_x, 700, 16, 16))
		{
			cannon_fire = false;
			game_over = true;
		}

		//Showing goblin's health.
		iSetColor(255, 0, 0);
		iFilledRectangle(1330, 770, 3 * goblin.value, 10);
		iSetColor(0, 0, 0);
		iRectangle(1330, 770, 72, 10);
	}

	/*__________________________________________________Showing player's firing._______________________________________________________*/

	/*Firing from front.*/
	if (fire && (intro_player.condition == 0 || intro_player.condition == 2 || intro_player.condition == 4 || intro_player.condition == 6))
	{
		iShowImage(bullet_x, intro_player.y + jumping_height + 40, 20, 10, bullet_image);

		if (!pause) //Bullet doesn't move when game is paused.
		{
			bullet_x += 10;
		}

		if (bullet_x > 1520)
		{
			fire = false;
			bullet_x = intro_player.x + 110;
		}

		/*Fire, goblin collision.*/

		if (fire && goblin.state && checkCollision(goblin.x, goblin.y, 120, 120, bullet_x, intro_player.y + jumping_height + 40, 20, 10))
		{
			//cout << "Boom!" << endl;
			fire = false;
			bullet_x = ground_player.x + 110;

			goblin.value -= 8;
			if (goblin.value <= 0)
			{
				goblin.state = false;
			}
		}
	}

	/*Firing from back.*/

	if (fire && (intro_player.condition == 1 || intro_player.condition == 3 || intro_player.condition == 5 || intro_player.condition == 7))
	{
		iShowImage(bullet_back_x, intro_player.y + jumping_height + 40, 20, 10, bullet_back_image);

		if (!pause) //Bullet doesn't move when game is paused.
		{
			bullet_back_x -= 10;
		}

		if (bullet_back_x < -20)
		{
			fire = false;
			bullet_back_x = intro_player.x;
		}
	}

	//Showing intro player.
	showIntroPlayer();
}

/*__________________________________________________Intro level two codes are here.____________________________________________________*/

void introLevelTwo()
{
	iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HIGHT, intro_two_background);
	iShowImage(mouse_x, mouse_y, 40, 40, ring);

	if (show_apple % 3 == 0)
	{
		iShowImage(294, 560, 30, 33, apple[apple_index1]);

		if (new_number)
		{
			if (checkCollision(294, 560, 30, 33, mouse_x + 15, mouse_y + 15, 10, 10))
			{
				if (apple_index1 == 1)
				{
					apple_count++;
				}
				else if (apple_index1 == 0 && apple_count > 0)
				{
					apple_count--;
				}
				new_number = false;
			}
		}
	}
	if (show_apple % 5 == 0)
	{
		iShowImage(122, 340, 30, 33, apple[apple_index2]);

		if (new_number)
		{
			if (checkCollision(122, 340, 30, 33, mouse_x + 15, mouse_y + 15, 10, 10))
			{
				if (apple_index2 == 1)
				{
					apple_count++;
				}
				else if (apple_index2 == 0 && apple_count > 0)
				{
					apple_count--;
				}
				new_number = false;
			}
		}
	}
	if (show_apple % 7 == 0)
	{
		iShowImage(838, 620, 30, 33, apple[apple_index3]);

		if (new_number)
		{
			if (checkCollision(838, 620, 30, 33, mouse_x + 15, mouse_y + 15, 10, 10))
			{
				if (apple_index3 == 1)
				{
					apple_count++;
				}
				else if (apple_index3 == 0 && apple_count > 0)
				{
					apple_count--;
				}
				new_number = false;
			}
		}
	}
	if (show_apple % 11 == 0)
	{
		iShowImage(774, 570, 30, 33, apple[apple_index4]);

		if (new_number)
		{
			if (checkCollision(774, 570, 30, 33, mouse_x + 15, mouse_y + 15, 10, 10))
			{
				if (apple_index4 == 1)
				{
					apple_count++;
				}
				else if (apple_index4 == 0 && apple_count > 0)
				{
					apple_count--;
				}
				new_number = false;
			}
		}
	}
	if (show_apple % 13 == 0)
	{
		iShowImage(634, 440, 30, 33, apple[apple_index5]);

		if (new_number)
		{
			if (checkCollision(634, 440, 30, 33, mouse_x + 15, mouse_y + 15, 10, 10))
			{
				if (apple_index5 == 1)
				{
					apple_count++;
				}
				else if (apple_index5 == 0 && apple_count > 0)
				{
					apple_count--;
				}
				new_number = false;
			}
		}
	}
	if (show_apple % 17 == 0)
	{
		iShowImage(514, 200, 30, 33, apple[apple_index6]);

		if (new_number)
		{
			if (checkCollision(514, 200, 30, 33, mouse_x + 15, mouse_y + 15, 10, 10))
			{
				if (apple_index6 == 1)
				{
					apple_count++;
				}
				else if (apple_index6 == 0 && apple_count > 0)
				{
					apple_count--;
				}
				new_number = false;
			}
		}
	}
	if (show_apple % 19 == 0)
	{
		iShowImage(366, 480, 30, 33, apple[apple_index7]);

		if (new_number)
		{
			if (checkCollision(366, 480, 30, 33, mouse_x + 15, mouse_y + 15, 10, 10))
			{
				if (apple_index7 == 1)
				{
					apple_count++;
				}
				else if (apple_index7 == 0 && apple_count > 0)
				{
					apple_count--;
				}
				new_number = false;
			}
		}
	}
	if (show_apple % 23 == 0)
	{
		iShowImage(441, 555, 30, 33, apple[apple_index8]);

		if (new_number)
		{
			if (checkCollision(441, 555, 30, 33, mouse_x + 15, mouse_y + 15, 10, 10))
			{
				if (apple_index8 == 1)
				{
					apple_count++;
				}
				else if (apple_index8 == 0 && apple_count > 0)
				{
					apple_count--;
				}
				new_number = false;
			}
		}
	}
	if (show_apple % 29 == 0)
	{
		iShowImage(510, 525, 30, 33, apple[apple_index9]);

		if (new_number)
		{
			if (checkCollision(510, 525, 30, 33, mouse_x + 15, mouse_y + 15, 10, 10))
			{
				if (apple_index9 == 1)
				{
					apple_count++;
				}
				else if (apple_index9 == 0 && apple_count > 0)
				{
					apple_count--;
				}
				new_number = false;
			}
		}
	}
	if (show_apple % 31 == 0)
	{
		iShowImage(353, 420, 30, 33, apple[apple_index10]);

		if (new_number)
		{
			if (checkCollision(353, 420, 30, 33, mouse_x + 15, mouse_y + 15, 10, 10))
			{
				if (apple_index10 == 1)
				{
					apple_count++;
				}
				else if (apple_index10 == 0 && apple_count > 0)
				{
					apple_count--;
				}
				new_number = false;
			}
		}
	}
	if (show_apple % 37 == 0)
	{
		iShowImage(714, 455, 30, 33, apple[apple_index11]);

		if (new_number)
		{
			if (checkCollision(714, 455, 30, 33, mouse_x + 15, mouse_y + 15, 10, 10))
			{
				if (apple_index11 == 1)
				{
					apple_count++;
				}
				else if (apple_index11 == 0 && apple_count > 0)
				{
					apple_count--;
				}
				new_number = false;
			}
		}
	}

	/*_______________________________________________Showing number of apples collected._______________________________________________*/

	/*iSetColor(255, 0, 0);
	iText(50, 730, "Apples: ", GLUT_BITMAP_HELVETICA_18);
	sprintf(apple_string, "%d", apple_count);
	iText(120, 730, apple_string, GLUT_BITMAP_HELVETICA_18);*/

	showNumber(675, 720, 35, apple_count);
	iShowImage(595, 715, 60, 64, apple[1]);

	/*__________________________________________________________Level change.__________________________________________________________*/

	if (apple_count >= 20)
	{
		show_map = 2;
		intro_level = 0;
		apple_count = 0;

		saveGame(); //To save the game progress.
	}
}

/*_______________________________________________________Other intro level functions.__________________________________________________*/

//Changing goblin image index.
void changeGoblinImage()
{
	if (goblin.index >= 7)
	{
		goblin.index = 0;
	}
	else
	{
		goblin.index++;
	}
}

//Cannon fire condition.
void cannonFire()
{
	static int choose_call = 0;

	if (choose_call % 5 == 0)
	{
		fireball_x = 1420;
		cannon_fire = true;

		if (goblin.value < 24)
		{
			goblin.value++;
		}
	}

	choose_call++;

	if (choose_call >= 50)
	{
		choose_call = 0;
	}
}

//Apple showing condition.
void showApple()
{
	/*static int choose_call = 0;

	if (choose_call % 9 == 0)*/
	{
		show_apple = rand() % 10000;

		if ((rand() % 1000) % 2 == 0)
		{
			apple_index1 = 1;
		}
		else
		{
			apple_index1 = 0;
		}

		if ((rand() % 1000) % 2 == 0)
		{
			apple_index2 = 0;
		}
		else
		{
			apple_index2 = 1;
		}

		if ((rand() % 1000) % 2 == 0)
		{
			apple_index3 = 1;
		}
		else
		{
			apple_index3 = 0;
		}

		if ((rand() % 1000) % 2 == 0)
		{
			apple_index4 = 0;
		}
		else
		{
			apple_index4 = 1;
		}

		if ((rand() % 1000) % 2 == 0)
		{
			apple_index5 = 1;
		}
		else
		{
			apple_index5 = 0;
		}

		if ((rand() % 1000) % 2 == 0)
		{
			apple_index6 = 0;
		}
		else
		{
			apple_index6 = 1;
		}

		if ((rand() % 1000) % 2 == 0)
		{
			apple_index7 = 1;
		}
		else
		{
			apple_index7 = 0;
		}

		if ((rand() % 1000) % 2 == 0)
		{
			apple_index8 = 0;
		}
		else
		{
			apple_index8 = 1;
		}

		if ((rand() % 1000) % 2 == 0)
		{
			apple_index9 = 1;
		}
		else
		{
			apple_index9 = 0;
		}

		if ((rand() % 1000) % 2 == 0)
		{
			apple_index10 = 0;
		}
		else
		{
			apple_index10 = 1;
		}

		if ((rand() % 1000) % 2 == 0)
		{
			apple_index11 = 1;
		}
		else
		{
			apple_index11 = 0;
		}


		new_number = true;
	}

	/*choose_call++;

	if (choose_call >= 180)
	{
		choose_call = 0;
	}*/
}

#endif // !INTROLEVELS_H_INCLUDED
