#ifndef LEVELONE_H_INCLUDED
#define LEVELONE_H_INCLUDED

/*____________________________________________________Level one codes are here.________________________________________________________*/

//This function runs all the codes for level one.
void levelOne()
{
	//cout << "Level one codes running!" << endl;

	/*_______________________________________________Showing background for level one._________________________________________________*/

	showBackgroundOne();

	/*________________________________________________Showing characters for level one.________________________________________________*/

	showPlayerOne();

	/*__________________________________________________Showing player's firing._______________________________________________________*/

	/*Firing from front.*/
	if (fire && (ground_player.condition == 0 || ground_player.condition == 2 || ground_player.condition == 4 || ground_player.condition == 6))
	{
		iShowImage(bullet_x, ground_player.y + jumping_height + 40, 20, 10, bullet_image);

		if (!pause) //Bullet doesn't move when game is paused.
		{
			bullet_x += 10;
		}

		if (bullet_x > 1520)
		{
			fire = false;
			bullet_x = ground_player.x + 110;
		}

		/*Fire, enemy collision.*/

		if (fire && enemy_one1.state && checkCollision(enemy_one1.x, enemy_one1.y, 190, 135, bullet_x, ground_player.y, 20, 10))
		{
			if (ground_player.condition != 4 && ground_player.condition != 6 && ground_player.condition != 5 && ground_player.condition != 7)
			{
				ground_player.score += 10;
				fire = false;
				enemy_one1.x = 1580 + rand() % 120;
				bullet_x = ground_player.x + 110;
			}
		}

		if (fire && enemy_one2.state && checkCollision(enemy_one2.x, enemy_one2.y, 180, 135, bullet_x, ground_player.y, 20, 10))
		{
			if (ground_player.condition != 4 && ground_player.condition != 6 && ground_player.condition != 5 && ground_player.condition != 7)
			{
				ground_player.score += 10;
				fire = false;
				enemy_one2.x = 1580 + rand() % 420;
				bullet_x = ground_player.x + 110;
			}
		}

		if (fire && enemy_one3.state && checkCollision(enemy_one3.x, enemy_one3.y, 180, 135, bullet_x, ground_player.y, 20, 10))
		{
			if (ground_player.condition != 4 && ground_player.condition != 6 && ground_player.condition != 5 && ground_player.condition != 7)
			{
				ground_player.score += 10;
				fire = false;
				enemy_one3.x = 1580 + rand() % 120;
				bullet_x = ground_player.x + 110;
			}
		}
	}

	/*Firing from back.*/

	if (fire && (ground_player.condition == 1 || ground_player.condition == 3 || ground_player.condition == 5 || ground_player.condition == 7))
	{
		iShowImage(bullet_back_x, ground_player.y + jumping_height + 40, 20, 10, bullet_back_image);

		if (!pause) //Bullet doesn't move when game is paused.
		{
			bullet_back_x -= 10;
		}

		if (bullet_back_x < -20)
		{
			fire = false;
			bullet_back_x = ground_player.x;
		}

		/*Fire, enemy collision.*/

		if (fire && enemy_one1.state && checkCollision(enemy_one1.x, enemy_one1.y, 190, 135, bullet_back_x + 150, ground_player.y, 20, 10))
		{
			if (ground_player.condition != 4 && ground_player.condition != 6 && ground_player.condition != 5 && ground_player.condition != 7)
			{
				ground_player.score += 10;
				fire = false;
				enemy_one1.x = 1580 + rand() % 120;
				bullet_back_x = ground_player.x - 110;
			}
		}

		if (fire && enemy_one2.state && checkCollision(enemy_one2.x, enemy_one2.y, 180, 135, bullet_back_x + 150, ground_player.y, 20, 10))
		{
			if (ground_player.condition != 4 && ground_player.condition != 6 && ground_player.condition != 5 && ground_player.condition != 7)
			{
				ground_player.score += 10;
				fire = false;
				enemy_one2.x = 1580 + rand() % 420;
				bullet_back_x = ground_player.x - 110;
			}
		}

		if (fire && enemy_one3.state && checkCollision(enemy_one3.x, enemy_one3.y, 180, 135, bullet_back_x + 150, ground_player.y, 20, 10))
		{
			if (ground_player.condition != 4 && ground_player.condition != 6 && ground_player.condition != 5 && ground_player.condition != 7)
			{
				ground_player.score += 10;
				fire = false;
				enemy_one3.x = 1580 + rand() % 120;
				bullet_back_x = ground_player.x - 110;
			}
		}
	}

	/*__________________________________Showing health gem, checking collision & counting health score.________________________________*/

	if (health_gem1.x % 2 == 0 || health_gem1.x % 3 == 0)
	{
		if (health_gem1.state)
		{
			iShowImage(health_gem1.x, health_gem1.y, health_gem1.dimension_x, health_gem1.dimension_y, health_gem1.image);

			if (checkCollision(ground_player.x + ground_player.extended_x, ground_player.y + ground_player.extended_y + jumping_height, 80, 130, health_gem1.x, health_gem1.y, health_gem1.dimension_x, health_gem1.dimension_y))
			{
				//cout << "Boom!" << endl;
				if (ground_player.health <= 90)
				{
					ground_player.health += health_gem1.value;
				}

				health_gem1.state = false;
			}
		}
	}

	if (health_gem2.state)
	{
		iShowImage(health_gem2.x, health_gem2.y, health_gem2.dimension_x, health_gem2.dimension_y, health_gem2.image);

		if (checkCollision(ground_player.x + ground_player.extended_x, ground_player.y + ground_player.extended_y + jumping_height, 80, 130, health_gem2.x, health_gem2.y, health_gem2.dimension_x, health_gem2.dimension_y))
		{
			//cout << "Boom!" << endl;
			if (ground_player.health <= 70)
			{
				ground_player.health += health_gem2.value;
			}
			else
			{
				ground_player.health = 100;
			}

			health_gem2.state = false;
		}
	}

	/*___________________________________Showing shield, checking collision & counting shield number.__________________________________*/

	if (shield.state)
	{
		iShowImage(shield.x, shield.y, shield.dimension_x, shield.dimension_y, shield.image);

		if (checkCollision(ground_player.x + ground_player.extended_x, ground_player.y + ground_player.extended_y + jumping_height, 80, 130, shield.x, shield.y, shield.dimension_x, shield.dimension_y))
		{
			//cout << "Boom!" << endl;
			if (shield_count <= 9)
			{
				shield_count++;
			}

			shield.state = false;
		}
	}

	//Showing shield sign.
	if (active_shield)
	{
		iShowImage(ground_player.x + 62, ground_player.y + 26 + jumping_height, 40, 47, shield.image);
	}

	/*_________________________________________________________Showing enemy.__________________________________________________________*/

	showEnemyOne();

	/*_______________________________________________________Showing enemy bomb._______________________________________________________*/

	//if (bomb_random % 2 == 0 && bomb_state)
	{
		//cout << "Bomb is showing!" << endl;
		iShowImage(bomb_x, 75, 60, 70, bomb_image);

		//Bomb player collision.
		if (ground_player.visible && checkCollision(ground_player.x + ground_player.extended_x, ground_player.y + ground_player.extended_y + jumping_height, ground_player.dimension_x, ground_player.dimension_y, bomb_x, 75, 60, 70) && ground_player.condition < 4)
		{
			//cout << "Boom!" << endl;
			if (ground_player.health >= 20)
			{
				if (!active_shield)
				{
					ground_player.health -= 20;
				}
				else
				{
					shield_count--;
					if (shield_count <= 0)
					{
						active_shield = false;
					}
				}
				explosion = true;
			}
			else
			{
				if (!active_shield)
				{
					ground_player.health = 0;
				}
				else
				{
					shield_count--;
					if (shield_count <= 0)
					{
						active_shield = false;
					}
				}
				explosion = true;
			}

			explosion_x = bomb_x - 100;
			//bomb_state = false;
			bomb_x = 1520 + rand() % 3040;
		}
	}

	if (explosion)
	{
		showExplosion(explosion_x, 70);
	}

	/*_________________________________________________Player, Fire and enemy collision._______________________________________________*/

	playerEnemyCollision();

	/*____________________________________________________Showing magic objects._______________________________________________________*/

	//cout << player_distance << endl;

	if (magic_stone.state)
	{
		//cout << "Showing magic stone!" << endl;
		iShowImage(magic_stone.x, magic_stone.y, magic_stone.dimension_x, magic_stone.dimension_y, stone);

		if (ground_player.visible && checkCollision(ground_player.x + ground_player.extended_x, ground_player.y + ground_player.extended_y + jumping_height, 80, 130, magic_stone.x, magic_stone.y, magic_stone.dimension_x, magic_stone.dimension_y))
		{
			//cout << "Boom!" << endl;
			magic_stone.state = false;
			magic_object_gained++;
			magic_stone.taken = true;
		}
	}

	if (magic_chest.state)
	{
		//cout << "Showing magic chest!" << endl;
		iShowImage(magic_chest.x, magic_chest.y, magic_chest.dimension_x, magic_chest.dimension_y, chest);

		if (ground_player.visible && checkCollision(ground_player.x + ground_player.extended_x, ground_player.y + ground_player.extended_y + jumping_height, 80, 130, magic_chest.x, magic_chest.y, magic_chest.dimension_x, magic_chest.dimension_y))
		{
			//cout << "Boom!" << endl;
			magic_chest.state = false;
			magic_object_gained++;
			magic_chest.taken = true;
		}
	}

	if (magic_key.state)
	{
		//cout << "Showing magic key!" << endl;
		iShowImage(magic_key.x, magic_key.y, magic_key.dimension_x, magic_key.dimension_y, key);

		if (ground_player.visible && checkCollision(ground_player.x + ground_player.extended_x, ground_player.y + ground_player.extended_y + jumping_height, 80, 130, magic_key.x, magic_key.y, magic_key.dimension_x, magic_key.dimension_y))
		{
			//cout << "Boom!" << endl;
			magic_key.state = false;
			magic_object_gained++;
			magic_key.taken = true;
		}
	}

	/*___________________________________________Showing score, health and magic object bar.___________________________________________*/

	showNumber(675, 720, 35, ground_player.score);
	iShowImage(590, 703, 80, 80, score_coin[coin_index]);
	iShowImage(40, 720, 252, 50, health_bar[ground_player.health / 10]);
	iShowImage(40, 660, 252, 50, shield_bar[shield_count]);
	iShowImage(40, 600, 252, 50, magic_bar[magic_object_gained]);

	//cout << shield_count << endl;

	/*__________________________________________________________Level change.__________________________________________________________*/

	if (magic_object_gained >= 3)
	{
		//Resetting conditions.
		show_gift = 1;
		level = 0;
		intro_level = 0;
		show_map = 0;

		ground_player.health = 100;
		player_distance = 0;
		shield_count = 0;
		active_shield = false;

		intro_player.x = 160;
		intro_player.y = 30;

		ground_player.x = 160;

		saveGame(); //To save the game progress.
	}
}

#endif // !LEVELONE_H_INCLUDED
