#include <Servo.h>

const int servo1 = 10;       // first servo
const int servo2 = 9;       // second servo

Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo

void setup() {

  // Servo  
  myservo1.attach(servo1);  // attaches the servo
  myservo2.attach(servo2);  // attaches the servo

  // Inizialize Serial
  Serial.begin(9600);
  Serial.println("Type a command and press Enter:");
}


void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); // read until newline
    input.trim(); // remove any trailing \r or whitespace

    if (input == "f") {
      myservo1.write(90);
      myservo2.write(-90);
      delay(1000);
    }
    else if (input == "b") {
      myservo1.write(-90);
      myservo2.write(90);
      delay(1000);
    }
    else {
      Serial.print("Unknown command: ");
      Serial.println(input);
    }
  }
}