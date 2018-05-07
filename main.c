#include <18F4620.h>
#include <stdlib.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)
#use fast_io(b)
#use fast_io(c)
#use fast_io(d)
int contadorCiclos200=0;
int contadorCiclos500=0;
int contadorCiclos1s=0;
#int_timer0                 
void timer0(void)  
{
   contadorCiclos200++;         
   contadorCiclos500++;
   contadorCiclos1s++;
}
void main (void)
{
   set_timer0(0);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_128|T0_8_BIT);   //Configuracion de la fuente y divisor del TMR0 <<<<<<Acomodar
   enable_interrupts(int_timer0);  //Abilitamos la interrupcion TIMER0
   enable_interrupts(GLOBAL);      //Abilitamos las interrupciones globales 
   while(1)
   {
       if(contadorCiclos200>24)
       {
           conteoDisplay200++;
           contadorCiclos200=0;
           if(conteoDisplay200>9)
               conteoDisplay200 = 0;
       }
       if(contadorCiclos500>61)
       {           
           conteoDisplay500++;
           contadorCiclos500=0;
           if(conteoDisplay500>9)
               conteoDisplay500 = 0;
       }
       if(contadorCiclos1s>122)
       {
           conteoDisplay1s++;
           contadorCiclos1s=0;
           if(conteoDisplay1s>9)
               conteoDisplay1s = 0;
       }
   }
}

