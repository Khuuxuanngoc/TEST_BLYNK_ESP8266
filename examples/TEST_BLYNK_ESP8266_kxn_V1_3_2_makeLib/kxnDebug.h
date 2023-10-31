#ifndef kxnDebug__h
#define kxnDebug__h

#include "Arduino.h"

#define KXN_SERIAL                  Serial

#define KXN_DEBUG_UART_CMD(...)       KXN_SERIAL.print(__VA_ARGS__);
#define KXN_DEBUG_UART_CMD_T(...)     KXN_SERIAL.print(__VA_ARGS__); KXN_SERIAL.print("\t");
#define KXN_DEBUG_UART_CMD_LN(...)    KXN_SERIAL.print("[");KXN_SERIAL.print(__VA_ARGS__);KXN_SERIAL.println("]");

// #define KXN_DEBUG_UART_CMD(x)
// #define KXN_DEBUG_UART_CMD_T(x)
// #define KXN_DEBUG_UART_CMD_LN(x)

#endif