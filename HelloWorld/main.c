#include <windows.h>
#include <locale.h>
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define RED "\x1b[31m"
#define RESET   "\x1b[0m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"

void printSlow(const char* text, int delay) {
    while (*text) {
        printf("%c", *text++);
        fflush(stdout);
        Sleep(delay);
    }
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    float celsius, fahrenheit;

    printSlow(BLUE  "Привет, я конвертер градусов, конвертирую Цельсию на Фаренгейт" RESET"\n", 5);
    printSlow(YELLOW  "Напиши температуру по Цельсию: "RESET "\n", 8);

    if (scanf_s("%f", &celsius) != 1) {
        printSlow(RED "Ошибка ввода. Попробуйте снова." RESET "\n", 10);
        return 1;
    }

    fahrenheit = (celsius * 9 / 5) + 32;

    char buffer[100];
    sprintf_s(buffer, sizeof(buffer), BLUE "Температура в Фаренгейтах:" RESET " %.2f\n", fahrenheit);
    printSlow(buffer, 10);

    printSlow("                                                                        Спасибо что зашёл!" RED " <3" RESET "\n",100);

    return 0;
}

