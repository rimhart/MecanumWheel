void setup() {
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
    pinMode(PrimaryServo, OUTPUT);
    pinMode(SecondaryServo, OUTPUT);
    pinMode(Sucker, OUTPUT);

  //LEDCWRITE CONFIGURATION
  // configure LED PWM functionalitites
  ledcSetup(1, PWM_FREQ, PWM_RESOLUTION);
  ledcSetup(2, PWM_FREQ, PWM_RESOLUTION);
  ledcSetup(3, PWM_FREQ, PWM_RESOLUTION);
  ledcSetup(4, PWM_FREQ, PWM_RESOLUTION);
  ledcSetup(5, PWM_FREQ, PWM_RESOLUTION);
  
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(Motor1ENA, Motor1);
  ledcAttachPin(Motor2ENA, Motor2);
  ledcAttachPin(Motor3ENA, Motor3);
  ledcAttachPin(Motor4ENA, Motor4);
  ledcAttachPin(SuckerENA, Sucker);

  // Communication Task on Core 0
  xTaskCreatePinnedToCore(CommunicationTask, "CommunicationTask", 10000, NULL, 1, NULL, 0);

  // System Control Task on Core 1
  xTaskCreatePinnedToCore(SystemControlTask, "SystemControlTask", 10000, NULL, 1, NULL, 1);
}