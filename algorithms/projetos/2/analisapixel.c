/*************************************************************************************************************
Desenvolvido por Emanuel Almeida e Eduardo Bento
*************************************************************************************************************/

#include "analisapixel.h"
#include <stdio.h>

int coordenadaValida(int M, int N, bool mat[M][N], int linha, int coluna, bool proc[M][N]) {
    // row number is in range, column number is in range and value is 1
    // and not yet visited
    return (linha >= 0) && (linha < M) &&
        (coluna >= 0) && (coluna < N) &&
        (mat[linha][coluna] && !proc[linha][coluna]);
}

int buscaEmProfundidade(int M, int N, bool mat[M][N], int linha, int coluna, bool proc[M][N]) {
    int j;

    // Um pixel é considerado da mesma mancha apenas nas condições do enunciado
    // O que se resume em 4 direções: esquerda (-1, 0), direita (1, 0), baixo (0, 1), cima (0, -1)
    int linhavizinha[4] = {-1, 0, 0, 1};
    int colunavizinha[4] = {0, -1, 1, 0};

    // Processa pixel, logo = true
    proc[linha][coluna] = true;

    // for(j = 0; j < 4; j++){

    //     if ( ( (linha + linhavizinha[j] >= 0) && (linha + linhavizinha[j] <= N) &&
    //         (coluna + colunavizinha[j] >= 0) && (coluna + colunavizinha[j] <= M) &&
    //         (mat[linha + linhavizinha[j]][coluna+ colunavizinha[j]] &&
    //           !proc[linha + linhavizinha[j]][coluna + colunavizinha[j]]) ) )
    //     {
    //         buscaEmProfundidade(mat, (linha + linhavizinha[j]), (coluna + colunavizinha[j]), proc);
    //     }

    // }

    for (j = 0; j < 4; j++) {
        if( coordenadaValida(M, N, mat, linha + linhavizinha[j], coluna + colunavizinha[j], proc) ) {
            buscaEmProfundidade(M, N, mat, (linha + linhavizinha[j]), (coluna + colunavizinha[j]), proc);
        }
    }

    return 0;
}

int buscaManchas(int M, int N, bool mat[M][N]) {
    // mapeador de processamento
    // (sim = true, não = false)
    bool proc[M][N];
    int i, k;
    for(i = 0; i < M; i++) {
        for(k = 0; k < N; k++) {
            proc[i][k] = 0;
        }
    }

    // contabiliza se na vizinhança não houver uma mancha já processada
    int manchas = 0;
    for(i = 0; i < M; i++) {
        for(k = 0; k < N; k++) {
            if(mat[i][k] && !proc[i][k]) {
                buscaEmProfundidade(M, N, mat, i, k, proc);
                manchas++;
            }
        }
    }

    return manchas;
}