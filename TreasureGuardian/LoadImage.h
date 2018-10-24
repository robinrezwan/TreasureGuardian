#ifndef LOADIMAGE_H_INCLUDED
#define LOADIMAGE_H_INCLUDED

//#include "Variables.h"
#include "LifeGem.h"
#include "Player.h"
#include "Enemy.h"

void loadImage()
{
	/*_____________________________________________________________Menu________________________________________________________________*/

	for (int i = 0; i <= 5; i++)
	{
		if (i != 1)
		{
			menu_image[i] = iLoadImage(menu_image_location[i]);
		}
	}
	
	life_gem1.image = iLoadImage("life_gem\\life_potion1.png");

	/*__________________________________________________________Level One._____________________________________________________________*/

	//level_one = iLoadImage("level_one\\level_one.png");

	/*Background for level one.*/

	background_one0 = iLoadImage("level_one\\background\\background_one0.png");

	background_one1[0] = iLoadImage("level_one\\background\\background_one1.png");
	background_one1[1] = iLoadImage("level_one\\background\\background_one1.png");

	background_one2[0] = iLoadImage("level_one\\background\\background_one2.png");
	background_one2[1] = iLoadImage("level_one\\background\\background_one2.png");

	background_one3[0] = iLoadImage("level_one\\background\\background_one3.png");
	background_one3[1] = iLoadImage("level_one\\background\\background_one3.png");

	/*Characters for level one.*/

	for (int i = 0; i <= 11; i++)
	{
		player1.image_idle[i] = iLoadImage(player_idle_image[i]);
	}

	for (int i = 0; i <= 11; i++)
	{
		player1.image_idleback[i] = iLoadImage(player_idleback_image[i]);
	}

	for (int i = 0; i <= 7; i++)
	{
		player1.image_running[i] = iLoadImage(player_running_image[i]);
	}

	for (int i = 0; i <= 7; i++)
	{
		player1.image_runningback[i] = iLoadImage(player_runningback_image[i]);
	}

	for (int i = 0; i <= 7; i++)
	{
		player1.image_jumping[i] = iLoadImage(player_jumping_image[i]);
	}

	for (int i = 0; i <= 7; i++)
	{
		player1.image_jumpingback[i] = iLoadImage(player_jumpingback_image[i]);
	}

	/*Bullet.*/

	bullet_image = iLoadImage("level_one\\arms\\bullet.png");
	bullet_back_image = iLoadImage("level_one\\arms\\bullet_back.png");

	/*Enemy images.*/

	enemy_image = iLoadImage("level_one\\enemy\\WALK_002.png");

	for (int i = 0; i <= 8; i++)
	{
		enemy1.image[i] = iLoadImage(enemy1_image_location[i]);
	}

	for (int i = 0; i <= 8; i++)
	{
		enemy3.image[i] = iLoadImage(enemy3_image_location[i]);
	}

	/*__________________________________________________________Level Two._____________________________________________________________*/

	background_two0 = iLoadImage("level_two\\background\\background_two0.png");

	background_two1[0] = iLoadImage("level_two\\background\\background_two1.png");
	background_two1[1] = iLoadImage("level_two\\background\\background_two1.png");

	background_two2[0] = iLoadImage("level_two\\background\\background_two2.png");
	background_two2[1] = iLoadImage("level_two\\background\\background_two2.png");

	background_two3[0] = iLoadImage("level_two\\background\\background_two3.png");
	background_two3[1] = iLoadImage("level_two\\background\\background_two3.png");

	/*Characters for level two.*/

	for (int i = 0; i <= 5; i++)
	{
		player2.image_plane[i] = iLoadImage(player_plane_image[i]);
	}

	enemy_image_level2 = iLoadImage("level_two\\enemy\\enemy_000.png");
	bomb = iLoadImage("level_one\\enemy\\bomb.png");

	/*___________________________________________________________Game Over_____________________________________________________________*/

	game_over_image[0] = iLoadImage("game_over\\game_over0.png");
	game_over_image[1] = iLoadImage("game_over\\game_over1.png");
	game_over_image[2] = iLoadImage("game_over\\game_over2.png");
}

#endif // !LOADIMAGE_H_INCLUDED
