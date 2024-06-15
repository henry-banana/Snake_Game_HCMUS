#ifndef _Menu_H_
#define _Menu_H_
#pragma once
#include "resource.h"
#include "Snake.h"
#include "Sound.h"

void delete_old_pause_menu(int x, int y, int w, int h, int number, int color);

void conver_string_into_pixel(const string s, int x, int y);

void menu();

void welcome();

void Mes_exit();

#endif



