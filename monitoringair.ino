// Configuration - Update these values with your own
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6IkGNj8GB"
#define BLYNK_TEMPLATE_NAME "ultrasonik"
#define BLYNK_AUTH_TOKEN "9UGAhXp0An6mwuInp_qCt_MaCNAAqU_U"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "M15";
char pass[] = "12345678";

BlynkTimer timer;

#define echoPin 27
#define trigPin 26

long duration;
float distance;

float heightContainer = 12; // base distance to sensor (cm)
float widthContainer = 20; // cm
float lengthContainer = 30; // cm
float baseareaContainer = 50.26; // if the container is cylindrical Area of ​​the circle (π × r²) (cm2) if the container is square widthContainer * lengthContainer
float waterLevel;
float waterVolume;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello, ESP32!");
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.0343 / 2;

  waterLevel = heightContainer - distance;
  waterVolume = waterLevel * baseareaContainer;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  Serial.print("Water Level:");
  Serial.print(waterLevel);
  Serial.println(" cm");
  Serial.print("Water Volume:");
  Serial.print(waterVolume);
  Serial.println(" ml");

  Blynk.run();
  timer.run();
  Blynk.virtualWrite(V0, waterLevel);
  Blynk.virtualWrite(V1, waterVolume);
  delay(1000);
}