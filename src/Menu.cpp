#include "../header/Menu.h"

void delete_old_pause_menu(int x, int y, int w, int h, int number, int color) {

	textcolor(color);

	draw_game();

	gotoXY(X_SCREEN_TOP + 25, Y_SCREEN_TOP + 3);
	cout << ' ';

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


void conver_string_into_pixel(const string s, int x, int y) {
	int i = 0 + x;
	string ans = "letter\\";
	char h = ' ';
	for (char x : s) {
		if (isalpha(x)) {
			h = tolower(x);
			string ans = "letter\\";
			ans += h;
			read_file(ans, i, y);
			i += 6;
		}
		else {
			i += 7;
		}

	}
}



void menu() {
	thread soundThread(soundControl, std::ref(running), std::ref(play));
	system("cls");
	system("color F0");
	SetConsoleFont(8, 8, L"Terminal");
	setConsoleFontSize(8, 8);
	resizeConsole(HEIGHT, WIDTH);
	ShowCur(0);
	int x_menu = 20;
	int y_menu = 10;
	int h = 150, w = 89;
	string Botton[6] = { "start_game","load_game","high_score", "help","setting","exit" };
	Point A[6] = { {52,32},{33,48},{33,63},{82,48},{82,63},{64,75} };

	textcolor(10);
	for (int i = 0; i < h; i++) {
		gotoXY(x_menu + i, y_menu);
		cout << ' ';
		gotoXY(x_menu + i, y_menu + w - 1);
		cout << ' ';
	}

	for (int i = 0; i < w; i++) {
		gotoXY(x_menu, y_menu + i);
		cout << ' ';
		gotoXY(x_menu + h - 1, y_menu + i);
		cout << ' ';
	}

	read_file("draw_menu", x_menu, y_menu);
	read_file("draw_title", x_menu + 18, y_menu + 15);
	read_file("start_game_CLICK", A[0].x + x_menu, A[0].y + y_menu);
	for (int i = 1; i < 6; i++) {
		read_file(Botton[i], A[i].x + x_menu, A[i].y + y_menu);
	}

	int gameover2 = 0;
	char character_from_keyboard;
	int i = 0;
	string name;

	while (!gameover2) {
		if (_kbhit()) {
			character_from_keyboard = _getch();
			if (character_from_keyboard == 72 || character_from_keyboard == 'w') { //len

				if (is_on[0]) {
					Beep(500, 80);
				}

				if (i > 0) {
					read_file(Botton[i], A[i].x + x_menu, A[i].y + y_menu);
					if (i == 3) {
						i = 0;
					}
					else {
						i--;
					}
					name = Botton[i] + "_CLICK";
					read_file(name, A[i].x + x_menu, A[i].y + y_menu);


				}
			}
			else if (character_from_keyboard == 80 || character_from_keyboard == 's') { //xuong

				if (is_on[0]) {
					Beep(500, 80);
				}

				if (i < 5) {
					if (i == 2) {
						read_file(Botton[i], A[i].x + x_menu, A[i].y + y_menu);
						i = 5;
						name = Botton[i] + "_CLICK";
						read_file(name, A[i].x + x_menu, A[i].y + y_menu);

					}
					else {
						read_file(Botton[i], A[i].x + x_menu, A[i].y + y_menu);
						i++;
						name = Botton[i] + "_CLICK";
						read_file(name, A[i].x + x_menu, A[i].y + y_menu);

					}
				}
			}
			else if (character_from_keyboard == 75 || character_from_keyboard == 'a') { // trai

				if (is_on[0]) {
					Beep(500, 80);
				}

				if (i == 3 || i == 4) {
					read_file(Botton[i], A[i].x + x_menu, A[i].y + y_menu);
					i -= 2;
					name = Botton[i] + "_CLICK";
					read_file(name, A[i].x + x_menu, A[i].y + y_menu);

				}
			}
			else if (character_from_keyboard == 77 || character_from_keyboard == 'd') { //phai

				if (is_on[0]) {
					Beep(500, 80);
				}

				if (i == 1 || i == 2) {
					read_file(Botton[i], A[i].x + x_menu, A[i].y + y_menu);
					i += 2;
					name = Botton[i] + "_CLICK";
					read_file(name, A[i].x + x_menu, A[i].y + y_menu);

				}
			}

			if (character_from_keyboard == 13) { //enter

				if (is_on[0]) {
					Beep(1500, 80);
				}

				gameover2 = 1;
			}




		}

	}

	delete_old_pause_menu(50, 8, 20, 2, 7, 120);
	draw_left_right_wall(X_SCREEN_TOP);
	draw_left_right_wall(X_SCREEN_BOTTOM);
	draw_top_bottom_wall(Y_SCREEN_TOP);
	draw_top_bottom_wall(Y_SCREEN_BOTTOM + 1);

	if (i == 0) {
		S[0] = ':';
		game_1(false);
		return;
	}
	else if (i == 1) {
		FixConsoleWindow();
		system("cls");
		system("color f0");
		ShowCur(0);
		setConsoleFontSize(12, 16);
		resizeConsole(HEIGHT, WIDTH);
		gotoXY(X_SCREEN_TOP, Y_SCREEN_TOP);
		read_file("load_game_menu", x_menu - 10, y_menu - 9);
		int h = 99, w = 40;
		textcolor(10);
		for (int i = 0; i < h; i++) {
			gotoXY(x_menu + i - 10, y_menu);
			cout << ' ';
			gotoXY(x_menu + i - 10, y_menu + w - 1);
			cout << ' ';
		}

		for (int i = 0; i < w; i++) {
			gotoXY(x_menu - 10, y_menu + i);
			cout << ' ';
			gotoXY(x_menu + h - 10, y_menu + i);
			cout << ' ';
		}
		read_file("Toro", 45, 17);
		ifstream  filename("resource\\load-game\\filename.txt");
		string name[10] = { "" };
		int num = 0;
		while (!filename.eof()) {
			filename >> name[num];
			num++;
		}
		filename.close();
		textcolor(240);
		SetColor(0);
		for (int i = 0; i < 5; i++) {
			gotoXY(35, 38 + 2 * i);
			cout << name[2 * i];
			gotoXY(65, 38 + 2 * i);
			cout << name[2 * i + 1];
		}
		textcolor(240);
		SetColor(0);
		gotoXY(42, 16);
		cout << "PLEASE INPUT YOUR NAME TO LOAD ";
		gotoXY(33, 31);
		cout << "Your name: ";
		string NAME = "";
		getline(cin, NAME);
		if (is_on[0]) {
			Beep(1500, 80);
		}
		gotoXY(X_SCREEN_TOP + 20, Y_SCREEN_TOP + 17);
		textcolor(240);


		ifstream inputFile("resource\\load-game\\" + NAME + ".txt");
		if (!(inputFile.is_open())) {
			textcolor(244);
			SetColor(4);
			gotoXY(33, 33);
			cout << "Failed to load your name!";
			Sleep(1000);
			menu();
		}
		else {
			textcolor(242);
			SetColor(2);
			gotoXY(33, 33);
			cout << "Load your name successfully!";
			outGate = length_of_snake;
			Sleep(1000);
			inputFile >> length_of_snake >> snake_direction >> game >> x_food >> y_food >> food_ate >> level;
			SPEED = 130 - level * 10;

			if (level < 5) {
				I = (Point*)malloc(40 * sizeof(Point));
			}
			else {
				I = (Point*)malloc(level * 10 * sizeof(Point));
			}

			for (int i = 0; i < length_of_snake; i++) {
				inputFile >> I[i].x >> I[i].y;
			}
			inputFile >> x_cr >> y_cr;

			if (game == 1) {
				game_1(true);
			}
			else if (game == 2) {
				game_2(true);
			}
			else if (game == 3) {
				game_3(true);
			}
			else if (game == 4) {
				game_4(true);
			}
		}
		inputFile.close();

	}
	else if (i == 2) {
		system("cls");
		system("color F0");
		setConsoleFontSize(12, 16);
		resizeConsole(HEIGHT, WIDTH);
		read_file("high_score_menu", x_menu - 7, y_menu - 3);
		ifstream inputFile("resource\\high-score\\HighScore.txt");
		string name;
		int len;
		int i = 12;
		gotoXY(15 + x_menu, y_menu + i);
		textcolor(240);
		SetColor(0);
		cout << "NAME CHARACTER";
		gotoXY(50 + x_menu, y_menu + i);
		cout << "SCORE";

		for (int j = 1; j < 11; j++) {
			inputFile >> name >> len;
			gotoXY(15 + x_menu, y_menu + i + 2);
			cout << j << ". " << name << endl;
			gotoXY(50 + x_menu, y_menu + i + 2);
			cout << len;
			i += 2;
		}

		inputFile.close();
		int h = 100, w = 35;
		textcolor(10);
		for (int i = 0; i < h; i++) {
			gotoXY(x_menu + i - 7, y_menu + 6);
			cout << ' ';
			gotoXY(x_menu + i - 7, y_menu + w - 1 + 6);
			cout << ' ';
		}

		for (int i = 0; i < w; i++) {
			gotoXY(x_menu - 7, y_menu + i + 5);
			cout << ' ';
			gotoXY(x_menu + h - 8, y_menu + i + 5);
			cout << ' ';
		}
		gotoXY(47, 47);
		textcolor(240);
		cout << "PRESS ANY TO RETURN MENU";
		if (_getch()) {
			if (is_on[0]) {
				Beep(1500, 80);
			}
			menu();
		}
	}
	else if (i == 3) {
		system("cls");
		system("color F0");
		SetConsoleFont(12, 16, L"Consolas");
		ShowCur(0);
		resizeConsole(HEIGHT, WIDTH);
		read_file("help_menu", 0, 0);
		textcolor(240);
		gotoXY(50, 30);
		int h = 99, w = 43;
		textcolor(10);

		for (int i = 0; i < h; i++) {
			gotoXY(i, 0);
			cout << ' ';
			gotoXY(i, w);
			cout << ' ';
		}

		for (int i = 0; i < w; i++) {
			gotoXY(0, i);
			cout << ' ';
			gotoXY(h, i + 1);
			cout << ' ';
		}

		gotoXY(6, 12);
		textcolor(240);
		SetColor(0);
		ShowCur(0);
		cout << "To navigate the snake, use the 4 arrow buttons [◄]   [►] or the [A]   [D] buttons on the ";
		gotoXY(6, 13);
		cout << "keyboard. ";
		gotoXY(73, 11);
		cout << "[W]";
		gotoXY(73, 13);
		cout << "[S]";

		gotoXY(56, 11);
		cout << "[▲]";
		gotoXY(56, 13);
		cout << "[▼]";

		gotoXY(6, 15);
		cout << "Press P to pause the game.";
		gotoXY(6, 17);
		cout << "Press \"Enter\" to select an option on the Game menu. ";
		gotoXY(6, 19);
		cout << "To save your game while playing, pause by pressing P and select \"Save game\". Enter a file \n";
		gotoXY(6, 20);
		cout << "name with at least one word and no spaces to save. ";
		gotoXY(6, 22);
		cout << "To save your game while playing, pause by pressing P and select \"Save game\". Enter a file \n";
		gotoXY(6, 23);
		cout << "name with at least one word and no spaces to save. ";
		gotoXY(6, 26);
		cout << "------------------------------------------------------------------------------------------";
		gotoXY(6, 28);
		cout << "The game Snake Hunting was created by five students under the guidance of teacher Truong \n";
		gotoXY(6, 29);
		cout << "Toan Thinh from the University of Science, Ho Chi Minh City\n";
		gotoXY(6, 31);
		cout << "Group 1 includes 5 members:";
		gotoXY(6, 32);
		cout << "- Nguyen Phuc Hau - 23120252";
		gotoXY(6, 33);
		cout << "- Nguyen Van Binh Duong - 23120242";
		gotoXY(6, 34);
		cout << "- Tran Nhat Duong - 23120243";
		gotoXY(6, 35);
		cout << "- Nguyen Phuc Hoang - 23120264";
		gotoXY(6, 36);
		cout << "- Tong Duong Thai Hoa - 23120262";
		gotoXY(40, 40);
		textcolor(244);
		cout << "PRESS ANY TO RETURN MENU";
		if (_getch())
		{
			if (is_on[0]) {
				Beep(1500, 80);
			}
			menu();
		}
	}
	else if (i == 4) {
		system("cls");
		system("color f0");
		setConsoleFontSize(8, 8);
		resizeConsole(HEIGHT, WIDTH);
		int h = 150, w = 80;
		textcolor(10);
		read_file("setting_menu", x_menu, y_menu);
		read_file("effect_text", x_menu + 100, 34);
		read_file("sound_text", x_menu + 100, 69);

		for (int i = 0; i < h; i++) {
			gotoXY(x_menu + i, y_menu + 11);
			cout << ' ';
			gotoXY(x_menu + i, y_menu + w - 1 + 6);
			cout << ' ';
		}

		for (int i = 0; i < w; i++) {
			gotoXY(x_menu, y_menu + i + 6);
			cout << ' ';
			gotoXY(x_menu + h - 1, y_menu + i + 6);
			cout << ' ';
		}

		if (is_on[0]) {
			read_file("effect_ON", 70 + x_menu, 15 + y_menu);
		}
		else {
			read_file("effect_OFF", 70 + x_menu, 15 + y_menu);
		}
		if (is_on[1]) {
			read_file("background_ON", 70 + x_menu, 50 + y_menu);
		}
		else {
			read_file("background_OFF", 70 + x_menu, 50 + y_menu);
		}


		int j = 0;
		char character_from_keyboard2;
		read_file("choice_icon", 35 + x_menu, 18 + y_menu);
		gotoXY(80, 90);
		textcolor(244);
		cout << "PRESS [ESC] TO RETURN MENU";
		while (true) {
			if (_kbhit()) {
				character_from_keyboard2 = _getch();
				if (character_from_keyboard2 == 72 || character_from_keyboard2 == 'w') { //len
					if (is_on[0]) {
						Beep(500, 80);
					}
					if (j == 1) {

						j = 0;

						destroy_file("choice_icon", 35 + x_menu, 53 + y_menu, 240);
						read_file("choice_icon", 35 + x_menu, 18 + y_menu);

					}

				}
				else if (character_from_keyboard2 == 80 || character_from_keyboard2 == 's') { //xuong
					if (is_on[0]) {
						Beep(500, 80);
					}
					if (j == 0) {
						j = 1;
						destroy_file("choice_icon", 35 + x_menu, 18 + y_menu, 240);
						read_file("choice_icon", 35 + x_menu, 53 + y_menu);
					}

				}
				else if (character_from_keyboard2 == 13) { //enter
					if (is_on[0]) {
						Beep(1500, 80);
					}
					if (j == 0) {
						if (is_on[j]) {
							read_file("effect_OFF", 70 + x_menu, 15 + y_menu);
						}
						else {
							read_file("effect_ON", 70 + x_menu, 15 + y_menu);
						}
					}
					else {
						if (is_on[j]) {
							read_file("background_OFF", 70 + x_menu, 50 + y_menu);
							play = false;
						}
						else {
							read_file("background_ON", 70 + x_menu, 50 + y_menu);
							play = true;
						}
					}
					is_on[j] = !is_on[j];
				}
				else if (character_from_keyboard2 == 27) {
					menu();
				}
			}
		}

		if (soundThread.joinable()) {
			soundThread.join();
		}

		menu();
	}
	else {
		SetConsoleFont(12, 16, L"Consolas");
		resizeConsole(HEIGHT, WIDTH);
		system("cls");
		system("color f0");

		gotoXY(40, 30);
		textcolor(244);
		cout << "❤️❤️ SEE YOU AGAIN ❤️❤️";

		Mes_exit();
		shutdownConsole();
		exit(EXIT_SUCCESS);
	}

}


void welcome() {
	system("cls");
	system("color F0");
	SetConsoleFont(8, 8, L"Terminal");
	setConsoleFontSize(8, 8);
	resizeConsole(HEIGHT, WIDTH);
	ShowCur(0);
	textcolor(10);
	for (int i = 20; i < 170; i++) {
		gotoXY(i, 10);
		cout << ' ';
		gotoXY(i, 98);
		cout << ' ';
	}

	for (int i = 10; i < 99; i++) {
		gotoXY(19, i);
		cout << ' ';
		gotoXY(170, i);
		cout << ' ';
	}
	read_file("welcome\\welcome", 20, 10);
	gotoXY(82, 80);
	textcolor(244);
	cout << "PRESS [ENTER] TO CONTINUE";
	bool welcome = true;
	while (welcome) {
		read_file("welcome\\snake_moving2", 79, 38);
		Sleep(400);
		read_file("welcome\\snake_moving0", 79, 38);
		Sleep(400);
		read_file("welcome\\snake_moving1", 79, 38);
		Sleep(400);
		read_file("welcome\\snake_moving0", 79, 38);
		Sleep(400);

		if (_kbhit()) {
			if (_getch()) {
				if (is_on[0]) {
					Beep(1500, 80);
				}
				welcome = false;
				menu();
			}
		}
	}
}

void Mes_exit()
{
	SetConsoleFont(12, 16, L"Consolas");
	resizeConsole(HEIGHT, WIDTH);
	read_file("Toro - Copy", 39, 0);
	// 43 - 15 - 50 - 13
	const int Mes_BoardX = 33;
	const int Mes_BoardY = 15;
	const int Mes_BoardH = 13;
	const int X = Mes_BoardX;
	const int Y = Mes_BoardH + Mes_BoardY;
	textcolor(0);
	for (int i = 25; i <= 77; i++) {
		gotoXY(i, 10);
		cout << ' ';
		gotoXY(i, 40);
		cout << ' ';
	}

	for (int i = 10; i <= 40; i++) {
		gotoXY(25, i);
		cout << ' ';
		gotoXY(77, i);
		cout << ' ';
	}
	textcolor(240);
	for (int i = Y; i > -Y + 18; i--)
	{
		int j = 0;
		if (i + j > Mes_BoardY && i + j < Y)
		{
			gotoXY(X, i + (j));
			if (i + j <= Y)
				cout << "  Trường Đại học Khoa học Tự nhiên";
			;
		}j++;
		if (i + j > Mes_BoardY && i + j < Y)
		{
			gotoXY(X, i + (j));
			if (i + j <= Y)
				cout << "                                        ";
			;
		}j++;
		if (i + j > Mes_BoardY && i + j < Y)
		{
			gotoXY(X, i + (j));
			cout << "        ĐỒ ÁN CUỐI KÌ KTLT      ";

		}; j++;
		if (i + j > Mes_BoardY && i + j < Y)
		{
			gotoXY(X, i + (j));
			if (i + j <= Y)
				cout << "  MÔ PHỎNG RẮN SĂN MỒI - SNAKE GAME ";

		}j++;
		if (i + j > Mes_BoardY && i + j < Y)
		{
			gotoXY(X, i + (j));
			if (i + j <= Y)
				cout << "                                        ";
		}j++;
		if (i + j > Mes_BoardY && i + j < Y)
		{
			gotoXY(X, i + (j));
			if (i + j <= Y)
				cout << "Lớp:                                    ";
			;
		}j++;
		if (i + j > Mes_BoardY && i + j < Y)
		{
			gotoXY(X, i + (j));
			if (i + j <= Y)
				cout << "             23CTT3                     ";
			;
		}j++;
		if (i + j > Mes_BoardY && i + j < Y)
		{
			gotoXY(X, i + (j));
			if (i + j <= Y)
				cout << "                                        ";
			;
		}j++;
		if (i + j > Mes_BoardY && i + j < Y)
		{
			gotoXY(X, i + (j));
			if (i + j <= Y)
				cout << "Giảng viên hướng dẫn:              ";
			;
		}j++;
		if (i + j > Mes_BoardY && i + j < Y)
		{
			gotoXY(X, i + (j));
			if (i + j <= Y)
				cout << "          Trương Toàn Thịnh    ";
			;
		}j++;
		if (i + j > Mes_BoardY && i + j < Y)
		{
			gotoXY(X, i + (j));
			if (i + j <= Y)
				cout << "                                        ";
			;
		}j++;
		if (i + j > Mes_BoardY && i + j < Y)
		{
			gotoXY(X, i + (j));
			if (i + j <= Y)
				cout << "Nhóm thực hiện:                   ";
			;
		}j++;
		if (i + j > Mes_BoardY && i + j < Y)
		{
			gotoXY(X, i + (j));
			if (i + j <= Y)
				cout << "             Nhóm 1               ";
			;
		}j++;
		if (i + j > Mes_BoardY && i + j < Y)
		{
			gotoXY(X, i + (j));
			if (i + j <= Y) cout << "                                        ";
			;
		}j++;
		if (i + j > Mes_BoardY && i + j < Y)
		{
			gotoXY(X, i + (j));
			if (i + j <= Y)
				cout << "Các thành viên:                   ";
			;
		}j++;
		if (i + j > Mes_BoardY && i + j < Y)
		{
			gotoXY(X, i + (j));
			if (i + j <= Y)
				cout << "          Nguyễn Phúc Hoàng (Leader)";
			;
		}j++;
		if (i + j > Mes_BoardY && i + j < Y)
		{
			gotoXY(X, i + (j));
			if (i + j <= Y)
				cout << "          Nguyễn Phúc Hậu.           ";
			;
		}j++;
		if (i + j > Mes_BoardY && i + j < Y)
		{
			gotoXY(X, i + (j));
			if (i + j <= Y)
				cout << "          Trần Nhật Dương.          ";
			;
		}j++;
		if (i + j > Mes_BoardY && i + j < Y)
		{
			gotoXY(X, i + (j));
			if (i + j <= Y)
				cout << "          Nguyễn Văn Bình Dương.       ";
			;
		}j++;
		if (i + j > Mes_BoardY && i + j < Y)
		{
			gotoXY(X, i + (j));
			if (i + j <= Y)
				cout << "          Tống Dương Thái Hòa.       ";
			;
		}j++;
		if (i + j > Mes_BoardY && i + j < Y)
		{
			gotoXY(X, i + (j));
			if (i + j <= Y)
				cout << "                                        ";
			;
		}j++;
		if (i + j > Mes_BoardY && i + j < Y)
		{
			gotoXY(X, i + (j));
			if (i + j <= Y)
				cout << "                                        ";
			;
		}j++;
		if (i + j > Mes_BoardY && i + j < Y)
		{
			gotoXY(X, i + (j));
			if (i + j <= Y)
				cout << "                                        ";
			;
		}j++;
		if (i + j > Mes_BoardY && i + j < Y)
		{
			gotoXY(X, i + (j));
			if (i + j <= Y)
				cout << "                                        ";
			;
		}j++;
		if (i + j > Mes_BoardY && i + j < Y)
		{
			gotoXY(X, i + (j));
			if (i + j <= Y)
				cout << "                                        ";
			;
		}j++;
		if (i + j > Mes_BoardY && i + j < Y)
		{
			gotoXY(X, i + (j));
			if (i + j <= Y)
				cout << "                                        ";
			;
		}j++;
		Sleep(300);
	}
}