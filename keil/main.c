#include "code_def.h"
#include <string.h>
#include <stdint.h>
#include "role.h"

uint8_t ready_time_en ;
uint16_t ready_time;
uint8_t show_gameover;
uint16_t show_time;
uint8_t show_mode;
uint8_t ready_time2_en ;
uint16_t ready_time2;
uint8_t hurt2_time;
uint8_t hurt1_time;
uint32_t game_time;

int main()
{ 
    //interrupt initial
    NVIC_CTRL_ADDR = 0x3ffff;
    unsigned long temp;                                  

		temp = 0x80804000|0x3F3F3F3F;          
		*((volatile unsigned long *)(0xE000E400)) = temp;     // IRP0
	   		temp = 0x80808080|0x3F3F3F3F;          
		*((volatile unsigned long *)(0xE000E404)) = temp;     // IRP1                              
      		temp = 0x80808080|0x3F3F3F3F;          
		*((volatile unsigned long *)(0xE000E408)) = temp;     // IRP2   
		temp = 0x80808080|0x3F3F3F3F;          
		*((volatile unsigned long *)(0xE000E40C)) = temp;     // IRP3
		temp = 0x80808080|0x3F3F3F3F;          
		*((volatile unsigned long *)(0xE000E410)) = temp;     // IRP4
	
	//----------------------------------//
    USER->LED=0xFFFF;
	  Role_Ini();
    show_mode=0;show_time=0;show_gameover=0;ready_time=0;ready_time_en=0;ready_time2=0;ready_time2_en=0;game_time=0;
	while(1){
			

			
    }
}
