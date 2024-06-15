#ifndef _Variable_H_
#define _Variable_H_
#pragma once
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include<ctime> 
#include <windows.h> 
#include <thread>
#include <string>
#include <fstream>

struct Point {
	int x, y;
};

extern const int X_SCREEN_TOP;
extern const int Y_SCREEN_TOP;
extern const int X_SCREEN_BOTTOM;
extern const int Y_SCREEN_BOTTOM;
extern const int X_BLOCK_1;
extern const int X_BLOCK_2;
extern const int MAX; 
extern const int MSSV;
extern const int HEIGHT; //1050
extern const int WIDTH; //610
extern const int X_GATE;
extern const int Y_GATE;
extern const int MAX_FOOD;

extern int SPEED;
extern int length_of_snake;
extern int score;
extern char S[];
extern bool gameover;
extern Point* I;
extern int snake_direction;
extern int x_food, y_food, pause;
extern int x_cr, y_cr;
extern bool is_on[2];
extern bool next_level;
extern int draw;
extern int game;
extern bool go_next;
extern bool is_outtro;
extern int food_ate;
extern int draw_energy;
extern int level;
extern int preX, preY;
extern bool running;
extern bool play;
extern int prex, prey;
extern int outGate, inGate;
extern char character_from_keyboard;
extern bool load;
extern int gateColor;
extern bool load_check;
#endif