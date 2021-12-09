#include "clear_n.h"

void clear_n(char str[100]) {

    for (int i = 0; str[i] != '\0'; ++i)

        if (str[i] == '\n') {

            str[i] = '\0';

        }

    return;

}

