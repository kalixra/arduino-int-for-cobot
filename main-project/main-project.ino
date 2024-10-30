#include <IRremote.h>

// Pin Declarations
const int micPin = A0;       // Microphone sensor connected to analog pin A0
const int outputPin = 7;     // Output pin to send signal to cobot
const int inputPin = 2;      // Input pin for cobot release signal
const int irPin = 11;        // IR receiver connected to digital pin 11

// Threshold and IR Codes - Change each value to match the command values from your ir-system test
int threshold = 25;          // Initial audio threshold
const unsigned long V_PLUS_CODE = 0xFF18E7;   // Vol+ button
const unsigned long V_MINUS_CODE = 0xFF4AB5;  // Vol- button
const unsigned long NEXT_CODE = 0xFF5AA5;       // Next button

// Initialize IR receiver
IRrecv irrecv(irPin);
decode_results results;

void setup() {
    pinMode(outputPin, OUTPUT);
    pinMode(inputPin, INPUT);
    Serial.begin(9600);

    // Start IR receiver
    irrecv.enableIRIn();
    Serial.println("System Initialized. Monitoring audio levels and IR commands.");
}

void loop() {
    // Continuously monitor IR remote and handle any commands received
    if (irrecv.decode(&results)) {
        handleRemoteCommand(results.value);  // Process the IR command
        irrecv.resume(); // Resume listening for the next IR code
    }

    // Continuously read audio level from microphone
    int audioLevel = analogRead(micPin);
    Serial.print("Audio Level: ");
    Serial.println(audioLevel);

    // If audio level exceeds the threshold and inputPin is HIGH, send signal to cobot
    if (audioLevel > threshold && digitalRead(inputPin) == HIGH) {
        sendCobotSignal();
    }

    delay(100); // Small delay to avoid excessive serial output
}

/*
 * handleRemoteCommand
 * Adjusts threshold or sends cobot signal based on the received IR command
 */
void handleRemoteCommand(unsigned long command) {
    if (command == V_PLUS_CODE) {         // Increase threshold
        threshold += 3;
        Serial.print("Threshold increased to: ");
        Serial.println(threshold);
    } else if (command == V_MINUS_CODE) { // Decrease threshold
        threshold -= 3;
        Serial.print("Threshold decreased to: ");
        Serial.println(threshold);
    } else if (command == NEXT_CODE && digitalRead(inputPin) == HIGH) { // Manual trigger for cobot signal if allowed
        Serial.println("Manual override: Sending signal to cobot.");
        sendCobotSignal();
    }
}

/*
 * sendCobotSignal
 * Sends a single output signal to the cobot
 */
void sendCobotSignal() {
    digitalWrite(outputPin, HIGH);    // Set output HIGH to trigger cobot
    delay(500);                       // Hold the signal for 500 ms
    digitalWrite(outputPin, LOW);     // Reset output
    Serial.println("Cobot signal sent.");
}
