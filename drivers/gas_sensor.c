#include <BlynkSimpleEsp32.h>
#define MQ2_PIN 34
#define MQ135_PIN 35

void sendGASValue()
{
    int MQ135_gasvalue = analogRead(MQ135_PIN);
    int MQ2_gasvalue = analogRead(MQ2_PIN);

    Serial.print("MQ135 Value: ");
    Serial.println(MQ135_gasvalue);

    Serial.print("MQ2 Value: ");
    Serial.println(MQ2_gasvalue);
  //*********************//MQ135//********************//
  
  if (MQ135_gasvalue > 800 ) {   // Threshold (adjust this)
    Blynk.virtualWrite( V2,"⚠ DANGER ");
    Serial.println("⚠ DANGER ");
    
  } else if(MQ135_gasvalue > 600 && MQ135_gasvalue < 800 ) {
    Serial.println(" ⚠ HIGH METHANE GAS DETECTED ");
    Blynk.virtualWrite(V2," ⚠ HIGH METHANE GAS DETECTED ");
    
  }else if(MQ135_gasvalue > 300 && MQ135_gasvalue < 600 ){
    Serial.println(" ⚠ MEDIUM METHANE GAS DETECTED  ");
    Blynk.virtualWrite(V2," ⚠ MEDIUM METHANE GAS DETECTED  ");
    
  }else if(MQ135_gasvalue > 100 && MQ135_gasvalue < 300){
    Serial.println(" ⚠ LOW METHANE GAS DETECTED ");
    Blynk.virtualWrite(V2," ⚠ LOW METHANE GAS DETECTED ");
    
  }else{
    Serial.println(" ✅ METHANE Gas Level Normal ");
    Blynk.virtualWrite(V2," ✅ METHANE Gas Level Normal ");
  }

  //*********************//MQ2//********************//
  
  if (MQ2_gasvalue > 400 ) {   // Threshold (adjust this)
    Serial.println("⚠ DANGER ");
    Blynk.virtualWrite(V3,"⚠ DANGER ");
   
  } else if(MQ2_gasvalue > 300 && MQ2_gasvalue < 400 ) {
    Serial.println(" ⚠ HIGH C02 GAS DETECTED ");
   Blynk.virtualWrite(V3," ⚠ HIGH C02 GAS DETECTED ");
    
  }else if(MQ2_gasvalue > 200 && MQ2_gasvalue < 300 ){
    Serial.println(" ⚠ MEDIUM CO2 GAS DETECTED  ");
    Blynk.virtualWrite(V3," ⚠ MEDIUM CO2 GAS DETECTED  ");
    
  }else if(MQ2_gasvalue > 100 && MQ2_gasvalue < 200){
    Serial.println(" ⚠ LOW CO2 GAS DETECTED ");
    Blynk.virtualWrite(V3," ⚠ LOW CO2 GAS DETECTED ");
    
  }else{
    Serial.println(" ✅ C02 Gas Level Normal ");
    Blynk.virtualWrite(V3," ✅ CO2 Gas Level Normal ");
  }

  delay(1000);
}

}
