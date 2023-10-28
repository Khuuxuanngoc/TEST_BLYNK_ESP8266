// Wire Master Reader
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Reads data from an I2C/TWI slave device
// Refer to the "Wire Slave Sender" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

uint8_t txI2C[]={1,2,3,4,5,6,7};
uint8_t ui8_Address = 0x08;

void setup() {
  Wire.begin();        // join I2C bus (address optional for master)
  Serial.begin(9600);  // start serial for output

  uint8_t bb[10] = {1,2,3,4,5,6,7,8,9,10};

  uint8_t index = 3;
  Serial.println(bb[index]);    // 4
  Serial.println(bb[index++]);  // 4
  Serial.println(bb[index++]);  // 5
  Serial.println(bb[++index]);  // 7
  Serial.println(bb[++index]);  // 8
}
byte x = 0;
void loop() {
//  Wire.beginTransmission(0x2d); // transmit to device #8
//  Wire.write("x is ");        // sends five bytes
//  Wire.write(x);              // sends one byte
//  Wire.endTransmission();    // stop transmitting
//  x++;
//
//  delay(100);
//  Wire.requestFrom(0x2d, 6);    // request 6 bytes from slave device #8
//
//  while (Wire.available()) { // slave may send less than requested
//    char c = Wire.read(); // receive a byte as character
//    Serial.write(c);         // print the character
//  }
//  Serial.println();
//
//  delay(500);
  checkPC();
  printLive();
}

void checkPC(){
  if(Serial.available()){
    char rr = Serial.read();
    if(rr == 0x01){
      Serial.print("Send I2C to ");
      Serial.println(ui8_Address, HEX);
      Wire.beginTransmission(ui8_Address); // transmit to device #8
      Wire.write(txI2C[0]+x);
      Wire.write(txI2C[1]);
      Wire.write(txI2C[2]);
      Wire.write(txI2C[3]);
      Wire.write(txI2C[4]);
      Wire.write(txI2C[5] + x);
//      Wire.write("09876");        // sends five bytes
//      Wire.write(x);              // sends one byte
      Wire.endTransmission();    // stop transmitting
      x++;
    }else if(rr ==0x02){
      Serial.print("Read I2C from ");
      Serial.println(ui8_Address, HEX);
      Wire.requestFrom(ui8_Address, 6);    // request 6 bytes from slave device #8

      while (Wire.available()) { // slave may send less than requested
//        char c = Wire.read(); // receive a byte as character
//        Serial.write(c);         // print the character
        unsigned char c = Wire.read(); // receive a byte as character
        Serial.print(c);         // print the character
        Serial.print("\t");         // print the character
      }
      Serial.println();
    }else if(rr == 0x03){
      Serial.print("Send I2C to");
      Serial.println(ui8_Address, HEX);
      Wire.beginTransmission(ui8_Address); // transmit to device #8
      Wire.write(0b00000001);
      Wire.write(txI2C[1]);
      Wire.write(txI2C[2]);
      Wire.write(txI2C[3]);
      Wire.write(txI2C[4]);
      Wire.write(txI2C[5] + x);
//      Wire.write("09876");        // sends five bytes
//      Wire.write(x);              // sends one byte
      Wire.endTransmission();    // stop transmitting
      x++;
    }else if(rr == 0x04){
      Serial.print("Send I2C to ");
      Serial.println(ui8_Address, HEX);
      Wire.beginTransmission(ui8_Address); // transmit to device #8
      Wire.write(0b00000010);
      Wire.write(txI2C[1]);
      Wire.write(txI2C[2]);
      Wire.write(txI2C[3]);
      Wire.write(txI2C[4]);
      Wire.write(txI2C[5] + x);
//      Wire.write("09876");        // sends five bytes
//      Wire.write(x);              // sends one byte
      Wire.endTransmission();    // stop transmitting
      x++;
    }else if(rr == 0x05){
      scanI2C();
    }else{
      ui8_Address = rr;
    }
    
  }
}
unsigned long lastTimeLive = 0;
void printLive(){
  if(millis() - lastTimeLive >= 1000){
    lastTimeLive = millis();
    Serial.println("I live");
  }
}

void scanI2C(){
  int nDevices = 0;
  Serial.println("Scanning...");

  for (byte address = 1; address < 127; ++address) {
    // The i2c_scanner uses the return value of
    // the Wire.endTransmission to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    byte error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.print(address, HEX);
      Serial.println("  !");

      ++nDevices;
    } else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);
    }
  }
  if (nDevices == 0) {
    Serial.println("No I2C devices found\n");
  } else {
    Serial.println("done\n");
  }
}
