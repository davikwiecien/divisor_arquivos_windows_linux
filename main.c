/*
COMO EXECUTAR O CÓDIGO (Linux):
Compile o código-fonte com o GCC em algum diretório, então crie um arquivo de teste nesse mesmo diretório (ou baixe o "teste.txt" anterior), escolha a opção 1 e
informe o nome do arquivo (se o arquivo escolhido estiver em outro diretório que não seja o do código fonte, digite o caminho completo). Em seguida, informe em
quantas partes quer dividir o arquivo, assim a divisão será feita. Para uni-lo novamente, escolha a opção 2 e informe outra vez o nome do arquivo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include "atribuicao_dados_divisao.h"
#include "atribuicao_dados_uniao.h"
#include "clear_win_linux.h"
#include "buffer_win_linux.h"
#include "color.h"

#ifdef __linux__

    #include <stdio_ext.h>

#endif

int main(int argc, char *argv[]) {

    setlocale(LC_ALL, "");

    int op = 0, partes = 0, imprime_n = 0;
    char imprime_fim[100] = {0};
    bool verifica_divisao = false, flag = false;

    #ifdef __linux__

        char blue[] = {0x1b, '[', '1', ';', '3', '4', 'm', 0 };
        char normal[] = {0x1b, '[', '0', ';', '3', '9', 'm', 0 };

    #endif

    do {

        clear_win_linux();

        printf("\n1 - Dividir arquivo\n2 - Unir arquivo\n3 - Sair\n\nEscolha uma opção: ");
        scanf("%d", &op);

        flag = false;
        partes = 0;
        imprime_n = 0;

        while (op < 1 || op > 3) {

            if (imprime_n == 0) printf("\n");

            printf("Inválido! Digite \"1\" para dividir um arquivo, \"2\" para unir um arquivo ou \"3\" para sair: ");
            scanf("%d", &op);
            ++imprime_n;

        }

        switch (op) {

            case 1:

                if (atribuicao_dados_divisao(&partes, &verifica_divisao, imprime_fim)) {

                    clear_win_linux();

                    if (verifica_divisao == true)

                        printf("\nA divisão do arquivo por %d não deu exata! A %dª parte ficou com mais bytes!", partes, partes);

                    #ifdef __WIN32

                    printf("\nArquivo");
                    color(1, 0);
                    printf(" \"%s\" ", imprime_fim);
                    color(7, 0);
                    printf("dividido com sucesso em %d partes!\n", partes);

                    #else

                    printf("\nArquivo %s\"%s\"%s dividido com sucesso em %d partes!\n", blue, imprime_fim, normal, partes);

                    #endif

                    remove(imprime_fim);
                    flag = true;

                }

                break;

            case 2:

                atribuicao_dados_uniao(&partes, imprime_fim);

                clear_win_linux();

                #ifdef _WIN32

                    printf("\nArquivo");
                    color(1, 0);
                    printf(" \"%s\" ", imprime_fim);
                    color(7, 0);
                    printf("unido com sucesso em %d partes!\n", partes);

                #else

                printf("\nArquivo %s\"%s\"%s unido com sucesso em %d partes!\n", blue, imprime_fim, normal, partes);

                #endif

                flag = true;
                break;

            }


            if (op != 3 && flag == true) {

                printf("\nPressione ENTER para continuar... ");
                buffer_win_linux();
                getc(stdin);

            }

    }
    while (op != 3);

    clear_win_linux();

    printf("\nSaindo!\n\n");

    return 0;

}
