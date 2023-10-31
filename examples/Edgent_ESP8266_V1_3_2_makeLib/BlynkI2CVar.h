#ifndef BlynkI2CVar__h_
#define BlynkI2CVar__h_

#include "Arduino.h"
#include "Wire.h"
#include "kxnDebug.h"

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

/* --------------------------- Command Uart String -------------------------- */
#define BLYNK_CMD_UART_SET_NAME         "SETNAME"
#define BLYNK_CMD_UART_SET_ID           "SETID"
#define BLYNK_CMD_UART_SET_TOKEN        "SETTOKEN"

#define BLYNK_CMD_UART_SET_WF_ID        "SETWFID"
#define BLYNK_CMD_UART_SET_WF_PS        "SETWFPS"

#define BLYNK_CMD_UART_RESTART          "RESTART"

// set name command example "SETNAME123456\n" => BLYNK_TEMPLATE_NAME = "123456"
// set name command example "SETID12345689\n" => BLYNK_TEMPLATE_ID = "12345689"


typedef struct{
    uint8_t notUse;
    uint8_t command;
    uint8_t len;
    char* buffer;
    uint8_t checksum;   // low BYTE sum only buffer

}structI2CData;

extern char blynkTemplateName[];
extern char blynkTemplateId[];
extern char blynkToken[];

extern char blynkWifiId[];
extern char blynkWifiPs[];

// void BlynkI2C_Init();
void BlynkGetBuffer(char item_temp);

void CheckCmdString(String command_temp, String tempStrCmd, char * outArrayChar);

void testGetStringFromUart(String command_temp);

void GetDataFromSerial(Stream * pTempSerial);

void ShowKxnAllBuffer();

#endif