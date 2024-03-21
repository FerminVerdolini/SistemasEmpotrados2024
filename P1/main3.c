#define uint32_t unsigned int
#include "gpio_drv.h"


int main()
{
    uint32_t input[4]={0,0,0,0};
    uint32_t last_input[4]={0,0,0,0};

    uint32_t dir;

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
                gpio_write( gpio_read() ^ (LED_0_MASK << i));
            }
        }
        
	}

return 0;
}