#include <locale.h>
#include "verifica_acao.h"
#include "color.h"

void verifica_acao(int **p, char n[100], char rpos[5], char **pos, bool v) {

    setlocale(LC_ALL, "");

    FILE *pfile = NULL, *ppfile = NULL;
    char c[5] = {0}, nome_recebe[50] = {0};
    unsigned long int soma = 0;
    int len = 0;
    bool flag = false;

    #ifdef __linux__

        char red[] = {0x1b, '[', '0', ';', '3', '1', 'm', 0 };
        char normal[] = {0x1b, '[', '0', ';', '3', '9', 'm', 0 };

    #endif

    strcpy(nome_recebe, n);

    if (v) strcpy(rpos, *pos);

    while (flag == false) {

        sprintf(c, "%d", (**p) + 1);

        if (v) retira_extensao(n);

        if (**p == 0) {

            len = strlen(n);
            n[len] = '-';

        }

        for (int j = len + 1; n[j] != '\0'; ++j)

            n[j] = '\0';

        strcat(n, c);

        if (v) strcat(n, rpos);

        ppfile = fopen(n, "r");

        if (ppfile != NULL) {

            if (**p == 0) pfile = fopen(nome_recebe, "w");

            une_arquivos(&pfile, &ppfile, &soma);
            remove(n);
            ++(**p);

        }

        else flag = true;

    }

    if (**p != 0) {

        rewind(pfile);
        fclose(pfile);
        return;

    }

    else {

        clear_win_linux();

        #ifdef __WIN32

            printf("\nErro ao unir o arquivo");
            color(4, 0);
            printf(" \"%s\"", nome_recebe);
            color(7, 0);
            printf("! O arquivo não existe ou pode não ter sido dividido previamente!\n\n");

        #else

            printf("\nErro ao unir o arquivo %s\"%s\"%s! O arquivo não existe ou pode não ter sido dividido previamente!\n\n", red, nome_recebe, normal);

        #endif

        exit(1);

    }

}

