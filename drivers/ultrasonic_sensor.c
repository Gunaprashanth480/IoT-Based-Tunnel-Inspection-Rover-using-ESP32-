#include <BlynkSimpleEsp32.h>
#define TRIG_PIN 17
#define ECHO_PIN 18

long getDistance()
{
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);

    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH);

    long distance = duration * 0.034 / 2;

    Serial.print("Distance: ");
    Serial.println(distance);
    
    Blynk.virtualWrite(V11,distance);

    // -------- Collision Detection --------
  if (distance > 0 && distance < COLLISION_DISTANCE) {
    stopMotors();
    Serial.println("Obstacle detected! Stopping...");
  }
}

