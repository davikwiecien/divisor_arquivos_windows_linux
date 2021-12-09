#include "divide_arquivo.h"

void divide_arquivo(FILE **pfile, FILE **pcopy, char n[100], char rpos[5], int **p, unsigned long int tam, bool **vd) {

    unsigned long int soma = 0;
    int lenght = 0;
    char *ptr = NULL, *posicao = NULL, caracter[5] = {0};
    bool verifica = false;

    verifica = verifica_ponto(n, &posicao);

    if (verifica) strcpy(rpos, posicao);

    for (int i = 1; i <= **p; ++i) {

        ptr = (char*) malloc(tam * sizeof(char));

        if (ptr == NULL) {

            clear_win_linux();

            printf("\nErro na alocação de memória! Saindo do programa!\n\n");
            exit(1);

        }

        altera_nome(n, &posicao, caracter, rpos, i, &lenght, verifica);

        *pcopy = fopen(n, "w");

        if (*pcopy == NULL) {

            clear_win_linux();

            printf("\nErro ao criar a %dª parte do arquivo!\n\n", i);
            exit(1);

        }

        fread(ptr, sizeof(char), tam, *pfile);
        fwrite(ptr, sizeof(char), tam, *pcopy);

        soma += tam;

        fseek(*pfile, soma, SEEK_SET);

        if (i == **p) {

            zera_n(n);

            for (int j = 0; !feof(*pfile); ++j) {

                n[j] = fgetc(*pfile);

                if (n[j] == '\377') continue;

                fwrite(n, sizeof(char), 1, *pcopy);
                **vd = true;

            }

        }

        memset(ptr, '\0', tam);
        fclose(*pcopy);
        free(ptr);

    }

    rewind(*pfile);
    fclose(*pfile);

    return;

}

