#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

/*______________________________________________________Structure for the player.________________________________________________________*/

struct Player
{
	int x, y;
	int dimension_x, dimension_y;
	int condition;
	int condition_changer;
	bool dead;
	int score;
	int life;
	int image_idle[20], image_idleback[20], image_running[20], image_runningback[20], image_jumping[20], image_jumpingback[20];

	static const int extended_x = 35, extended_y = 8; //As the images have some blank spaces around the character.

	Player()
	{
		;
	}

	Player(int _x, int _y, int _dimension_x, int _dimension_y, int _condition, int _condition_changer, bool _dead, int _score, int _life)
	{
		x = _x;
		y = _y;
		dimension_x = _dimension_x;
		dimension_y = _dimension_y;
		condition = _condition;
		condition_changer = _condition_changer;
		dead = _dead;
		score = _score;
		life = _life;
		//strcpy(name, _name);
	}
} player1(460, 68, 90, 140, 0, 0, false, 0, 100);

#endif // !PLAYER_H_INCLUDED