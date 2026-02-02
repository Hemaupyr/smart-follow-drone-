#include <SoftwareSerial.h>

SoftwareSerial bt(10, 11); // RX, TX

int throttle = 0;
int yaw = 0;
int pitch = 0;
int roll = 0;

void setup() {
  Serial.begin(9600);
  bt.begin(9600);
}

void loop() {
  if (bt.available()) {
    String cmd = bt.readStringUntil('\n');
    parseCommand(cmd);
  }

  // Send control values to flight controller (PPM/PWM logic placeholder)
  Serial.print("T:");
  Serial.print(throttle);
  Serial.print(" Y:");
  Serial.print(yaw);
  Serial.print(" P:");
  Serial.print(pitch);
  Serial.print(" R:");
  Serial.println(roll);
}

void parseCommand(String c) {
  if (c.startsWith("T")) throttle = c.substring(1).toInt();
  if (c.startsWith("Y")) yaw = c.substring(1).toInt();
  if (c.startsWith("P")) pitch = c.substring(1).toInt();
  if (c.startsWith("R")) roll = c.substring(1).toInt();
}
