//BAUD RATE 
#define BAUDRATE 115200

//PIN LOCOMOTION DECLARATION
#define Motor1ENA 32
#define Motor1IN1 33
#define Motor1IN2 25
#define Motor2ENA 26 
#define Motor2IN1 27
#define Motor2IN2 14
#define Motor3ENA 5
#define Motor3IN1 18
#define Motor3IN2 19
#define Motor4ENA 13
#define Motor4IN1 12
#define Motor4IN2 4

//LEDCWRITE CHANNEL 
const int Motor1 = 1; 
const int Motor2 = 2;
const int Motor3 = 3; 
const int Motor4 = 4; 

//for ledcWrite program
const int PWM_FREQ = 500;     // Recall that Arduino Uno is ~490 Hz. Official ESP32 example uses 5,000Hz
const int PWM_RESOLUTION = 8; // We'll use same resolution as Uno (8 bits, 0-255) but ESP32 can go up to 16 bits 


//pwm 
float pwm = 100; 

//DECLARE FUNCTION 
void forward(int pwm);
void backward(int pwm);
void right(int pwm);
void left(int pwm);
void clockwise(int pwm);
void counterClockwise(int pwm);
void rightForward(int pwm);
void leftForward(int pwm);
void rightBackward(int pwm);
void leftBackward(int pwm);

//ENUM FOR STATE
enum state{
  FORWARD, BACKWARD, RIGHT, LEFT, CW, CCW, RIGHTFORWARD, RIGHTBACKWARD, LEFTFORWARD, LEFTBACKWARD, OFF
};

state currentState;

void setup() {
  // put your setup code here, to run once:
  //BAUD RATE
  Serial.begin(BAUDRATE);

  // PIN MODE
    pinMode(Motor1ENA, OUTPUT);
    pinMode(Motor1IN1, OUTPUT);
    pinMode(Motor1IN2, OUTPUT);
    pinMode(Motor2ENA, OUTPUT);
    pinMode(Motor2IN1, OUTPUT);
    pinMode(Motor2IN2, OUTPUT);
    pinMode(Motor3ENA, OUTPUT);
    pinMode(Motor3IN1, OUTPUT);
    pinMode(Motor3IN2, OUTPUT);
    pinMode(Motor4ENA, OUTPUT);
    pinMode(Motor4IN1, OUTPUT);
    pinMode(Motor4IN2, OUTPUT);


  //LEDCWRITE CONFIGURATION
  // configure LED PWM functionalitites
  ledcSetup(1, PWM_FREQ, PWM_RESOLUTION);
  ledcSetup(2, PWM_FREQ, PWM_RESOLUTION);
  ledcSetup(3, PWM_FREQ, PWM_RESOLUTION);
  ledcSetup(4, PWM_FREQ, PWM_RESOLUTION);
  
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(Motor1ENA, Motor1);
  ledcAttachPin(Motor2ENA, Motor2);
  ledcAttachPin(Motor3ENA, Motor3);
  ledcAttachPin(Motor4ENA, Motor4);
}

void loop() {
    if (Serial.available()) {
    String command = Serial.readStringUntil('\n'); // Read input until newline
    command.trim(); // Remove extra spaces or newlines

    // Convert the string to a state
    if (command == "FORWARD") currentState = FORWARD;
    else if (command == "BACKWARD") currentState = BACKWARD;
    else if (command == "RIGHT") currentState = RIGHT;
    else if (command == "LEFT") currentState = LEFT;
    else if (command == "CW") currentState = CW;
    else if (command == "CCW") currentState = CCW;
    else if (command == "RIGHTFORWARD") currentState = RIGHTFORWARD;
    else if (command == "RIGHTBACKWARD") currentState = RIGHTBACKWARD;
    else if (command == "LEFTFORWARD") currentState = LEFTFORWARD;
    else if (command == "LEFTBACKWARD") currentState = LEFTBACKWARD;
    else if (command == "OFF") currentState = OFF;

    Serial.print("Current State: ");
    Serial.println(command);
  }

  // Execute movement based on the current state
  if (currentState == FORWARD) forward(pwm);
  else if (currentState == BACKWARD) backward(pwm);
  else if (currentState == RIGHT) right(pwm);
  else if (currentState == LEFT) left(pwm);
  else if (currentState == CW) clockwise(pwm);
  else if (currentState == CCW) counterClockwise(pwm);
  else if (currentState == RIGHTFORWARD) rightForward(pwm);
  else if (currentState == RIGHTBACKWARD) rightBackward(pwm);
  else if (currentState == LEFTFORWARD) leftForward(pwm);
  else if (currentState == LEFTBACKWARD) leftBackward(pwm);
  else if (currentState == OFF) off(pwm);

}

 void forward(int pwm){
      //MOTOR 1 
    digitalWrite(Motor1IN1, LOW); //IF HIGH CCW (-)
    digitalWrite(Motor1IN2, HIGH);  //IF HIGH CW (+)
    ledcWrite(Motor1, pwm);
  
    //MOTOR 2 
    digitalWrite(Motor2IN1, LOW); //IF HIGH CCW (-)
    digitalWrite(Motor2IN2, HIGH); //IF HIGH CW (+)
    ledcWrite(Motor2, pwm);
  
    // //MOTOR 3
    digitalWrite(Motor3IN1, LOW); //IF HIGH CCW (-) 
    digitalWrite(Motor3IN2, HIGH); //IF HIGH CW (+)
    ledcWrite(Motor3, pwm);
  
    // //MOTOR 4
    digitalWrite(Motor4IN1, LOW); //IF HIGH CCW (-)
    digitalWrite(Motor4IN2, HIGH); //IF HIGH (+)
    ledcWrite(Motor4, pwm);
  }
  
  void backward(int pwm){
      //MOTOR 1 
    digitalWrite(Motor1IN1, HIGH); //IF HIGH CCW (-)
    digitalWrite(Motor1IN2, LOW);  //IF HIGH CW (+)
    ledcWrite(Motor1, pwm);
  
    //MOTOR 2 
    digitalWrite(Motor2IN1, HIGH); //IF HIGH CCW (-)
    digitalWrite(Motor2IN2, LOW); //IF HIGH CW (+)
    ledcWrite(Motor2, pwm);
  
    // //MOTOR 3
    digitalWrite(Motor3IN1, HIGH); //IF HIGH CCW (-) 
    digitalWrite(Motor3IN2, LOW); //IF HIGH CW (+)
    ledcWrite(Motor3, pwm);
  
    // //MOTOR 4
    digitalWrite(Motor4IN1, HIGH); //IF HIGH CCW (-)
    digitalWrite(Motor4IN2, LOW); //IF HIGH (+)
    ledcWrite(Motor4, pwm);
  }
  
  void left(int pwm){
      //MOTOR 1 
    digitalWrite(Motor1IN1, LOW); //IF HIGH CCW (-)
    digitalWrite(Motor1IN2, HIGH);  //IF HIGH CW (+)
    ledcWrite(Motor1, pwm);
  
    //MOTOR 2 
    digitalWrite(Motor2IN1, HIGH); //IF HIGH CCW (-)
    digitalWrite(Motor2IN2, LOW); //IF HIGH CW (+)
    ledcWrite(Motor2, pwm);
  
    // //MOTOR 3
    digitalWrite(Motor3IN1, HIGH); //IF HIGH CCW (-) 
    digitalWrite(Motor3IN2, LOW); //IF HIGH CW (+)
    ledcWrite(Motor3, pwm);
  
    // //MOTOR 4
    digitalWrite(Motor4IN1, LOW); //IF HIGH CCW (-)
    digitalWrite(Motor4IN2, HIGH); //IF HIGH (+)
    ledcWrite(Motor4, pwm);
  }
  
  void right(int pwm){
      //MOTOR 1 
    digitalWrite(Motor1IN1, HIGH); //IF HIGH CCW (-)
    digitalWrite(Motor1IN2, LOW);  //IF HIGH CW (+)
    ledcWrite(Motor1, pwm);
  
    //MOTOR 2 
    digitalWrite(Motor2IN1, LOW); //IF HIGH CCW (-)
    digitalWrite(Motor2IN2, HIGH); //IF HIGH CW (+)
    ledcWrite(Motor2, pwm);
  
    // //MOTOR 3
    digitalWrite(Motor3IN1, LOW); //IF HIGH CCW (-) 
    digitalWrite(Motor3IN2, HIGH); //IF HIGH CW (+)
    ledcWrite(Motor3, pwm);
  
    // //MOTOR 4
    digitalWrite(Motor4IN1, HIGH); //IF HIGH CCW (-)
    digitalWrite(Motor4IN2, LOW); //IF HIGH (+)
    ledcWrite(Motor4, pwm);
  
  }
  
  void clockwise(int pwm){
      //MOTOR 1 
    digitalWrite(Motor1IN1, HIGH); //IF HIGH CCW (-)
    digitalWrite(Motor1IN2, LOW);  //IF HIGH CW (+)
    ledcWrite(Motor1, pwm);
  
    //MOTOR 2 
    digitalWrite(Motor2IN1, LOW); //IF HIGH CCW (-)
    digitalWrite(Motor2IN2, HIGH); //IF HIGH CW (+)
    ledcWrite(Motor2, pwm);
  
    // //MOTOR 3
    digitalWrite(Motor3IN1, LOW); //IF HIGH CCW (-) 
    digitalWrite(Motor3IN2, HIGH); //IF HIGH CW (+)
    ledcWrite(Motor3, pwm);
  
    // //MOTOR 4
    digitalWrite(Motor4IN1, HIGH); //IF HIGH CCW (-)
    digitalWrite(Motor4IN2, LOW); //IF HIGH (+)
    ledcWrite(Motor4, pwm);
  
  }
  
  void counterClockwise(int pwm){
      //MOTOR 1 
    digitalWrite(Motor1IN1, LOW); //IF HIGH CCW (-)
    digitalWrite(Motor1IN2, HIGH);  //IF HIGH CW (+)
    ledcWrite(Motor1, pwm);
  
    //MOTOR 2 
    digitalWrite(Motor2IN1, HIGH); //IF HIGH CCW (-)
    digitalWrite(Motor2IN2, LOW); //IF HIGH CW (+)
    ledcWrite(Motor2, pwm);
  
    // //MOTOR 3
    digitalWrite(Motor3IN1, HIGH); //IF HIGH CCW (-) 
    digitalWrite(Motor3IN2, LOW); //IF HIGH CW (+)
    ledcWrite(Motor3, pwm);
  
    // //MOTOR 4
    digitalWrite(Motor4IN1, HIGH); //IF HIGH CCW (-)
    digitalWrite(Motor4IN2, LOW); //IF HIGH (+)
    ledcWrite(Motor4, pwm);
  }
  
  void rightForward(int pwm){
      //MOTOR 1 
    digitalWrite(Motor1IN1, LOW); //IF HIGH CCW (-)
    digitalWrite(Motor1IN2, LOW);  //IF HIGH CW (+)
    ledcWrite(Motor1, pwm);
  
    //MOTOR 2 
    digitalWrite(Motor2IN1, LOW); //IF HIGH CCW (-)
    digitalWrite(Motor2IN2, HIGH); //IF HIGH CW (+)
    ledcWrite(Motor2, pwm);
  
    // //MOTOR 3
    digitalWrite(Motor3IN1, LOW); //IF HIGH CCW (-) 
    digitalWrite(Motor3IN2, HIGH); //IF HIGH CW (+)
    ledcWrite(Motor3, pwm);
  
    // //MOTOR 4
    digitalWrite(Motor4IN1, LOW); //IF HIGH CCW (-)
    digitalWrite(Motor4IN2, LOW); //IF HIGH (+)
    ledcWrite(Motor4, pwm);
  }
  
  void rightBackward(int pwm){
      //MOTOR 1 
    digitalWrite(Motor1IN1, HIGH); //IF HIGH CCW (-)
    digitalWrite(Motor1IN2, LOW);  //IF HIGH CW (+)
    ledcWrite(Motor1, pwm);
  
    //MOTOR 2 
    digitalWrite(Motor2IN1, LOW); //IF HIGH CCW (-)
    digitalWrite(Motor2IN2, LOW); //IF HIGH CW (+)
    ledcWrite(Motor2, pwm);
  
    // //MOTOR 3
    digitalWrite(Motor3IN1, LOW); //IF HIGH CCW (-) 
    digitalWrite(Motor3IN2, LOW); //IF HIGH CW (+)
    ledcWrite(Motor3, pwm);
  
    // //MOTOR 4
    digitalWrite(Motor4IN1, HIGH); //IF HIGH CCW (-)
    digitalWrite(Motor4IN2, LOW); //IF HIGH (+)
    ledcWrite(Motor4, pwm);
  }
  
  void leftForward(int pwm){
      //MOTOR 1 
    digitalWrite(Motor1IN1, LOW); //IF HIGH CCW (-)
    digitalWrite(Motor1IN2, HIGH);  //IF HIGH CW (+)
    ledcWrite(Motor1, pwm);
  
    //MOTOR 2 
    digitalWrite(Motor2IN1, LOW); //IF HIGH CCW (-)
    digitalWrite(Motor2IN2, LOW); //IF HIGH CW (+)
    ledcWrite(Motor2, pwm);
  
    // //MOTOR 3
    digitalWrite(Motor3IN1, LOW); //IF HIGH CCW (-) 
    digitalWrite(Motor3IN2, LOW); //IF HIGH CW (+)
    ledcWrite(Motor3, pwm);
  
    // //MOTOR 4
    digitalWrite(Motor4IN1, LOW); //IF HIGH CCW (-)
    digitalWrite(Motor4IN2, HIGH); //IF HIGH (+)
    ledcWrite(Motor4, pwm);
  }
  
  void leftBackward(int pwm){
      //MOTOR 1 
    digitalWrite(Motor1IN1, LOW); //IF HIGH CCW (-)
    digitalWrite(Motor1IN2, LOW);  //IF HIGH CW (+)
    ledcWrite(Motor1, pwm);
  
    //MOTOR 2 
    digitalWrite(Motor2IN1, HIGH); //IF HIGH CCW (-)
    digitalWrite(Motor2IN2, LOW); //IF HIGH CW (+)
    ledcWrite(Motor2, pwm);
  
    // //MOTOR 3
    digitalWrite(Motor3IN1, HIGH); //IF HIGH CCW (-) 
    digitalWrite(Motor3IN2, LOW); //IF HIGH CW (+)
    ledcWrite(Motor3, pwm);
  
    // //MOTOR 4
    digitalWrite(Motor4IN1, LOW); //IF HIGH CCW (-)
    digitalWrite(Motor4IN2, LOW); //IF HIGH (+)
    ledcWrite(Motor4, pwm);
  }
  
  void off(int pwm){
        //MOTOR 1 
    digitalWrite(Motor1IN1, LOW); //IF HIGH CCW (-)
    digitalWrite(Motor1IN2, LOW);  //IF HIGH CW (+)
    ledcWrite(Motor1, pwm);
  
    //MOTOR 2 
    digitalWrite(Motor2IN1, LOW); //IF HIGH CCW (-)
    digitalWrite(Motor2IN2, LOW); //IF HIGH CW (+)
    ledcWrite(Motor2, pwm);
  
    // //MOTOR 3
    digitalWrite(Motor3IN1, LOW); //IF HIGH CCW (-) 
    digitalWrite(Motor3IN2, LOW); //IF HIGH CW (+)
    ledcWrite(Motor3, pwm);
  
    // //MOTOR 4
    digitalWrite(Motor4IN1, LOW); //IF HIGH CCW (-)
    digitalWrite(Motor4IN2, LOW); //IF HIGH (+)
    ledcWrite(Motor4, pwm);
  }
