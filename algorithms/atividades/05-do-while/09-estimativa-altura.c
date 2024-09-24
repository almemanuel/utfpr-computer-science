// RM 11:36

/********************************************************************************************************************
Fulano tem 1,50 metro e cresce 2 centímetros por ano, enquanto Ciclano tem 1,10 metro e cresce 3 centímetros por ano.
Construa um programa que calcule e imprima quantos anos serão necessários para que Ciclano seja maior que Fulano.
********************************************************************************************************************/

#include <stdio.h>

int main() {
    // dados iniciais
    int heightFulano = 150, heightCiclano = 110, time = 0;

    // processamento de dados
    do {
        heightFulano += 2;
        heightCiclano += 3;
        time++;
    } while(heightFulano > heightCiclano);

    // saída de dados
    printf("Serão necessarios %i anos para que Ciclano seja mais alto de Fulano", time);

    return 0;
}

// RM 11:36