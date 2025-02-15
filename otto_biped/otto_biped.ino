#include <SoftwareSerial.h>
#include <Otto.h>

Otto Otto;
SoftwareSerial BTserial(10, 11); // RX, TX pins for Bluetooth module

#define LeftLeg 2 
#define RightLeg 3
#define LeftFoot 4 
#define RightFoot 5 
#define Buzzer 13 

char serial_data = ' ';

void setup() {
    Otto.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true, Buzzer); // Set servo and buzzer pins
    Otto.home();  // Reset to starting position
    pinMode(Buzzer, OUTPUT);

    Serial.begin(9600);  // Monitor baud rate
    BTserial.begin(9600); // Bluetooth baud rate
}

void loop() {
    if (BTserial.available()) {
        serial_data = BTserial.read();
        Serial.print("BT Command Received: ");
        Serial.println(serial_data); // Display received data on Serial Monitor
        processCommand(serial_data);
    }
    
    if (Serial.available()) {
        char c = Serial.read();
        Serial.print("Serial Monitor Command Received: ");
        Serial.println(c); // Display received data on Serial Monitor
        processCommand(c);
    }
}

void processCommand(char command) {
    switch (command) {
        case 'F': Otto.walk(5, 1000, 1); break;   // Walk forward
        case 'B': Otto.walk(5, 1000, -1); break;  // Walk backward
        case 'L': Otto.turn(5, 1000, 1); break;   // Turn left
        case 'R': Otto.turn(5, 1000, -1); break;  // Turn right
        case 'J': Otto.jump(1, 1000); break;      // Jump
        case 'M': Otto.updown(3, 1000, 20); break; // Move up/down
        case 'S': Otto.swing(3, 1000, 20); break; // Swing
        default:
            Serial.println("Invalid Command!"); // Handle unknown commands
    }
}
