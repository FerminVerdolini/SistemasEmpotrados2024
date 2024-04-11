#include "riscv_types.h"
#include "dispatch.h"

uint32_t ticks = 0;
uint8_t flag1 = 0;
uint8_t flag2 = 0;

void timer_handler(void)
{	
	ticks++;
    if(ticks%10 == 0){
        flag1 = 1;
    }
    if(ticks%50 == 0){
        flag2 = 1;
    }
}

int main()
{
	install_local_timer_handler( timer_handler );
	local_timer_set_gap( 1000000 ); // CLINC timer clock is 10Mhz
    
	enable_timer_clinc_irq();
	enable_irq();	          // Global interrupt enable

	while(1){
        if(flag1){
            flag1 = 0;
        	printf("msg 1");
        }
        if (flag2)
        {
            flag2 = 0;
        	printf("msg 2");
        }        
    }    
    return 0;
}