clear all
clc
close all

# Você recebeu um arquivo de dados com uma matriz 50 x 50
M = csvread('dados-teste.csv');

# Sua tarefa é a seguinte.
# Determine qual coluna dessa matriz tem a menor média de valores.
med = 100000;
col = 1;
for i = 1:50
    this_mean = mean(M(:,i));
    if (mean(M(:,i)) < med)
        med = this_mean;
        col = i;
    endif
endfor


# Em seguida, considere que os valores nessa coluna correspondem a f(x),
#  para x variando entre -1.2 e +1.5.
ny = size(M,1);
y = M(:,22);
xm = linspace(-1.2, 1.5, numel(y));
x = zeros(ny,1);
for i=1:ny
    x(i) = xm(i);
endfor

# Calcule três regressões; uma linear, outra com parábola
#  e uma última usando um polinômio de grau 3.
# linear
p = polyfit(x, y, 1);
plot(x, y, 'o', x, polyval(p, x), '-');
xlabel('x');
ylabel('y');
title('Regressão Linear');
legend('Dados', 'Regressão Linear');
pause;

# parabola
pq = polyfit(x, y, 2);
plot(x, y, 'o', x, polyval(pq, x), '-');
xlabel('x');
ylabel('y');
title('Parabola');
legend('Dados', 'Parabola');
pause;

# Grau 3
p3 = polyfit(x, y, 3) #polinomio de grau 3
plot(x, y, 'o', x, polyval(p3, x), '-');
xlabel('x');
ylabel('y');
title('Grau 3');
legend('Dados', 'Grau 3');
pause;
