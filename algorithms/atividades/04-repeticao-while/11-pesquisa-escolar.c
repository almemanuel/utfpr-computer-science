// RM 11:36

/****************************************************************************************************
Foi feita uma pesquisa para saber o perfil dos alunos que cursam o ginásio de uma determinada escola.
Cada aluno fornecia:
- a sua idade;
- série (primeira-1, segunda-2, terceira-3 ou quarta-4);
- quantos livros liam por mês;
- e se gostavam de fazer redação (Sim-1 ou Não-0).
Fazer um programa que leia os dados, calcule e imprima:
1. A quantidade de alunos que está na terceira série;
2. A maior quantidade de livros lidos por um aluno que está na quarta série;
3. A porcentagem de alunos que não gostam de fazer redação e que estão na terceira série.
4. Média de idade dos alunos da primeira e segunda séries.
OBS: A condição de parada (flag) é que seja digitado 0 (zero) para idade.
****************************************************************************************************/

#include <stdio.h>

int main() {
    // entrada de dados
    int age = 1, grade, booksPerMonth, likeEssay;

    while (age != 0) {
        // idade do estudante
        printf("Idade do estudante: ");
        scanf("%i", &age);
        // validacao da idade
        while (age < 0) {
            printf("Idade Inválida. Digite novamente: ");
            scanf("%i", &age);
        }

        // serie
        printf("Serie (OBS: somente de 1 a 4): ");
        scanf("%i", &grade);
        // validacao da serie
        while(grade < 1 || grade > 4) {
            printf("Por favor, digite o numero correspondente a serie dentro do intervalo [1, 4]: ");
            scanf("%i", &grade);
        }

        // livros por mes
        printf("Livros lidos por mes: ");
        scanf("%i", &booksPerMonth);
        // validacao
        while(booksPerMonth < 0) {
            printf("ERRO! Digite valores nao nulos para a quantidade de livros lidas por mes");
            scanf("%i", &booksPerMonth);
        }

        // redacao
        printf("Digite 1 se o aluno gosta de fazer redação e 2 se não: ");
        scanf("%i", &likeEssay);
        //validacao
        while(likeEssay < 1 || likeEssay > 2) {
            printf("Por favor, digite apenas 1 ou 2. Tente novamente: ");
            scanf("%i", &likeEssay);
        }
    }
}

// RM 11:36