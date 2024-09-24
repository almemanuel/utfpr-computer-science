// RM 11:36

/*************************************************************************************
Fazer um algoritmo para determinar e escrever o valor do seguinte somatório:
S = X – Xˆ2/3! + Xˆ4/5! – Xˆ6/7! + Xˆ8/!9 - ... usando os n primeiros termos do somatório.
O valor de X e de n é fornecido pelo usuário.
*************************************************************************************/

#include <stdio.h>
#include <math.h>

int main() {
    float x;
    int n;

    printf("Informe um valor para x: ");
    scanf("%f", &x);

    // n precisa ser positivo para o fatorial existir
    do{
        printf("Informe um valor positivo para n: ");
        scanf("%i", &n);

        if(n < 0) {
            printf("Erro! Informe um valor positivo!\n");
        }
    } while(n < 0);

    float s = x;
    int factorial = 1;

    for(int i = 1; i < n; i++) {
        factorial *= (i + 1) * (i + 2); // fatorial simplicado
        if(i % 2 == 0) {
            s += (pow(x, i * 2) / factorial);
        } else {
            s -= (pow(x, i * 2) / factorial);
        }
    }

    printf("O somatorio de x = %.3f ate o termo n = %i eh %.3f", x, n, s);

    return 0;
}

// RM 11:36