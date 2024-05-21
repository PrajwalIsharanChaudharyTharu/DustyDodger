# DustyDodger : Obstacle-Avoidance Vacuum Cleaner Car

Overview
Welcome to the Obstacle-Avoidance Vacuum Cleaner Car project! This project involves creating an autonomous vacuum cleaner that uses an ultrasonic sensor and servo motor to navigate around obstacles. The car is built with an Arduino Uno and an L293D motor shield, and it features four DC motor wheels and a rotating servo motor for the ultrasonic sensor.

Table of Contents
Introduction
Features
Hardware Requirements
Software Requirements
Installation
Hardware Setup
Software Setup
Usage
Future Updates
Contributing


Introduction
The Obstacle-Avoidance Vacuum Cleaner Car is an automated device designed to clean floors while avoiding obstacles. It uses an ultrasonic sensor mounted on a servo motor to detect and navigate around obstacles, ensuring efficient and uninterrupted cleaning.

Features
Autonomous Navigation: The car automatically navigates around obstacles using an ultrasonic sensor.
Efficient Cleaning: Designed to clean floors efficiently without getting stuck.
Expandable: Future updates will include a mobile app for manual control.
Hardware Requirements
Arduino Uno
L293D Motor Shield
Ultrasonic Sensor (HC-SR04)
Servo Motor
4 DC Motors with wheels
Power Supply (battery pack)
Jumper wires
USB cable
Software Requirements
Arduino IDE
Arduino libraries: AFMotor, Servo, NewPing
Installation
Hardware Setup
Note: Hardware setup is already completed.

Software Setup
Install Arduino IDE:

Download the Arduino IDE from the official Arduino website and install it.
Install Required Libraries:

Open the Arduino IDE.
Go to Sketch > Include Library > Manage Libraries.
Search for and install the following libraries:
Adafruit Motor Shield
NewPing
Download the Code:

Clone the repository or download the ZIP file from the GitHub Repository.
Extract the ZIP file to a convenient location on your computer.
Open the Code:

Open the Arduino IDE.
Connect the Arduino Uno to your computer using the USB cable.
Open the extracted folder and double-click on ObstacleAvoidanceVacuumCleaner.ino.
Select the Board and Port:

Go to Tools > Board and select Arduino Uno.
Go to Tools > Port and select the appropriate port for your Arduino.
Upload the Code:

Click on the Upload button (right arrow icon) to compile and upload the code to the Arduino.
Once you see Upload successful in the status bar, disconnect the USB cable.
Usage
Powering Up:

Turn on the power supply to the vacuum cleaner car.
Operation:

The car should begin moving automatically and start navigating around obstacles.
Place objects in front of the ultrasonic sensor to test obstacle detection and avoidance.
Future Control:

A mobile app will be developed soon to manually control the car and update the vacuum cleaner with new code.
Future Updates
Mobile App Development:
We are working on a mobile app that will allow you to control the vacuum cleaner car through your device.
Stay tuned for updates and additional features!
Contributing
Contributions are welcome! If you have any ideas, suggestions, or improvements, please feel free to open an issue or submit a pull request.
