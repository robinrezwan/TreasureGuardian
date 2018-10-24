#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED

#include "Player.h"

#define SCREEN_WIDTH 1520
#define SCREEN_HIGHT 792

/*_______________________________________________________________Menu__________________________________________________________________*/

int level = 0;

char menu_image_location[][23] = { "menu\\menu.png", "blank", "menu\\high_scores.png", "menu\\instructions.png", "menu\\options.png", "menu\\about.png" };
int menu_image[6];

int menu_x, menu_y;
int menu_option = 0;

/*Sound*/

bool play_sound = true;

/*Timer Inedex*/

int background_two1_timer, background_two2_timer, background_two3_timer;

/*Collision*/

int life_gem_image1;

/*_____________________________________________________________Level One_______________________________________________________________*/

int level_one;

/*Background for level one.*/

int background_one0;

int background_one1[2];
int background_one1_x[] = { 0, 2512 }, background_one1_y[] = { 0, 0 };

int background_one2[2];
int background_one2_x[] = { 0, 2512 }, background_one2_y[] = { 0, 0 };

int background_one3[2];
int background_one3_x[] = { 0, 2512 }, background_one3_y[] = { 0, 0 };

/*Characters for level one.*/

char player_idle_image[12][32] = { "level_one\\player\\Idle_000.png", "level_one\\player\\Idle_001.png",
"level_one\\player\\Idle_002.png", "level_one\\player\\Idle_003.png", "level_one\\player\\Idle_004.png",
"level_one\\player\\Idle_005.png", "level_one\\player\\Idle_006.png", "level_one\\player\\Idle_007.png",
"level_one\\player\\Idle_008.png", "level_one\\player\\Idle_009.png", "level_one\\player\\Idle_010.png",
"level_one\\player\\Idle_011.png" };

//int player_idle[13];
int player_idle_index = 0;

char player_idleback_image[12][36] = { "level_one\\player\\IdleBack_000.png", "level_one\\player\\IdleBack_001.png",
"level_one\\player\\IdleBack_002.png", "level_one\\player\\IdleBack_003.png", "level_one\\player\\IdleBack_004.png",
"level_one\\player\\IdleBack_005.png", "level_one\\player\\IdleBack_006.png", "level_one\\player\\IdleBack_007.png",
"level_one\\player\\IdleBack_008.png", "level_one\\player\\IdleBack_009.png", "level_one\\player\\IdleBack_010.png",
"level_one\\player\\IdleBack_011.png" };

//int player_idleback[13];
int player_idleback_index = 0;

char player_running_image[8][39] = { "level_one\\player\\RunWithGun_000.png", "level_one\\player\\RunWithGun_001.png",
"level_one\\player\\RunWithGun_002.png", "level_one\\player\\RunWithGun_003.png", "level_one\\player\\RunWithGun_004.png",
"level_one\\player\\RunWithGun_005.png", "level_one\\player\\RunWithGun_006.png", "level_one\\player\\RunWithGun_007.png" };

//int player_running[8];
int player_running_index = 0;

char player_runningback_image[8][42] = { "level_one\\player\\RunWithGunBack_000.png", "level_one\\player\\RunWithGunBack_001.png",
"level_one\\player\\RunWithGunBack_002.png", "level_one\\player\\RunWithGunBack_003.png", "level_one\\player\\RunWithGunBack_004.png",
"level_one\\player\\RunWithGunBack_005.png", "level_one\\player\\RunWithGunBack_006.png", "level_one\\player\\RunWithGunBack_007.png" };

//int player_runningback[8];
int player_runningback_index = 0;

char player_jumping_image[8][32] = { "level_one\\player\\Jump_000.png", "level_one\\player\\Jump_001.png",
"level_one\\player\\Jump_002.png", "level_one\\player\\Jump_003.png", "level_one\\player\\Jump_004.png",
"level_one\\player\\Jump_005.png", "level_one\\player\\Jump_006.png", "level_one\\player\\Jump_007.png" };

char player_jumpingback_image[8][36] = { "level_one\\player\\JumpBack_000.png", "level_one\\player\\JumpBack_001.png",
"level_one\\player\\JumpBack_002.png", "level_one\\player\\JumpBack_003.png", "level_one\\player\\JumpBack_004.png",
"level_one\\player\\JumpBack_005.png", "level_one\\player\\JumpBack_006.png", "level_one\\player\\JumpBack_007.png" };

int player_jumping_index = 0;
//int player_jumpingback_index = 0;

/*Jumping variables.*/

bool jump = false;
bool jumping = false;
int jumping_height = 0;
#define JUMPLIMIT 150

/*Firing*/

bool fire = false;
int bullet_image;
int bullet_back_image;
int bullet_x = player1.x + 110;
int bullet_back_x = player1.x;

/*Enemy variables.*/

int enemy_image;

char enemy1_image_location[][39] = { "level_one\\enemy\\enemy_1\\WALK_000.png", "level_one\\enemy\\enemy_1\\WALK_001.png", "level_one\\enemy\\enemy_1\\WALK_002.png",
"level_one\\enemy\\enemy_1\\WALK_003.png", "level_one\\enemy\\enemy_1\\WALK_004.png", "level_one\\enemy\\enemy_1\\WALK_005.png", "level_one\\enemy\\enemy_1\\WALK_006.png",
"level_one\\enemy\\enemy_1\\WALK_007.png", "level_one\\enemy\\enemy_1\\WALK_008.png" };

char enemy3_image_location[][39] = { "level_one\\enemy\\enemy_3\\WALK_000.png", "level_one\\enemy\\enemy_3\\WALK_001.png", "level_one\\enemy\\enemy_3\\WALK_002.png",
"level_one\\enemy\\enemy_3\\WALK_003.png", "level_one\\enemy\\enemy_3\\WALK_004.png", "level_one\\enemy\\enemy_3\\WALK_005.png", "level_one\\enemy\\enemy_3\\WALK_006.png",
"level_one\\enemy\\enemy_3\\WALK_007.png", "level_one\\enemy\\enemy_3\\WALK_008.png" };

/*Showing score on screen.*/

char score_string[10];

/*____________________________________________________________Level Two________________________________________________________________*/

/*Background for level two.*/

int background_two0;

int background_two1[2];
int background_two1_x[] = { 0, 2512 }, background_two1_y[] = { 0, 0 };

int background_two2[2];
int background_two2_x[] = { 0, 2512 }, background_two2_y[] = { 0, 0 };

int background_two3[2];
int background_two3_x[] = { 0, 2512 }, background_two3_y[] = { 0, 0 };

/*Characters for level two.*/

char player_plane_image[6][33] = { "level_two\\player\\plane_000.png", "level_two\\player\\plane_001.png", "level_two\\player\\plane_002.png",
"level_two\\player\\plane_003.png", "level_two\\player\\plane_004.png", "level_two\\player\\plane_005.png" };

int player_plane_index = 0;

/*_____________________________________________________Game Over and Score Saving._____________________________________________________*/

bool game_over = false;
int game_over_image[3];
int game_over_index = 0;

int player_rank = 0;
int star_image[6];
int star_index;

bool field_active = false;
int name_index = 0;

/*Firing*/

int bullet_y;

/*Enemy image for level two.*/

int enemy_image_level2;
int bomb_image;
int bomb_x = 1550;

#endif // !VARIABLES_H_INCLUDED
