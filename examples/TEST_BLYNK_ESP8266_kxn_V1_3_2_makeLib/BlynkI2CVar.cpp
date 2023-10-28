#include "BlynkI2CVar.h"

void BlynkI2C_Init(){
    Wire.begin(SDA_PIN, SCL_PIN, I2C_SLAVE);
    Wire.onReceive(receiveEvent); // register event
    Wire.onRequest(requestEvent); // register event
}