// RM 11:36

/*******************************************************************************************
Escrever um algoritmo que lê um valor X e calcula e escreve os 20 primeiros termos da série:
1+1/Xˆ2 +1/Xˆ3 +1/Xˆ4 +...
*******************************************************************************************/

#include <stdio.h>

int main() {
    // entrada de dados
    float startX;
    printf("Informe x: ");
    scanf("%f", &startX);

    // processamento de dados;
    int counter = 1; /*variavel contadora, e iniciará em 1 para que, com mais facilidade,
    consiga somar os 20 primeiros termos, visto que o primeiro termo, aqui, foge do padrão dos demais */
    float result = 1, modifiedX = startX; /* result e modified X serão acumuladoras.
    result = 1 pois o primeiro termo da soma é 1, e modifiedX iniciará = startX para fácil manipulação */

    /*******************************************************************
    1+1/Xˆ2 +1/Xˆ3 +1/Xˆ4 +...
    Se x ˆ 2 = x * x, logo x ^ 3 = x ^ 2 * x
    Portanto, x ^ n = x ^ (n - 1) * x; o que dispensa a bilioteca math.h
    *******************************************************************/
    while(counter < 20) {
        // x será manipulada, sempre multiplicada por startX, para obter o valor da potenciação
        modifiedX *= startX;
        result += (float) 1 / modifiedX;

        counter++; // incremento
    }
    // saída de dados
    printf("Para x=%f, o resultado de 1+1/xˆ2+1/xˆ3+...+1+xˆ20=%f", startX, result );

    return 0;
}

// RM 11:36