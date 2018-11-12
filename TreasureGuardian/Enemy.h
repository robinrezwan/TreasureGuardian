#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include "Collision.h"

#include <iostream>
using namespace std;

/*___________________________________________________Structure for level one enemy.____________________________________________________*/

struct Enemy
{
	int x, y;
	int dimension_x, dimension_y;
	bool state; //If on screen or not.
	int value;
	int image[20];
	int index;

	/*Enemy()
	{
		;
	}*/

	Enemy(int _x, int _y, bool _state, int _value, int _index)
	{
		x = _x;
		y = _y;
		state = _state;
		value = _value;
		index = _index;
	}

	void reset(int _x, int _y, bool _state, int _value, int _index)
	{
		//This setter method is for intro level goblin.
		x = _x;
		y = _y;
		state = _state;
		value = _value;
		index = _index;
	}
}enemy_one1(1820, 68, true, 10, 0), enemy_one2(1720, 68, true, 10, 0), enemy_one3(1620, 68, true, 10, 0), enemy_two1(1820, 520, true, 10, 0), enemy_two2(1820, 675, true, 10, 0), enemy_two3(1820, 557, true, 10, 0), goblin(1390, 662, true, 24, 0);

/*_____________________________________________________Showing enemy for level one.____________________________________________________*/

void showEnemyOne()
{
	iShowImage(enemy_one1.x, enemy_one1.y, 190, 135, enemy_one2.image[enemy_one2.index]);
	iShowImage(enemy_one2.x, enemy_one2.y, 180, 135, enemy_one1.image[enemy_one1.index]);
	iShowImage(enemy_one3.x, enemy_one3.y, 170, 135, enemy_one3.image[enemy_one3.index]);

	if (enemy_one1.x <= 1430)
	{
		enemy_one1.state = true;
	}
	else
	{
		enemy_one1.state = false;
	}

	if (enemy_one2.x <= 1430)
	{
		enemy_one2.state = true;
	}
	else
	{
		enemy_one2.state = false;
	}

	if (enemy_one3.x <= 1430)
	{
		enemy_one3.state = true;
	}
	else
	{
		enemy_one3.state = false;
	}
}

void changeEnemyPosition()
{
	static int choose_call = 0;

	if (choose_call % 1 == 0)
	{
		enemy_one1.x -= 3;

		if (enemy_one1.x <= -130)
		{
			enemy_one1.x = 1520;
		}
	}

	if (choose_call % 2 == 0)
	{
		enemy_one2.x -= 3;

		if (enemy_one2.x <= -130)
		{
			enemy_one2.x = 1520;
		}
	}

	if (choose_call % 2 == 0)
	{
		enemy_one3.x -= 4;

		if (enemy_one3.x <= -130)
		{
			enemy_one3.x = 1520;
		}
	}

	//Enemy image index changing.

	if (choose_call % 3 == 0)
	{
		enemy_one2.index++;

		if (enemy_one2.index > 8)
		{
			enemy_one2.index = 0;
		}
	}

	if (choose_call % 4 == 0)
	{
		enemy_one1.index++;

		if (enemy_one1.index > 8)
		{
			enemy_one1.index = 0;
		}
	}

	if (choose_call % 5 == 0)
	{
		enemy_one3.index++;

		if (enemy_one3.index > 8)
		{
			enemy_one3.index = 0;
		}
	}

	choose_call++;

	if (choose_call >= 2520)
	{
		choose_call = 0;
	}
}

/*______________________________________________Player and enemy collision for level one.______________________________________________*/

void playerEnemyCollision()
{
	/*Crossing from front.*/

	if (checkCollision(enemy_one1.x, enemy_one1.y, 190, 135, ground_player.x + ground_player.extended_x, ground_player.y + ground_player.extended_y, ground_player.dimension_x, ground_player.dimension_y))
	{
		if (ground_player.condition != 4 && ground_player.condition != 6 && ground_player.condition != 5 && ground_player.condition != 7)
		{
			if (!active_shield)
			{
				if (ground_player.health >= 10)
				{
					ground_player.health -= 10;
				}
				else
				{
					ground_player.health = 0;
				}
			}
			else
			{
				shield_count--;
				if (shield_count <= 0)
				{
					active_shield = false;
				}
			}
			enemy_one1.state = false;
			enemy_one1.x = 1580 + rand() % 120;
		}
	}

	if (checkCollision(enemy_one2.x, enemy_one2.y, 180, 135, ground_player.x + ground_player.extended_x, ground_player.y + ground_player.extended_y, ground_player.dimension_x, ground_player.dimension_y))
	{
		if (ground_player.condition != 4 && ground_player.condition != 6 && ground_player.condition != 5 && ground_player.condition != 7)
		{
			if (!active_shield)
			{
				if (ground_player.health >= 10)
				{
					ground_player.health -= 10;
				}
				else
				{
					ground_player.health = 0;
				}
			}
			else
			{
				shield_count--;
				if (shield_count <= 0)
				{
					active_shield = false;
				}
			}
			enemy_one2.state = false;
			enemy_one2.x = 1580 + rand() % 420;
		}
	}

	if (checkCollision(enemy_one3.x, enemy_one3.y, 180, 135, ground_player.x + ground_player.extended_x, ground_player.y + ground_player.extended_y, ground_player.dimension_x, ground_player.dimension_y))
	{
		if (ground_player.condition != 4 && ground_player.condition != 6 && ground_player.condition != 5 && ground_player.condition != 7)
		{
			if (!active_shield)
			{
				if (ground_player.health >= 10)
				{
					ground_player.health -= 10;
				}
				else
				{
					ground_player.health = 0;
				}
			}
			else
			{
				shield_count--;
				if (shield_count <= 0)
				{
					active_shield = false;
				}
			}
			enemy_one3.state = false;
			enemy_one3.x = 1580 + rand() % 120;
		}
	}

	/*Crossing from back.*/

	if (checkCollision(enemy_one1.x, enemy_one1.y, 190, 135, ground_player.x + ground_player.extended_x, ground_player.y + ground_player.extended_y, ground_player.dimension_x, ground_player.dimension_y))
	{
		if (ground_player.condition != 4 && ground_player.condition != 6 && ground_player.condition != 5 && ground_player.condition != 7)
		{
			if (!active_shield)
			{
				if (ground_player.health >= 10)
				{
					ground_player.health -= 10;
				}
				else
				{
					ground_player.health = 0;
				}
			}
			else
			{
				shield_count--;
				if (shield_count <= 0)
				{
					active_shield = false;
				}
			}
			enemy_one1.state = false;
			enemy_one1.x = 1580 + rand() % 120;
		}
	}

	if (checkCollision(enemy_one3.x, enemy_one3.y, 180, 135, ground_player.x + ground_player.extended_x, ground_player.y + ground_player.extended_y, ground_player.dimension_x, ground_player.dimension_y))
	{
		if (ground_player.condition != 4 && ground_player.condition != 6 && ground_player.condition != 5 && ground_player.condition != 7)
		{
			if (!active_shield)
			{
				if (ground_player.health >= 10)
				{
					ground_player.health -= 10;
				}
				else
				{
					ground_player.health = 0;
				}
			}
			else
			{
				shield_count--;
				if (shield_count <= 0)
				{
					active_shield = false;
				}
			}
			enemy_one3.state = false;
			enemy_one3.x = 1580 + rand() % 420;
		}
	}

	if (checkCollision(enemy_one2.x, enemy_one2.y, 180, 135, ground_player.x + ground_player.extended_x, ground_player.y + ground_player.extended_y, ground_player.dimension_x, ground_player.dimension_y))
	{
		if (ground_player.condition != 4 && ground_player.condition != 6 && ground_player.condition != 5 && ground_player.condition != 7)
		{
			if (!active_shield)
			{
				if (ground_player.health >= 10)
				{
					ground_player.health -= 10;
				}
				else
				{
					ground_player.health = 0;
				}
			}
			else
			{
				shield_count--;
				if (shield_count <= 0)
				{
					active_shield = false;
				}
			}
			enemy_one2.state = false;
			enemy_one2.x = 1580 + rand() % 120;
		}
	}
}

/*____________________________________________________Showing enemy for level two._____________________________________________________*/

void showEnemyTwo()
{
	iShowImage(enemy_two1.x, enemy_two1.y, 140, 95, enemy_image_level2);
	iShowImage(enemy_two3.x, enemy_two3.y, 140, 95, enemy_image_level2);
	iShowImage(enemy_two2.x, enemy_two2.y, 140, 95, enemy_image_level2);

	//If the enemy is on the screen.
	if (enemy_two1.x <= 1450)
	{
		enemy_two1.state = true;
	}
	else
	{
		enemy_two1.state = false;
	}

	if (enemy_two2.x <= 1450)
	{
		enemy_two2.state = true;
	}
	else
	{
		enemy_two2.state = false;
	}

	if (enemy_two3.x <= 1450)
	{
		enemy_two3.state = true;
	}
	else
	{
		enemy_two3.state = false;
	}
}

void changeEnemyPosition2() {

	static int choose_call = 0;

	if (choose_call % 1 == 0)
	{
		enemy_two1.x -= 2;

		if (enemy_two1.x <= -140)
		{
			enemy_two1.x = 1520 + rand() % 200;
			enemy_two1.y = 352 + rand() % 340;
		}
	}

	if (choose_call % 2 == 0)
	{
		enemy_two2.x -= 3;

		if (enemy_two2.x <= -140)
		{
			enemy_two2.x = 1520 + rand() % 200;
			enemy_two2.y = 352 + rand() % 340;
		}
	}

	if (choose_call % 3 == 0)
	{
		enemy_two3.x -= 3;

		if (enemy_two3.x <= -140)
		{
			enemy_two3.x = 1520 + rand() % 200;
			enemy_two3.y = 352 + rand() % 340;
		}
	}

	choose_call++;

	if (choose_call >= 2520)
	{
		choose_call = 0;
	}
}

/*___________________________________________Player, Fire and enemy collision for level two.__________________________________________*/

void showExplosion(int x, int y);

void fireEnemyCollision2()
{
	/*For enemy one.*/
	if (enemy_two1.state && checkCollision(bullet_x, bullet_y, 20, 20, enemy_two1.x, enemy_two1.y + 6, 140, 89))
	{
		fire = false;
		ground_player.score += 10;

		bullet_x = flying_player.x + 110;

		explosion = true;
		exploded1 = true;
		explosion_x = enemy_two1.x;
		explosion_y = enemy_two1.y;

		enemy_two1.x = 1520 + rand() % 200;
		enemy_two1.y = 352 + rand() % 340;
	}

	if (exploded1)
	{
		showExplosion(explosion_x, explosion_y);
	}

	/*For enemy two.*/
	if (enemy_two2.state && checkCollision(bullet_x, bullet_y, 20, 20, enemy_two2.x, enemy_two2.y + 6, 140, 89))
	{
		fire = false;
		ground_player.score += 10;

		bullet_x = flying_player.x + 110;

		explosion = true;
		exploded2 = true;
		explosion_x = enemy_two2.x;
		explosion_y = enemy_two2.y;

		enemy_two2.x = 1520 + rand() % 200;
		enemy_two2.y = 352 + rand() % 340;
	}

	if (exploded2)
	{
		showExplosion(explosion_x, explosion_y);
	}

	/*For enemy three.*/
	if (enemy_two3.state && checkCollision(bullet_x, bullet_y, 20, 20, enemy_two3.x, enemy_two3.y + 6, 140, 89))
	{
		fire = false;
		ground_player.score += 10;

		bullet_x = flying_player.x + 110;

		explosion = true;
		exploded3 = true;
		explosion_x = enemy_two3.x;
		explosion_y = enemy_two3.y;

		enemy_two3.x = 1520 + rand() % 200;
		enemy_two3.y = 352 + rand() % 340;
	}

	if (exploded3)
	{
		showExplosion(explosion_x, explosion_y);
	}
}

void playerEnemyCollision2()
{
	/*For enemy one.*/
	if (enemy_two1.state && checkCollision(flying_player.x + flying_player.extended_x, flying_player.y + flying_player.extended_y, flying_player.dimension_x, flying_player.dimension_y, enemy_two1.x, enemy_two1.y + 6, 140, 89))
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
		exploded4 = true;
		explosion_x = flying_player.x + 80;
		explosion_y = flying_player.y + 40;

		enemy_two1.y = 352 + rand() % 340;
		enemy_two1.x = 1520 + rand() % 200;
	}

	if (exploded4)
	{
		showExplosion(explosion_x, explosion_y);
	}

	/*For enemy two.*/
	if (enemy_two2.state && checkCollision(flying_player.x + flying_player.extended_x, flying_player.y + flying_player.extended_y, flying_player.dimension_x, flying_player.dimension_y, enemy_two2.x, enemy_two2.y + 6, 140, 89))
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
		exploded5 = true;
		explosion_x = flying_player.x + 80;
		explosion_y = flying_player.y + 40;

		enemy_two2.y = 352 + rand() % 340;
		enemy_two2.x = 1520 + rand() % 200;
	}

	if (exploded5)
	{
		showExplosion(explosion_x, explosion_y);
	}

	/*For enemy three.*/
	if (enemy_two3.state && checkCollision(flying_player.x + flying_player.extended_x, flying_player.y + flying_player.extended_y, flying_player.dimension_x, flying_player.dimension_y, enemy_two3.x, enemy_two3.y + 6, 140, 89))
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
		exploded6 = true;
		explosion_x = flying_player.x + 80;
		explosion_y = flying_player.y + 40;

		enemy_two3.x = 1520 + rand() % 200;
		enemy_two3.y = 352 + rand() % 340;
	}

	if (exploded6)
	{
		showExplosion(explosion_x, explosion_y);
	}
}

/*______________________________________Bomb showing condition and position changing codes.____________________________________________*/

//Function for bomb showing timer.
void bombRandom()
{
	static int choose_call = 0;

	if (choose_call % 3 == 0)
	{
		bomb_random = rand() % 400;
		//cout << bomb_random << endl;
		//bomb_state = true;
	}

	choose_call++;

	if (choose_call >= 300)
	{
		choose_call = 0;
	}
}

void changeBombPosition()
{
	//if (bomb_random % 2 == 0 && bomb_state)
	{
		bomb_x -= 6;
	}

	if (bomb_x < -50)
	{
		bomb_x = 1520 + rand() % 3040;
	}
}

/*____________________________________________________Anti-firing timer conditions.____________________________________________________*/

void enemyFire()
{
	//srand((unsigned)time(NULL));
	antifire = rand() % 1000;

	antibullet1_x = enemy_two1.x + 10;
	antibullet2_x = enemy_two2.x + 10;
	antibullet3_x = enemy_two3.x + 10;

	enemybullethit1 = true;
	enemybullethit2 = true;
	enemybullethit3 = true;
}

/*_____________________________________________________________Explosion._____________________________________________________________*/

void changeFire()
{
	if (fire_index < 19)
	{
		fire_index++;
	}
	else
	{
		fire_index = 0;
		explosion = false;
		exploded1 = false;
		exploded2 = false;
		exploded3 = false;
		exploded4 = false;
		exploded5 = false;
		exploded6 = false;
	}
}

void showExplosion(int x, int y)
{
	iShowImage(x, y, 140, 140, fire_image[fire_index]);

	if (fire_index >= 19)
	{
		explosion = false;
		exploded1 = false;
		exploded2 = false;
		exploded3 = false;
		exploded4 = false;
		exploded5 = false;
		exploded6 = false;
	}
}

#endif // !ENEMY_H_INCLUDED