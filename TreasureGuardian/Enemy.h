#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

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

void showEnemy()
{
	//iShowImage(enemy1.x, enemy1.y, 120, 130, enemy_image);
	iShowImage(enemy2.x, enemy2.y, 180, 135, enemy1.image[enemy1.index]);
	iShowImage(enemy3.x, enemy3.y, 170, 135, enemy3.image[enemy3.index]);
	//iShowImage(enemy4.x, enemy4.y, 120, 130, enemy_image);
}

void changeEnemyPosition() {

	static int choose_call = 0;

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

#endif // !ENEMY_H_INCLUDED