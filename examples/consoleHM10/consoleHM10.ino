
#include <SoftwareSerial.h>

const int BLUETOOTH_TX = 7;
const int BLUETOOTH_RX = 4;

const int READ_TIME = 500;

SoftwareSerial bt(BLUETOOTH_TX, BLUETOOTH_RX);

void setup() {
	bt.begin(9600);
	Serial.begin(115200);
	Serial.println("Setup Complete");
}

void loop() {
	// while incoming signal is available.
	if (bt.available()) {
		unsigned long readStart = millis();
		while (bt.available() || millis() - readStart < READ_TIME) {
			if (bt.available()) {
				Serial.print((char)bt.read());
			}
		}
		Serial.println();
	}

	while (Serial.available()) {
		String input = Serial.readStringUntil('\r');
		String output = "";
		for (int i = 0; i < input.length(); i++) {
			char c = input.charAt(i);
			if (c != 10 && c != 13) { // Don't send line end characters to HM 10 
				output += c;
			}
		}
		Serial.print("Entered: "); Serial.println(output);
		bt.print(output);
	}
}