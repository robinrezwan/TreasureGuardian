#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include "Collision.h"

/*___________________________________________________Structure for level one enemy.____________________________________________________*/

struct Enemy
{
	int x, y;
	int dimension_x, dimension_y;
	bool state;
	int value;
	int image[20];
	int index;

	Enemy()
	{
		;
	}

	Enemy(int _x, int _y, bool _state, int _value, int _index)
	{
		x = _x;
		y = _y;
		state = _state;
		value = _value;
		index = _index;
	}
}enemy1(1820, 68, true, 10, 0), enemy2(1720, 68, true, 10, 0), enemy3(1620, 68, true, 10, 0), enemy4(1520, 68, true, 10, 0);

/*_____________________________________________________Showing enemy for level one.____________________________________________________*/

void showEnemy()
{
	//iShowImage(enemy1.x, enemy1.y, 120, 130, enemy_image);
	iShowImage(enemy2.x, enemy2.y, 180, 135, enemy1.image[enemy1.index]);
	iShowImage(enemy3.x, enemy3.y, 170, 135, enemy3.image[enemy3.index]);
	//iShowImage(enemy4.x, enemy4.y, 120, 130, enemy_image);
	iShowImage(bomb_x, 75, 50, 60, bomb_image);
}

void changeEnemyPosition() {

	static int choose_call = 0;

	bomb_x -= 7;

	if (bomb_x < -80)
	{
		bomb_x = 1550;
	}

	if (choose_call % 1 == 0)
	{
		enemy1.x -= 2;

		if (enemy1.x <= -130)
		{
			enemy1.x = 1520;
		}
	}

	if (choose_call % 2 == 0)
	{
		enemy2.x -= 3;

		if (enemy2.x <= -130)
		{
			enemy2.x = 1520;
		}
	}

	if (choose_call % 3 == 0)
	{
		enemy3.x -= 3;

		if (enemy3.x <= -130)
		{
			enemy3.x = 1520;
		}
	}

	if (choose_call % 4 == 0)
	{
		enemy4.x -= 3;

		if (enemy4.x <= -130)
		{
			enemy4.x = 1520;
		}

		enemy1.index++;

		if (enemy1.index > 8)
		{
			enemy1.index = 0;
		}
	}

	if (choose_call % 5 == 0)
	{
		enemy3.index++;

		if (enemy3.index > 8)
		{
			enemy3.index = 0;
		}
	}

	choose_call++;

	if (choose_call >= 2520)
	{
		choose_call = 0;
	}
}

/*_____________________________________________Player, Fire and enemy collision for level one._________________________________________*/

void fireEnemyCollision()
{
	/*Firing from front.*/

	if (checkCollision(enemy2.x, enemy2.y, 180, 135, bullet_x, player1.y, 20, 20))
	{
		if (player1.condition != 4 && player1.condition != 6 && player1.condition != 5 && player1.condition != 7)
		{
			player1.score += 10;
			fire = false;
			enemy2.state = false;
			enemy2.x = 1580;
			bullet_x = player1.x + 110;
		}
	}

	if (checkCollision(enemy3.x, enemy3.y, 180, 135, bullet_x, player1.y, 20, 20))
	{
		if (player1.condition != 4 && player1.condition != 6 && player1.condition != 5 && player1.condition != 7)
		{
			player1.score += 10;
			fire = false;
			enemy3.state = false;
			enemy3.x = 1580;
			bullet_x = player1.x + 110;
		}
	}

	/*Firing from back.*/

	if (checkCollision(enemy3.x, enemy3.y, 180, 135, bullet_back_x + 150, player1.y, 20, 20))
	{
		if (player1.condition != 4 && player1.condition != 6 && player1.condition != 5 && player1.condition != 7)
		{
			player1.score += 10;
			fire = false;
			enemy3.state = false;
			enemy3.x = 1580;
			bullet_back_x = player1.x - 110;
		}
	}

	if (checkCollision(enemy2.x, enemy2.y, 180, 135, bullet_back_x + 150, player1.y, 20, 20))
	{
		if (player1.condition != 4 && player1.condition != 6 && player1.condition != 5 && player1.condition != 7)
		{
			player1.score += 10;
			fire = false;
			enemy2.state = false;
			enemy2.x = 1580;
			bullet_back_x = player1.x - 110;
		}
	}
}

void playerEnemyCollision()
{
	/*Bomb Collision.*/

	if (checkCollision(bomb_x, 75, 50, 60, player1.x + player1.extended_x, player1.y + player1.extended_y, player1.dimension_x, player1.dimension_y))
	{
		if (player1.condition != 4 && player1.condition != 6 && player1.condition != 5 && player1.condition != 7)
		{
			player1.life -= 0.01;
		}
	}

	/*Crossing from front.*/

	if (checkCollision(enemy2.x, enemy2.y, 180, 135, player1.x+player1.extended_x, player1.y+player1.extended_y, player1.dimension_x, player1.dimension_y))
	{
		if (player1.condition != 4 && player1.condition != 6 && player1.condition != 5 && player1.condition != 7)
		{
			player1.life -= 50;
			enemy2.state = false;
			enemy2.x = 1580;
		}
	}

	if (checkCollision(enemy3.x, enemy3.y, 180, 135, player1.x + player1.extended_x, player1.y + player1.extended_y, player1.dimension_x, player1.dimension_y))
	{
		if (player1.condition != 4 && player1.condition != 6 && player1.condition != 5 && player1.condition != 7)
		{
			player1.life -= 50;
			enemy3.state = false;
			enemy3.x = 1580;
		}
	}

	/*Crossing from back.*/

	if (checkCollision(enemy3.x, enemy3.y, 180, 135, player1.x + player1.extended_x, player1.y + player1.extended_y, player1.dimension_x, player1.dimension_y))
	{
		if (player1.condition != 4 && player1.condition != 6 && player1.condition != 5 && player1.condition != 7)
		{
			player1.life -= 50;
			enemy3.state = false;
			enemy3.x = 1580;
		}
	}

	if (checkCollision(enemy2.x, enemy2.y, 180, 135, player1.x + player1.extended_x, player1.y + player1.extended_y, player1.dimension_x, player1.dimension_y))
	{
		if (player1.condition != 4 && player1.condition != 6 && player1.condition != 5 && player1.condition != 7)
		{
			player1.life -= 50;
			enemy2.state = false;
			enemy2.x = 1580;
		}
	}
}

/*___________________________________________________Structure for level two enemy.____________________________________________________*/

struct Enemy2
{
	int x, y;
	int dimension_x, dimension_y;
	bool state;
	int value;
	int image[20];
	int index;

	Enemy2()
	{
		;
	}

	Enemy2(int _x, int _y, bool _state, int _value, int _index)
	{
		x = _x;
		y = _y;
		state = _state;
		value = _value;
		index = _index;
	}
}enemy11(1820, 520, true, 10, 0), enemy22(1820, 675, true, 10, 0), enemy33(1820, 557, true, 10, 0), enemy44(1820, 469, true, 10, 0);


/*____________________________________________________Showing enemy for level two._____________________________________________________*/

void showEnemy2()
{
	if (enemy11.state)
	{
		iShowImage(enemy11.x, enemy11.y, 130, 95, enemy_image_level2);
	}

	if (enemy33.state)
	{
		iShowImage(enemy33.x, enemy33.y, 130, 95, enemy_image_level2);
	}
	if (enemy22.state)
	{
		iShowImage(enemy22.x, enemy22.y, 130, 95, enemy_image_level2);
	}
}

void changeEnemyPosition2() {

	static int choose_call = 0;

	if (choose_call % 1 == 0)
	{
		enemy11.state = true;
		enemy11.x -= 2;

		if (enemy11.x <= -130)
		{
			enemy11.x = 1520;
		}
	}

	if (choose_call % 2 == 0)
	{
		enemy22.state = true;
		enemy22.x -= 3;

		if (enemy22.x <= -130)
		{
			enemy22.x = 1520;
		}
	}

	if (choose_call % 3 == 0)
	{
		enemy33.state = true;
		enemy33.x -= 3;

		if (enemy33.x <= -130)
		{
			enemy33.x = 1520;
		}
	}

	if (choose_call % 4 == 0)
	{
		enemy33.state = true;
		enemy44.x -= 3;

		if (enemy44.x <= -130)
		{
			enemy44.x = 1520;
		}

		/*enemy1.index++;

		if (enemy1.index > 8)
		{
		enemy1.index = 0;
		}
		}

		if (choose_call % 5 == 0)
		{
		enemy3.index++;

		if (enemy3.index > 8)
		{
		enemy3.index = 0;
		}
		}*/
	}

	choose_call++;

	if (choose_call >= 2520)
	{
		choose_call = 0;
	}
}

/*___________________________________________Player, Fire and enemy collision for level two.__________________________________________*/

void fireEnemyCollision2()
{
	/*For enemy11.*/
	if (checkCollision(bullet_x, bullet_y, 20, 20, enemy11.x, enemy11.y, 130, 95))
	{
		fire = false;
		bullet_x = player2.x + 110;
		enemy11.state = false;
		enemy11.x = 1520;
		player1.score += 10;
	}

	/*For enemy 22.*/
	if (checkCollision(bullet_x, bullet_y, 20, 20, enemy22.x, enemy22.y, 130, 95))
	{
		fire = false;
		bullet_x = player2.x + 110;
		enemy22.state = false;
		enemy22.x = 1520;
		player1.score += 10;
	}

	/*For enemy33.*/

	if (checkCollision(bullet_x, bullet_y, 20, 20, enemy33.x, enemy33.y, 130, 95))
	{
		fire = false;
		bullet_x = player2.x + 110;
		enemy33.state = false;
		enemy33.x = 1520;
		player1.score += 10;
	}
}

void playerEnemyCollision2()
{
	/*For enemy11.*/
	if (checkCollision(player2.x, player2.y, player2.dimension_x, player2.dimension_y, enemy11.x, enemy11.y, 130, 95))
	{
		player1.life -= 50;
		enemy11.state = false;
		enemy11.x = 1520;
	}

	/*For enemy 22.*/
	if (checkCollision(player2.x, player2.y, player2.dimension_x, player2.dimension_y, enemy22.x, enemy22.y, 130, 95))
	{
		player1.life -= 50;
		enemy22.state = false;
		enemy22.x = 1520;
	}

	/*For enemy33.*/

	if (checkCollision(player2.x, player2.y, player2.dimension_x, player2.dimension_y, enemy33.x, enemy33.y, 130, 95))
	{
		player1.life -= 50;
		enemy33.state = false;
		enemy33.x = 1520;
	}
}

/*___________________________________________Function for enemy position changing timer._______________________________________________*/

void enemyPosition()
{
	changeEnemyPosition();
	changeEnemyPosition2();
}

#endif // !ENEMY_H_INCLUDED