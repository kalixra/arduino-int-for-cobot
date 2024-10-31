// include the library code:
#include <LiquidCrystal.h>

// Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7) RS=12, E=11, D4=5, D5=4, D6=3, D7=2
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
    Serial.begin(9600);       // Start serial communication for debugging
    Serial.println("Starting LCD setup...");

    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    Serial.println("LCD initialized with 16 columns and 2 rows.");

    // Clears the LCD screen
    lcd.clear();
    Serial.println("LCD screen cleared.");
}

void loop() {
    Serial.println("Starting loop...");

    // Print a message to the LCD
    lcd.print(" Goodbye world!");
    Serial.println("Printed 'Goodbye world!' to the first line of the LCD.");

    // set the cursor to column 0, line 1
    lcd.setCursor(0, 1);
    Serial.println("Cursor set to the beginning of the second line.");

    // Print a message to the LCD
    lcd.print(" LCD Work Damnit");
    Serial.println("Printed 'LCD Work Damnit' to the second line of the LCD.");

    delay(2000);  // Wait 2 seconds before the next loop for easier tracking
}
