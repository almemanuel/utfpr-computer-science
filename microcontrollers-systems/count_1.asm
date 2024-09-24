; Configura��es do PIC
#include <p16f877a.inc>
__CONFIG _CP_OFF & _WDT_OFF & _PWRTE_ON & _HS_OSC

; Defini��o de constantes
COUNT_MAX    equ 9
COUNT_MIN    equ 0

; Defini��o de registradores
COUNT        equ 0x30

; Inicializa��o
   org 0x00
   goto start

; Interrup��o de reset
   org 0x04
   goto start

start:
   ; Configura��o dos pinos
   bsf STATUS, RP0      ; Muda para o banco 1
   movlw b'00000000'
   tris PORTB           ; Configura todos os pinos de PORTB como sa�das
   bcf STATUS, RP0      ; Muda de volta para o banco 0

   ; Inicializa��o do contador
   movlw COUNT_MIN
   movwf COUNT

loop:
   ; Atualiza display ou qualquer outra a��o aqui

   ; Incrementa ou decrementa
   incfsz COUNT, f
   goto loop
   movlw COUNT_MAX
   movwf COUNT
   decfsz COUNT, f
   goto loop

   end
