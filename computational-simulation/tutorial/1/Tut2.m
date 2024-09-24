
#
# Exemplo de script no software Octave
#
#




# Limpe memoria (esqueça todas variáveis)
clear all

# Limpe a tela
clc




printf ("Este script contem exemplos de contas simples\ne programação em Octave\n");
printf ("Pressione uma tecla\n");
pause;




#-------------------------------------------------
# Contas

printf ("\nAlgumas contas simples\n");

x = 1 + 0
y = 2 * 1
x = 3 ^ 1  #potenciação



#-------------------------------------------------
# Comandos de todo dia:

n = 0;
m = 1;



printf ("\nExamine o código para saber de onde vem os valores 0..10\n");


for x = 0:10

   x
   n = n + x;
   m = m * x;
  
endfor



printf ("\nAgora um laço while \n");

n = 3;
while (n > 0)

   n = n - 1

endwhile



printf ("\nEste é um comando if:\n");

if (2 > 1)
	printf ("sim");
else
	printf ("não");
endif




#-------------------------------------------------


#entrada de dados

x = input ("\n\nDigite um número");



#-------------------------------------------------


#Leia uma matriz de numeros,
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

#-------------------------------------------------

# ja temos os vetores x e y.

# Agora encontre um polinomio p de interpolacao
#  grau do polinomio = 3.

p = polyfit (x, y, 3);


#-------------------------------------------------

# Usando polyfit(), o Octave ja fez a interpolacao
#  e determinou um polinomio.

# Agora teste a interpolacao,
#  isto e,
# calcule os valores  
# y2(1) = p(1)
# y2(2) = p(2), 
# etc..


y2 = polyval (p, x);


#-------------------------------------------------

#agora plote os dados originais, cor preta (blacK).
plot(x,y,'k');

#plote por cima outro grafico.
hold on;

#plote a interpolacao, cor azul (blue).
plot(x,y2,'b');

#-------------------------------------------------


# Por fim, plote outro grafico.
# Calculo valores do mesmo polinomio p, fora do intervalo dos dados.

# Crie um vetor [-5 -4 -3 -2 ...  ny+3 ny+4 ny+5]
x3 = -5 : ny+5;

# Calcule polinomio com esses valores.
y3 = polyval (p, x3);


# Abra uma nova janela de plotagem.
figure ; 

# Desenhe.
plot(x3,y3);  


# ==> COMPARE OS VALORES DOS GRAFICOS



