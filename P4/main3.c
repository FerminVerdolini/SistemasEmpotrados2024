#include riscv_types.h

int main()
{
	printf("----------MONOTONIC TIME---------\n");

	// Time set: 5/5/2024 12:40
	InitMonotonicClock(date_time_to_Y2K(5, 5, 24, 12, 40, 0 ));
    
	uint32_t previous = 0;
	uint32_t current  = 0;

	do {
		current = GetUniversalTime_Y2K();

		if ( current != previous )
		{
			print_date_time_from_Y2K( current );
			previous = current;
		}
	} while ( 1 );

	printf("\n----------END---------\n");
    
    return 0;
}