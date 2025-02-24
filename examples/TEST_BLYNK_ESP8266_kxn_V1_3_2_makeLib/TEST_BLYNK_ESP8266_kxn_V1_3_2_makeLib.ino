/**
 * @brief TEST_BLYNK_ESP8266_kxn_V1_3_2_makeLib.ino
 * 
 *    Idea:
 *      - User setup and get data Over I2C
 *        - WiFi name, pas
 *          + SetWiFi(SSID, PASS)
 *        - BlynkTemplateID, BlynkTemplateNAME, BlynkAuthToken
 *          + SetBlynk(ID, NAME, TOKEN)
 *        - Get-Set Vpin Data:
 *          + V0-> V9: double
 *            + getNumberData(i) return double
 *            + setNumberData(i, double value)
 *          + V10-> V19: String
 *            + getStringData(i) return String          
 *            + setStringData(i, string value)
 */
// https://docs.blynk.io/en/blynk-library-firmware-api/virtual-pins

#define BLYNK_TEMPLATE_ID "TTMPL6_UMd7kUHkxn"
#define BLYNK_TEMPLATE_NAME "kxntemplate8266kxn"
// #define BLYNK_AUTH_TOKEN "bw9Dlfusw60bHR6YVmZux9S_RSOmw2iM"    // kxntemplate8266

// #define BLYNK_TEMPLATE_ID "TMPL6dOjDR5a3"
// #define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "9wKogex0eoSGCMMsUZywCmbv_YNcHqew"    // Quickstart Template token

// #define BLYNK_TEMPLATE_ID    (char*)var_BLYNK_TEMPLATE_ID
// #define BLYNK_TEMPLATE_NAME  (char*)var_BLYNK_TEMPLATE_NAME
// #define BLYNK_AUTH_TOKEN     (char*)var_BLYNK_AUTH_TOKEN

// String var_BLYNK_TEMPLATE_ID    = "TMPL6_UMd7kUH";
// String var_BLYNK_TEMPLATE_NAME  = "kxntemplate8266";
// String var_BLYNK_AUTH_TOKEN     = "bw9Dlfusw60bHR6YVmZux9S_RSOmw2iM";

#define pin_led 2 // led onboar
#define pin_button 0
#include <ESP8266WiFi.h> // Enable the use of wifi module. Make sure you downloaded and installed the ESP8266 library
#include <BlynkSimpleEsp8266.h>
#include "BlynkI2CVar.h"
/**
 * @brief Note
 * 
 *  Thu vien blynk1.2 chay OK
 */

int Virtualpin_V1;
int flag_V1 = 0;



////
//#define BLYNK_AUTH_TOKEN "CgGJDmfA9o7ELQEHMXcVFFAcWVySHbiS"
char auth[] = BLYNK_AUTH_TOKEN;
// char auth[] = "bw9Dlfusw60bHR6YVmZux9S_RSOmw2iM";
// char ssid[] = "Hshop.vn";     // Key in your wifi name. You can check with your smart phone for your wifi name
// char pass[] = ""; // Key in your wifi password.

char ssid[] = "DESKTOPkxn";     // Key in your wifi name. You can check with your smart phone for your wifi name
char pass[] = "30121992"; // Key in your wifi password.

// button
bool manual_relay_button = 0;

unsigned long pressStartTime;
bool databutton = 0;
void setup()
{
  // put your setup code here, to run once:
  pinMode(pin_led, OUTPUT);
  pinMode(pin_button, INPUT);
  Serial.begin(9600);
  Serial.print("RUN");

  // Blynk.begin(auth, ssid, pass);
  Serial.println("....OK");
}

void loop()
{
  GetDataFromSerial(&Serial);
  // Blynk.run();
  // if (digitalRead(pin_button) == LOW)
  // {
  //   Blynk.virtualWrite(V0, 400);
  //   Serial.println("button LOW");
  // }
  // else if (digitalRead(pin_button) == HIGH)
  // {

  //   Blynk.virtualWrite(V0, 200);
  //   Serial.println("button HIGH");
  // }

  // button_control_blynk();


}
void button_control_blynk()
{

  if (flag_V1 == 1)
  {

    if (Virtualpin_V1 == 0)
    {
      digitalWrite(pin_led, LOW);
    }
    else if (Virtualpin_V1 == 1)
    {

      digitalWrite(pin_led, HIGH);
    }
  }

  flag_V1 = 0;
}
BLYNK_CONNECTED()
{

  Blynk.syncVirtual(V1);
  Serial.println(F("Blynk Connect"));
}

BLYNK_WRITE(V1)
{

  Virtualpin_V1 = param.asInt();
  flag_V1 = 1;
}
void button()
{
  if (digitalRead(pin_button) == LOW)
  {
    manual_relay_button = LOW;
  }
  else if (digitalRead(pin_button) == HIGH)
  {
    manual_relay_button = HIGH;
  }
}
