clear all
clc
close all

M = csvread('Dados.csv');

[num_linhas, num_colunas] = size(M);

P = zeros(num_linhas, num_colunas);

% Loop sobre os graus de polinômio de 3 a 7
for grau = 3:7
    P = zeros(num_linhas, num_colunas);

    % Loop sobre as colunas para preencher os valores faltantes
    for i = 1:num_colunas
        % Encontrar índices onde os valores são diferentes de zero
        indices = find(M(:,i) ~= 0);

        % Verificar se há pelo menos 3 pontos para ajustar um polinômio
        if numel(indices) >= 3
            % Ajustar polinômio de grau atual aos índices não nulos
            coeficientes = polyfit(indices, M(indices,i), grau);

            % Calcular os valores estimados para todos os índices
            valores_estimados = polyval(coeficientes, 1:num_linhas);

            % Atualizar a coluna correspondente em P
            P(:,i) = valores_estimados';
        end
    end

    % Plotar o gráfico da matriz de saída para o grau atual
    figure;
    surf(P);
    title(['Matriz de saída (Regressão Polinomial de Grau ' num2str(grau) ')']);
    xlabel('Coluna');
    ylabel('Linha');
    zlabel('Valor');

    % Salvar o gráfico da matriz de saída para o grau atual
    saveas(gcf, ['Matriz_de_saida_grau_' num2str(grau) '.png']);
end

% Plotar os gráficos
surf(M);
title('Matriz de entrada');
xlabel('Coluna');
ylabel('Linha');
zlabel('Valor');

% Salvar o gráfico da matriz de entrada
saveas(gcf, 'Matriz_de_entrada.png');

figure();
surf(P);
title('Matriz de saída (Regressão Polinomial)');
xlabel('Coluna');
ylabel('Linha');
zlabel('Valor');
saveas(gcf, 'Matriz_de_saida.png');