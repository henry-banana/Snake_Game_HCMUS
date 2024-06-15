#ifndef _file_function_H
#define _file_function_H
//Chua cac ham xu li file
#pragma once
#include "resource.h"
#include "Variable.h"
using namespace std;

void read_file(const string s, int x, int y);

void destroy_file(const string s, int x, int y, int color);

bool checkStr(string str);

void gameOverScreen();
#endif
