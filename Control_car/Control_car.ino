#include <string>

// #define STATE 13

struct Motor{
  int pin1;
  int pin2;
  int reg_speed_pin;
}

int speed = 75;
Motor front_left_motor;
Motor front_right_motor;

Motor back_left_motor;
Motor back_right_motor;

string state ="STOP";

void setMotorPins(Motor motor){
  pinMode(motor.pin1, OUTPUT);
  pinMode(motor.pin2, OUTPUT);
  pinMode(motor.reg_speed_pin, OUTPUT);
}

void setup() {

  Serial.begin(115200);
  front_left_motor.pin1 = ;
  front_left_motor.pin2 = ;
  front_left_motor.reg_speed_pin =  ;
  
  front_right_motor.pin1 =  ;
  front_right_motor.pin2 = ;
  front_right_motor.reg_speed_pin = ; 
 
  back_left_motor.pin1 =  ;
  back_left_motor.pin2 = ;
  back_left_motor.reg_speed_pin =  ;
  
  back_right_motor.pin1 =  ;
  back_right_motor.pin2 = ; 
  back_right_motor.reg_speed_pin =  ;

  Serial.println("Starting motor pins...");
  setMotorPins(front_left_motor);
  setMotorPins(front_right_motor);
  setMotorPins(back_left_motor);
  setMotorPins(back_right_motor);
  Serial.println("Microcontroller is ready and waiting for commands...");
}

void loop() {
  // Check if there is any data available to read from the serial port.
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    incomingMessage.trim();
    action(command);
  } else{
    action(state);
  } 
}