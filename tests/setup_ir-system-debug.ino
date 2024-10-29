#include <IRremote.h>

const int irPin = 7;  // Define the pin connected to the IR receiver

void setup() {
    Serial.begin(9600);                      // Start serial communication
    IrReceiver.begin(irPin, ENABLE_LED_FEEDBACK);  // Initialize the IR receiver
    Serial.println("IR Receiver Test Initialized. Press buttons on the remote.");
}

void loop() {
    if (IrReceiver.decode()) {
        // Check for command value, address, or data, depending on which is populated
        Serial.print("Received Signal: ");

        if (IrReceiver.decodedIRData.command != 0) {
            Serial.print("Command Value: 0x");
            Serial.println(IrReceiver.decodedIRData.command, HEX);
        } 
        else if (IrReceiver.decodedIRData.address != 0) {
            Serial.print("Address Value: 0x");
            Serial.println(IrReceiver.decodedIRData.address, HEX);
        } 
        else {
            Serial.print("Data Value: 0x");
            Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
        }

        IrReceiver.resume(); // Prepare to receive the next value
    }
    delay(100); // Small delay to avoid excessive serial output
}
