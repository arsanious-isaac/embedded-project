#include "gpio.h"

void EdgeCounter_Init(void){                          
  SYSCTL_RCGC2_R |= 1<<4;  // (a) activate clock for port E
  GPIO_PORTE_DIR_R &= ~0x10;    // (c) make PF4 in (built-in button)
  GPIO_PORTE_AFSEL_R &= ~0x10;  //     disable alt funct on PF4
  GPIO_PORTE_DEN_R |= 0x10;     //     enable digital I/O on PF4   
  GPIO_PORTE_PCTL_R &= ~0x000F0000; // configure PF4 as GPIO
  GPIO_PORTE_AMSEL_R = 0;       //     disable analog functionality on PF4
  GPIO_PORTE_PUR_R |= 0x10;     //     enable weak pull-up on PF4
  GPIO_PORTE_IS_R &= ~0x10;     // (d) PF4 is edge-sensitive
  GPIO_PORTE_IBE_R &= ~0x10;    //     PF4 is not both edges
  GPIO_PORTE_IEV_R &= ~0x10;    //     PF4 falling edge event
  GPIO_PORTE_ICR_R = 0x10;      // (e) clear flag4
  GPIO_PORTE_IM_R |= 0x10;      // (f) arm interrupt on PF4
	
  NVIC_PRI7_R = (NVIC_PRI7_R&0xFF00FFFF)|0x00A00000; // (g) priority 5
  NVIC_EN0_R = 0x40000000;      // (h) enable interrupt 30 in NVIC
  EnableInterrupts();           // (i) Clears the I bit
}

void PortE_Init(void){ 
	volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000010;     // 1) F clock
  delay = SYSCTL_RCGC2_R;           // delay   
  GPIO_PORTE_LOCK_R = 0x4C4F434B;   // 2) unlock PortE
  GPIO_PORTE_CR_R = 0x1E;           // allow changes to PE4-0     
  GPIO_PORTE_AMSEL_R = 0x00;        // 3) disable analog function
  GPIO_PORTE_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
  GPIO_PORTE_DIR_R = 0x02;          // 5) PE0 input, PE1 output   
  GPIO_PORTE_AFSEL_R = 0x00;        // 6) no alternate function
  GPIO_PORTE_PDR_R= 0x01;          // enable pulldown resistors on PE0       
  GPIO_PORTE_DEN_R = 0xFF;  
	GPIO_PORTE_PUR_R = 0x00;          // enable pullup resistors on PE1,PE0       

}



