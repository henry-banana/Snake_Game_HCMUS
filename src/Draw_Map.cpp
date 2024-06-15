#include "../header/Draw_Map.h"

void draw_left_right_wall(int x) {
	textcolor(50);
	SetColor(7);

	int y = Y_SCREEN_TOP + 1;

	if (x < X_SCREEN_BOTTOM) {
		gotoXY(X_SCREEN_TOP, Y_SCREEN_TOP);
		cout << char(201); // tren ben trai
		gotoXY(X_SCREEN_TOP, Y_SCREEN_BOTTOM + 1);
		cout << char(200); // duoi ben trai
	}

	while (y <= Y_SCREEN_BOTTOM) {
		gotoXY(x, y);
		if (!(x % X_SCREEN_BOTTOM == 0)) {
			cout << char(186);
		}
		else {
			cout << char(179);
		}
		y++;
	}
}

void draw_top_bottom_wall(int y) {
	// y = 1, 26
	int x = X_SCREEN_TOP + 1;
	while (x <= X_SCREEN_BOTTOM - 1) {
		gotoXY(x, y);
		cout << char(205);
		x++;
	}

	if (y < Y_SCREEN_BOTTOM) {
		gotoXY(X_SCREEN_BOTTOM, Y_SCREEN_TOP);
		cout << char(209); // tren ben phai
	}
	else {
		gotoXY(X_SCREEN_BOTTOM, Y_SCREEN_BOTTOM + 1); // duoi ben phai
		cout << char(207);
	}
}

void draw_mini_top_bottom_wall(int y) {
	int x = X_SCREEN_BOTTOM + 1;
	while (x < X_SCREEN_BOTTOM + 20) {
		gotoXY(x, y);
		cout << char(205);
		x++;
	}

	gotoXY(x, y);
	if (y < Y_SCREEN_BOTTOM) {
		cout << char(187);
	}
	else {
		cout << char(188);
	}

}

void draw_score() {
	score = length_of_snake - 4;
	string s = to_string(score);
	int dis = 0;
	textcolor(150);

	for (int i = 86; i < 97; i++) {
		for (int j = 2; j < 10; j++) {
			gotoXY(i, j);
			cout << ' ';
		}
	}

	for (char x : s) {
		string ans = "";
		ans += x;
		read_file(ans, 86 + dis, 2);
		dis += 4;
	}

	textcolor(230);

}

void draw_game() {
	textcolor(230);
	for (int x = X_SCREEN_TOP + 1; x < X_SCREEN_BOTTOM; x++) {
		for (int y = Y_SCREEN_TOP + 1; y <= Y_SCREEN_BOTTOM; y++) {
			gotoXY(x, y);
			cout << ' ';
		}
	}
}


void draw_comment() {
	for (int x = Y_SCREEN_TOP; x < Y_SCREEN_BOTTOM + 2; x++) {
		for (int y = X_SCREEN_TOP; y < X_SCREEN_BOTTOM + 1; y++) {
			gotoXY(y, x);
			SetColor(2);
			cout << char(219);
		}
	}

	gotoXY(X_SCREEN_BOTTOM / 2, Y_SCREEN_BOTTOM / 2);
	SetColor(3);
	cout << "GAME OVER";

}

void gate_init() {
	textcolor(230);
	SetColor(0);
	gotoXY(X_GATE, Y_GATE);
	cout << ']';
	gotoXY(X_GATE - 51, Y_GATE - 5);
	cout << '[';
}

void draw_wall_and_numbers() {
	system("cls");
	ShowCur(0);
	system("color 70");
	resizeConsole(HEIGHT, WIDTH);

	draw_left_right_wall(X_SCREEN_TOP);
	draw_left_right_wall(X_SCREEN_BOTTOM);
	draw_left_right_wall(X_SCREEN_BOTTOM + 20);
	draw_top_bottom_wall(Y_SCREEN_TOP);
	draw_top_bottom_wall(Y_SCREEN_BOTTOM + 1);
	draw_mini_top_bottom_wall(Y_SCREEN_TOP);
	draw_mini_top_bottom_wall(Y_SCREEN_BOTTOM + 1);
	draw_game();
	draw_score();

	if (game == 1) {
		gate_init();
	}
	else if (game == 2) {
		textcolor(10);
		for (int i = X_SCREEN_TOP + 15; i <= X_SCREEN_BOTTOM - 15; i++) {
			gotoXY(i, Y_SCREEN_TOP + 8);
			cout << ' ';
			gotoXY(i, Y_SCREEN_BOTTOM - 8);
			cout << ' ';

		}
		for (int i = Y_SCREEN_TOP + 8; i <= Y_SCREEN_TOP + 14; i++) {
			gotoXY(X_SCREEN_TOP + 15, i);
			cout << ' ';
			gotoXY(X_SCREEN_BOTTOM - 15, i);
			cout << ' ';
		}

		for (int i = Y_SCREEN_BOTTOM - 8; i >= Y_SCREEN_BOTTOM - 14; i--) {
			gotoXY(X_SCREEN_TOP + 15, i);
			cout << ' ';
			gotoXY(X_SCREEN_BOTTOM - 15, i);
			cout << ' ';
		}
		textcolor(230);
	}
	else if (game == 3) {
		textcolor(10);
		for (int i = Y_SCREEN_TOP + 5; i <= Y_SCREEN_BOTTOM - 5; i++) {
			gotoXY(X_SCREEN_TOP + 10, i);
			cout << ' ';
			gotoXY(X_SCREEN_BOTTOM - 10, i);
			cout << ' ';
			gotoXY(X_SCREEN_TOP + 17, i);
			cout << ' ';
			gotoXY(X_SCREEN_BOTTOM - 17, i);
			cout << ' ';
		}
		for (int i = X_SCREEN_TOP + 17; i <= X_SCREEN_BOTTOM - 25; i++) {
			gotoXY(i, Y_SCREEN_TOP + 8);
			cout << ' ';
		}
		for (int i = X_SCREEN_BOTTOM - 17; i >= X_SCREEN_TOP + 25; i--) {
			gotoXY(i, Y_SCREEN_BOTTOM - 8);
			cout << ' ';
		}

		textcolor(230);
	}
	else if (game == 4) {
		textcolor(10);
		for (int i = X_SCREEN_TOP; i <= X_SCREEN_TOP + 60; i++) {
			gotoXY(i, Y_SCREEN_TOP + 5);
			cout << ' ';
			gotoXY(X_SCREEN_BOTTOM - i, Y_SCREEN_BOTTOM - 5);
			cout << ' ';
		}
		for (int i = Y_SCREEN_TOP; i <= Y_SCREEN_TOP + 13; i++) {
			gotoXY(X_SCREEN_BOTTOM - 10, i);
			cout << ' ';
			gotoXY(X_SCREEN_TOP + 10, Y_SCREEN_BOTTOM - i + Y_SCREEN_TOP);
			cout << ' ';
		}

		for (int i = X_SCREEN_BOTTOM - 10; i >= X_SCREEN_BOTTOM - 35; i--) {
			gotoXY(i, Y_SCREEN_TOP + 13);
			cout << ' ';
		}

		for (int i = X_SCREEN_TOP + 10; i <= X_SCREEN_TOP + 35; i++) {
			gotoXY(i, Y_SCREEN_BOTTOM - 13);
			cout << ' ';
		}

		textcolor(230);
	}
}

void draw_box(int x, int y, int w, int h, int box_color, int b_color, string nd) {

	textcolor(b_color);
	for (int i = y + 1; i < y + h - 1; i++) {
		for (int j = x + 1; j < x + w - 1; j++) {
			gotoXY(j, i);
			cout << ' ';
		}
	}

	SetColor(0);
	gotoXY(x + 1, y + 1);
	cout << nd;

	textcolor(240);
	SetColor(box_color);

	//ve vien khung************
	for (int i = x; i <= x + w; i++) {
		gotoXY(i, y);
		cout << ' ';
		gotoXY(i, y + h);
		cout << ' ';
	}
	for (int i = y; i <= y + h; i++) {
		gotoXY(x, i);
		cout << ' ';
		gotoXY(x + w, i);
		cout << ' ';
	}

	gotoXY(x, y);
	cout << ' ';
	gotoXY(x + w, y);
	cout << ' ';
	gotoXY(x, y + h);
	cout << ' ';
	gotoXY(x + w, y + h);
	cout << ' ';
	//************************

}


void box_light(int x, int y, int w, int h, int b_color, string nd) {
	textcolor(b_color);
	for (int i = y + 1; i < y + h - 1; i++) {
		for (int j = x + 1; j < x + w - 1; j++) {
			gotoXY(j, i);
			cout << ' ';
		}
	}

	SetColor(7);
	gotoXY(x + 1, y + 1);
	cout << nd;
}