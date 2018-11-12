#ifndef LOADIMAGE_H_INCLUDED
#define LOADIMAGE_H_INCLUDED

#include "Objects.h"
#include "Player.h"
#include "Enemy.h"

void loadImage()
{
	/*_____________________________________________________________Menu________________________________________________________________*/

	for (int i = 0; i <= 5; i++)
	{
		menu_image[i] = iLoadImage(menu_image_location[i]);
	}

	for (int i = 0; i <= 5; i++)
	{
		menu_highlight_image[i] = iLoadImage(menu_highlight_image_location[i]);
	}

	cout << "L"; //Printing loading.

	start_highlight_image[0] = iLoadImage("menu\\highlight\\new_game.png");
	start_highlight_image[1] = iLoadImage("menu\\highlight\\continue.png");

	back_highlight_image[0] = iLoadImage("menu\\highlight\\back\\1.png");
	back_highlight_image[1] = iLoadImage("menu\\highlight\\back\\2.png");
	back_highlight_image[2] = iLoadImage("menu\\highlight\\back\\3.png");
	back_highlight_image[3] = iLoadImage("menu\\highlight\\back\\4.png");
	back_highlight_image[4] = iLoadImage("menu\\highlight\\back\\5.png");

	/*_________________________________________________Custom number font rendering.___________________________________________________*/

	for (int i = 0; i <= 9; i++)
	{
		digit_image[i] = iLoadImage(digit_image_location[i]);
	}

	/*_____________________________________________________Health gem and shield.______________________________________________________*/

	health_gem1.image = iLoadImage("others\\icons\\health.png");
	health_gem2.image = iLoadImage("others\\icons\\health2.png");
	shield.image = iLoadImage("others\\icons\\shield.png");

	cout << "    O"; //Printing loading.

	/*___________________________________________Score, health, shield and magic object bar.___________________________________________*/

	for (int i = 0; i <= 10; i++)
	{
		health_bar[i] = iLoadImage(health_bar_image[i]);
	}

	for (int i = 0; i <= 10; i++)
	{
		shield_bar[i] = iLoadImage(shield_bar_image[i]);
	}

	magic_bar[0] = iLoadImage("others\\icons\\magic_bar000.png");
	magic_bar[1] = iLoadImage("others\\icons\\magic_bar001.png");
	magic_bar[2] = iLoadImage("others\\icons\\magic_bar002.png");
	magic_bar[3] = iLoadImage("others\\icons\\magic_bar003.png");

	cout << "    A"; //Printing loading.

	score_coin[0] = iLoadImage("others\\icons\\Coin_000.png");
	score_coin[1] = iLoadImage("others\\icons\\Coin_001.png");
	score_coin[2] = iLoadImage("others\\icons\\Coin_002.png");
	score_coin[3] = iLoadImage("others\\icons\\Coin_003.png");

	/*___________________________________________________________Explosion.____________________________________________________________*/

	for (int i = 0; i <= 19; i++)
	{
		fire_image[i] = iLoadImage(fire_image_location[i]);
	}

	/*____________________________________________________________Screens._____________________________________________________________*/

	map_screen[0] = iLoadImage("others\\screens\\map_screen1.png");
	map_screen[1] = iLoadImage("others\\screens\\map_screen2.png");

	gift_screen = iLoadImage("others\\screens\\land_screen.png");
	gift_plane[0] = iLoadImage("others\\objects\\bottled_plane.png");
	gift_plane[1] = iLoadImage("others\\objects\\plane.png");
	invite = iLoadImage("others\\screens\\invite.png");

	cout << "    D"; //Printing loading.

	/*________________________________________________________Intro Level One__________________________________________________________*/

	intro_one_background = iLoadImage("intro_level_one\\background.png");
	stair = iLoadImage("intro_level_one\\stair.png");
	stair_top_map = iLoadImage("intro_level_one\\stair_top_map.png");

	cannon = iLoadImage("intro_level_one\\cannon.png");
	fireball = iLoadImage("intro_level_one\\fireball.png");

	for (int i = 0; i <= 7; i++)
	{
		goblin.image[i] = iLoadImage(goblin_image_location[i]);
	}

	/*________________________________________________________Intro Level Two__________________________________________________________*/

	intro_two_background = iLoadImage("intro_level_two\\background.png");
	apple[0] = iLoadImage("intro_level_two\\bad_apple.png");
	apple[1] = iLoadImage("intro_level_two\\good_apple.png");
	ring = iLoadImage("intro_level_two\\ring.png");

	/*__________________________________________________________Level One._____________________________________________________________*/

	/*Background for level one.*/

	background_one0 = iLoadImage("level_one\\background\\background_one0.png");

	background_one1[0] = iLoadImage("level_one\\background\\background_one1.png");
	background_one1[1] = iLoadImage("level_one\\background\\background_one1.png");

	background_one2[0] = iLoadImage("level_one\\background\\background_one2.png");
	background_one2[1] = iLoadImage("level_one\\background\\background_one2.png");

	background_one3[0] = iLoadImage("level_one\\background\\background_one3.png");
	background_one3[1] = iLoadImage("level_one\\background\\background_one3.png");

	cout << "    I"; //Printing loading.

	/*Magic objects.*/

	stone = iLoadImage("level_one\\magic_objects\\stone.png");
	chest = iLoadImage("level_one\\magic_objects\\chest.png");
	key = iLoadImage("level_one\\magic_objects\\key.png");

	/*Characters for level one.*/

	for (int i = 0; i <= 11; i++)
	{
		ground_player.image_idle[i] = iLoadImage(player_idle_image[i]);
	}

	for (int i = 0; i <= 11; i++)
	{
		ground_player.image_idleback[i] = iLoadImage(player_idleback_image[i]);
	}

	cout << "    N"; //Printing loading.

	for (int i = 0; i <= 7; i++)
	{
		ground_player.image_running[i] = iLoadImage(player_running_image[i]);
	}

	for (int i = 0; i <= 7; i++)
	{
		ground_player.image_runningback[i] = iLoadImage(player_runningback_image[i]);
	}

	for (int i = 0; i <= 7; i++)
	{
		ground_player.image_jumping[i] = iLoadImage(player_jumping_image[i]);
	}

	cout << "    G"; //Printing loading.

	for (int i = 0; i <= 7; i++)
	{
		ground_player.image_jumpingback[i] = iLoadImage(player_jumpingback_image[i]);
	}

	/*Bullet.*/

	bullet_image = iLoadImage("level_one\\arms\\bullet.png");
	bullet_back_image = iLoadImage("level_one\\arms\\bullet_back.png");

	/*Enemy images.*/

	for (int i = 0; i <= 8; i++)
	{
		enemy_one1.image[i] = iLoadImage(enemy1_image_location[i]);
	}

	cout << "    !"; //Printing loading.

	for (int i = 0; i <= 8; i++)
	{
		enemy_one2.image[i] = iLoadImage(enemy2_image_location[i]);
	}

	cout << "!"; //Printing loading.

	for (int i = 0; i <= 8; i++)
	{
		enemy_one3.image[i] = iLoadImage(enemy3_image_location[i]);
	}

	/*__________________________________________________________Level Two._____________________________________________________________*/

	background_two0 = iLoadImage("level_two\\background\\background_two0.png");

	cout << "!\n"; //Printing loading.

	background_two1[0] = iLoadImage("level_two\\background\\background_two1.png");
	background_two1[1] = iLoadImage("level_two\\background\\background_two1.png");

	background_two2[0] = iLoadImage("level_two\\background\\background_two2.png");
	background_two2[1] = iLoadImage("level_two\\background\\background_two2.png");

	background_two3[0] = iLoadImage("level_two\\background\\background_two3.png");
	background_two3[1] = iLoadImage("level_two\\background\\background_two3.png");

	/*Characters for level two.*/

	enemy_image_level2 = iLoadImage("level_two\\enemy\\enemy_000.png");
	bomb_image = iLoadImage("level_one\\enemy\\bomb.png");

	for (int i = 0; i <= 7; i++)
	{
		flying_player.image_plane[i] = iLoadImage(player_plane_image[i]);
	}

	cout << "Loading completed! Enjoy!" << endl;

	/*___________________________________________________________Game Over_____________________________________________________________*/

	game_over_image[0] = iLoadImage("game_over\\game_over0.png");
	game_over_image[1] = iLoadImage("game_over\\game_over1.png");
	game_over_image[2] = iLoadImage("game_over\\game_over2.png");

	game_over_highlight_image[0] = iLoadImage("game_over\\highlight\\game_over0.png");
	game_over_highlight_image[1] = iLoadImage("game_over\\highlight\\game_over1.png");
	game_over_highlight_image[2] = iLoadImage("game_over\\highlight\\game_over2.png");

	/*Game pause and resume.*/

	pause_screen = iLoadImage("others\\screens\\pause.png");
}

#endif // !LOADIMAGE_H_INCLUDED
