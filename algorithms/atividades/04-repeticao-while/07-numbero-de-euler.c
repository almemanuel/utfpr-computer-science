// RM 11:36

/********************************************************************************************************
Sabe-se que o número Neperiano e = 2.7182818 ... (que é um número irracional) pode ser calculado
pela soma dos valores de uma série infinita, como mostrado abaixo:
    e = 1/0! + 1/1! + 1/2! + ... + 1/n!
Fazer um programa em C que calcule este número (e) considerando apenas as 15 (quinze) primeiras parcelas.
********************************************************************************************************/

#include <stdio.h>

int main(){
    // dados iniciais
    double e = 1, factorial; // e será a variável acumuladora, e será iniciada em 1, pois 1/0! = 1
    int n = 15; // será a variavel contadora

    // processamento de dados
    // calculo do numero de Euler considerando n = 15
    while(n >= 1) {
        // calculo do fatorial de n
        int factorial = n, auxiliar = n;

	    while(auxiliar > 1) {
		    auxiliar--;
	    	factorial *= auxiliar;
    	}

        e += (1.0 / factorial);
        n--;
    }
    // saída de dados
    printf("Considerando as 15 primeiras parcelas, o numero de Euler é, aproximadamente, %.10lf", e);

    return 0;
}

// RM 11:36