// y23m10d23// kxn comment here fix bug macro

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

#define BLYNK_TEMPLATE_ID           arr_String
#define BLYNK_TEMPLATE_NAME         arr_StringName

#define BLYNK_FIRMWARE_VERSION        "0.100.20"

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
// char arr_String[100] = "hello From [arr_String[100]]";
char arr_String[100] = "TMPL6dOjDR5a3kxn";
char arr_StringName[100] = "kxn Quickstart Template kxn";

void testConstStrPara(const char * p_tempConstStr){
  String kk = p_tempConstStr;
  Serial.println(kk);
  Serial.println(p_tempConstStr);
}


#include "BlynkEdgent.h"



void setup()
{
  Serial.begin(115200);
  delay(100);
  Serial.println(BLYNK_FIRMWARE_VERSION);
  testConstStrPara(KXN_MACRO_STR);
  testConstStrPara(p_String);
  testConstStrPara(arr_String);

  kxntest();
  kxnTestLoop();

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
}

void kxnTestLoop(){
  char arrayTest[100] = "hello1";
  strcpy(BLYNK_TEMPLATE_ID, arrayTest);
  kxntest();

  char arrayTest2[50] = "TMPLkxn6dOjDR5a3kxn";
  strcpy(BLYNK_TEMPLATE_ID, arrayTest2);
  kxntest();
}

void kxntest(){
  static const char profile[] BLYNK_PROGMEM = "blnkinf\0"

        // Firmware info
#if defined(BLYNK_NCP_VERSION)
        BLYNK_PARAM_KV("ncp"    , BLYNK_NCP_VERSION)
#else
        BLYNK_PARAM_KV("mcu"    , BLYNK_FIRMWARE_VERSION)
#endif
#ifdef BLYNK_FIRMWARE_TYPE
        // BLYNK_PARAM_KV("fw-type", BLYNK_FIRMWARE_TYPE)
        // BLYNK_PARAM_KV("fw-type", kxnfirmwareType)
#endif
        BLYNK_PARAM_KV("build"  , __DATE__ " " __TIME__)
        BLYNK_PARAM_KV("blynk"  , BLYNK_VERSION)

        // Protocol setup
        BLYNK_PARAM_KV("h-beat" , BLYNK_TOSTRING(BLYNK_HEARTBEAT))
        BLYNK_PARAM_KV("buff-in", BLYNK_TOSTRING(BLYNK_MAX_READBYTES))

        // Additional info
#ifdef BLYNK_INFO_DEVICE
        BLYNK_PARAM_KV("dev"    , BLYNK_INFO_DEVICE)
#endif
#ifdef BLYNK_INFO_CPU
        BLYNK_PARAM_KV("cpu"    , BLYNK_INFO_CPU)
#endif
#ifdef BLYNK_INFO_CONNECTION
        BLYNK_PARAM_KV("con"    , BLYNK_INFO_CONNECTION)
#endif
        "\0"
    ;
    Serial.println(F("=========="));
    Serial.println(sizeof(profile));
    Serial.println(profile);
    Serial.println(profile + 8);

    Serial.println(F("====----++++"));
    for (int i = 0; i < sizeof(profile); i++) {
    if (profile[i] == '\0') {
      Serial.println(); // In dòng mới khi gặp ký tự null
    } else {
      Serial.print(profile[i]); // In ký tự hiện tại
    }
  }

//     char mem_dyn[164];
//     BlynkParam profile_dyn(mem_dyn, 0, sizeof(mem_dyn));
// #ifdef BLYNK_TEMPLATE_ID
//     {
//         const char* tmpl = BLYNK_TEMPLATE_ID;
//         if (tmpl && strlen(tmpl)) {
//             profile_dyn.add_key("tmpl", tmpl);
//             profile_dyn.add_key("fw-type", tmpl);
//             profile_dyn.add_key("kxntime","kxnTime"__TIME__);
//             profile_dyn.add_key("kxntime","kxnTime"__DATE__);
//         }
//     }
// #endif
    /* -------------------------------------------------------------------------- */
    /*                             Print out Sendinfo                             */
    /* -------------------------------------------------------------------------- */
  char mem_dyn[264];
    BlynkParam profile_dyn(mem_dyn, 0, sizeof(mem_dyn));

    /* -------------------------------------------------------------------------- */
    /*                                   Kxn add                                  */
    /* -------------------------------------------------------------------------- */
    #define BLYNK_PARAM_KV_KXN(x,y)     profile_dyn.add_key(x, y);
    
#ifdef BLYNK_FIRMWARE_TYPE
        BLYNK_PARAM_KV_KXN("fw-type", BLYNK_FIRMWARE_TYPE)
        // BLYNK_PARAM_KV_KXN("fw-type", kxnfirmwareType)
#endif
        BLYNK_PARAM_KV_KXN("build"  , __DATE__ " " __TIME__)
        BLYNK_PARAM_KV_KXN("blynk"  , BLYNK_VERSION)

        // Protocol setup
        BLYNK_PARAM_KV_KXN("h-beat" , BLYNK_TOSTRING(BLYNK_HEARTBEAT))
        BLYNK_PARAM_KV_KXN("buff-in", BLYNK_TOSTRING(BLYNK_MAX_READBYTES))

        // Additional info
#ifdef BLYNK_INFO_DEVICE
        BLYNK_PARAM_KV_KXN("dev"    , BLYNK_INFO_DEVICE)
#endif
#ifdef BLYNK_INFO_CPU
        BLYNK_PARAM_KV_KXN("cpu"    , BLYNK_INFO_CPU)
#endif
#ifdef BLYNK_INFO_CONNECTION
        BLYNK_PARAM_KV_KXN("con"    , BLYNK_INFO_CONNECTION)
#endif
    /* ------------------------------- end Kxn add ------------------------------ */
#ifdef BLYNK_TEMPLATE_ID
    {
        const char* tmpl = BLYNK_TEMPLATE_ID;
        if (tmpl && strlen(tmpl)) {
            profile_dyn.add_key("tmpl", tmpl);
            profile_dyn.add_key("kxnEnd", "kxnEnd");
        }
    }
#endif
    /* ------------------------- End Print out sendInfo ------------------------- */
    Serial.println(F("++++++"));
    Serial.println("sizeof(mem_dyn)" + String(sizeof(mem_dyn)));
    Serial.println(profile_dyn.getLength()-1);
    Serial.println((char*)profile_dyn.getBuffer());
    // Serial.println((char*)profile_dyn.getBuffer() + 5);

    for (int i = 0; i < profile_dyn.getLength()-1; i++) {
    if (*((char*)profile_dyn.getBuffer()+i) == '\0') {
      Serial.print((char*)profile_dyn.getBuffer()+i+1); // In ký tự hiện tại
      Serial.println(); // In dòng mới khi gặp ký tự null
    } else {
      // Serial.print((char*)profile_dyn.getBuffer()+i); // In ký tự hiện tại
    }
  }
}

