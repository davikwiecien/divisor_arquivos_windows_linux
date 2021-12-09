#include <locale.h>
#include "atribuicao_dados_uniao.h"
#include "clear_win_linux.h"
#include "buffer_win_linux.h"
#include "clear_n.h"
#include "verifica_ponto.h"

void atribuicao_dados_uniao(int *p, char imprime_fim[100]) {

    setlocale(LC_ALL, "");

    char nome[100] = {0}, rpos[5] = {0}, *posicao = NULL;
    bool verifica = false;

    clear_win_linux();

    printf("\nInforme o nome do arquivo a ser unido: ");
    buffer_win_linux();
    fgets(nome, 100, stdin);
    clear_n(nome);

    strcpy(imprime_fim, nome);

    verifica = verifica_ponto(nome, &posicao);

    verifica_acao(&p, nome, rpos, &posicao, verifica);

    return;

}

