#include <windows.h>

void gotoxy(int x, int y)             /*定位光标，x为行坐标,y为列坐标*/
{
    COORD pos = {x,y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
    return;
}
