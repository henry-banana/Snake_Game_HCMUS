#include "../header/resource.h"

void gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

//Ham dat mau cho chu
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

//Ham lam an con tro chuot
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}


// Ham thay doi kich thuoc console
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	COORD bufferSize = { width, height * 2 };
	SetConsoleScreenBufferSize(console, bufferSize);
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);

	SetConsoleScreenBufferSize(console, bufferSize);

}

//Ham co dinh man hinh console
void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);


}

void FixConsole() {
	HWND consoleWindow = GetConsoleWindow();
	ShowScrollBar(consoleWindow, SB_BOTH, FALSE);
}


void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

void setConsoleFontSize(int sizex, int sizey) {
	CONSOLE_FONT_INFOEX fontInfo;
	fontInfo.cbSize = sizeof(fontInfo);
	GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &fontInfo);
	fontInfo.dwFontSize.X = sizex; // Width
	fontInfo.dwFontSize.Y = sizey; // Height
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &fontInfo);
}

void SetConsoleFont(int a, int b, const wchar_t* font) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = a;
	cfi.dwFontSize.Y = b;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, font);
	SetCurrentConsoleFontEx(hConsole, FALSE, &cfi);
}

void shutdownConsole() {
	HWND hwnd = GetConsoleWindow();  // Lấy handle của cửa sổ console
	if (hwnd != NULL) {
		PostMessage(hwnd, WM_CLOSE, 0, 0);  // Gửi thông điệp đóng cửa sổ
	}
}