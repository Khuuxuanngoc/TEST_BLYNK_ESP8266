// y23m10d23// kxn comment here fix bug macro
 /* -------------------------------------------------------------------------- */
 /*                             Serial command test                            */
 /* -------------------------------------------------------------------------- */
// Console.h:63
//  connect 9wKogex0eoSGCMMsUZywCmbv_YNcHqew DESKTOPkxn 30121992
//  connect bw9Dlfusw60bHR6YVmZux9S_RSOmw2iM DESKTOPkxn 30121992

// wifi

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
//#define BLYNK_TEMPLATE_ID           "TMPxxxxxx"
//#define BLYNK_TEMPLATE_NAME         "Device"

// #define BLYNK_TEMPLATE_ID "TMPL6dOjDR5a3"
// #define BLYNK_TEMPLATE_NAME "Quickstart Template"

// #define BLYNK_TEMPLATE_ID           arr_String
// #define BLYNK_TEMPLATE_NAME         arr_StringName

// #define BLYNK_FIRMWARE_VERSION        "0.100.20"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI


// #define KXN_MACRO_STR     "hello"
#define KXN_MACRO_STR     arr_String

char* p_String = "hello From [char* p_String]";
char arr_String[100] = "TMPL6dOjDR5a3";
char arr_StringName[100] = "kxn Quickstart Template";

void testConstStrPara(const char * p_tempConstStr){
  String kk = p_tempConstStr;
  Serial.println(kk);
  Serial.println(p_tempConstStr);
}


#include "kxnRunBlynk.h"
#include "BlynkEdgent.h"

char arr_StringTemplateId[100] = "TMPL6dOjDR5a3";
char arr_StringTemplateName[100] = "Quickstart Template";

// char auth[100] = BLYNK_AUTH_TOKEN;
// char ssid[50] = "DESKTOPkxn";     // Key in your wifi name. You can check with your smart phone for your wifi name
// char pass[100] = "30121992"; // Key in your wifi password.

void kxn_BlynkInit(){
    // Blynk.begin(auth, ssid, pass);
}

//#define KXNSHOW(x)   Serial.print(#x"\t"); Serial.println(x);

void setup()
{
  Serial.begin(115200);
  delay(100);
  Serial.println(BLYNK_FIRMWARE_VERSION);

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
  // GetDataFromSerial(&Serial);
}
