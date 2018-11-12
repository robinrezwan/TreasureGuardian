#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

/*_____________________________________________________Structure for the player._______________________________________________________*/

struct Player
{
	int x, y;
	int dimension_x, dimension_y; //Character's actual dimension, not the image's dimension.
	int extended_x, extended_y; //As the images have some blank spaces around the character.
	int condition; //This number will represent if the player standing, walking or jumping. 
	int condition_changer;
	bool visible;
	int score;
	int health;
	int image_idle[20], image_idleback[20], image_running[20], image_runningback[20], image_jumping[20], image_jumpingback[20], image_plane[20];

	//Player()
	//{
	//	;
	//}

	Player(int _x, int _y, int _dimension_x, int _dimension_y, int _extended_x, int _extended_y, int _condition, int _condition_changer, bool _visible, int _score, int _health)
	{
		//This constructor is for the player of level one.
		x = _x;
		y = _y;
		dimension_x = _dimension_x;
		dimension_y = _dimension_y;
		extended_x = _extended_x;
		extended_y = _extended_y;
		condition = _condition;
		condition_changer = _condition_changer;
		visible = _visible;
		score = _score;
		health = _health;
	}

	Player(int _x, int _y, int _dimension_x, int _dimension_y, int _extended_x, int _extended_y, bool _visible)
	{
		//This constructor is for the player of level two.
		x = _x;
		y = _y;
		dimension_x = _dimension_x;
		dimension_y = _dimension_y;
		extended_x = _extended_x;
		extended_y = _extended_y;
		visible = _visible;
	}

	Player(int _x, int _y, int _dimension_x, int _dimension_y, int _extended_x, int _extended_y)
	{
		//This constructor is for the player of intro levels.
		x = _x;
		y = _y;
		dimension_x = _dimension_x;
		dimension_y = _dimension_y;
		extended_x = _extended_x;
		extended_y = _extended_y;
	}
} intro_player(160, 30, 90, 140, 35, 8), ground_player(160, 68, 90, 140, 35, 8, 0, 0, true, 0, 100), flying_player(160, 520, 152, 122, 24, 25, true);

#endif // !PLAYER_H_INCLUDED