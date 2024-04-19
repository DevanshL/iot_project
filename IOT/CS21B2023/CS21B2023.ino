#define BLYNK_TEMPLATE_ID "TMPL3_s_hPGqs"
#define BLYNK_TEMPLATE_NAME "parking"
#define BLYNK_AUTH_TOKEN "3rbEF6h3S5ByWSBk5q1p_JjeHmACnU7I"

#include <Servo.h>
#include <Wire.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// WiFi credentials
char ssid[] = "D";
char password[] = "dev@n$h777";
char auth[] = BLYNK_AUTH_TOKEN;

// Blynk virtual pin assignments
#define VIRTUAL_PIN_SLOT1 V10
#define VIRTUAL_PIN_SLOT2 V11

// Define GPIO pins for IR sensors and servo motor
const int irSensorPin1 = D3;   // IR sensor 1 connected to D3 (GPIO 0)
const int irSensorPin2 = D6;   // IR sensor 2 connected to D6 (GPIO 12)
const int irSensorPin3 = D4;   // IR sensor 3 connected to D4 (GPIO 2)
const int servoPin = D5;       // Servo motor connected to D5 (GPIO 14)

int freeslots = 2;  // Initial number of free parking slots
Servo myServo;



void setup() {
  Serial.begin(9600);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");

  // Initialize Blynk with WiFi and authentication token
  Blynk.begin(auth, WiFi.SSID().c_str(), WiFi.psk().c_str());

  // Attach servo to the GPIO pin
  myServo.attach(servoPin);

  // Initialize IR sensor pins
  pinMode(irSensorPin1, INPUT);
  pinMode(irSensorPin2, INPUT);
  pinMode(irSensorPin3, INPUT);

}

void loop() {
  Blynk.run();  // Continuously run Blynk to maintain connection

  // Read IR sensor states
  int sensorState1 = digitalRead(irSensorPin1);
  int sensorState2 = digitalRead(irSensorPin2);
  int sensorState3 = digitalRead(irSensorPin3);

  // Determine overall parking status based on sensor states
  if (sensorState1 == HIGH ) {
    // Vehicle detected in at least one parking slot, rotate servo to 180 degrees
    myServo.write(180);
  } else {
    // No vehicle detected in any parking slot, rotate servo to 0 degrees
    myServo.write(0);
  }

  // Update free slots based on sensor readings
  if (sensorState2 == HIGH ) {
    if (freeslots < 2) {
      freeslots++; // Increment freeSlots if a vehicle leaves a parking slot
    }
     Blynk.virtualWrite(VIRTUAL_PIN_SLOT1, 0); // Turn off virtual bulb for slot 1
  } else {
    if (freeslots > 0) {
      freeslots--; // Decrement freeSlots if a vehicle occupies a parking slot
    }
    Blynk.virtualWrite(VIRTUAL_PIN_SLOT1, 255); // Turn on virtual bulb for slot 1
  }

  if (sensorState3 == HIGH ) {
    if (freeslots < 2) {
      freeslots++; // Increment freeSlots if a vehicle leaves a parking slot
    }
    Blynk.virtualWrite(VIRTUAL_PIN_SLOT2, 0); // Turn off virtual bulb for slot 2
  } else {
    if (freeslots > 0) {
      freeslots--; // Decrement freeSlots if a vehicle occupies a parking slot // Turn on virtual bulb for slot 2
    }
    Blynk.virtualWrite(VIRTUAL_PIN_SLOT2, 255);
  }

  delay(1000); // Adjust delay for stability
}
