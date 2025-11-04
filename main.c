#include <stdio.h>
#include "ripes_system.h"

volatile int * LEDMat = (volatile int *)LED_MATRIX_0_BASE;
volatile int * Switches = (volatile int *)SWITCHES_0_BASE;
volatile int * DPadUp = (volatile int *)D_PAD_0_UP;
volatile int * DPadDown = (volatile int *)D_PAD_0_DOWN;
volatile int * DPadLeft = (volatile int *)D_PAD_0_LEFT;
volatile int * DPadRight = (volatile int *)D_PAD_0_RIGHT;

int main(){
    
    int rgb = 0;
    
    while(1){
        
        
        rgb = *Switches;
        printf("RGB = %x\n", rgb);
        
        *LEDMat = 0x00;
        
        if(*DPadUp)
            LEDMat -= LED_MATRIX_0_WIDTH;
        else if(*DPadDown)
            LEDMat += LED_MATRIX_0_WIDTH;
        else if(*DPadLeft)
            LEDMat --;
        else if(*DPadRight)
            LEDMat ++;
            
        *LEDMat = rgb;
        
        for(int i = 0; i < 10000; i++);
    }
    
    return 0;
    
}
