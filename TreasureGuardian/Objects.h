#ifndef OBJECTS_H_INCLUDED
#define OBJECTS_H_INCLUDED

/*__________________________________________________Structure for different objects.___________________________________________________*/

struct Objects
{
	int x, y;
	int dimension_x, dimension_y;
	int value;
	bool state;
	bool taken;
	int image;

	//Objects()
	//{
	//	;
	//}

	Objects(int _x, int _y, int _dimension_x, int _dimension_y, int _value, bool _state)
	{
		//This constructor is for health gem and shield.
		x = _x;
		y = _y;
		dimension_x = _dimension_x;
		dimension_y = _dimension_y;
		value = _value;
		state = _state;
	}

	Objects(int _x, int _y, int _dimension_x, int _dimension_y, bool _state, bool _taken)
	{
		//This constractor is for magic objects.
		x = _x;
		y = _y;
		dimension_x = _dimension_x;
		dimension_y = _dimension_y;
		state = _state;
		taken = _taken;
	}

	void resetMagicObject(int _x, int _y, int _dimension_x, int _dimension_y, bool _state, bool _taken)
	{
		//This setter method is for magic objects.
		x = _x;
		y = _y;
		dimension_x = _dimension_x;
		dimension_y = _dimension_y;
		state = _state;
		taken = _taken;
	}
} health_gem1(482, 370, 40, 43, 10, false), health_gem2(600, 370, 60, 67, 30, false), shield(1000, 370, 55, 65, 1, false), magic_stone(1600, 45, 89, 120, false, false), magic_chest(1600, 48, 132, 195, false, false), magic_key(1600, 65, 72, 120, false, false);

/*___________________________________________________Changes health gem's position.____________________________________________________*/

void positionHealthGem()
{
	if (level == 1) //for level 1
	{
		health_gem1.x = rand() % (1520 - health_gem1.dimension_x);
		health_gem1.y = 70 + rand() % 260;
		health_gem1.state = true;
	}

	else if (level == 2) //for level 2
	{
		health_gem1.x = rand() % (1520 - health_gem1.dimension_x);
		health_gem1.y = 350 + rand() % 395;
		health_gem1.state = true;
	}
}

void positionHealthGem2()
{
	static int choose_call = 0;

	if (level == 1) //for level 1
	{
		if (choose_call % 4 == 0)
		{
			health_gem2.state = false;
		}

		if (choose_call % 12 == 0)
		{
			health_gem2.x = rand() % (1520 - health_gem2.dimension_x);
			health_gem2.y = 70 + rand() % 260;
			health_gem2.state = true;
		}
	}
	else if (level == 2) //for level 2
	{
		if (choose_call % 4 == 0)
		{
			health_gem2.state = false;
		}

		if (choose_call % 12 == 0)
		{
			health_gem2.x = rand() % (1520 - health_gem2.dimension_x);
			health_gem2.y = 350 + rand() % 375;
			health_gem2.state = true;
		}
	}

	choose_call++;

	if (choose_call >= 120)
	{
		choose_call = 0;
	}
}

/*______________________________________________________Changes shield's position.____________________________________________________*/

void shieldPositionChange()
{
	static int choose_call = 0;

	if (level == 1) //for level 1
	{
		if (choose_call % 40 == 0)
		{
			shield.state = false;
		}

		if (choose_call % 120 == 0)
		{
			shield.x = rand() % (1520 - shield.dimension_x);
			shield.y = 70 + rand() % 260;
			shield.state = true;
		}
	}
	else if (level == 2) //for level 2
	{
		if (choose_call % 40 == 0)
		{
			shield.state = false;
		}

		if (choose_call % 120 == 0)
		{
			shield.x = rand() % (1520 - shield.dimension_x);
			shield.y = 350 + rand() % 375;
			shield.state = true;
		}
	}

	choose_call++;

	if (choose_call >= 1200)
	{
		choose_call = 0;
	}
}

#endif // !OBJECTS_H_INCLUDED
