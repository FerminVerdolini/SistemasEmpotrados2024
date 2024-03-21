#include "gpio_drv.h"
#include "riscv_types.h"
#include "riscv_uart.h"

int main()
{
	int32_t rec;
	char car;
	// TX/RX enable
	riscv_uart_enable_TX();
	riscv_uart_enable_RX();

	riscv_print_string("Type a caracter string: ");
	do
	{
		// Blocking loop until a char is received
		do {
			rec = riscv_getchar(); 
		} while( rec == -1 );
        
		car = (char)(rec);

		printf("Recibido: [%c:%d]\n", (char)car, car);

	} while (rec != 27);
    
	return 0;
}