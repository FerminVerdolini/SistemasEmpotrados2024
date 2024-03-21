#include "riscv_uart.h"

int main()
{
	// TX enable
	riscv_uart_enable_TX();

	// First test, console output
	riscv_putchar('P');
	riscv_putchar('2');
	riscv_putchar('\n');

	// Wait until TX fifo is empty
	do {
		// do nothing
	} while( !riscv_uart_tx_fifo_is_empty() );

	/* This is the same using a while loop
	while(!riscv_uart_tx_fifo_is_empty())
		; // empty statement
	*/
    
    return 0;
}