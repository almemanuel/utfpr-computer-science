% x''(t) = (-k * x(t)) / m
% determinar x(t)

% k = m = 1, del(t) = 2^(-5)
m = 1;
k = 1;
del_t = 2 ** -5;
t = 0:del_t:20;
vt = t;
n = length(t);
vx= zeros(1, n);
vv = zeros(1, n);
va = zeros(1, n);

vx(1) = 0;
vv(1) = 0;

for i = 2:n
    va(i - 1) = (-k * vx(i-1)) / m;
    vv(i) = vv(i-1)+ va(i-1) + del_t;
    vx(i) = vx(i-1) + vv(i) + del_t;
end

figure;
plot(vt, vx, 'b-', 'linewidth', 1.5);
title('Posição em função do tempo');
xlabel('Tempo');
ylabel('Posição');
pause();

figure;
plot(vx, vv, 'b-', 'linewidth', 1.5);
title('Velocidade em função da Posição');
xlabel('Posição');
ylabel('Velocidade');
pause();

vx(1) = 0; % posição inicial
vv(1) = 0.5; % velocidade inicial

% Simulação
for i = 2:n
    va(i - 1) = (-k * vx(i-1)) / m;
    vv(i) = vv(i-1) + va(i-1) * del_t; % Correção: alterado de + para *
    vx(i) = vx(i-1) + vv(i) * del_t; % Correção: alterado de + para *
end

% Plotar x(t) com velocidade inicial não nula
figure;
plot(vt, vx, 'b-', 'linewidth', 1.5);
title('Posição em função do tempo (velocidade inicial não nula)');
xlabel('Tempo');
ylabel('Posição');
pause();

figure;
plot(vx, vv, 'b-', 'linewidth', 1.5);
title('Velocidade em função da Posição');
xlabel('Posição');
ylabel('Velocidade');
pause();

% Implementar o esquema de cálculo apresentado em sala de aula
% mx'' = -kx -> massa
% x'' = -kx -> aceleração
% x''_n = -kx_a -> aceleração
% x'_n = x'a+del(t)x''_a -> velocidade
% x_n = x_a+del(t)x'_a -> posição

% aceleração, velocidade e posicao novas = funcao variaveis velhas
% velho recebe novo, roda o laço
% crie vetores para armazenar: vt, vx, vv e va
% simular o teste no inverlado t = [0; 20] e grafico com plot(vt, vx)
% repetir o experimento com x'(t=0)=+0.5
