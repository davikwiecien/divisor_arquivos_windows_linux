#include "une_arquivos.h"
#include "clear_win_linux.h"

void une_arquivos(FILE **pfile, FILE **ppfile, unsigned long int *s) {

    char *ptr = NULL;
    unsigned long int tam = 0;

    fseek(*ppfile, 0, SEEK_END);
    tam = ftell(*ppfile);

    ptr = (char*) malloc(tam * sizeof(char));

    if (ptr == NULL) {

        clear_win_linux();

        printf("\nErro na alocação de memória! Saindo do programa!\n\n");
        exit(1);

    }

    rewind(*ppfile);

    fread(ptr, sizeof(char), tam, *ppfile);
    fwrite(ptr, sizeof(char), tam, *pfile);

    *s += tam;

    fseek(*pfile, *s, SEEK_SET);

    memset(ptr, '\0', tam);
    fclose(*ppfile);
    free(ptr);

    return;

}

