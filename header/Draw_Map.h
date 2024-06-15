#ifndef _Draw_Map_H_
#define _Draw_Map_H_
#pragma once
//Chua cac ham lien quan toi ve map
#include "resource.h"
#include "file_function.h"

void draw_left_right_wall(int x);

void draw_top_bottom_wall(int y);

void draw_mini_top_bottom_wall(int y);

void draw_score();

void draw_game();

void draw_comment();

void gate_init();

void draw_wall_and_numbers();

void draw_box(int x, int y, int w, int h, int box_color, int b_color, string nd);

void box_light(int x, int y, int w, int h, int b_color, string nd);

#endif