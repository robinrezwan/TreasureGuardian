#ifndef LEVELTWO_H_INCLUDED
#define LEVELTWO_H_INCLUDED

/*____________________________________________________Level two codes are here.________________________________________________________*/

//This function runs all the codes for level two.
void levelTwo()
{
	//cout << "Level two codes running!" << endl;

	/*________________________________________________Showing background for level two.________________________________________________*/

	showBackground2();

	/*________________________________________________Showing characters for level two.________________________________________________*/

	iShowImage(flying_player.x, flying_player.y, 216, 180, flying_player.image_plane[player_plane_index]);

	/*__________________________________Showing health gem, checking collision & counting health score.________________________________*/

	if (health_gem1.x % 2 == 0 || health_gem1.x % 3 == 0)
	{
		if (health_gem1.state)
		{
			iShowImage(health_gem1.x, health_gem1.y, health_gem1.dimension_x, health_gem1.dimension_y, health_gem1.image);

			if (checkCollision(flying_player.x + flying_player.extended_x, flying_player.y + flying_player.extended_y, flying_player.dimension_x, flying_player.dimension_y, health_gem1.x, health_gem1.y, 40, 43))
			{
				//cout << "Boom!" << endl;

				health_gem1.state = false;

				if (ground_player.health <= 90)
				{
					ground_player.health += 10;
				}
			}
		}
	}

	if (health_gem2.state)
	{
		iShowImage(health_gem2.x, health_gem2.y, health_gem2.dimension_x, health_gem2.dimension_y, health_gem2.image);

		if (checkCollision(flying_player.x + flying_player.extended_x, flying_player.y + flying_player.extended_y, flying_player.dimension_x, flying_player.dimension_y, health_gem2.x, health_gem2.y, health_gem2.dimension_x, health_gem2.dimension_y))
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

		if (checkCollision(flying_player.x + flying_player.extended_x, flying_player.y + flying_player.extended_y, flying_player.dimension_x, flying_player.dimension_y, shield.x, shield.y, shield.dimension_x, shield.dimension_y))
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
		iShowImage(flying_player.x + 82, flying_player.y + 48, 50, 59, shield.image);
	}

	/*__________________________________________________Showing player's firing._______________________________________________________*/

	if (fire)
	{
		bullet_y = flying_player.y + 63;
		iShowImage(bullet_x, bullet_y, 20, 10, bullet_image);

		if (!pause) //Bullet doesn't move when game is paused.
		{
			bullet_x += 10;
		}

		if (bullet_x > 1520)
		{
			fire = false;
			bullet_x = flying_player.x + 120;
		}

		fireEnemyCollision2();
	}

	/*___________________________________________________Showing enemy for level two.__________________________________________________*/

	showEnemyTwo();

	/*_________________________________________________Player, Fire and enemy collision._______________________________________________*/

	playerEnemyCollision2();

	/*___________________________________________________Anti-firing and collision.____________________________________________________*/

	//For enemy one.
	if (antifire % 3 != 0 && enemy_two1.state)
	{
		//cout << "Enemy one firing!" << endl;
		if (enemybullethit1)
		{
			iShowImage(antibullet1_x, enemy_two1.y + 20, 20, 10, bullet_back_image);

			if (!pause) //Bullet doesn't move when game is paused.
			{
				antibullet1_x -= 2;
			}

			//Player, enemy-fire collision.
			if (checkCollision(flying_player.x + flying_player.extended_x, flying_player.y + flying_player.extended_y, flying_player.dimension_x, flying_player.dimension_y, antibullet1_x, enemy_two1.y + 20, 20, 10))
			{
				if (!active_shield)
				{
					ground_player.health -= 10;
				}
				else
				{
					shield_count--;
					if (shield_count <= 0)
					{
						active_shield = false;
					}
				}
				enemybullethit1 = false;
			}
		}

		if (antibullet1_x <= 0)
		{
			enemybullethit1 = false;
			antibullet1_x = enemy_two1.x + 10;
		}
	}

	//For enemy two.
	if (antifire % 4 != 0 && enemy_two2.state)
	{
		//cout << "Enemy two firing!" << endl;
		if (enemybullethit2)
		{
			iShowImage(antibullet2_x, enemy_two2.y + 20, 20, 10, bullet_back_image);

			if (!pause) //Bullet doesn't move when game is paused.
			{
				antibullet2_x -= 2;
			}

			//Player, enemy-fire collision.
			if (checkCollision(flying_player.x + flying_player.extended_x, flying_player.y + flying_player.extended_y, flying_player.dimension_x, flying_player.dimension_y, antibullet2_x, enemy_two2.y + 20, 20, 10))
			{
				if (!active_shield)
				{
					ground_player.health -= 10;
				}
				else
				{
					shield_count--;
					if (shield_count <= 0)
					{
						active_shield = false;
					}
				}
				enemybullethit2 = false;
			}
		}

		if (antibullet2_x <= 0)
		{
			enemybullethit2 = false;
			antibullet2_x = enemy_two2.x + 10;
		}
	}

	//For enemy three.
	if (antifire % 5 != 0 && enemy_two3.state)
	{
		//cout << "Enemy three firing!" << endl;
		if (enemybullethit3)
		{
			iShowImage(antibullet3_x, enemy_two3.y + 20, 20, 10, bullet_back_image);

			if (!pause) //Bullet doesn't move when game is paused.
			{
				antibullet3_x -= 2;
			}

			//Player, enemy-fire collision.
			if (checkCollision(flying_player.x + flying_player.extended_x, flying_player.y + flying_player.extended_y, flying_player.dimension_x, flying_player.dimension_y, antibullet3_x, enemy_two3.y + 20, 20, 10))
			{
				if (!active_shield)
				{
					ground_player.health -= 10;
				}
				else
				{
					shield_count--;
					if (shield_count <= 0)
					{
						active_shield = false;
					}
				}
				enemybullethit3 = false;
			}
		}

		if (antibullet3_x <= 0)
		{
			enemybullethit3 = false;
			antibullet3_x = enemy_two3.x + 80;
		}
	}

	/*___________________________________________Showing score, health and magic object bar.___________________________________________*/

	showNumber(675, 720, 35, ground_player.score);
	iShowImage(590, 703, 80, 80, score_coin[coin_index]);
	iShowImage(40, 720, 252, 50, health_bar[ground_player.health / 10]);
	iShowImage(40, 660, 252, 50, shield_bar[shield_count]);
	//iShowImage(40, 660, 252, 50, magic_bar[magic_object_gained]);
}

#endif // !LEVELTWO_H_INCLUDED
