#include "gpio_drv.h"
#include "riscv_types.h"
#include "riscv_uart.h"

int main()
{
    char cadena[100];

    // TX/RX enable
    riscv_uart_enable_TX();
    riscv_uart_enable_RX();

    do {
        riscv_print_string("Type a caracter string: ");
        riscv_get_line( cadena );

        printf( "Se ha recibido la cadena: %s", cadena );

        // Send echo
        riscv_print_string( cadena );
    } while (1);
    return 0; 
}