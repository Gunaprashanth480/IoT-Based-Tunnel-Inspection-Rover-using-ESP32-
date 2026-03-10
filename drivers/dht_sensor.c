#include <BlynkSimpleEsp32.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void sendDHTData()
{
    float humidity = dht.readHumidity();
    float temp = dht.readTemperature();

    Serial.print("Temp: ");
    Serial.println(temp);
    Serial.println(" °C");

    Serial.print("Humidity: ");
    Serial.println(humidity);
    Serial.println(" %");

  Blynk.virtualWrite(V0, t);

  if (t>45) {
    Blynk.virtualWrite(V1,"⚠ DANGER ,VERY HOT");
  } else if(t > 25 && t < 35){
    Blynk.virtualWrite(V1,"⚠ MODERATE TEMPERATURE ");
  }else if(t >15 && t < 25){
    Blynk.virtualWrite(V1,"✅ NORMAL TEMPERATURE ");
  }else if(t <15){
    Blynk.virtualWrite(V1,"⚠ DANGER,VERY COOL ");
  }
}
