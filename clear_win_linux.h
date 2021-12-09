#include <stdio.h>

#ifdef __linux__

    #define clear() printf("\033[H\033[J")

#endif

void clear_win_linux(void);
