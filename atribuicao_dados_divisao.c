#include <locale.h>
#include "atribuicao_dados_divisao.h"
#include "color.h"

bool atribuicao_dados_divisao(int *p, bool *vd, char imprime_fim[100]) {

    setlocale(LC_ALL, "");

    FILE *pfile = NULL, *pcopy = NULL;
    unsigned long int tamanho = 0;
    int cont = 0;
    char nome[100] = {0}, rpos[5] = {0}, op;

    #ifdef __linux__

        char blue[] = {0x1b, '[', '1', ';', '3', '4', 'm', 0 };
        char red[] = {0x1b, '[', '0', ';', '3', '1', 'm', 0 };
        char normal[] = {0x1b, '[', '0', ';', '3', '9', 'm', 0 };

    #endif

    clear_win_linux();

    printf("\nInforme o nome do arquivo a ser dividido: ");
    buffer_win_linux();
    fgets(nome, 100, stdin);
    clear_n(nome);

    pfile = fopen(nome, "r");

    if (pfile == NULL) {

        clear_win_linux();

        #ifdef _WIN32

            printf("\nErro ao abrir o arquivo");
            color(4, 0);
            printf(" \"%s\"", nome);
            color(7, 0);
            printf("!\n\n");

        #else

            printf("\nErro ao abrir o arquivo %s\"%s\"%s!\n\n", red, nome, normal);

        #endif

        exit(1);

    }

    fseek(pfile, 0, SEEK_END);
    tamanho = ftell(pfile);

    if (tamanho < 2) {

        printf("\nInválido! Arquivo com %lu byte de tamanho!\n\n", tamanho);
        exit(1);

    }

    #ifdef _WIN32

        printf("Informe em quantas partes quer dividir o arquivo");
        color(1, 0);
        printf(" \"%s\" ", nome);
        color(7, 0);
        printf(": ");

    #else

        printf("Informe em quantas partes quer dividir o arquivo %s\"%s\"%s: ", blue, nome, normal);

    #endif

    scanf("%d", &(*p));

    while (*p <= 1 || *p > tamanho || *p > 5000) {

        if (*p <= 1) {

            printf("\nInválido! É necessário dividir o arquivo em mais de 1 parte, digite novamente: ");
            scanf("%d", &(*p));

        }

        else if (*p > tamanho) {

            printf("\nInválido! A quantidade de partes é maior que o tamanho do arquivo, digite novamente: ");
            scanf("%d", &(*p));

        }

        else {

            printf("\nInválido! O limite para a divisão de arquivos é de 5000 partes, digite novamente: ");
            scanf("%d", &(*p));

        }

    }

    #ifdef _WIN32

        printf("\nATENÇÃO! O arquivo original");
        color(1, 0);
        printf(" \"%s\" ", nome);
        color(7, 0);
        printf("será dividido em %d partes! Tem certeza que deseja continuar (s/n)? ", *p);

    #else

        printf("\nATENÇÃO! O arquivo original %s\"%s\"%s será dividido em %d partes! Tem certeza que deseja continuar (s/n)? ", blue, nome, normal, *p);

    #endif

    scanf(" %c", &op);

    while (op != 's' && op != 'S' && op != 'n' && op != 'N') {

        if (cont == 0) printf("\n");

        printf("Inválido! Digite \"s\" ou \"n\": ");
        scanf(" %c", &op);

        ++cont;

    }

    if (op == 'n' || op == 'N') return false;

    tamanho /= *p;

    strcpy(imprime_fim, nome);

    rewind(pfile);

    divide_arquivo(&pfile, &pcopy, nome, rpos, &p, tamanho, &vd);

    return true;

}

