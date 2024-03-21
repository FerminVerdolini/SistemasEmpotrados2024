#include "gpio_drv.h"


int main()
{
    uint32_t input;
    uint32_t dir;

    uint32_t input_mask  = SW_0_MASK ;
    uint32_t output_mask = LED_0_MASK;

	// Enable output on bits 19..16
	dir = gpio_get_direction();
	dir |= 0x000F0000;
	gpio_set_direction( dir );

	printf("P1_1\n");

	while(1)
	{
	   	// Get GPIO bits
	   	input = gpio_read();


	   	if ( input & input_mask )
	   	{
	    	gpio_write( gpio_read() | output_mask );
	   	}
	   	else
	   	{
	      	gpio_write( gpio_read() & ~output_mask );
		}

		input_mask  <<= 1;
		output_mask <<= 1;
        
		if(input_mask > (SW_3_MASK)){
			input_mask  = SW_0_MASK ;
    		output_mask = LED_0_MASK;
		}

	} // while(1)

return 0;
}