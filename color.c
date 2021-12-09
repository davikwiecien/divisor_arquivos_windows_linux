#include "color.h"

#ifdef _WIN32

    #include <windows.h>

    static int __BACKGROUND;
    static int __FOREGROUND;

    void color(int letras, int fundo) {

        __FOREGROUND = letras;
        __BACKGROUND = fundo;
        SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
        letras + (__BACKGROUND << 4));

        return;

    }

#endif
