/*
* Demo program for controling red, green, and blue LED.
*/

#include <SoftwareSerial.h>
#include <ArduinoBlue.h>

#define RED_PIN 13
#define GREEN_PIN 12
#define BLUE_PIN 4

// The bluetooth tx and rx pins must be supported by software serial.
// Visit https://www.arduino.cc/en/Reference/SoftwareSerial for unsupported pins.
// Bluetooth TX -> Arduino D8
// Bluetooth RX -> Arduino D7
#define BLUETOOTH_TX_PIN 8
#define BLUETOOTH_RX_PIN 7

SoftwareSerial bluetooth(BLUETOOTH_TX_PIN, BLUETOOTH_RX_PIN);
ArduinoBlue phone(bluetooth); // pass reference of bluetooth object to ArduinoCommander.

int button;
bool redOn;
bool greenOn;
bool blueOn;

void setup() {
  // Start serial monitor at 9600 bps.
    Serial.begin(9600);

  // Start bluetooth serial at 9600 bps.
  bluetooth.begin(9600);

  // delay just in case bluetooth module needs time to "get ready".
  delay(100);

  // Declare LED pins as output pins
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  
  Serial.println("setup complete");
}

void loop() {
  button = phone.getButton();

  if (button == 0) {
    if (redOn) {
      digitalWrite(RED_PIN, LOW);
      redOn = false;
    }
    else {
      digitalWrite(RED_PIN, HIGH);
      redOn = true;
    }
  }
  else if (button == 1) {
    if (greenOn) {
      digitalWrite(GREEN_PIN, LOW);
      greenOn = false;
    }
    else {
      digitalWrite(GREEN_PIN, HIGH);
      greenOn = true;
    }
  }
  else if (button == 2) {
    if (blueOn) {
      digitalWrite(BLUE_PIN, LOW);
      blueOn = false;
    }
    else {
      digitalWrite(BLUE_PIN, HIGH);
      blueOn = true;
    }
  }
}
