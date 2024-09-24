#
# Exemplo de script no software Octave
#
#




# Limpe memoria (esqueça todas variáveis)
clear all

# Limpe a tela
clc

# Feche todos gráficos
close all


printf ("Este script contem um ou outro exemplo de plotagem\n");
printf ("Pressione uma tecla\n");
pause;




printf ("Criamos um array. Veja no código que o array cresce dinamicamente\n");

for k=1:10
   x(k) = (k-6) * 2;
endfor

x



printf ("\nAgora fazemos alguns cálculos\n");


for k=1:10
   y(k) = x(k) * x(k);
   z(k) = x(k) * y(k)  - x(k) * x(k);
endfor


printf ("\nE por fim alguns comandos plot. As janelas podem estar sobrepostas\n");
printf ("Pressione uma tecla\n");
pause;


#----------------------------------------------------------------------------------
plot (x,y);


#----------------------------------------------------------------------------------
figure
plot(x,y,'color','b', 'marker', 'd', 'linestyle', '--', 'linewidth', 3);
xlabel ('posição', 'fontsize', 24);
ylabel ('temperatura', 'fontsize', 24)
title ('gráfico', 'fontsize', 32)



#----------------------------------------------------------------------------------
figure
plot(x,y,'color','g', 'linewidth', 2);
hold on
plot(x,z,'color','b', 'linewidth', 2);

title ('Outro gráfico', 'fontsize', 32)
h=legend ('f(x)', 'g(x)')
set (h, "fontsize", 22);
