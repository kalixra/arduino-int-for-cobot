// Global variables for pin declarations
const int micPin = A0; // Microphone connected to analog pin A0
const int outputPin = 7; // Output pin / LED trigger
const int threshold = 66; // Mic threshold value (adjust as needed)

void setup() {
    pinMode(outputPin, OUTPUT);   
    Serial.begin(9600);   
}

void loop() {
    int audioLevel = analogRead(micPin);   
    Serial.print("Audio Level: ");
    Serial.println(audioLevel); 

    if (audioLevel > threshold) {
        digitalWrite(outputPin, HIGH); // Turn on the LED if threshold is exceeded / Send
        Serial.println("Conditions Satisfied");
    } else {
        digitalWrite(outputPin, LOW); // Turn off the LED if below threshold / No Send
        Serial.println("Not Satisfied");
    }

    delay(100); // Delay to avoid flooding serial monitor
}
