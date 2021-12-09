#include "retira_extensao.h"

void retira_extensao(char n[100]) {

    int len = strlen(n) - 1;

    for (int i = len; ; --i) {

        if (n[i] == '.') {

            n[i] = '\0';
            break;

        }

        else n[i] = '\0';

    }

    return;

}
