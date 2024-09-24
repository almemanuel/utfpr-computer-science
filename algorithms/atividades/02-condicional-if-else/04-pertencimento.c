// RM 11:36

/****************************************************************************************************
São dados um número n e quatro outros, “A”, “B”, “C”, e “D”,
correspondentes, respectivamente, às extremidades dos intervalos [A,B] e [C,D], sendo A<B, C<D e A<C.
Determinar se n pertence somente ao intervalo [A,B] ou somente ao intervalo [C,D]
ou se, n pertence a ambos ou se n não pertence a nenhum dos dois.
Em cada caso imprimir uma mensagem conveniente.
****************************************************************************************************/

#include <stdio.h>

int main() {
    /***********************************************************************
    a, b, c e d correspondem as extremidades dos intervalos [A, B] e [C, D].
    number será o valor testado nos intervalos
    ***********************************************************************/
    float a, b, c, d, number;

    // entrada de dados
    printf("Digite um número: ");
    scanf("%f", &number);

    printf("Informe os valores das extremidades do primeiro intervalo: \n");
    scanf("%f %f", &a, &b);
    printf("Informe os valores das extremidades do segundo intervalo: \n");
    scanf("%f %f", &c, &d);

    // processamento e saida de dados
    // para a analise ser possivel, os intervalos devem ser validos
    if(a < b && c < d && a < c) {
        // verificar dentro de qual(is) intervalo(o) number está
        if((number > a && number < b) && (number > c && number < d)) {
            printf("%.2f pertence aos dois intervalos.", number);
        } else if(number > a && number < b) {
            printf("%.2f pertence ao intervalo [%.2f, %.2f]", number, a, b);
        } else if(number > c && number < d) {
            printf("%.2f pertence ao intervalo [%.2f, %.2f]", number, c, d);
        } else {
            printf("%.2f não pertence a nenhum dos intervalos", number);
        }
    } else {
        printf("Intervalo(s) invalido(s).");
    }

    return 0;
}

// RM 11:36