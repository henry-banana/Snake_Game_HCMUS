#ifndef _Sound_H_
#define _Sound_H_
#pragma once
#include "../header/Variable.h"
#pragma comment(lib, "Winmm.lib")


void playNgu();
void playPop();

void playNen();

void playSound();

void stopSound();

void soundControl(bool& running, bool& play);

#endif