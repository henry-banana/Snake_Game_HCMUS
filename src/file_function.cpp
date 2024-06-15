#include "../header/file_function.h"

void read_file(const string s, int x, int y) {

	ifstream inputFile("resource\\front-end\\draw\\" + s + ".txt");

	if (!inputFile.is_open()) {
		cout << "Khong mo duoc file!";
		return;
	}

	int val1, val2, val3;
	while (inputFile >> val1) {
		inputFile >> val2;
		inputFile >> val3;
		gotoXY(val1 + x, val2 + y);
		textcolor(val3);
		cout << ' ';
	}

	inputFile.close();

}

void destroy_file(const string s, int x, int y, int color) {

	ifstream inputFile("resource\\front-end\\draw\\" + s + ".txt");

	if (!inputFile.is_open()) {
		cout << "Khong mo duoc file!";
	}

	int val1, val2, val3;
	while (inputFile >> val1) {
		inputFile >> val2;
		inputFile >> val3;
		gotoXY(val1 + x, val2 + y);
		textcolor(color);
		cout << ' ';
	}
	inputFile.close();
}

bool checkStr(string str) {
	int n = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') return true;
		if ('0' <= str[i] && str[i] <= '9')
			n++;
	}
	if (n == str.length()) return true;
	if (str.length() > 20) return true;
	if (str == "")
		return true;
	return false;
}

void gameOverScreen() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleFont(12, 16, L"Consolas");
	resizeConsole(1240, 750);
	textcolor(230);
	for (int x = X_SCREEN_TOP + 1; x < X_SCREEN_BOTTOM; x++) {
		for (int y = Y_SCREEN_TOP + 1; y <= Y_SCREEN_BOTTOM; y++) {
			gotoXY(x, y);
			cout << ' ';
		}
	}
	fstream fin;
	int x, y, k;
	fin.open("resource\\front-end\\draw\\cat.txt", std::ios::in);
	while (!fin.eof()) {
		fin >> x >> y >> k;
		gotoXY(x, y + 10);
		textcolor(k);
		std::cout << ' ';
	}

	fin.close();
	fin.open("resource\\front-end\\draw\\game.txt", std::ios::in);
	x = 35, y = 15, k = 240;
	while (!fin.eof()) {
		std::string _text;
		getline(fin, _text);
		gotoXY(x, y++);
		textcolor(230);
		std::cout << _text;
	}

	fin.close();
	fin.open("resource\\front-end\\draw\\over.txt", std::ios::in);
	x = 35, y = 32, k = 240;
	while (!fin.eof()) {
		std::string _text;
		getline(fin, _text);
		gotoXY(x, y++);
		textcolor(230);
		std::cout << _text;
	}

	gotoXY(35, 25);
	textcolor(228);
	std::cout << "= = = PRESS ANY KEY TO CONTINUE = = =";
	while (true)
		if (_kbhit())
			return;
}