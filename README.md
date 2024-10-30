# arduino-int-for-cobot

This project configures an Arduino as an interactive control device within a multi-input system for a collaborative robotic arm (cobot) demonstration. The Arduino responds to audience engagement and user inputs, communicating with the cobot to trigger automated branching programs. Real-time status is displayed via LEDs based on cobot feedback, enhancing the audience’s experience and the demonstration’s interactivity.

---

## Table of Contents
- [Project Description](#project-description)
- [Getting Started](#getting-started)
- [Components](#components)
- [Installation](#installation)
- [Usage](#usage)
- [Component Tests](#component-tests)
- [Project Structure](#project-structure)

---

## project-description

At a high level, the Arduino functions as follows:
1. **Idle Mode ~with LED Display~**: The Arduino initially runs in an idle mode, ~displaying status via LEDs~ until it receives a stimulus signal from the cobot. This signal indicates that the cobot’s program has reached the audio sensor phase, at which point the Arduino activates the audio sensor to monitor audience engagement.

2. **Audience Participation Detection**: Once activated by the cobot, the audio sensor monitors sound levels (e.g., clapping or cheering). If the sound threshold is met or exceeded, the Arduino sends a signal to the cobot to initiate the next phase of its automated program.

3. **Threshold Adjustment with Remote Control**: The IR remote allows live adjustments to the sound threshold. The **Vol+/Vol- buttons** incrementally adjust the threshold level to accommodate varying audience engagement. The **Next button** manually triggers the threshold output signal, bypassing the audio sensor if necessary, for cases of sensor malfunction or inactive audience response.

4. **Final Program Branch Selection**: Near the demonstration’s end, the cobot prompts the Arduino to re-evaluate sound levels. Based on the final threshold check, the Arduino sends a high or low signal to instruct the cobot on its terminal program branch choice.

5. **Standby Mode**: After the final signal is sent, the Arduino deactivates the audio sensor and re-enters idle mode, conserving power until the next activation cycle.

This setup provides responsive, audience-driven control and seamless integration within the cobot’s automated program, using a mix of sensor feedback and manual adjustments to maintain flow and adaptability during the demonstration.

---

## getting-started
These instructions will help you set up the project on your Arduino Uno R3 and test individual components before integrating them.

### Prerequisites
- **Arduino IDE**: Download and install from [Arduino's official site](https://www.arduino.cc/en/software).
- **IRremote Library**: Required for IR sensor control. Download it from the [IRremote GitHub repository](https://github.com/Arduino-IRremote/Arduino-IRremote) if it’s not available in the Library Manager.

---

## components
- **Arduino Uno R3**
- **IR Sensor**
- **Microphone Sensor**
- **LEDs (for status display)**
- **Jumper Wires and Resistors**
- **Dual 5x17 Slot Expansion Board**

---

## Installation

### Step 1: Clone the Repository
Clone the repository to your local machine by running the following commands:

```bash
git clone https://github.com/kalixra/arduino-int-for-cobot.git
cd arduino-int-for-cobot
```

### Step 2: Install Necessary Libraries

  Open the Arduino IDE.
  Go to Sketch > Include Library > Manage Libraries….
  In the Library Manager, search for IRremote and click Install. If not available, download it directly from the IRremote GitHub repository and add it as a .ZIP library.
  To add manually downloaded libraries, go to Sketch > Include Library > Add .ZIP Library… and select the downloaded .zip file.
	
## Usage

### Upload the Main Project Sketch

1. Connect your Arduino Uno R3 to your computer.
2. Open main_project/main_project.ino in the Arduino IDE.
3. Select the correct Board and Port in Tools.
4. Click Upload to load the code onto the Arduino.

### Operating the Project

   - IR Remote: Control various functions by pressing the IR remote buttons. See the code comments for button functions.
   - Microphone: Sound level is read by the microphone sensor, and the system responds based on sound threshold settings.
	
## component-tests

This project includes test sketches for each component in the tests folder. These can be used to verify component functionality before full integration.

### IR Sensor Test:
1. Open tests/test_IRsensor.ino in the Arduino IDE.
2. Upload it to your Arduino and open the Serial Monitor.
3. Point your IR remote at the sensor and press buttons. The Serial Monitor should display corresponding codes.

### Microphone Sensor Test:
1. Open tests/test_audio_sensor.ino.
2. Upload it to your Arduino and open the Serial Monitor.
3. Observe the audio levels printed to confirm the microphone’s readings.

## project-structure
```
arduino-int-for-cobot/
│
├── main_project/
│   ├── main_project.ino            # Main integrated sketch
│   ├── README.md                   # Documentation for the main project
│
├── tests/                          # Folder for test sketches
│   ├── setup_irsensor_debug.ino    # Test sketch for IR sensor
│   ├── setup_mic-debug.ino 	    # Test sketch for audio sensor
│
└── docs/                           # Documentation and resources
    ├── schematic.png               # Circuit diagram
    ├── notes.md                    # Notes on component testing
```
