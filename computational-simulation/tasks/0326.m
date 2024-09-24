clear all
clc
close all

% Um veículo inicialmente parado começa a se mover e demora 1 minuto para atingir 60km/h (a aceleração nesse trecho é constante).
v1_final = 60; % km/h
t1 = 1 / 60; % h
d1 = 10; % km
a1 = v1_final / t1; % km/h^2
t1_segment = linspace(0, t1, 100); % min
v1_segment = a1 * t1_segment; % km/h
x1_segment = 0.5 * a1 * t1_segment.^2; % Distância percorrida durante o segmento 1 (km)

%Ele permanece nessa velocidade constante, percorrendo uma distância de 10 km.
v2 = 60;
d2 = 10;
t2 = d2 / v2;
a2 = 0;
t2_segment = linspace(t1, t1 + t2, 100);
v2_segment = v2 * ones(size(t2_segment));
x2_segment = d1 + v2 * (t2_segment - t1); % Distância percorrida durante o segmento 2 (km)

%O veículo entra em uma rodovia, e gradativamente acelera de 60 km/h até 120 km/h, demorando 3 minutos para isso(a aceleração nesse período também é constante).
v3_inicial = 60;
v3_final = 120;
t3 = 3 / 60;
d3 = 10 / 60;
a3 = (v3_final - v3_inicial) / t3;
t3_segment = linspace((t1 + t2), (t1 + t2 + t3), 100);
v3_segment = a3 * (t3_segment - t1 + t2) + v3_inicial;
x3_segment = d1 + d2 + v2 * (t3_segment - t1 - t2) + 0.5 * a3 * (t3_segment - t1 - t2).^2; % Distância percorrida durante o segmento 3 (km)

%Ele permanece nessa velocidade, constante, e percorre outros 10 km.
v4 = 120;
d4 = 10;
t4 = d4 / v4;
a4 = 0;
t4_segment = linspace(t1 + t2 + t3, t1 + t2 + t3 + t4, 100);
v4_segment = v4 * ones(size(t4_segment));
x4_segment = d1 + d2 + d3 + v4 * (t4_segment - t1 - t2 - t3); % Distância percorrida durante o segmento 4 (km)


%Finalmente, o condutor decide parar, demorando 2 minutos para que a velocidade caia a zero.
v5_inicial = 120;
v5_final = 0;
t5 = 2 / 60;
d5 = 10;
a5 = (v5_final - v5_inicial) / t5;
t5_segment = linspace((t1 + t2 + t3 + t4), (t1 + t2 + t3 + t4 + t5), 100);
v5_segment = a5 * (t5_segment - t1 + t2 + t3 + t4) + v5_inicial;
x5_segment = d1 + d2 + d3 + d4 + v4 * (t5_segment - t1 - t2 - t3 - t4); % Distância percorrida durante o segmento 5 (km)


% Juntando os vetores de tempo, velocidade e posição para todos os trechos
% Definição dos tempos em minutos
t1_minutes = t1_segment * 60;
t2_minutes = (t1 + t2_segment) * 60;
t3_minutes = (t1 + t2 + t3_segment) * 60;
t4_minutes = (t1 + t2 + t3 + t4_segment) * 60;
t5_minutes = (t1 + t2 + t3 + t4 + t5_segment) * 60;


% Plotando o gráfico
% Concatenando os vetores de tempo, velocidade e distância para plotagem
tempo_total = [t1_minutes, t2_minutes, t3_minutes, t4_minutes, t5_minutes];
velocidade_total = [v1_segment, v2_segment, v3_segment, v4_segment, v5_segment];
distancia_total = [x1_segment, x2_segment, x3_segment , x4_segment, x5_segment];

% Plotando os gráficos de velocidade e distância em função do tempo
figure;

% Gráfico de Velocidade
subplot(2,1,1);
plot([0, t1_minutes(end)], [0, v1_final], 'Color', [0.8500, 0.3250, 0.0980], 'LineWidth', 2, ...
     [t1_minutes(end), t2_minutes(end)], [v1_final, v2], 'Color', [0.8500, 0.3250, 0.0980], 'LineWidth', 2, ...
     [t2_minutes(end), t3_minutes(end)], [v2, v3_final], 'Color', [0.8500, 0.3250, 0.0980], 'LineWidth', 2, ...
     [t3_minutes(end), t4_minutes(end)], [v3_final, v4], 'Color', [0.8500, 0.3250, 0.0980], 'LineWidth', 2, ...
     [t4_minutes(end), t5_minutes(end)], [v4, v5_final], 'Color', [0.8500, 0.3250, 0.0980], 'LineWidth', 2);
xlabel('Tempo (minutos)');
ylabel('Velocidade (km/h)');
ylim([0, 140]); % Limitando o eixo y para valores positivos e um pouco acima do máximo
title('Gráfico de Velocidade em Função do Tempo');
grid on;

% Gráfico de Distância
subplot(2,1,2);
plot([0, t1_minutes(end)], [0, x1_segment(end)], 'Color', [0.8500, 0.3250, 0.0980], 'LineWidth', 2, ...
     [t1_minutes(end), t2_minutes(end)], [x1_segment(end), x2_segment(end)], 'Color', [0.8500, 0.3250, 0.0980], 'LineWidth', 2, ...
     [t2_minutes(end), t3_minutes(end)], [x2_segment(end), x3_segment(end)], 'Color', [0.8500, 0.3250, 0.0980], 'LineWidth', 2, ...
     [t3_minutes(end), t4_minutes(end)], [x3_segment(end), x4_segment(end)], 'Color', [0.8500, 0.3250, 0.0980], 'LineWidth', 2, ...
     [t4_minutes(end), t5_minutes(end)], [x4_segment(end), x5_segment(end)], 'Color', [0.8500, 0.3250, 0.0980], 'LineWidth', 2);
xlabel('Tempo (minutos)');
ylabel('Distância (km)');
ylim([0, 50]); % Limitando o eixo y para valores positivos e um pouco acima do máximo
title('Gráfico de Distância em Função do Tempo');
grid on;

% Ajustando espaçamento entre os subplots
spacing = 0.05; % Ajuste o valor conforme necessário
pos = get(gca, 'Position');
pos(4) = pos(4) - spacing;
set(gca, 'Position', pos);

% Ajustando espaçamento entre os subplots
pos = get(gca, 'Position');
pos(2) = pos(2) + spacing;
set(gca, 'Position', pos);

pause();
