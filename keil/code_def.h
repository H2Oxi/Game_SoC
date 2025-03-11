#include <stdint.h>

//INTERRUPT DEF
#define NVIC_CTRL_ADDR (*(volatile unsigned *)0xe000e100)

//WATERLIGHT DEF
typedef struct{
    volatile uint32_t LED;
    volatile uint32_t DLED;
    volatile uint32_t MUSIC;
    volatile uint32_t LCD;
	
}UserType;

#define USER_BASE 0x40000000
#define USER ((UserType *)USER_BASE)

//UART DEF
typedef struct{
    volatile uint32_t UARTRX_DATA;
    volatile uint32_t UARTTX_STATE;
    volatile uint32_t UARTTX_DATA;
}UARTType;

#define UART_BASE 0x40000010
#define UART ((UARTType *)UART_BASE)


void Delay(int interval);
void delay_us(uint32_t delay_us);
char ReadUARTState(void);
char ReadUART(void);
void WriteUART(char data);
void UARTString(char *stri);
void UARTHandle(void);
void DrawLCD(uint32_t x,uint32_t y,uint32_t picture_ID);
void MusicPlay(uint32_t song_ID);
void SetDled(uint32_t n1,uint32_t n2,uint32_t n3,uint32_t n4,uint32_t n5,uint32_t n6);





