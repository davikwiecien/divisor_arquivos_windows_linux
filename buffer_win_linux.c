#include <stdio.h>
#include "buffer_win_linux.h"

void buffer_win_linux(void) {

    #ifdef __linux__

        __fpurge(stdin);

    #elif _WIN32

        fflush(stdin);

    #endif

    return;

}
