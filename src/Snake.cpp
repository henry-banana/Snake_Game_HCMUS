#include "../header/Snake.h"

int pause_menu() {
	SetConsoleOutputCP(CP_UTF8);

	fstream fin;
	fin.open("resource\\front-end\\draw\\pause\\title.txt", std::ios::in);
	int x_pause = 18, y_pause = 11, k_pause = 224;
	while (!fin.eof()) {
		std::string _text;
		getline(fin, _text);
		gotoXY(x_pause, y_pause++);
		textcolor(k_pause);
		std::cout << _text;
	}
	fin.close();

	read_file("pause\\button", 19, 18);
	read_file("pause\\button", 19, 26);
	read_file("pause\\button", 19, 34);

	fin.open("resource\\front-end\\draw\\pause\\resume.txt", std::ios::in);
	fin >> x_pause >> y_pause >> k_pause;
	while (!fin.eof()) {
		std::string _text;
		getline(fin, _text);
		gotoXY(x_pause, y_pause++);
		textcolor(k_pause);
		std::cout << _text;
	}
	fin.close();

	fin.open("resource\\front-end\\draw\\pause\\save.txt", std::ios::in);
	fin >> x_pause >> y_pause >> k_pause;
	while (!fin.eof()) {
		std::string _text;
		getline(fin, _text);
		gotoXY(x_pause, y_pause++);
		textcolor(k_pause);
		std::cout << _text;
	}
	fin.close();

	fin.open("resource\\front-end\\draw\\pause\\exit.txt", std::ios::in);
	fin >> x_pause >> y_pause >> k_pause;
	while (!fin.eof()) {
		std::string _text;
		getline(fin, _text);
		gotoXY(x_pause, y_pause++);
		textcolor(k_pause);
		std::cout << _text;
	}
	fin.close();

	read_file("pause\\button_CLICK", 19, 18);

	fin.open("resource\\front-end\\draw\\pause\\resume_CLICK.txt", std::ios::in);
	fin >> x_pause >> y_pause >> k_pause;
	while (!fin.eof()) {
		std::string _text;
		getline(fin, _text);
		gotoXY(x_pause, y_pause++);
		textcolor(k_pause);
		std::cout << _text;
	}
	fin.close();

	int i = 0;
	char character_from_keyboard;
	while (true) {
		if (_kbhit()) {
			character_from_keyboard = _getch();
			if (character_from_keyboard == 72 || character_from_keyboard == 'w') { //len
				if (is_on[0]) {
					Beep(500, 80);
				}
				if (i == 1) {
					i = 0;
					read_file("pause\\button", 19, 26);

					fin.open("resource\\front-end\\draw\\pause\\save.txt", std::ios::in);
					fin >> x_pause >> y_pause >> k_pause;
					while (!fin.eof()) {
						std::string _text;
						getline(fin, _text);
						gotoXY(x_pause, y_pause++);
						textcolor(k_pause);
						std::cout << _text;
					}
					fin.close();

					read_file("pause\\button_CLICK", 19, 18);

					fin.open("resource\\front-end\\draw\\pause\\resume_CLICK.txt", std::ios::in);
					fin >> x_pause >> y_pause >> k_pause;
					while (!fin.eof()) {
						std::string _text;
						getline(fin, _text);
						gotoXY(x_pause, y_pause++);
						textcolor(k_pause);
						std::cout << _text;
					}
					fin.close();
				}

				else if (i == 2) {
					i = 1;
					read_file("pause\\button", 19, 34);

					fin.open("resource\\front-end\\draw\\pause\\exit.txt", std::ios::in);
					fin >> x_pause >> y_pause >> k_pause;
					while (!fin.eof()) {
						std::string _text;
						getline(fin, _text);
						gotoXY(x_pause, y_pause++);
						textcolor(k_pause);
						std::cout << _text;
					}
					fin.close();

					read_file("pause\\button_CLICK", 19, 26);

					fin.open("resource\\front-end\\draw\\pause\\save_CLICK.txt", std::ios::in);
					fin >> x_pause >> y_pause >> k_pause;
					while (!fin.eof()) {
						std::string _text;
						getline(fin, _text);
						gotoXY(x_pause, y_pause++);
						textcolor(k_pause);
						std::cout << _text;
					}
					fin.close();
				}
			}
			else if (character_from_keyboard == 80 || character_from_keyboard == 's') { //xuong
				if (is_on[0]) {
					Beep(500, 80);
				}
				if (i == 0) {
					i = 1;
					read_file("pause\\button", 19, 18);

					fin.open("resource\\front-end\\draw\\pause\\resume.txt", std::ios::in);
					fin >> x_pause >> y_pause >> k_pause;
					while (!fin.eof()) {
						std::string _text;
						getline(fin, _text);
						gotoXY(x_pause, y_pause++);
						textcolor(k_pause);
						std::cout << _text;
					}
					fin.close();

					read_file("pause\\button_CLICK", 19, 26);

					fin.open("resource\\front-end\\draw\\pause\\save_CLICK.txt", std::ios::in);
					fin >> x_pause >> y_pause >> k_pause;
					while (!fin.eof()) {
						std::string _text;
						getline(fin, _text);
						gotoXY(x_pause, y_pause++);
						textcolor(k_pause);
						std::cout << _text;
					}
					fin.close();
				}
				else if (i == 1) {
					i = 2;
					read_file("pause\\button", 19, 26);

					fin.open("resource\\front-end\\draw\\pause\\save.txt", std::ios::in);
					fin >> x_pause >> y_pause >> k_pause;
					while (!fin.eof()) {
						std::string _text;
						getline(fin, _text);
						gotoXY(x_pause, y_pause++);
						textcolor(k_pause);
						std::cout << _text;
					}
					fin.close();

					read_file("pause\\button_CLICK", 19, 34);

					fin.open("resource\\front-end\\draw\\pause\\exit_CLICK.txt", std::ios::in);
					fin >> x_pause >> y_pause >> k_pause;
					while (!fin.eof()) {
						std::string _text;
						getline(fin, _text);
						gotoXY(x_pause, y_pause++);
						textcolor(k_pause);
						std::cout << _text;
					}
					fin.close();
				}
			}

			if (character_from_keyboard == 13) { //enter
				if (is_on[0]) {
					Beep(1500, 80);
				}
				return i;
			}


		}

	}
}

//Kiem tra thuc an tao ra co nam tren ran hay khong ( day la 1 ham con nam trong ham create_food)
bool is_snake_lying_on_food(int x, int y) {
	for (int i = 0; i < length_of_snake; i++) {
		if (x == I[i].x && y == I[i].y) {
			return true;
		}
	}
	return false;
}

//Ham tao thuc an
void create_food() {
	int x, y;
	if (length_of_snake < MAX_FOOD * level + 4) {
		if (game == 1) {
			x = rand() % (X_SCREEN_BOTTOM - X_SCREEN_TOP) + X_SCREEN_TOP;
			y = rand() % (Y_SCREEN_BOTTOM - Y_SCREEN_TOP) + Y_SCREEN_TOP;

			while (is_snake_lying_on_food(x, y) || (x == X_GATE && y == Y_GATE) || (x == X_GATE - 51 && y == Y_GATE - 5)) {
				x = rand() % (X_SCREEN_BOTTOM - X_SCREEN_TOP) + X_SCREEN_TOP;
				y = rand() % (Y_SCREEN_BOTTOM - Y_SCREEN_TOP) + Y_SCREEN_TOP;
			}
		}
		else if (game == 2) {
			bool re_create = false;
			do {
				x = rand() % (X_SCREEN_BOTTOM - X_SCREEN_TOP) + X_SCREEN_TOP;
				y = rand() % (Y_SCREEN_BOTTOM - Y_SCREEN_TOP) + Y_SCREEN_TOP;

				if (((x >= X_SCREEN_TOP + 15 && x <= X_SCREEN_BOTTOM - 15) && (y == Y_SCREEN_TOP + 8 || y == Y_SCREEN_BOTTOM - 8)) || ((x == X_SCREEN_TOP + 15 || x == X_SCREEN_BOTTOM - 15) && ((y >= Y_SCREEN_TOP + 8 && y <= Y_SCREEN_TOP + 14) || (y <= Y_SCREEN_BOTTOM - 8 && y >= Y_SCREEN_BOTTOM - 14))))
					re_create = true;
			} while (is_snake_lying_on_food(x, y) || re_create);
		}
		else if (game == 3) {
			bool re_create = false;
			do {
				x = rand() % (X_SCREEN_BOTTOM - X_SCREEN_TOP) + X_SCREEN_TOP;
				y = rand() % (Y_SCREEN_BOTTOM - Y_SCREEN_TOP) + Y_SCREEN_TOP;

				if (((x == X_SCREEN_TOP + 10 || x == X_SCREEN_BOTTOM - 10 || x == X_SCREEN_TOP + 17 || x == X_SCREEN_BOTTOM - 17) && (y >= Y_SCREEN_TOP + 5 && Y_SCREEN_BOTTOM - 5 >= y)) || (((x >= X_SCREEN_TOP + 17 && x <= X_SCREEN_BOTTOM - 25 && y == Y_SCREEN_TOP + 8) || (x >= X_SCREEN_TOP + 25 && x <= X_SCREEN_BOTTOM - 17 && y == Y_SCREEN_BOTTOM - 8))))
					re_create = true;
			} while (is_snake_lying_on_food(x, y) || re_create);
		}
		else {
			bool re_create = false;
			do {
				x = rand() % (X_SCREEN_BOTTOM - X_SCREEN_TOP) + X_SCREEN_TOP;
				y = rand() % (Y_SCREEN_BOTTOM - Y_SCREEN_TOP) + Y_SCREEN_TOP;

				if (((x <= X_SCREEN_TOP + 60 && x >= X_SCREEN_TOP && y == Y_SCREEN_TOP + 5) || (x <= X_SCREEN_BOTTOM && x >= X_SCREEN_BOTTOM - 60 && y == Y_SCREEN_BOTTOM - 5)) || ((x >= X_SCREEN_TOP + 10 && x <= X_SCREEN_TOP + 35 && y == Y_SCREEN_BOTTOM - 13) || (x <= X_SCREEN_BOTTOM - 10 && x >= X_SCREEN_BOTTOM - 35 && y == Y_SCREEN_TOP + 13)))
					re_create = true;
			} while (is_snake_lying_on_food(x, y) || re_create);
		}
		x_food = x;
		y_food = y;
		gotoXY(x, y);
		textcolor(206);
		if (x_food != 0)
			cout << '0';
	}
}

//Khoi tao ran luc choi game moi
void snake_init() {
	snake_direction = 3;
	food_ate = 1;
	draw_energy = 0;
	draw_score();
	int x = X_SCREEN_TOP + length_of_snake + 1, y = Y_SCREEN_TOP + 1;
	for (int i = 0; i < length_of_snake; i++) {
		I[i].x = x;
		I[i].y = y;
		x--;
	}
}

//Ve ran
void draw_snake() {
	ShowCur(0);
	textcolor(160);
	if (outGate < length_of_snake) {
		for (int i = 0; i < outGate; i++) {
			gotoXY(I[i].x, I[i].y);
			cout << S[i % MSSV];
		}
	}
	else if (outGate >= length_of_snake && (go_next == false)) {

		for (int i = 0; i < length_of_snake; i++) {
			gotoXY(I[i].x, I[i].y);
			cout << (S[i % MSSV]);
		}
		gotoXY(preX, preY);
		textcolor(230);
		if (preX != 0) {
			cout << ' ';
		}
	}
	else {

		for (int i = 0; i < length_of_snake; i++) {
			gotoXY(I[i].x, I[i].y);
			if (i <= draw) {
				textcolor(230);
				cout << ' ';
			}
			else {
				textcolor(160);
				cout << (S[i % MSSV]);
			}
		}
		draw++;
	}

	if (draw == length_of_snake) {
		is_outtro = true;
		go_next = false;
		draw = 0;
	}
	if (gameover) {
		gotoXY(I[0].x, I[0].y);
		textcolor(70);
		cout << 'x';
		Sleep(500);
	}
}

//Di chuyen ran
void Move() {
	int prevX = I[0].x;
	int prevY = I[0].y;
	switch (snake_direction) {
	case 2:
		I[0].x -= 1;
		break;
	case 3:
		I[0].x += 1;
		break;
	case 1:
		I[0].y -= 1;
		break;
	case 0:
		I[0].y += 1;
		break;
	default:
		break;
	}

	for (int i = 1; i < length_of_snake; i++) {
		int prev2X = I[i].x;
		int prev2Y = I[i].y;
		I[i].x = prevX;
		I[i].y = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	prex = prevX;
	prey = prevY;
}

//Kiem tra ran dung wall hay chua
bool is_snake_alive() {
	//Kiem tra ran dung wall
	if (I[0].y == Y_SCREEN_BOTTOM + 1 || I[0].y == Y_SCREEN_TOP || I[0].x == X_SCREEN_TOP || I[0].x == X_SCREEN_BOTTOM) {
		return false;
	}
	//Kiem tra ran can chinh no
	for (int i = 1; i < length_of_snake; i++) {
		if (I[0].x == I[i].x && I[0].y == I[i].y) {
			return false;
		}
	}

	if ((MAX_FOOD * level - length_of_snake + 4) == 0) {
		textcolor(70);
		SetColor(0);
		if (draw_energy == 0) {
			string ans = "";
			for (int i = 1; i < 16; i++) {
				ans = "open_gate\\light (" + to_string(i) + ")";
				read_file(ans, 77, 9);
				Sleep(50);
			}
			textcolor(10);
			for (int i = 10; i < Y_SCREEN_BOTTOM - 10; i++) {
				gotoXY(X_SCREEN_BOTTOM, i);
				cout << ' ';
			}
			draw_energy = 1;
		}

		gotoXY(X_SCREEN_BOTTOM - 1, Y_SCREEN_TOP + 1);
		textcolor((gateColor += 20) % 255);
		cout << ' ';

		gotoXY(X_SCREEN_BOTTOM, Y_SCREEN_TOP + 1);
		textcolor(170);
		cout << ' ';

		gotoXY(X_SCREEN_BOTTOM, Y_SCREEN_TOP + 2);
		textcolor(170);
		cout << ' ';

		gotoXY(X_SCREEN_BOTTOM - 1, Y_SCREEN_TOP);
		textcolor(170);
		cout << ' ';

		gotoXY(X_SCREEN_BOTTOM, Y_SCREEN_TOP);
		textcolor(170);
		cout << ' ';

		gotoXY(X_SCREEN_BOTTOM, Y_SCREEN_TOP + 1);
		textcolor(170);
		cout << ' ';

		gotoXY(X_SCREEN_BOTTOM, Y_SCREEN_TOP + 2);
		textcolor(170);
		cout << ' ';

		gotoXY(X_SCREEN_BOTTOM - 1, Y_SCREEN_TOP + 2);
		textcolor(170);
		cout << ' ';

		next_level = true;
	}


	return true;
}

//Ham con trong ham draw_snake dung de xoa anh ran o vi tri cuoi duoi
void delete_old_snake() {
	textcolor(230);
	gotoXY(preX, preY);
	cout << ' ';
}

//Ham input ten khi save game
void input_name() {
	delete_old_pause_menu(X_SCREEN_TOP, Y_SCREEN_TOP, 120, 31, 1, 120);
	draw_game();
	gotoXY(X_SCREEN_TOP + 2, Y_SCREEN_TOP + 14);
	textcolor(230);
	SetColor(0);
	read_file("Toro", 25, 12);
	gotoXY(22, 12);
	textcolor(230);
	SetColor(0);
	cout << "PLEASE INPUT YOUR NAME TO SAVE ";
	gotoXY(15, 26);
	cout << "Your name: ";
	string NAME;
	getline(cin, NAME);
	while (checkStr(NAME)) {
		gotoXY(15, 26);
		cout << "                                                      ";
		gotoXY(15, 28);
		SetColor(4);
		cout << "Your name are not valid!";
		gotoXY(15, 26);
		SetColor(4);
		cout << "Please input again: ";
		SetColor(0);
		getline(cin, NAME);
	}
	gotoXY(15, 28);
	SetColor(2);
	cout << "Get your name successfully!";

	ofstream outputFile("resource\\load-game\\" + NAME + ".txt");
	outputFile << length_of_snake << ' ' << snake_direction << ' ' << game << ' ' << x_food << ' ' << y_food << ' ' << food_ate << ' ' << level << endl;
	for (int i = 0; i < length_of_snake; i++) {
		outputFile << I[i].x << ' ' << I[i].y << endl;
	}
	outputFile << I[0].x << ' ' << I[0].y << endl;
	outputFile.close();
	ifstream filename("resource\\load-game\\filename.txt");
	string name[11];
	int i = 1, flag = 0;
	bool sameName = false;
	while (!filename.eof()) {
		filename >> name[i];
		i++;
	}
	filename.close();

	for (int j = 1; j < i; j++) {
		if (NAME == name[j]) {
			sameName = true;
			flag = j;
		}
	}
	if (!sameName) {
		name[0] = NAME;
	}
	else {
		name[0] = name[flag];
		name[flag].erase(0);
	}
	ofstream filenamein("resource\\load-game\\filename.txt");
	for (int i = 0; i < 10; i++)
		filenamein << name[i] << '\n';
	filenamein.close();
	Sleep(1000);
	level = 0;
	food_ate = 1;
	snake_direction = 3;
	length_of_snake = 4;
	free(I);
	menu();
}

//Ham thong so tu ban phim khi choi game
void keyboard_input() {
	if (_kbhit()) {
		character_from_keyboard = _getch();
		if (character_from_keyboard == -32) {
			character_from_keyboard = _getch();
			if (character_from_keyboard == 72 && snake_direction != 0) { //len
				snake_direction = 1;
			}
			else if (character_from_keyboard == 80 && snake_direction != 1) { //xuong
				snake_direction = 0;
			}
			else if (character_from_keyboard == 75 && snake_direction != 3) { // trai
				snake_direction = 2;
			}
			else if (character_from_keyboard == 77 && snake_direction != 2) { //phai
				snake_direction = 3;
			}

		}

		if (character_from_keyboard == 'w' && snake_direction != 0) {
			S[0] = '\"';
			snake_direction = 1;
		}
		else if (character_from_keyboard == 's' && snake_direction != 1) {
			S[0] = '\"';
			snake_direction = 0;
		}
		else if (character_from_keyboard == 'a' && snake_direction != 3) {
			S[0] = ':';
			snake_direction = 2;
		}
		else if (character_from_keyboard == 'd' && snake_direction != 2) {
			S[0] = ':';
			snake_direction = 3;
		}

		if (character_from_keyboard == 'p') {
			// ve de menu
			draw_snake();
			pause = pause_menu();
			if (pause == 0) { //RESUME GAME
				delete_old_pause_menu(X_SCREEN_TOP + 30, Y_SCREEN_TOP + 4, 18, 2, 6, 230);
				draw_snake();
				gotoXY(x_food, y_food);
				textcolor(206);
				if (x_food != 0)
					cout << '0';
				if ((MAX_FOOD * level - length_of_snake + 4) == 0) {
					gotoXY(X_SCREEN_BOTTOM - 1, Y_SCREEN_TOP + 1);
					textcolor(70);
					cout << ' ';
				}
			}
			else if (pause == 1) { //SAVE GAME
				delete_old_pause_menu(X_SCREEN_TOP + 101, Y_SCREEN_TOP + 10, 18, 2, 4, 120);
				input_name();


			}
			else if (pause == 2) { //EXIT
				level = 0;
				food_ate = 1;
				snake_direction = 3;
				length_of_snake = 4;
				free(I);
				I = nullptr;
				menu();
				delete_old_pause_menu(X_SCREEN_TOP + 101, Y_SCREEN_TOP + 10, 18, 2, 4, 120);
			}
			delete_old_snake();
		}
	}
}

//Ham kiem tra va cham voi cac chuong ngai vat
void check_collision() {
	if ((I[0].x == X_SCREEN_BOTTOM - 2 || I[0].x == X_SCREEN_BOTTOM - 1) && I[0].y == Y_SCREEN_TOP + 2 && food_ate == 6)
		gameover = true;
	int i = 0, x_pre = I[length_of_snake - 1].x, y_pre = I[length_of_snake - 1].y;

	if (game == 1) {

		if (I[0].x == X_GATE && I[0].y == Y_GATE && snake_direction != 3) {
			gameover = true;
		}
		else if (I[i].x == X_GATE && I[i].y == Y_GATE) {

			I[i].x -= 50;
			I[i].y -= 5;
			x_cr -= 50;
			y_cr -= 5;

		}

		if (I[0].x == X_GATE - 51 && I[0].y == Y_GATE - 5 && snake_direction != 2) {
			gameover = true;

		}

		else if (I[0].x == X_GATE - 51 && I[0].y == Y_GATE - 5) {
			I[0].x += 50;
			I[0].y += 5;
			x_cr += 50;
			y_cr += 5;
		}
	}
	else if (game == 2) {

		if (((I[0].x >= X_SCREEN_TOP + 15 && I[0].x <= X_SCREEN_BOTTOM - 15) && (I[0].y == Y_SCREEN_TOP + 8 || I[0].y == Y_SCREEN_BOTTOM - 8)) || ((I[0].x == X_SCREEN_TOP + 15 || I[0].x == X_SCREEN_BOTTOM - 15) && ((I[0].y >= Y_SCREEN_TOP + 8 && I[0].y <= Y_SCREEN_TOP + 14) || (I[0].y <= Y_SCREEN_BOTTOM - 8 && I[0].y >= Y_SCREEN_BOTTOM - 14)))) {
			gameover = true;
		}

	}
	else if (game == 3) {

		if ((I[0].x == X_SCREEN_TOP + 10 || I[0].x == X_SCREEN_BOTTOM - 10 || I[0].x == X_SCREEN_TOP + 17 || I[0].x == X_SCREEN_BOTTOM - 17) && (I[0].y >= Y_SCREEN_TOP + 5 && Y_SCREEN_BOTTOM - 5 >= I[0].y))
			gameover = true;

		if ((I[0].x >= X_SCREEN_TOP + 17 && I[0].x <= X_SCREEN_BOTTOM - 25 && I[0].y == Y_SCREEN_TOP + 8) || (I[0].x >= X_SCREEN_TOP + 25 && I[0].x <= X_SCREEN_BOTTOM - 17 && I[0].y == Y_SCREEN_BOTTOM - 8))
			gameover = true;

	}
	else if (game == 4) {

		if ((I[0].x <= X_SCREEN_TOP + 60 && I[0].x >= X_SCREEN_TOP && I[0].y == Y_SCREEN_TOP + 5) || (I[0].x <= X_SCREEN_BOTTOM && I[0].x >= X_SCREEN_BOTTOM - 60 && I[0].y == Y_SCREEN_BOTTOM - 5))
			gameover = true;
		if ((I[0].x >= X_SCREEN_TOP + 10 && I[0].x <= X_SCREEN_TOP + 35 && I[0].y == Y_SCREEN_BOTTOM - 13) || (I[0].x <= X_SCREEN_BOTTOM - 10 && I[0].x >= X_SCREEN_BOTTOM - 35 && I[0].y == Y_SCREEN_TOP + 13))
			gameover = true;

	}
}

//Ham thuc hien cac thao tac khi an thuc an
void eat_food() {
	if (x_food == I[0].x && y_food == I[0].y) {
		length_of_snake++;

		Move();

		score++;
		draw_score();
		if (is_on[0]) {
			playPop();
		}
		if (MAX_FOOD * level - length_of_snake + 4 != 0) {
			create_food();
		}
		if (food_ate < 6) {

			string ans = "object\\energy";
			switch (food_ate) {
			case 1:
				ans = ans + "1";
				break;
			case 2:
				ans = ans + "2";
				break;
			case 3:
				ans = ans + "3";
				break;
			case 4:
				ans = ans + "4";
				break;
			case 5:
				ans = ans + "5";
				break;
			}
			food_ate++;
			read_file(ans, 83, 24);
		}
		if (food_ate == 6) {
			x_food = 0;
			y_food = 0;
			food_ate = 5;
		}
	}
}

void snake_run() {

	keyboard_input();
	Move();
	check_collision();

	if (I[0].x == X_SCREEN_BOTTOM - 1 && I[0].y == Y_SCREEN_TOP + 1 && next_level == true) {
		I[0].x = X_SCREEN_TOP + 1;
		I[0].y = Y_SCREEN_TOP + 1;
		go_next = true;
	}
}

void intro() {
	ShowCur(0);

	gotoXY(X_SCREEN_TOP + 1, Y_SCREEN_TOP);
	textcolor(70);
	cout << ' ';

	gotoXY(X_SCREEN_TOP, Y_SCREEN_TOP + 1);
	textcolor(70);
	cout << ' ';

	gotoXY(X_SCREEN_TOP + 1, Y_SCREEN_TOP + 2);
	textcolor(70);
	cout << ' ';

	gotoXY(X_SCREEN_TOP, Y_SCREEN_TOP + 2);
	textcolor(70);
	cout << ' ';

	gotoXY(X_SCREEN_TOP, Y_SCREEN_TOP);
	textcolor(70);
	cout << ' ';

	for (int j = 0; j < length_of_snake; j++) {
		gotoXY(X_SCREEN_TOP + 1, Y_SCREEN_TOP + 1);
		textcolor((gateColor += 20) % 255);
		cout << ' ';
		textcolor(160);
		for (int i = 0; i <= j; i++) {
			gotoXY(I[i].x + j - (length_of_snake - 1), I[i].y);
			cout << (S[i % MSSV]);
		}

		gotoXY(X_SCREEN_BOTTOM / 2 - 3, Y_SCREEN_BOTTOM / 2);
		Sleep(200);

	}

	gotoXY(X_SCREEN_TOP + 1, Y_SCREEN_TOP);
	textcolor(0);
	cout << ' ';

	gotoXY(X_SCREEN_TOP, Y_SCREEN_TOP + 1);
	textcolor(0);
	cout << ' ';

	gotoXY(X_SCREEN_TOP + 1, Y_SCREEN_TOP + 2);
	textcolor(230);
	cout << ' ';

	gotoXY(X_SCREEN_TOP, Y_SCREEN_TOP + 2);
	textcolor(0);
	cout << ' ';

	gotoXY(X_SCREEN_TOP, Y_SCREEN_TOP);
	textcolor(0);
	cout << ' ';

	outGate = length_of_snake;
}

//Phan ket thuc man choi khi nguoi choi thua
void end_game() {
	gameOverScreen();
	system("cls");
	system("color F0");
	SetConsoleFont(12, 16, L"Consolas");
	resizeConsole(HEIGHT, WIDTH);
	read_file("congratulation", 0, 0);
	int h = 99, w = 44;
	textcolor(10);
	for (int i = 0; i < h; i++) {
		gotoXY(i, 0);
		cout << ' ';
		gotoXY(i, w - 1);
		cout << ' ';
	}

	for (int i = 0; i < w; i++) {
		gotoXY(0, i);
		cout << ' ';
		gotoXY(h, i);
		cout << ' ';
	}
	fstream file("high-score\\HighScore.txt", ios::in);
	string NAME = "", tmp = "";
	pair<string, int> info[10];
	int i = 0, temp = 0;
	while (i < 10) {
		file >> info[i].first >> info[i].second;
		i++;
	}
	file.close();
	i--;
	if (score > info[i].second) {
		textcolor(240);
		SetColor(6);
		gotoXY(10, 15);
		cout << "█▀▀ █▀█ █▀█ █▀▀ █▀▄ █▀█ ▀█▀ █ █ █   █▀█ ▀█▀ ▀█▀ █▀█ █▀█ █   █ █ █▀█ █ █";
		gotoXY(10, 16);
		cout << "█   █ █ █ █ █ █ █▀▄ █▀█  █  █ █ █   █▀█  █   █  █ █ █ █ ▀    █  █ █ █ █";
		gotoXY(10, 17);
		cout << "▀▀▀ ▀▀▀ ▀ ▀ ▀▀▀ ▀ ▀ ▀ ▀  ▀  ▀▀▀ ▀▀▀ ▀ ▀  ▀  ▀▀▀ ▀▀▀ ▀ ▀ ▀    ▀  ▀▀▀ ▀▀▀";
		gotoXY(10, 18);
		cout << "█▀█ █▀▄ █▀▀   █▀█ █▀█ █▀▀   █▀█ █▀▀   ▀█▀ █ █ █▀▀   █▀▄ █▀▀ █▀▀ ▀█▀";
		gotoXY(10, 19);
		cout << "█▀█ █▀▄ █▀▀   █ █ █ █ █▀▀   █ █ █▀▀    █  █▀█ █▀▀   █▀▄ █▀▀ ▀▀█  █";
		gotoXY(10, 20);
		cout << "▀ ▀ ▀ ▀ ▀▀▀   ▀▀▀ ▀ ▀ ▀▀▀   ▀▀▀ ▀      ▀  ▀ ▀ ▀▀▀   ▀▀  ▀▀▀ ▀▀▀  ▀";
		gotoXY(10, 21);
		cout << "█▀█ █   █▀█ █ █ █▀▀ █▀▄   █▀█ █▀▀   ▀█▀ █ █ ▀█▀ █▀▀   █▀▀ █▀█ █▄█ █▀▀ █";
		gotoXY(10, 22);
		cout << "█▀▀ █   █▀█  █  █▀▀ █▀▄   █ █ █▀▀    █  █▀█  █  ▀▀█   █ █ █▀█ █ █ █▀▀ ▀";
		gotoXY(10, 23);
		cout << "▀   ▀▀▀ ▀ ▀  ▀  ▀▀▀ ▀ ▀   ▀▀▀ ▀      ▀  ▀ ▀ ▀▀▀ ▀▀▀   ▀▀▀ ▀ ▀ ▀ ▀ ▀▀▀ ▀";
		gotoXY(10, 24);


		gotoXY(10, 26);
		SetColor(0);
		cout << "Please enter your name: ";
		cin.ignore();
		gotoXY(34, 26);
		getline(cin, NAME);
		while (checkStr(NAME)) {
			gotoXY(10, 26);
			cout << "                                                                                        ";
			gotoXY(10, 26);
			SetColor(4);
			cout << "Your name is not valid, enter again: ";
			getline(cin, NAME);
		}
		info[i].first = NAME;
		info[i].second = score;
		gotoXY(10, 29);
		SetColor(2);
		cout << "Get your name successfully!";

		gotoXY(35, 31);
		textcolor(240);
		cout << "PRESS ANY KEY TO RETURN MENU";

		while (info[i].second > info[i - 1].second && i) {
			tmp = info[i].first;
			info[i].first = info[i - 1].first;
			info[i - 1].first = tmp;
			temp = info[i].second;
			info[i].second = info[i - 1].second;
			info[i - 1].second = temp;
			i--;
		}
	}
	else {
		gotoXY(15, 15);
		textcolor(240);
		cout << "█   █▀▀ ▀█▀ ▀ █▀▀   █▀█ █   █▀█ █ █   █▀█ █▀▀ █ █   █▀▀ █▀█ █▄█ █▀▀\n";
		gotoXY(15, 16);
		cout << "█   █▀▀  █    ▀▀█   █▀▀ █   █▀█  █    █ █ █▀▀ █▄█   █ █ █▀█ █ █ █▀▀\n";
		gotoXY(15, 17);
		cout << "▀▀▀ ▀▀▀  ▀    ▀▀▀   ▀   ▀▀▀ ▀ ▀  ▀    ▀ ▀ ▀▀▀ ▀ ▀   ▀▀▀ ▀ ▀ ▀ ▀ ▀▀▀\n";
		gotoXY(15, 18);
		cout << "▀█▀ █▀█   █▀▀ █▀▀ ▀█▀   █ █ ▀█▀ █▀▀ █ █ █▀▀ █▀▄   █▀▀ █▀▀ █▀█ █▀▄ █▀▀ █\n";
		gotoXY(15, 19);
		cout << " █  █ █   █ █ █▀▀  █    █▀█  █  █ █ █▀█ █▀▀ █▀▄   ▀▀█ █   █ █ █▀▄ █▀▀ ▀\n";
		gotoXY(15, 20);
		cout << " ▀  ▀▀▀   ▀▀▀ ▀▀▀  ▀    ▀ ▀ ▀▀▀ ▀▀▀ ▀ ▀ ▀▀▀ ▀ ▀   ▀▀▀ ▀▀▀ ▀▀▀ ▀ ▀ ▀▀▀ ▀\n";
		Sleep(2000);
	}
	fstream file1("high-score\\HighScore.txt", ios::out);
	i = 0;
	for (; i < 10; i++)
		file1 << info[i].first << ' ' << info[i].second << '\n';
	file1.close();
	gameover = false;
	score = 0;
	level = 0;
	length_of_snake = 4;
	game = 1;
	food_ate = 1;
	free(I);
	if (_getch())
		menu();
}

//Phan ve con ran di ra khoi cong
void OutGate() {



	if (outGate < 4 + MAX_FOOD * (level - 1) && !load) {

		gotoXY(X_SCREEN_TOP + 1, Y_SCREEN_TOP);
		textcolor(70);
		cout << ' ';

		gotoXY(X_SCREEN_TOP, Y_SCREEN_TOP + 1);
		textcolor(70);
		cout << ' ';

		gotoXY(X_SCREEN_TOP + 1, Y_SCREEN_TOP + 2);
		textcolor(70);
		cout << ' ';

		gotoXY(X_SCREEN_TOP, Y_SCREEN_TOP + 2);
		textcolor(70);
		cout << ' ';

		gotoXY(X_SCREEN_TOP, Y_SCREEN_TOP);
		textcolor(70);
		cout << ' ';

		gotoXY(X_SCREEN_TOP + 1, Y_SCREEN_TOP + 1);
		textcolor((gateColor += 20) % 255);
		cout << ' ';
	}
	else if (outGate == 5 + MAX_FOOD * (level - 1)) {
		gotoXY(X_SCREEN_TOP + 1, Y_SCREEN_TOP + 1);
		textcolor(230);
		cout << ' ';

		gotoXY(X_SCREEN_TOP + 1, Y_SCREEN_TOP);
		textcolor(0);
		cout << ' ';

		gotoXY(X_SCREEN_TOP, Y_SCREEN_TOP + 1);
		textcolor(0);
		cout << ' ';

		gotoXY(X_SCREEN_TOP + 1, Y_SCREEN_TOP + 2);
		textcolor(230);
		cout << ' ';

		gotoXY(X_SCREEN_TOP, Y_SCREEN_TOP + 2);
		textcolor(0);
		cout << ' ';

		gotoXY(X_SCREEN_TOP, Y_SCREEN_TOP);
		textcolor(0);
		cout << ' ';
	}


	outGate++;
}


//Man choi game 4
void game_4(bool check_load) {
	game = 4;
	load = check_load;
	if (!check_load) {
		food_ate = 1;
		outGate = 0;
		level++;
	}
	draw_energy = 0;
	if (SPEED > 50) {
		SPEED -= 10;
	}
	if (check_load == false && level == 4) {
		x_cr = X_SCREEN_TOP + 1;
		y_cr = Y_SCREEN_TOP + 1;
		//snake_init(I);
	}
	SetConsoleFont(12, 16, L"Consolas");
	draw_wall_and_numbers();
	read_file("map\\map4", 0, 0);
	read_file("object\\energy0", 83, 24);
	read_file("SCORE", 62, 2);

	gotoXY(80, 10);
	textcolor(144);
	cout << "PRESS [P] TO PAUSE";

	gotoXY(80, 13);
	textcolor(144);
	cout << "PRESS [◄]   [►]";

	gotoXY(89, 12);
	cout << "[▲]";
	gotoXY(89, 14);
	cout << "[▼]";

	gotoXY(80, 17);
	textcolor(144);
	cout << "OR    [A]   [D]";

	gotoXY(89, 16);
	cout << "[W]";
	gotoXY(89, 18);
	cout << "[S]";

	gotoXY(80, 20);
	textcolor(144);
	cout << "TO MOVE THE SNAKE";

	draw_score();
	if (!check_load) {
		//intro(I);
		create_food();
		I[0].x = X_SCREEN_TOP + 1;
		I[0].y = Y_SCREEN_TOP + 1;
	}
	else {
		textcolor(206);
		gotoXY(x_food, y_food);
		if (x_food != 0)
			cout << '0';
		if (food_ate == 5) {
			for (int i = 1; i <= food_ate; i++) {
				string ans = "object\\energy" + to_string(i);
				read_file(ans, 83, 24);
			}
		}
		else {
			for (int i = 1; i < food_ate; i++) {
				string ans = "object\\energy" + to_string(i);
				read_file(ans, 83, 24);
			}
		}

		score = length_of_snake - 4;
		draw_score();
		for (int i = 0; i < length_of_snake; i++) {
			gotoXY(I[i].x, I[i].y);
			textcolor(160);
			cout << S[i % MSSV];
		}
	}

	draw_snake();
	while (is_snake_alive() && gameover == false) {
		OutGate();
		preX = I[length_of_snake - 1].x;
		preY = I[length_of_snake - 1].y;
		delete_old_snake();

		snake_run();
		if (gameover) {
			gotoXY(I[1].x, I[1].y);
			textcolor(70);
			cout << 'X';
			Sleep(500);
			break;
		}
		gameover = !is_snake_alive();
		if (gameover) {
			gotoXY(I[1].x, I[1].y);
			textcolor(70);
			cout << 'X';
			Sleep(500);
			break;
		}
		if (is_outtro == false) {
			draw_snake();
			eat_food();
		}
		else {
			is_outtro = false;
			system("cls");
			game = 1;
			x_food = rand() % (X_SCREEN_BOTTOM - X_SCREEN_TOP - 6) + X_SCREEN_TOP + 30;
			y_food = rand() % (Y_SCREEN_BOTTOM - Y_SCREEN_TOP - 4) + Y_SCREEN_TOP + 5;
			game_1(false);
			break;
		}

		Sleep(SPEED);
	}
	end_game();
}
//Man choi game 3
void game_3(bool check_load) {
	game = 3;
	load = check_load;
	if (!check_load) {
		food_ate = 1;
		outGate = 0;
		level++;
	}
	draw_energy = 0;
	if (SPEED > 50) {
		SPEED -= 10;
	}
	if (check_load == false && level == 3) {
		x_cr = X_SCREEN_TOP + 1;
		y_cr = Y_SCREEN_TOP + 1;
		//snake_init(I);
	}
	// setConsoleFontSize(12,16); 
	SetConsoleFont(12, 16, L"Consolas");
	draw_wall_and_numbers();
	read_file("map\\map3", 0, 0);
	read_file("object\\energy0", 83, 24);
	read_file("SCORE", 62, 2);

	gotoXY(80, 10);
	textcolor(144);
	cout << "PRESS [P] TO PAUSE";

	gotoXY(80, 13);
	textcolor(144);
	cout << "PRESS [◄]   [►]";

	gotoXY(89, 12);
	cout << "[▲]";
	gotoXY(89, 14);
	cout << "[▼]";

	gotoXY(80, 17);
	textcolor(144);
	cout << "OR    [A]   [D]";

	gotoXY(89, 16);
	cout << "[W]";
	gotoXY(89, 18);
	cout << "[S]";

	gotoXY(80, 20);
	textcolor(144);
	cout << "TO MOVE THE SNAKE";

	draw_score();
	if (!check_load) {
		//intro(I);
		create_food();
		I[0].x = X_SCREEN_TOP + 1;
		I[0].y = Y_SCREEN_TOP + 1;
	}
	else {
		textcolor(206);
		gotoXY(x_food, y_food);
		if (x_food != 0)
			cout << '0';
		if (food_ate == 5) {
			for (int i = 1; i <= food_ate; i++) {
				string ans = "object\\energy" + to_string(i);
				read_file(ans, 83, 24);
			}
		}
		else {
			for (int i = 1; i < food_ate; i++) {
				string ans = "object\\energy" + to_string(i);
				read_file(ans, 83, 24);
			}
		}

		score = length_of_snake - 4;
		draw_score();
		for (int i = 0; i < length_of_snake; i++) {
			gotoXY(I[i].x, I[i].y);
			textcolor(160);
			cout << S[i % MSSV];
		}
	}

	draw_snake();

	while (gameover == false) {
		OutGate();
		preX = I[length_of_snake - 1].x;
		preY = I[length_of_snake - 1].y;
		delete_old_snake();

		snake_run();
		if (gameover) {
			gotoXY(I[1].x, I[1].y);
			textcolor(70);
			cout << 'X';
			Sleep(500);
			break;
		}
		gameover = !is_snake_alive();
		if (gameover) {
			gotoXY(I[1].x, I[1].y);
			textcolor(70);
			cout << 'X';
			Sleep(500);
			break;
		}
		if (is_outtro == false) {
			draw_snake();
			eat_food();
		}
		else {
			is_outtro = false;
			system("cls");
			game = 4;
			game_4(false);
			break;
		}

		Sleep(SPEED);
	}
	end_game();
}
//Man choi game 2
void game_2(bool check_load) {
	game = 2;
	load = check_load;
	if (!check_load) {
		food_ate = 1;
		outGate = 0;
		level++;
	}
	draw_energy = 0;
	if (SPEED > 50) {
		SPEED -= 10;
	}
	if (check_load == false && level == 2) {
		x_cr = X_SCREEN_TOP + 1;
		y_cr = Y_SCREEN_TOP + 1;
		//snake_init(I);
	}

	SetConsoleFont(12, 16, L"Consolas");
	draw_wall_and_numbers();
	read_file("map\\map2", 0, 0);
	read_file("object\\energy0", 83, 24);
	read_file("SCORE", 62, 2);

	gotoXY(80, 10);
	textcolor(144);
	cout << "PRESS [P] TO PAUSE";

	gotoXY(80, 13);
	textcolor(144);
	cout << "PRESS [◄]   [►]";

	gotoXY(89, 12);
	cout << "[▲]";
	gotoXY(89, 14);
	cout << "[▼]";

	gotoXY(80, 17);
	textcolor(144);
	cout << "OR    [A]   [D]";

	gotoXY(89, 16);
	cout << "[W]";
	gotoXY(89, 18);
	cout << "[S]";

	gotoXY(80, 20);
	textcolor(144);
	cout << "TO MOVE THE SNAKE";

	draw_score();
	if (!check_load) {
		I[0].x = X_SCREEN_TOP + 1;
		I[0].y = Y_SCREEN_TOP + 1;
		create_food();
	}
	else {
		check_load = false;
		textcolor(206);
		gotoXY(x_food, y_food);
		if (x_food != 0)
			cout << '0';
		if (food_ate == 5) {
			for (int i = 1; i <= food_ate; i++) {
				string ans = "object\\energy" + to_string(i);
				read_file(ans, 83, 24);
			}
		}
		else {
			for (int i = 1; i < food_ate; i++) {
				string ans = "object\\energy" + to_string(i);
				read_file(ans, 83, 24);
			}
		}
		score = length_of_snake - 4;
		draw_score();
		for (int i = 0; i < length_of_snake; i++) {
			gotoXY(I[i].x, I[i].y);
			textcolor(160);
			cout << S[i % MSSV];
		}
	}

	draw_snake();
	while (gameover == false) {
		OutGate();
		preX = I[length_of_snake - 1].x;
		preY = I[length_of_snake - 1].y;
		delete_old_snake();

		snake_run();
		if (gameover) {
			gotoXY(I[1].x, I[1].y);
			textcolor(70);
			cout << 'X';
			Sleep(500);
			break;
		}
		gameover = !is_snake_alive();
		if (gameover) {
			gotoXY(I[1].x, I[1].y);
			textcolor(70);
			cout << 'X';
			Sleep(500);
			break;
		}
		if (is_outtro == false) {
			draw_snake();
			eat_food();
		}
		else {
			is_outtro = false;
			system("cls");
			game = 3;
			game_3(false);
			break;
		}

		Sleep(SPEED);
	}
	end_game();
}
//Man choi game 1
void game_1(bool check_load) {
	game = 1;
	load = check_load;
	inGate = 0;
	if (!check_load) {
		food_ate = 1;
		outGate = 0;
		level++;
	}
	draw_energy = 0;
	if (level == 1) {
		SPEED = 130;
	}
	else {
		if (SPEED > 50) {
			SPEED -= 10;
		}
	}

	if (check_load == false && level == 1) {
		I = (Point*)malloc(sizeof(Point) * 30);
		if (I == nullptr) return;
		x_cr = X_SCREEN_TOP + length_of_snake + 1;
		y_cr = Y_SCREEN_TOP + 1;
		snake_init();
	}
	if (level > 1 && !check_load) {
		Point* a = (Point*)realloc(I, sizeof(I) * level * 10);
		if (a != nullptr)
			I = a;
		I[0].x = X_SCREEN_TOP + 1;
		I[0].y = Y_SCREEN_TOP + 1;
		x_food = 10;
		y_food = 35;
	}
	SetConsoleFont(12, 16, L"Consolas");
	draw_wall_and_numbers();
	read_file("map\\map1", 0, 0);
	read_file("object\\energy0", 83, 24);
	read_file("SCORE", 62, 2);

	gotoXY(80, 10);
	textcolor(144);
	cout << "PRESS [P] TO PAUSE";
	
	gotoXY(80, 13);
	textcolor(144);
	cout << "PRESS [◄]   [►]";

	gotoXY(89, 12);
	cout << "[▲]";
	gotoXY(89, 14);
	cout << "[▼]";

	gotoXY(80, 17);
	textcolor(144);
	cout << "OR    [A]   [D]";

	gotoXY(89, 16);
	cout << "[W]";
	gotoXY(89, 18);
	cout << "[S]";

	gotoXY(80, 20);
	textcolor(144);
	cout << "TO MOVE THE SNAKE";

	draw_score();
	if (!check_load && level == 1) {
		intro();
		create_food();
	}
	else if (check_load) {
		check_load = false;
		textcolor(206);
		gotoXY(x_food, y_food);
		if (x_food != 0)
			cout << '0';
		if (food_ate == 5) {
			for (int i = 1; i <= food_ate; i++) {
				string ans = "object\\energy" + to_string(i);
				read_file(ans, 83, 24);
			}
		}
		else {
			for (int i = 1; i < food_ate; i++) {
				string ans = "object\\energy" + to_string(i);
				read_file(ans, 83, 24);
			}
		}
		
		score = length_of_snake - 4;
		draw_score();
		for (int i = 0; i < length_of_snake; i++) {
			gotoXY(I[i].x, I[i].y);
			textcolor(160);
			cout << S[i % MSSV];
		}
		gameover = false;
	}
	else {
		gotoXY(x_food, y_food);
		textcolor(206);
		if (x_food != 0)
			cout << '0';
	}

	draw_snake();
	while (gameover == false) {
		OutGate();
		preX = I[length_of_snake - 1].x;
		preY = I[length_of_snake - 1].y;
		delete_old_snake();

		snake_run();
		if (gameover) {
			gotoXY(I[1].x, I[1].y);
			textcolor(70);
			cout << 'X';
			Sleep(500);
			break;
		}
		gameover = !is_snake_alive();
		if (gameover) {
			gotoXY(I[1].x, I[1].y);
			textcolor(70);
			cout << 'X';
			Sleep(500);
			break;
		}
		if (is_outtro == false) {
			draw_snake();
			eat_food();
		}
		else {
			is_outtro = false;
			system("cls");
			game = 2;
			game_2(false);
			break;
		}

		Sleep(SPEED);

	}
	end_game();
}