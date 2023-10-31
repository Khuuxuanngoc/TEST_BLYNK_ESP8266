/* -------------------------------------------------------------------------- */
/*                                   KXN LOG                                  */
/* -------------------------------------------------------------------------- */
/**
 *  HISTORY
 *    - y23m10d31:
 *      - Set Token, WF-ID, WF-PS ok: connect bw9Dlfusw60bHR6YVmZux9S_RSOmw2iM DESKTOPkxn 30121992
 *        + CMD: connect
 *        + Token: bw9Dlfusw60bHR6YVmZux9S_RSOmw2iM
 *        + Wifi-SSID: DESKTOPkxn
 *        + Wifi-Pass: 30121992
 *      - Connect Server Blynk ok
 *        + Read VirtualPin V1, V0 OK see BLYNK_WRITE_DEFAULT()
 *      - Dua theo https://docs.blynk.io/en/blynk.cloud/device-https-api: Template Name va ID ko can thiet
 */


/* ------------------------------- END KXN LOG ------------------------------ */

/*************************************************************
  Blynk is a platform with iOS and Android apps to control
  ESP32, Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build mobile and web interfaces for any
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: https://www.blynk.io
    Sketch generator:           https://examples.blynk.cc
    Blynk community:            https://community.blynk.cc
    Follow us:                  https://www.fb.com/blynkapp
                                https://twitter.com/blynk_app

  Blynk library is licensed under MIT license
 *************************************************************
  Blynk.Edgent implements:
  - Blynk.Inject - Dynamic WiFi credentials provisioning
  - Blynk.Air    - Over The Air firmware updates
  - Device state indication using a physical LED
  - Credentials reset using a physical Button
 *************************************************************/

/* Fill in information from your Blynk Template here */
/* Read more: https://bit.ly/BlynkInject */
// #define BLYNK_TEMPLATE_ID           "TMPxxxxxx"
// #define BLYNK_TEMPLATE_NAME         "Device"

#define BLYNK_TEMPLATE_ID "TMPL6_UMd7kUl"
// #define BLYNK_TEMPLATE_ID "TMPL6_UMd7kUH"
#define BLYNK_TEMPLATE_NAME "kxntemplate8266"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

// #define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"

void setup()
{
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
}

#define KXNSHOW(x)   Serial.print(#x"\t"); Serial.println(x);
// This is called for all virtual pins, that don't have BLYNK_WRITE handler
BLYNK_WRITE_DEFAULT() {
  Serial.print("input V");
  Serial.print(request.pin);
  Serial.println(":");
  // Print all parameter values
  for (auto i = param.begin(); i < param.end(); ++i) {
    Serial.print("* ");
    Serial.println(i.asString());
  }

  double myDouble = param.asDouble();
  String myString = param.asString();
  int myInt = param.asInt();

  KXNSHOW(myDouble);
  KXNSHOW(myString);
  KXNSHOW(myInt);
}