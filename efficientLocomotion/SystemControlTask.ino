void SystemControlTask(void *pvParameters) {
    controlMotors(currentState, pwm);
}

void controlMotors(int state, int pwm) {
    // Define motor states as a lookup table
    const int motorStates[11][4][2] = {
        //  {Motor1, Motor2, Motor3, Motor4}
        //  { {IN1, IN2}, {IN1, IN2}, {IN1, IN2}, {IN1, IN2} }
        {{0, 1}, {0, 1}, {0, 1}, {0, 1}}, // FORWARD
        {{1, 0}, {1, 0}, {1, 0}, {1, 0}}, // BACKWARD
        {{1, 0}, {0, 1}, {0, 1}, {1, 0}}, // RIGHT
        {{0, 1}, {1, 0}, {1, 0}, {0, 1}}, // LEFT
        {{1, 0}, {0, 1}, {0, 1}, {1, 0}}, // CW
        {{0, 1}, {1, 0}, {1, 0}, {0, 1}}, // CCW
        {{0, 0}, {0, 1}, {0, 1}, {0, 0}}, // RIGHTFORWARD
        {{1, 0}, {0, 0}, {0, 0}, {1, 0}}, // RIGHTBACKWARD
        {{0, 1}, {0, 0}, {0, 0}, {0, 1}}, // LEFTFORWARD
        {{0, 0}, {1, 0}, {1, 0}, {0, 0}}, // LEFTBACKWARD
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}}  // OFF
    };

    // Set motor directions
    digitalWrite(Motor1IN1, motorStates[state][0][0]);
    digitalWrite(Motor1IN2, motorStates[state][0][1]);
    digitalWrite(Motor2IN1, motorStates[state][1][0]);
    digitalWrite(Motor2IN2, motorStates[state][1][1]);
    digitalWrite(Motor3IN1, motorStates[state][2][0]);
    digitalWrite(Motor3IN2, motorStates[state][2][1]);
    digitalWrite(Motor4IN1, motorStates[state][3][0]);
    digitalWrite(Motor4IN2, motorStates[state][3][1]);

    // Set motor speed
    int speed = (state == OFF) ? 0 : pwm;
    ledcWrite(Motor1, speed);
    ledcWrite(Motor2, speed);
    ledcWrite(Motor3, speed);
    ledcWrite(Motor4, speed);
}

void loop(){
  //null
}
