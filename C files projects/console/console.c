/* Copyright (c) Microsoft Corporation.
   Licensed under the MIT License. */

#include "console.h"

int __io_putchar(int ch)
{
	HAL_UART_Transmit(&CONSOLE_UART_HANDLE, (uint8_t *)&ch, 1, COM_POLL_TIMEOUT);
	return ch;
}

int __io_getchar(void)
{
	uint8_t ch;
	HAL_UART_Receive(&CONSOLE_UART_HANDLE, &ch, 1, COM_POLL_TIMEOUT);

	/* Echo character back to console */
	HAL_UART_Transmit(&CONSOLE_UART_HANDLE, &ch, 1, COM_POLL_TIMEOUT);

	/* And cope with Windows */
	if (ch == '\r') {
		uint8_t ret = '\n';
		HAL_UART_Transmit(&CONSOLE_UART_HANDLE, &ret, 1, COM_POLL_TIMEOUT);
	}

	return ch;
}

#ifdef __ICCARM__
size_t __read(int file, unsigned char *ptr, size_t len)
#elif __GNUC__
int _read(int file, char *ptr, int len)
#else
#error unknown compiler
#endif
{
	int DataIdx;

	for (DataIdx = 0; DataIdx < len; DataIdx++)
	{
		*ptr++ = __io_getchar();
	}
	return len;
}

#ifdef __ICCARM__
size_t __write(int file, const unsigned char *ptr, size_t len)
#elif __GNUC__
int _write(int file, char *ptr, int len)
#else
#error unknown compiler
#endif
{
	int DataIdx;

	for (DataIdx = 0; DataIdx < len; DataIdx++)
	{
		__io_putchar(*ptr++);
	}
	return len;
}
