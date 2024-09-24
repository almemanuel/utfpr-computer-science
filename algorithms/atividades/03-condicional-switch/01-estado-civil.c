// RM 11:36

/**************************************************************************************************
Fazer um programa para ler a primeira letra do estado civil de uma pessoa (Solteiro, Casado, Viúvo,
Divorciado, Uniaoestavel) e mostrar uma mensagem com a descrição.
Considere letras maiúsculas e minúsculas. Mostre mensagem de erro, se necessário.
**************************************************************************************************/

#include <stdio.h>

int main() {
    // entrada de dados
    char civilState;

    printf("Informe o estado civil: \nS - Solteiro;\nC - Casado;\nV - Viuvo;\nD - Divorciado;\nU - Uniao Estavel\n");
    scanf("%c", &civilState);
    // limpeza de buffer do teclado
    fflush(stdin);

    // processamento de dados e saida de dados
    switch(civilState) {
        case 'S':
        case 's':
            printf("Estado civil: solteiro(a)");
        break;

        case 'C':
        case 'c':
            printf("Estado civil: casado(a)");
        break;

        case 'V':
        case 'v':
            printf("Estado civil: viuvo(a)");
        break;

        case 'D':
        case 'd':
            printf("Estado civil: divorciado(a)");
        break;

        case 'U':
        case 'u':
            printf("Estado civil: uniao estavel");
        break;

        default:
            printf("ERRO! Entrada invalida");
        break;
    }

    return 0;
}

// RM 11:36