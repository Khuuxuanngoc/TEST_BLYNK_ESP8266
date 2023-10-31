#include "BlynkI2CVar.h"

char blynkTemplateName[40];
char blynkTemplateId[40];
char blynkToken[40];

char blynkWifiId[40];
char blynkWifiPs[40];

void BlynkGetBuffer(char item_temp){
    ;
}

void KxnRestartMCU() {
  ESP.restart();
  ESP.reset();
  while(1) {};
}

void CheckCmdString(String command_temp, String tempStrCmd, char * outArrayChar){
    if(command_temp.indexOf(tempStrCmd) == 0){
        int tempLenContent = command_temp.length() - tempStrCmd.length() + 1;

        String cutTempString = command_temp.substring(tempStrCmd.length());
        cutTempString.toCharArray(outArrayChar, tempLenContent);

        KXN_DEBUG_UART_CMD_LN(F("Detect command:"));
        KXN_DEBUG_UART_CMD_T(tempStrCmd);
        KXN_DEBUG_UART_CMD_LN(tempLenContent);
        KXN_DEBUG_UART_CMD_LN(cutTempString);
    };
}

void testGetStringFromUart(String command_temp){
    CheckCmdString(command_temp, BLYNK_CMD_UART_SET_NAME, blynkTemplateName);
    CheckCmdString(command_temp, BLYNK_CMD_UART_SET_ID, blynkTemplateId);
    CheckCmdString(command_temp, BLYNK_CMD_UART_SET_TOKEN, blynkToken);
    CheckCmdString(command_temp, BLYNK_CMD_UART_SET_WF_ID, blynkWifiId);
    CheckCmdString(command_temp, BLYNK_CMD_UART_SET_WF_PS, blynkWifiPs);
    if(command_temp.indexOf("SHOW") > -1){
        ShowKxnAllBuffer();
    }else if(command_temp.indexOf(BLYNK_CMD_UART_RESTART) > -1){
        KxnRestartMCU();
    }
}

void GetDataFromSerial(Stream * pTempSerial){
    if(pTempSerial->available()){
        String tempMyString = pTempSerial->readStringUntil('\n');
        testGetStringFromUart(tempMyString);
    }
}

void ShowKxnAllBuffer(){
    KXN_DEBUG_UART_CMD_LN(F("---------------------"));
    KXN_DEBUG_UART_CMD_LN(blynkTemplateName);
    KXN_DEBUG_UART_CMD_LN(blynkTemplateId);
    KXN_DEBUG_UART_CMD_LN(blynkToken);
    KXN_DEBUG_UART_CMD_LN(blynkWifiId);
    KXN_DEBUG_UART_CMD_LN(blynkWifiPs);
}
