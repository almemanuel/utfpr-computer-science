
#
# Exemplo de script no software Octave
#
#



# Limpe memoria
clear all

# Limpe a tela
clc

# Feche todos gráficos
close all


printf ("Este script gera poucas saídas. Vc deve analisar o código e os resultados\n")
printf ("Pressione uma tecla\n");
pause;

#-------------------------------------------------


#Leia uma matriz de números,
# a partir de um arquivo em formato csv.

M = csvread ('dados-teste.csv');


#numero de linhas da matriz.
nx = size(M,1);

#numero de colunas da matriz.
ny = size(M,1);



#-------------------------------------------------

# Mostre na tela o primeiro elemento da matriz

M(1,1)


# Mostre o elemento na 5a linha, 3a coluna

M(5,3)


# Faca um calculo
M(1,1)+M(5,3)



#-------------------------------------------------

# Extraia (copie) da matriz a segunda linha

linha = M (2 , :);



# Extraia (copie) da matriz a terceira coluna

coluna = M ( : , 3);


# Mostre a linha e a coluna!

printf ("\n----------------------------\nDentro do script, altere a linha marcada com a palavra AQUI\n");
pause;


# AQUI  => coloque a próxima linha em comentário e rode novamente.
% more off

linha
coluna


# Transposição (observe saída na tela).

printf ("\n----------------------------------\nObserve o código!!\n\n")

[1 2 3]
[1 2 3]'

[4 ; 5 ; 6]
[4 ; 5 ; 6]'

printf ("\n----------------------------------\n")

#-------------------------------------------------

#construa um vetor com elementos da diagonal da matriz.
for k = 1:ny
   y(k) = M(k,k);
endfor

#-------------------------------------------------

# crie um vetor simples, numeros de 1 ate ny.
for k = 1:ny
   x(k) = k;
endfor


# outra forma de criar o mesmo vetor

x = 1:ny;



#uma função muito útil

printf ("Olhe no código como estes números são gerados!\n")
x = linspace (0,1,3);
x

y = linspace (0,1,10);
y
