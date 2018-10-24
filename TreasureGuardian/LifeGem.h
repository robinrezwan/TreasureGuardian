#ifndef LIFEGEM_H_INCLUDED
#define LIFEGEM_H_INCLUDED

/*______________________________________________________Structure for life potion.________________________________________________________*/

struct LifeGem
{
	int x, y;
	int dimension_x, dimension_y;
	int value;
	bool state;
	int image;

	LifeGem()
	{
		;
	}

	LifeGem(int _x, int _y, int _dimension_x, int _dimension_y, int _value, bool _state)
	{
		x = _x;
		y = _y;
		dimension_x = _dimension_x;
		dimension_y = _dimension_y;
		value = _value;
		state = _state;
	}
} life_gem1(482, 370, 40, 40, 1, false), life_gem2(482, 600, 40, 40, 1, false);

/*___________________________________________________Changes life potion's position.________________________________________________________*/

void positionLifeGem()
{
	//srand((unsigned)time(NULL));
	life_gem1.x = 200 + rand() % 1100; //for level 1
	life_gem2.x = 200 + rand() % 1100; //for level 2
	life_gem1.y = 70 + rand() % 260; //for level 1
	life_gem2.y = 350 + rand() % 250; //for level 2

	life_gem1.state = true;
	life_gem2.state = true;
}

#endif // !LIFEGEM_H_INCLUDED
