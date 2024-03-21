#include "gpio_drv.h"
#include "riscv_types.h"
#include "riscv_uart.h"

int main()
{
    uint32_t input[4]={0,0,0,0};
    uint32_t last_input[4]={0,0,0,0};

    uint32_t dir;
    char* textPrss = "BTX is pressed\n";
    char* textRls = "BTX is release\n";

    riscv_uart_enable_TX();

	// Enable output on bits 19..16
	dir = gpio_get_direction();
	dir |= 0x000F0000;
	gpio_set_direction( dir );

	printf("P1_1\n");

	while(1)
	{
        for (int i = 0; i < 4; i++)
        {
            last_input[i] = input[i];
	   	    input[i] = gpio_read() & (BTN_0_MASK<<i) ;

            if (!last_input[i] && input[i]){
                textPrss[2] = i + '0';
                riscv_print_string(textPrss);
            }

            if (last_input[i] && !input[i]){
                textRls[2] = i + '0';
                riscv_print_string(textRls);            
            }
        }
        
	}

return 0;
}