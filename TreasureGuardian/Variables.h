#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED

#include "Player.h"

#define SCREEN_WIDTH 1520
#define SCREEN_HIGHT 792

/*___________________________________________________________Timer index.______________________________________________________________*/

int timer_ten_mili, timer_twenty_mili, timer_forty_mili, timer_hundred_mili, timer_one_sec, timer_four_sec;

/*_______________________________________________________________Menu__________________________________________________________________*/

int level = 0;

char menu_image_location[][23] = { "menu\\menu.png", "menu\\start.png", "menu\\high_scores.png", "menu\\story.png", "menu\\controls.png", "menu\\about.png" };
int menu_image[7];

int menu_option = 0;

int highlight_index = 6;
int start_highlight_index = 3;
int back_highlight_index = 5;
char menu_highlight_image_location[][25] = { "menu\\highlight\\1.png", "menu\\highlight\\2.png", "menu\\highlight\\3.png", "menu\\highlight\\4.png", "menu\\highlight\\5.png", "menu\\highlight\\6.png" };
int menu_highlight_image[7];
int start_highlight_image[3];
int back_highlight_image[6];

/*Sound*/

bool play_sound = true;
bool mute = false;
bool sound_playing = false;

/*___________________________________________________Custom number font rendering._____________________________________________________*/

int digit_x, digit_y;
int digit[6];
int digit_image[11];
char digit_image_location[11][23] = { "others\\numbers\\0.png", "others\\numbers\\1.png",
"others\\numbers\\2.png", "others\\numbers\\3.png", "others\\numbers\\4.png",
"others\\numbers\\5.png", "others\\numbers\\6.png", "others\\numbers\\7.png",
"others\\numbers\\8.png", "others\\numbers\\9.png" };

/*_____________________________________________Score, health, shield and magic object bar._____________________________________________*/

int health_bar[12];
char health_bar_image[12][33] = { "others\\icons\\health_bar000.png", "others\\icons\\health_bar001.png",
"others\\icons\\health_bar002.png", "others\\icons\\health_bar003.png", "others\\icons\\health_bar004.png",
"others\\icons\\health_bar005.png", "others\\icons\\health_bar006.png", "others\\icons\\health_bar007.png",
"others\\icons\\health_bar008.png", "others\\icons\\health_bar009.png", "others\\icons\\health_bar010.png" };

int magic_bar[5];

int score_coin[5];
int coin_index = 0;

bool active_shield = false;
int shield_count = 0;

int shield_bar[12];
char shield_bar_image[12][33] = { "others\\icons\\shield_bar000.png", "others\\icons\\shield_bar001.png",
"others\\icons\\shield_bar002.png", "others\\icons\\shield_bar003.png", "others\\icons\\shield_bar004.png",
"others\\icons\\shield_bar005.png", "others\\icons\\shield_bar006.png", "others\\icons\\shield_bar007.png",
"others\\icons\\shield_bar008.png", "others\\icons\\shield_bar009.png", "others\\icons\\shield_bar010.png" };


/*_____________________________________________________________Explosion.______________________________________________________________*/

bool explosion = false;
bool exploded1 = false;
bool exploded2 = false;
bool exploded3 = false;
bool exploded4 = false;
bool exploded5 = false;
bool exploded6 = false;
char fire_image_location[21][30] = { "others\\fire\\fire_001_01.png", "others\\fire\\fire_001_02.png",
"others\\fire\\fire_001_03.png", "others\\fire\\fire_001_04.png", "others\\fire\\fire_001_05.png",
"others\\fire\\fire_001_06.png", "others\\fire\\fire_001_07.png", "others\\fire\\fire_001_08.png",
"others\\fire\\fire_001_09.png", "others\\fire\\fire_001_10.png", "others\\fire\\fire_001_11.png",
"others\\fire\\fire_001_12.png", "others\\fire\\fire_001_13.png", "others\\fire\\fire_001_14.png",
"others\\fire\\fire_001_15.png", "others\\fire\\fire_001_16.png", "others\\fire\\fire_001_17.png",
"others\\fire\\fire_001_18.png", "others\\fire\\fire_001_19.png", "others\\fire\\fire_001_20.png" };
int fire_image[21];
int fire_index = 0;

int explosion_x;
int explosion_y;

/*______________________________________________________________Screens._______________________________________________________________*/

int show_map = 0;
int map_screen[3];

int show_gift = 0;
int gift_screen;
int gift_plane[3];
bool gift_taken = false;
int invite;

/*__________________________________________________________Intro Level One____________________________________________________________*/

int intro_level = 0;

int intro_one_background;
int stair;
int stair_top_map;
int map;
int move_intro_player = 0;
//bool falling_down = false;

int cannon;
int fireball;
int fireball_x = 1420;
bool cannon_fire = false;
char goblin_image_location[][34] = { "intro_level_one\\goblin_000.png", "intro_level_one\\goblin_001.png", "intro_level_one\\goblin_002.png",
"intro_level_one\\goblin_003.png", "intro_level_one\\goblin_004.png", "intro_level_one\\goblin_005.png", "intro_level_one\\goblin_006.png",
"intro_level_one\\goblin_006.png", "intro_level_one\\goblin_007.png" };

/*__________________________________________________________Intro Level Two____________________________________________________________*/

int intro_two_background;
int apple[3];
int apple_index1 = 0, apple_index2 = 1, apple_index3 = 0, apple_index4 = 1, apple_index5 = 0, apple_index6 = 1, apple_index7 = 0, apple_index8 = 1, apple_index9 = 0, apple_index10 = 1, apple_index11 = 0;
int show_apple;
int apple_count;
char apple_string[10];
int ring;
int mouse_x;
int mouse_y;
bool new_number = false;

/*_____________________________________________________________Level One_______________________________________________________________*/

int level_one;
int player_distance = 0;

int stone;
int chest;
int key;
int magic_object_gained = 0;

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
int bullet_x = ground_player.x + 110;
int bullet_back_x = ground_player.x;

/*Enemy variables.*/

int enemy_image;

char enemy1_image_location[][39] = { "level_one\\enemy\\enemy_1\\WALK_000.png", "level_one\\enemy\\enemy_1\\WALK_001.png", "level_one\\enemy\\enemy_1\\WALK_002.png",
"level_one\\enemy\\enemy_1\\WALK_003.png", "level_one\\enemy\\enemy_1\\WALK_004.png", "level_one\\enemy\\enemy_1\\WALK_005.png", "level_one\\enemy\\enemy_1\\WALK_006.png",
"level_one\\enemy\\enemy_1\\WALK_007.png", "level_one\\enemy\\enemy_1\\WALK_008.png" };

char enemy2_image_location[][39] = { "level_one\\enemy\\enemy_2\\WALK_000.png", "level_one\\enemy\\enemy_2\\WALK_001.png", "level_one\\enemy\\enemy_2\\WALK_002.png",
"level_one\\enemy\\enemy_2\\WALK_003.png", "level_one\\enemy\\enemy_2\\WALK_004.png", "level_one\\enemy\\enemy_2\\WALK_005.png", "level_one\\enemy\\enemy_2\\WALK_006.png",
"level_one\\enemy\\enemy_2\\WALK_007.png", "level_one\\enemy\\enemy_2\\WALK_008.png" };

char enemy3_image_location[][39] = { "level_one\\enemy\\enemy_3\\WALK_000.png", "level_one\\enemy\\enemy_3\\WALK_001.png", "level_one\\enemy\\enemy_3\\WALK_002.png",
"level_one\\enemy\\enemy_3\\WALK_003.png", "level_one\\enemy\\enemy_3\\WALK_004.png", "level_one\\enemy\\enemy_3\\WALK_005.png", "level_one\\enemy\\enemy_3\\WALK_006.png",
"level_one\\enemy\\enemy_3\\WALK_007.png", "level_one\\enemy\\enemy_3\\WALK_008.png" };

/*Enemy bomb variables.*/
int bomb_image;
int bomb_x = 1620;
int bomb_random = 3;
bool bomb_state = false;

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

char player_plane_image[9][34] = { "level_two\\player\\plane_0000.png", "level_two\\player\\plane_0001.png", "level_two\\player\\plane_0002.png",
"level_two\\player\\plane_0003.png", "level_two\\player\\plane_0004.png", "level_two\\player\\plane_0005.png", "level_two\\player\\plane_0006.png",
"level_two\\player\\plane_0006.png", "level_two\\player\\plane_0007.png" };

int player_plane_index = 0;
int plane_direction = 0;

/*Enemy image for level two.*/
int enemy_image_level2;

/*Anti-firing.*/

int antifire;

int antibullet1_x;
int antibullet2_x;
int antibullet3_x;

bool enemybullethit1;
bool enemybullethit2;
bool enemybullethit3;

bool crash1, crash2, crash3;

/*_____________________________________________________Game Over and Score Saving._____________________________________________________*/

bool game_over = false;
int game_over_image[3];
int game_over_index = 3;

int game_over_highlight_index = 3;
int game_over_highlight_image[4];

int player_rank = 0;
int star_image[6];
int star_index;

bool field_active = false;
int name_index = 0;

/*Firing*/

int bullet_y;

/*Game pause and resume.*/

bool pause = false;
int pause_screen;

/*Others*/

bool cheatcode_active = false; //For testing purpose.

#endif // !VARIABLES_H_INCLUDED
