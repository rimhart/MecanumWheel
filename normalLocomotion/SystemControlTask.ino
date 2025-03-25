void SystemControlTask(void * pvParameters){
    //LOGIC MOVEMENT
    if(currentState == FORWARD){
      forward(pwm);
    }
    else if(currentState == BACKWARD){
      backward(pwm);
    }
    else if(currentState == RIGHT){
      right(pwm);
    }
    else if(currentState == LEFT){
      left(pwm);
    }
    else if(currentState == CW){
      clockwise(pwm);
    }
    else if(currentState == CCW){
      counterClockwise(pwm);
    }
    else if(currentState == RIGHTFORWARD){
      rightForward(pwm);
    }
    else if(currentState == RIGHTBACKWARD){
      rightBackward(pwm);
    }
    else if(currentState == LEFTFORWARD){
      leftForward(pwm);
    }
    else if(currentState == LEFTBACKWARD){
      leftBackward(pwm);
    }
    else if(currentState == OFF){
      off(pwm);
    }
  
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
    ledcWrite(Motor1, 0);
  
    //MOTOR 2 
    digitalWrite(Motor2IN1, LOW); //IF HIGH CCW (-)
    digitalWrite(Motor2IN2, LOW); //IF HIGH CW (+)
    ledcWrite(Motor2, 0);
  
    // //MOTOR 3
    digitalWrite(Motor3IN1, LOW); //IF HIGH CCW (-) 
    digitalWrite(Motor3IN2, LOW); //IF HIGH CW (+)
    ledcWrite(Motor3, 0);
  
    // //MOTOR 4
    digitalWrite(Motor4IN1, LOW); //IF HIGH CCW (-)
    digitalWrite(Motor4IN2, LOW); //IF HIGH (+)
    ledcWrite(Motor4, 0);
  }
  
  void loop() {
    // put your main code here, to run repeatedly:
  
  }