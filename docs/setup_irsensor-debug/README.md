# IR Receiver Test for Arduino

This sketch will test an IR receiver connected to an Arduino on pin 7, capturing IR remote button presses and displaying the command values in the Serial Monitor. You can use these values later in the main-project code.

## Requirements
- Arduino with IR receiver connected to **pin 7**
- IRremote library (version 4.x) installed. Install via Arduino Library Manager or from [IRremote GitHub](https://github.com/Arduino-IRremote/Arduino-IRremote).

## Code Overview
- The program initializes the IR receiver and listens for button presses.
- When a button is pressed, the command value, address, or raw data is printed in hexadecimal format to the Serial Monitor.

## Usage
1. Connect the IR receiver to pin 7 of the Arduino.
2. Open the Serial Monitor at **9600 baud**.
3. Press buttons on the remote, and observe the command values displayed.

## Troubleshooting
If no values appear:
- Ensure the Serial Monitor baud rate is set to **9600**.
- Verify that the latest IRremote library (4.x) is installed.
- Confirm wiring and consider using a different pin if issues persist.

