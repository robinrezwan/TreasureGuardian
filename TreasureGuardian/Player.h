#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

/*_____________________________________________________Structure for the player._______________________________________________________*/

struct Player
{
	int x, y;
	int dimension_x, dimension_y;
	int extended_x, extended_y; //As the images have some blank spaces around the character.
	int condition;
	int condition_changer;
	bool dead;
	int score;
	int life;
	int image_idle[20], image_idleback[20], image_running[20], image_runningback[20], image_jumping[20], image_jumpingback[20], image_plane[20];

	Player()
	{
		;
	}

	Player(int _x, int _y, int _dimension_x, int _dimension_y, int _extended_x, int _extended_y, int _condition, int _condition_changer, bool _dead, int _score, int _life)
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
		dead = _dead;
		score = _score;
		life = _life;
	}

	Player(int _x, int _y, int _dimension_x, int _dimension_y, int _extended_x, int _extended_y, bool _dead, int _score, int _life)
	{	
		//This constructor is for the player of level two.
		x = _x;
		y = _y;
		dimension_x = _dimension_x;
		dimension_y = _dimension_y;
		extended_x = _extended_x;
		extended_y = _extended_y;
		dead = _dead;
		score = _score;
		life = _life;
	}
} player1(460, 68, 90, 140, 35, 8, 0, 0, false, 0, 100), player2(460, 600, 130, 80, 140, 90, false, 0, 100);

//'player1' is for level one and 'player2' is for level two.

#endif // !PLAYER_H_INCLUDED