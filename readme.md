# ESP32 Wi-Fi Scanner and Connector using BLE

## Description

This project uses an ESP32 to scan available Wi-Fi networks, send the results via Bluetooth Low Energy (BLE) to a client, receive the network SSID and password from the client, and then connect to the specified Wi-Fi network. This is done using PlatformIO for development and deployment.

## Requirements

- ESP32 development board
- PlatformIO IDE (e.g., with Visual Studio Code)
- Bluetooth Low Energy capable device to act as a client (e.g., smartphone or BLE-enabled computer)

## Getting Started

### Hardware Setup

1. Connect your ESP32 board to your computer via USB.

### Software Setup

1. **Install PlatformIO**:
   - Install PlatformIO as an extension in Visual Studio Code.

2. **Clone the Repository**:
   - Clone this repository to your local machine or download and extract it.

3. **Open the Project**:
   - Open the project folder in Visual Studio Code.

4. **Configure PlatformIO**:
   - Ensure your `platformio.ini` file is configured as follows:
     ```ini
     [env:esp32dev]
     platform = espressif32
     board = esp32dev
     framework = arduino
     monitor_speed = 115200
     ```

5. **Build and Upload the Firmware**:
   - Click the check mark icon to compile the code.
   - Click the right arrow icon to upload the firmware to the ESP32.

### Code Overview

The main code is located in `src/main.cpp` and performs the following functions:

1. **BLE Initialization**:
   - Initializes the BLE service and characteristics for SSID, password, and connection result.

2. **Wi-Fi Scanning**:
   - Scans for available Wi-Fi networks and prints the results to the serial monitor.

3. **BLE Communication**:
   - Sends the scanned SSID list to a BLE client.
   - Receives SSID and password from the BLE client.

4. **Wi-Fi Connection**:
   - Attempts to connect to the Wi-Fi network using the received SSID and password.
   - Sends the connection result back to the BLE client.

### Usage

1. **BLE Client Setup**:
   - Use a BLE-capable device (e.g., a smartphone) and an appropriate BLE application to connect to the ESP32 BLE server named "ESP32_BLE_ski_sync".

2. **Scanning Wi-Fi Networks**:
   - Once connected via BLE, the ESP32 will scan for available Wi-Fi networks and send the list of SSIDs to the client.

3. **Connecting to Wi-Fi**:
   - Send the desired SSID and password to the ESP32 via BLE. The ESP32 will attempt to connect to the Wi-Fi network and turn of the light if it's ok.
