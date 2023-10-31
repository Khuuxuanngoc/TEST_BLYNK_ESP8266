// #include "kxnRunBlynk.h"
// #include "BlynkEdgent.h"

// char arr_StringTemplateId[100] = "TMPL6dOjDR5a3kxn";
// char arr_StringTemplateName[100] = "kxn Quickstart Template kxn";

// // char auth[100] = BLYNK_AUTH_TOKEN;
// // char ssid[50] = "DESKTOPkxn";     // Key in your wifi name. You can check with your smart phone for your wifi name
// // char pass[100] = "30121992"; // Key in your wifi password.

// void kxn_BlynkInit(){
//     // Blynk.begin(auth, ssid, pass);
// }

// #define KXNSHOW(x)   Serial.print(#x"\t"); Serial.println(x);

// BLYNK_WRITE_DEFAULT() {
//   Serial.print("input V");
//   Serial.print(request.pin);
//   Serial.println(":");
//   // Print all parameter values
//   for (auto i = param.begin(); i < param.end(); ++i) {
//     Serial.print("* ");
//     Serial.println(i.asString());
//   }

//   double myDouble = param.asDouble();
//   String myString = param.asString();
//   int myInt = param.asInt();

//   KXNSHOW(myDouble);
//   KXNSHOW(myString);
//   KXNSHOW(myInt);
//   if(myInt == 0){
//     Blynk.logEvent("baotrom", "Có trộm ở nhà");
//   }
// }