
#ifndef RISCV_UART_H_
#define RISCV_UART_H_

#include "riscv_types.h"

// STATUS REGISTER MASKS
#define RISCV_UART_DR   0x00000001 // UART DATA READY
#define RISCV_UART_TF   0x00000200 // UART TX FIFO is full
#define RISCV_UART_TE   0x00000004 // UART TX FIFO is empty

// CONTROL REGISTER MASKS
#define RISCV_UART_RXE   0x00000001 /* RX enable */
#define RISCV_UART_TXE   0x00000002 /* TX enable */
#define RISCV_UART_LB    0x00000080 /* Loop Back enable */
#define RISCV_UART_RI    0x00000004 /* Receiver interrupt enable */

int8_t riscv_putchar(char c);

int32_t riscv_getchar();

int8_t riscv_uart_tx_fifo_is_empty();

void riscv_uart_enable_TX();
void riscv_uart_disable_TX();

void riscv_uart_enable_RX();
void riscv_uart_disable_RX();

//transmits through the UART the string passed as a parameter

int8_t riscv_print_string(char* str);

//Receive a LF ended string an store it in the char array passed as a parameter

uint32_t riscv_get_line(char* str);

#endif /* RISCV_UART_H_ */
