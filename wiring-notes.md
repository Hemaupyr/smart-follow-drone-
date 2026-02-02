# Wiring Notes – Smart Follow Drone 

## Power System
Battery: 11.1V 3S LiPo

Battery → XT60 → Power Distribution Board (PDB)

PDB → ESC Power Wires
- Red → VCC (+)
- Black → GND (-)

Each ESC gets direct power from PDB.

## Motors ↔ ESC
Each brushless motor connects to one ESC using 3 wires.
Wire order does not matter.
If motor spins wrong direction → swap any 2 wires.

Motor Layout:
M1 – Front Left
M2 – Front Right
M3 – Rear Right
M4 – Rear Left


## ESC Signal → CC3D Flight Controller

ESC Signal Wires → CC3D Output Pins:

ESC1 → Channel 1
ESC2 → Channel 2
ESC3 → Channel 3
ESC4 → Channel 4

ESC Ground → CC3D GND

## CC3D Power
Use ESC BEC output or 5V regulator.

5V → CC3D +5V
GND → CC3D GND

## Arduino Connections

Arduino → HC-05 Bluetooth:
- TX → RX (via divider)
- RX → TX
- 5V → VCC
- GND → GND

Arduino → HC-SR04 Ultrasonic:
- VCC → 5V
- GND → GND
- TRIG → D7
- ECHO → D6



## ESP32-CAM Power

ESP32-CAM requires stable 5V supply.

5V Regulator → 5V pin
GND → GND

Do NOT power from weak Arduino 5V pin.


## Safety Notes
- Remove propellers during testing
- Check polarity before connecting battery
- Verify no short circuit with multimeter
