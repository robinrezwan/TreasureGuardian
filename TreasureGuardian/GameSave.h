#ifndef GAMESAVE_H_INCLUDED
#define GAMESAVE_H_INCLUDED

#include "Variables.h"

#include <iostream>
using namespace std;

struct GameState
{
	int menu_option;
	int intro_level;
	int show_map;
	int level;
	int show_gift;

	int score;

	GameState()
	{
		;
	}

	GameState(int _menu_option, int _intro_level, int _show_map, int _level, int _show_gift, int _score)
	{
		menu_option = _menu_option;
		intro_level = _intro_level;
		show_map = _show_map;
		level = _level;
		show_gift = _show_gift;

		score = _score;
	}

	void setValues(int _menu_option, int _intro_level, int _show_map, int _level, int _show_gift, int _score)
	{
		menu_option = _menu_option;
		intro_level = _intro_level;
		show_map = _show_map;
		level = _level;
		show_gift = _show_gift;

		score = _score;
	}
} game_state(0, 0, 0, 0, 0, 0);

void saveGame()
{
	FILE *fp = fopen("game_data.bin", "wb");

	game_state.setValues(menu_option, intro_level, show_map, level, show_gift, ground_player.score);

	fwrite(&game_state, sizeof(struct GameState), 1, fp);
	//cout << "Game saved!" << endl;

	fclose(fp);
}

void loadGame()
{
	FILE *fp = fopen("game_data.bin", "rb");

	if (fp == NULL)
	{
		//cout << "File not found!" << endl;
		menu_option = 6;
		intro_level = 1;
		show_map = 0;
		level = 0;
		show_gift = 0;

		ground_player.score = 0;
	}
	else
	{
		GameState game_state_temp;

		while (fread(&game_state_temp, sizeof(struct GameState), 1, fp) == 1)
		{
			menu_option = game_state_temp.menu_option;
			intro_level = game_state_temp.intro_level;
			show_map = game_state_temp.show_map;
			level = game_state_temp.level;
			show_gift = game_state_temp.show_gift;

			ground_player.score = game_state_temp.score;
		}

		//cout << "Game loaded!" << endl;
		fclose(fp);
	}
}

void eraseGame()
{
	FILE *fp = fopen("game_data.bin", "wb");

	game_state.setValues(6, 1, 0, 0, 0, 0);

	fwrite(&game_state, sizeof(struct GameState), 1, fp);

	fclose(fp);
}

#endif // !GAMESAVE_H_INCLUDED
