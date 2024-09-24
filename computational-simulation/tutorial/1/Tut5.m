
#
# Exemplo de script no software Octave
#
#






# ATENCAO
# Obrigatoriamente escreva algum comando antes da função.
# Se vc não fizer isso, Octave irá reclamar semelhante à Java
#  (vc pode experimentar).


1+1;



#----------------------------------------------------------------
function retorno = Funcao (a,b,c)

   retorno = a+b+c;

endfunction




#----------------------------------------------------------------
function OutraFuncao ()

   printf ("\nNada a dizer");

endfunction



#----------------------------------------------------------------
global gn;

function r = EOutraFuncao (x)

   global gn;

   gn = gn + 1;

   r = x * gn;

endfunction


#----------------------------------------------------------------
function r = AindaOutraFuncao(x)

   r = -1.23 * (x + 0.5);
   

endfunction



printf ("\nResultado 1 = %f", Funcao (1,2,3))

OutraFuncao ()

gn = 1;
printf ("\nResultado 2 = %f\n", EOutraFuncao (10))


AindaOutraFuncao ([1 2 ; 3 4])


