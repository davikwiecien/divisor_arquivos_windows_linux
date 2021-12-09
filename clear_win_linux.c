#include "clear_win_linux.h"

void clear_win_linux(void) {

    #ifdef __linux__

        clear();

    #elif _WIN32

        system("cls");

    #endif

    return;

}
