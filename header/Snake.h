#ifndef _Snake_H_
#define _Snake_H_
#pragma once
#include "resource.h"
#include "Draw_Map.h"
#include "Variable.h"
#include "Menu.h"
#include "file_function.h"
#include "Sound.h"

int pause_menu();
void menu();
void delete_old_pause_menu(int x, int y, int w, int h,int number, int color);
bool is_snake_lying_on_food(int x, int y);
void create_food();
void snake_init();
void draw_snake();
void Move();
void keyboard_input();
void check_collision();
void eat_food();
void snake_run();
void intro();
void end_game();
void OutGate();
void game_1(bool check_load );
void game_2(bool check_load );
void game_3(bool check_load );
void game_4(bool check_load );
bool is_snake_alive();
void delete_old_snake();
void input_name();
void keyboard_input();
void check_collision();

#endif

