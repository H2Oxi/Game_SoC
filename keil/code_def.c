#include "code_def.h"
#include <string.h>


uint32_t LCD_finish;

void SetDled(uint32_t n1,uint32_t n2,uint32_t n3,uint32_t n4,uint32_t n5,uint32_t n6)
{
	if(n1>15)
		n1=0;
	if(n2>15)
		n2=0;
	if(n3>15)
		n3=0;
	if(n4>15)
		n4=0;
	if(n5>15)
		n5=0;
	if(n6>15)
		n6=0;
	USER->DLED=(n1<<1)|(n2<<5)|(n3<<9)|(n4<<13)|(n5<<17)|(n6<<21)|0x1;



}

void MusicPlay(uint32_t song_ID)
{
	USER->MUSIC=song_ID<<1;
	USER->MUSIC=(song_ID<<1)|0x1;
	USER->MUSIC=song_ID<<1;
}

void DrawLCD(uint32_t x,uint32_t y,uint32_t picture_ID)
{
	USER->LCD=(x<<24)|(y<<15)|(picture_ID<<1);
	USER->LCD=(x<<24)|(y<<15)|(picture_ID<<1)|0x01;
  USER->LCD=(x<<24)|(y<<15)|(picture_ID<<1);
	while(!LCD_finish) ;
	LCD_finish = 0;

}

void delay_us(uint32_t delay_us) 
 {    
   volatile unsigned int num;
  volatile unsigned int t;
  
   
   for (num = 0; num < delay_us; num++)
   {
     t = 11;
     while (t != 0)
     {
      t--;
     }
   }
}
