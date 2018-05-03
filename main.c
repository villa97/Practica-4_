#include <18F4620.h>
#include <stdlib.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)
int contador200=0;
int contador500=0;
int contador1s=0;
void main (void)
{
   int display[10]={65,6,91,79,102,109,125,7,12,103};
   setup_oscillator(OSC_16MHZ);
   set_tris_b(0x00);
   set_tris_d(0x00);
   set_tris_c(0x00);
   while(1)
   {
      for(contador200;contador200<10;contador200++)
      output_b(display[contador200]);
   }
}

