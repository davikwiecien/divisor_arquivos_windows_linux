#include "verifica_ponto.h"
#include <string.h>

bool verifica_ponto(char n[100], char **pos) {

    int lenght = strlen(n) - 1;
    bool flag = false;

    for (int i = lenght; flag == false; --i) {

        if (n[i] == '.') {

            *pos = &n[i];
            flag = true;

        }

    }

    if (flag == false) return false;

    else return true;

}

