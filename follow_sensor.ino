#define TRIG 7
#define ECHO 6

long duration;
int distance;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  // Follow logic
  if (distance > 50 && distance < 150) {
    Serial.println("Move Forward");
  } else if (distance <= 50) {
    Serial.println("Stop / Move Back");
  }

  delay(200);
}
