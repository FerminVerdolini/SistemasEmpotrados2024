#include "riscv_types.h"
#include "dispatch.h"

#include "log.h"

int main()
{
    printf("----------SyscallS--------------\n");

    printf("syscall 22\n");
    syscall(22, 1);

    printf("syscall 15\n");
    syscall(15, 2);

    printf("----------EXCEPTIONS---------\n");

    printf("Write NULL pointer\n");
    uint32_t *p = 0;
    *p = 234;        // Attempt to write using a NULL pointer

    printf("READ NULL pointer\n");
    uint32_t x = *p; // Attempt to read using a NULL pointer

    printf("UNALIGNED WRITE\n");
    p = (uint32_t *)123;
    *p = 334;       // Attempt to write an uint32_t value to an odd address

    printf("UNALIGNED READ\n");
    x = *p;         // Attempt to read an uint32_t value from an odd address

    return 0;
}