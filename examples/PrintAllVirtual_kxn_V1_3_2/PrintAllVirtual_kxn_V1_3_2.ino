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
  This example code is in public domain.

 *************************************************************
  This example uses BLYNK_WRITE_DEFAULT to capture arbitrary
  virtual pin changes. This may be useful if you have lots
  of DataStreams with controls.
  It also shows how to iterate over all parameter values.
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID           "TMPxxxxxx"
#define BLYNK_TEMPLATE_NAME         "Device"
#define BLYNK_AUTH_TOKEN            "bw9Dlfusw60bHR6YVmZux9S_RSOmw2iM"


// #include <SPI.h>
// #include <Ethernet.h>
// #include <BlynkSimpleEthernet.h>

#include <ESP8266WiFi.h> // Enable the use of wifi module. Make sure you downloaded and installed the ESP8266 library
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "DESKTOPkxn";     // Key in your wifi name. You can check with your smart phone for your wifi name
char pass[] = "30121992"; // Key in your wifi password.

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
  if(myInt == 0){
    Blynk.logEvent("baotrom", "Có trộm ở nhà");
  }
}

void setup()
{
  // Debug console
  Serial.begin(115200);

  // Blynk.begin(BLYNK_AUTH_TOKEN);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}

