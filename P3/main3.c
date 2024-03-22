#include "riscv_types.h"
#include "riscv_uart.h"
#include "dispatch.h"

#include "log.h"

#define ESC 27

char car;
char buffer[256]; // 256 bytes buffer
uint32_t idx = 0;
volatile uint32_t flag = 0;

// UART ISR handler
// It is going to be called each time a new car is received
void uart_rx_irq_handler (void)
{
    car = (char)riscv_getchar();

    // store car in buffer
    buffer[idx] = car;
    // increment idx
    idx++;
    // if car is LF set flag
    if(car == ESC){
        flag = 1;       
    } 
}

int main()
{
	// TX/RX enable
	riscv_uart_enable_TX();
	riscv_uart_enable_RX();
    
	// Install uart handler
	install_irq_handler( UART_IRQ, uart_rx_irq_handler );
    
	riscv_uart_enable_RI();       // Enable RX irq
	plic_irq_unmask( UART_IRQ );  // PLIC UART irq unmask
	enable_ext_irq();    	      // Enable MIE.MEI
	enable_irq();	              // Global interrupt enable

	riscv_print_string("Embedded Systems\n");

	while( 1 )
	{
        // if flag is set print buffer and send it back as an echo
        if(flag == 1){
            printf(buffer);
            riscv_print_string(buffer);
            //set idx to zero
            idx = 0;
            //clear flag
            flag = 0;
        }
	}

	return 0;
}