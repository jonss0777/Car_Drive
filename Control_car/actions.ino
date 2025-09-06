void apply_speed(int speed){
  if (0 <= speed && speed < 245){
    analogWrite(front_left_motor.reg_speed_pin, speed);
    analogWrite(front_right_motor.reg_speed_pin, speed);
    analogWrite(back_left_motor.reg_speed_pin, speed);
    analogWrite(back_right_motor.reg_speed_pin, speed);
  }
}

void apply_action( bool v1a, bool v1b, bool v2a, bool v2b , bool v3a, bool v3b, bool v4a, bool v4b){
  digitalWrite(front_left_motor.pin1, v1a);
  digitalWrite(front_left_motor.pin2, v1b);
  digitalWrite(front_right_motor.pin1, v2a);
  digitalWrite(front_right_motor.pin2, v2)b;
  digitalWrite(back_left_motor.pin1, v3a);
  digitalWrite(back_left_motor.pin2, v3b);
  digitalWrite(back_right_motor.pin1, v4a);
  digitalWrite(back_right_motor.pin2, v4b);
}

void action() {
  switch (command) {
    case "START":
      
      break;

    case "MOVE FORWARD":
      Serial.println("Received command. 'MOVE FOWARD'");
      apply_speed(75);
      apply_action(1, 0, 1, 0, 1, 0, 1, 0);
      state = command;
      break;

    case "MOVE BACKWARD":
      Serial.println("Received command. 'MOVE BACKWARD'");
      apply_speed(75);
      apply_action(0, 1, 0, 1, 0, 1, 0, 1);
      state = command;
      break;

    case "MOVE LEFT FOWARD":
      Serial.println("Received command. 'MOVE LEFT FOWARD'");
      apply_speed(75);
      // How much?
      apply_action(0, 1, 0, 1, 1, 0, 1, 0);
      delay(1000);
      // Return back to foward
      apply_action(1, 0, 1, 0, 1, 0, 1, 0);
      state = command;
      break;

    case "MOVE RIGHT FOWARD":
      Serial.println("Received command. 'MOVE RIGHT FOWARD'");
      apply_speed(75);

      apply_action(1, 0, 1, 0, 0, 1, 0, 1);
      delay(1000);

      apply_action(1, 0, 1, 0, 1, 0, 1, 0);
      state = command;
      break;

    case "MOVE LEFT BACKWARD";
      Serial.println("Received command. 'MOVE LEFT BACKWARD'");
      apply_speed(75);
      apply_action(1, 1, 1, 1, 1, 1, 1, 1);
      delay(1000);

      apply_action(0, 1, 0, 1, 0, 1, 0, 1);
      state = command;
      break;

    case "MOVE RIGHT BACKWARD";
      Serial.println("Received command. 'MOVE RIGHT BACKWARD'");
      apply_speed(75);
      apply_action(1, 1, 1, 1, 1, 1, 1, 1);
      delay(1000);
      apply_action(0, 1, 0, 1, 0, 1, 0, 1);
      state = command;
      break;

    case "STOP":
      Serial.println("Received command. 'STOP'");
      apply_speed(0);
      apply_action(0, 0, 0, 0, 0, 0, 0, 0);
      state = command;
      break;

    default:
      Serial.println("Current state...");
      apply_speed(0);
      apply_action(0, 0, 0, 0, 0, 0, 0, 0);
      state = "STOP";
      break;
  }
