#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include <gpio.h>           // GPIO library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#define LED_GREEN PB5   // PB5 is AVR pin where green on-board LED
                        // is connected
#define LED_RED PB0     // External active-low LED
#define BUTTON PD3

#define PB5 5          // In Arduino world, PB5 is called "13"
#define PB0 0
#define PD3 3


int main(void)
{
    DDRB |= (1<<LED_GREEN);
    DDRB |= (1<<LED_RED);

    TIM2_overflow_4ms();
    // Enable overflow interrupt
    TIM2_overflow_interrupt_enable();
        
    // Enables interrupts by setting the global interrupt mask
    sei();
    while (1)
    {
      
    }
    
}

// Interrupt service routines
ISR(TIMER0_OVF_vect)
{
    /*
    static uint8_t no_of_overflows = 0;

    no_of_overflows++;
    if (no_of_overflows >= 6)
    {
        // Do this every 6 x 16 ms = 100 ms
        no_of_overflows = 0;
    */
        PORTB ^= (1<<LED_RED);
        PORTB ^= (1<<LED_RED);    
    //}
    // Else do nothing and exit the ISR
    
}