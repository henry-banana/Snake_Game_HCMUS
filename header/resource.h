#ifndef _resourse_H_
#define _resourse_H_
#pragma once 
#include "Variable.h"
#define KEY_NONE -1

void gotoXY(int x, int y);

//Ham dat mau cho chu
void SetColor(WORD color);

//Ham lam an con tro chuot
void ShowCur(bool CursorVisibility);


// Ham thay doi kich thuoc console
void resizeConsole(int width, int height);

//Ham co dinh man hinh console
void FixConsoleWindow();

void FixConsole();


void textcolor(int x);

void setConsoleFontSize(int sizex, int sizey);

void SetConsoleFont(int a, int b, const wchar_t* font);

void shutdownConsole();

#endif