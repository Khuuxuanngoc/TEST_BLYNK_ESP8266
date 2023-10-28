#ifndef BlynkI2CVar__h_
#define BlynkI2CVar__h_

#include "Arduino.h"
#include "Wire.h"
#include "BlynkVarPin.h"

/* -------------------------------------------------------------------------- */
/*                                 I2C Config                                 */
/* -------------------------------------------------------------------------- */
#define I2C_SLAVE       0x08

/* ------------------------------- I2C Config ------------------------------- */

enum{
    I2C_CMD_VIRTUALPIN_READ,
    I2C_CMD_VIRTUALPIN_WRITE,
    I2C_CMD_SET_WIFI_ID,
    I2C_CMD_SET_WIFI_PASS,
    I2C_CMD_BLYNK_SET_TEMPLATE_ID,
    I2C_CMD_BLYNK_SET_TEMPLATE_NAME,
    I2C_CMD_BLYNK_SET_TOKEN
}structI2CCommand;

typedef struct{
    uint8_t notUse;
    uint8_t command;
    uint8_t len;
    char* buffer;
    uint8_t checksum;   // low BYTE sum only buffer

}structI2CData;

void BlynkI2C_Init();
#endif