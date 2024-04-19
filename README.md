# Smart Vehicle Parking System

The Smart Vehicle Parking System is an efficient and automated solution for managing parking spaces, minimizing congestion, and enhancing user convenience. This project utilizes the ESP8266 microcontroller, IR sensors, and a servo motor to monitor parking slot occupancy and control entry/exit barriers.

## Features

- Real-time monitoring of parking slot availability
- Automated entry/exit barrier control using a servo motor
- Web-based or mobile application interface for users to check parking availability
- Optimized parking space utilization and reduced traffic congestion
- Enhanced user experience with a convenient parking management system

## Components

- NodeMCU ESP8266 Microcontroller
- IR Sensors for entry/exit detection and parking slot monitoring
- Servo Motor for automated barrier control
- Blynk Cloud Platform for IoT integration
- Wi-Fi Connection
- Jumper Wires
- Breadboard

## Installation

1. Clone the repository or download the source code.
2. Install the required libraries and dependencies for the ESP8266 microcontroller and Blynk Cloud Platform.
3. Connect the ESP8266 microcontroller, IR sensors, and servo motor according to the circuit diagram provided.
4. Configure the Wi-Fi credentials and Blynk authentication token in the code.
5. Upload the code to the ESP8266 microcontroller using the Arduino IDE or a similar development environment.
6. Set up the Blynk Cloud Platform and connect it to the ESP8266 microcontroller.
7. Deploy the web-based or mobile application interface for users to access parking availability information.

## Usage

1. Upon entering the parking area, the IR sensor detects the vehicle and triggers the servo motor to open the barrier.
2. The system monitors the occupancy of parking slots using IR sensors and updates the availability information.
3. Users can access the web-based or mobile application interface to check the real-time availability of parking slots.
4. When a vacant slot is located, the user can navigate to the designated parking area.
5. Upon exiting the parking area, the IR sensor detects the vehicle and triggers the servo motor to open the barrier.

## Video Demonstration

A video demonstration of the Smart Vehicle Parking System is available at the following link:

https://drive.google.com/file/d/1wyxhktHjDnOYrI9LyPSkeXgj-fMPoCWN/view?usp=sharing

## Contributing

Contributions to the Smart Vehicle Parking System project are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.

## Acknowledgements

- [ESP8266 Documentation](https://github.com/esp8266/Arduino)
- [Blynk Cloud Platform](https://blynk.io/)
- [Arduino Community](https://www.arduino.cc/)
