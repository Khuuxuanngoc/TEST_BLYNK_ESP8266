
#define pin_led 2 // led onboar
#define pin_button 0
#include <ESP8266WiFi.h> // Enable the use of wifi module. Make sure you downloaded and installed the ESP8266 library

/**
 * @brief Note
 * 
 *  Thu vien blynk1.2 chay OK
 */

int Virtualpin_V1;
int flag_V1 = 0;

#define BLYNK_TEMPLATE_ID "TMPL6_UMd7kUH"
#define BLYNK_TEMPLATE_NAME "kxntemplate8266"
#define BLYNK_AUTH_TOKEN "bw9Dlfusw60bHR6YVmZux9S_RSOmw2iM"
#include <BlynkSimpleEsp8266.h>
////
//#define BLYNK_AUTH_TOKEN "CgGJDmfA9o7ELQEHMXcVFFAcWVySHbiS"
char auth[] = BLYNK_AUTH_TOKEN;
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

  Blynk.begin(auth, ssid, pass);
  Serial.println("....OK");
}

void loop()
{
  Blynk.run();
  if (digitalRead(pin_button) == LOW)
  {
    Blynk.virtualWrite(V0, "400");
    Serial.println("button LOW");
  }
  else if (digitalRead(pin_button) == HIGH)
  {

    Blynk.virtualWrite(V0, 200);
    Serial.println("button HIGH");
  }

  button_control_blynk();


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
