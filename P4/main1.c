#include "riscv_types.h"
#include "dispatch.h"

uint32_t ticks = 0;

void timer_handler(void)
{
	printf("%d ", ticks );
	ticks++;
}

int main()
{
	printf("----------TIMER IRQ---------\n");
	install_local_timer_handler( timer_handler );
	local_timer_set_gap( 10000000 ); // CLINC timer clock is 10Mhz
    
	enable_timer_clinc_irq();
	enable_irq();	          // Global interrupt enable

	while( ticks <= 10 )
		; // empty statement

	printf("\n----------END---------\n");
    
    return 0;
}