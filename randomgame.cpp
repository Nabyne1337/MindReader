#include <iostream>
#include <ctime>
#include <conio.h>
#include<windows.h>

using namespace std;

int a, b, yourtry;
enum ConsoleColor
{
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15
};

void SetColor(ConsoleColor text, ConsoleColor background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
int main() {
    setlocale(LC_ALL, "");

    srand(time(0));
    yourtry = 3;
    while (true) {
        system("cls");
        SetColor(Magenta, Black);
        cout << "'########::'########:'##::: ##:'########:'########:'##::::'##:::::::'######:::'######::\n"
            << " ##.... ##: ##.....:: ###:: ##:... ##..:: ##.....::. ##::'##:::::::'##... ##:'##... ##:\n"
            << " ##:::: ##: ##::::::: ####: ##:::: ##:::: ##::::::::. ##'##:::::::: ##:::..:: ##:::..::\n"
            << " ########:: ######::: ## ## ##:::: ##:::: ######:::::. ###::::::::: ##::::::: ##:::::::\n"
            << " ##.. ##::: ##...:::: ##. ####:::: ##:::: ##...:::::: ## ##:::::::: ##::::::: ##:::::::\n"
            << " ##::. ##:: ##::::::: ##:. ###:::: ##:::: ##:::::::: ##:. ##::'###: ##::: ##: ##::: ##:\n"
            << " ##:::. ##: ########: ##::. ##:::: ##:::: ########: ##:::. ##: ###:. ######::. ######::\n"
            << "..:::::..::........::..::::..:::::..:::::........::..:::::..::...:::......::::......:::" << "\n" << endl;
        b = rand() % 10 + 1;
        SetColor(Yellow, Black);
        cout << "Угадайте число от 1 до 10" << endl;
        for (int i {0}; i <= 2; i++) {
            //cout << i << endl;
            //cout << b << "\n"; проверка рандомизации
            SetColor(Yellow, Black);
            cout << "Ваше число: ";
            cin >> a;
            if (a == b) {
                SetColor(Green, Black);
                cout << "Вы угадали! Заданное число было " << a << endl;
                cout << "\nНажмите Enter для перезапуска..." << endl; _getch(); break;
            }
            else {
                SetColor(Red, Black);
                cout << "Вы не угадали ! Попыток осталось ==> " << yourtry - (i + 1) << endl;
                if (i == 2) {
                    SetColor(White, Black);
                    cout << "Попытки закончились!  \nНажмите Enter для перезапуска..." << endl;
                    _getch();
                }
            }
        }
    }
}
