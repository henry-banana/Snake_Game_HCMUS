#include "../header/Menu.h"

const int X_SCREEN_TOP = 0;
const int Y_SCREEN_TOP = 9;
const int X_SCREEN_BOTTOM = X_SCREEN_TOP + 78;
const int Y_SCREEN_BOTTOM = Y_SCREEN_TOP + 33;
const int X_BLOCK_1 = X_SCREEN_TOP + 30;
const int X_BLOCK_2 = X_SCREEN_TOP + 50;
const int MAX = 200;
const int MSSV = 41;
const int HEIGHT = 1240; //1050
const int WIDTH = 750; //610
const int X_GATE = X_SCREEN_TOP + 60;
const int Y_GATE = Y_SCREEN_BOTTOM - 3;
const int MAX_FOOD = 5;

int SPEED = 250;
int length_of_snake = 4;
int score = 0;
char S[MSSV] = { ':' ,'2','3','1','2','0','2','5','2','2','3','1','2','0','2','4','3','2','3','1','2','0','2','4','2','2','3','1','2','0','2','6','2','2','3','1','2','0','2','6','4'};
bool gameover = false;
Point* I = nullptr;
int snake_direction = 3;
int x_food, y_food, pause;
int x_cr = X_SCREEN_BOTTOM / 2, y_cr = Y_SCREEN_BOTTOM / 2;
bool is_on[2] = { 1,1 };
bool next_level = false;
int draw = 0;
int game = 1;
bool go_next = false;
bool is_outtro = false;
int food_ate = 1;
int draw_energy = 0;
int level = 0;
int preX = 0, preY = 0;
bool running = true;
bool play = true;
int prex, prey;
int outGate, inGate;
char character_from_keyboard;
bool load;
int gateColor = 1;
bool load_check = false;

int main() {
	LPCWSTR title = L"SNAKE GAME - GROUP 1 - 23CTT3 - HCMUS";
	SetConsoleTitleW(title);
	FixConsoleWindow();
	SetConsoleOutputCP(CP_UTF8);
	welcome();
	Sleep(10000);
	free(I);
	return 0;
}