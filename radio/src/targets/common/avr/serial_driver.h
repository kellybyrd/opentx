/*
 * Copyright (C) OpenTX
 *
 * Based on code named
 *   th9x - http://code.google.com/p/th9x 
 *   er9x - http://code.google.com/p/er9x
 *   gruvin9x - http://code.google.com/p/gruvin9x
 *
 * License GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _SERIAL_DRIVER_H_
#define _SERIAL_DRIVER_H_

#include <inttypes.h>

typedef enum serial_tx_state_ {
	TX_STATE_EMPTY = 0, //
	TX_STATE_READY, //
	TX_STATE_BUSY
} serial_tx_state_t;
extern serial_tx_state_t serialTxState;

//! \brief Baudrate selection.
enum SERIAL_BAUDS {
	BAUD_4800 = 0,
	BAUD_9600,
	BAUD_14400,
	BAUD_19200,
	BAUD_38400,
	BAUD_57600,
	BAUD_76800
};

//! \brief Definition of baudrate settings item choices.
typedef void (*SerialFuncP)(uint8_t event);

extern SerialFuncP RXHandler;

#define MAX_TX_BUFFER 32
//#if 0
extern uint8_t serialTxBuffer[MAX_TX_BUFFER]; // 32 characters
extern uint8_t serialTxBufferCount;
extern uint8_t * ptrTxISR;
//#endif

void SERIAL_Init(void);
//void SERIAL_transmitBuffer(uint8_t len);
extern void SERIAL_start_uart_send();
extern void SERIAL_end_uart_send();
extern void SERIAL_send_uart_bytes(uint8_t * buf, uint16_t len);

void SERIAL_startTX(void);
#define IS_TX_BUSY (serialTxState!=TX_STATE_EMPTY)

#endif // _SERIAL_DRIVER_H_
