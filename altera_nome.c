#include "altera_nome.h"
#include "retira_extensao.h"

void altera_nome(char n[100], char **pos, char c[5], char rpos[10], int cont, int *lenght, bool v) {

    sprintf(c, "%d", cont);

    if (v) retira_extensao(n);

    if (cont == 1) {

        *lenght = strlen(n);
        n[*lenght] = '-';

    }

    for (int j = *lenght + 1; n[j] != '\0'; ++j)

        n[j] = '\0';

    strcat(n, c);

    if (v) strcat(n, rpos);

    return;

}
