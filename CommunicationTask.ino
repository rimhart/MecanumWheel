void CommunicationTask(void * pvParameters){
    //PARAMETER FROM WIFI
  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    if (request->hasParam("tombolKanan")) {
      String tombolKananString = request->getParam("tombolKanan")->value();
      request->send(200, "text/plain", "Input tombol kanan received: " + tombolKananString);

      int a = tombolKananString.toFloat(); //kalo tombol dipencet dia bakal on terus (1)
      if(a == 1){
      currentState = RIGHT;
      Serial.println("RIGHT"); }
      else{
        currentState = OFF;
      }
      
    }

      if (request->hasParam("tombolKiri")) {
      String tombolKiriString = request->getParam("tombolKiri")->value();
      request->send(200, "text/plain", "Input tombol kiri received: " + tombolKiriString);

      int a = tombolKiriString.toFloat();
      if(a == 1){
      currentState = LEFT;
      Serial.println("LEFT"); }
      else{
        currentState = OFF;
      }
      
    }
    
      if (request->hasParam("tombolMaju")) {
      String tombolMajuString = request->getParam("tombolMaju")->value();
      request->send(200, "text/plain", "Input tombol maju received: " + tombolMajuString);

      int a = tombolMajuString.toFloat();
      if(a == 1){
      currentState = FORWARD;
      Serial.println("FORWARD"); }
      else{
        currentState = OFF;
      }
      
    }
    
      if (request->hasParam("tombolMundur")) {
      String tombolMundurString = request->getParam("tombolMundur")->value();
      request->send(200, "text/plain", "Input tombol mundur received: " + tombolMundurString);

      int a = tombolMundurString.toFloat();
      if(a == 1){
      currentState = BACKWARD;
      Serial.println("BACKWARD"); }
      else{
        currentState = OFF;
      }
      
    }
    
     if (request->hasParam("tombolCW")) {
      String tombolCWString = request->getParam("tombolCW")->value();
      request->send(200, "text/plain", "Input tombol CW received: " + tombolCWString);

      int a = tombolCWString.toFloat();
      if(a == 1){
      currentState = CW;
      Serial.println("cw"); }
      else{
        currentState = OFF;
      }
    }
    
 if (request->hasParam("tombolCCW")) {
      String tombolCCWString = request->getParam("tombolCCW")->value();
      request->send(200, "text/plain", "Input tombol CCW received: " + tombolCCWString);

      int a = tombolCCWString.toFloat();
      if(a == 1){
      currentState = CCW;
      Serial.println("ccw"); }
      else{
        currentState = OFF;
      }
    }
    
     if (request->hasParam("tombolKananAtas")) {
      String tombolKananAtasString = request->getParam("tombolKananAtas")->value();
      request->send(200, "text/plain", "Input tombol kanan atas received: " + tombolKananAtasString);

      int a = tombolKananAtasString.toFloat();
      if(a == 1){
      currentState = RIGHTFORWARD;
      Serial.println("RIGHT FORWARD"); }
      else{
        currentState = OFF;
      }
      
    }
    
     if (request->hasParam("tombolKananBawah")) {
      String tombolKananBawahString = request->getParam("tombolKananBawah")->value();
      request->send(200, "text/plain", "Input tombol kanan bawah received: " + tombolKananBawahString);

      int a = tombolKananBawahString.toFloat();
      if(a == 1){
      currentState = RIGHTBACKWARD;
      Serial.println("RIGHT BACKWARD"); }
      else{
        currentState = OFF;
      }
      
    }
    
     if (request->hasParam("tombolKiriAtas")) {
      String tombolKiriAtasString = request->getParam("tombolKiriAtas")->value();
      request->send(200, "text/plain", "Input tombol kiri atas received: " + tombolKiriAtasString);

      int a = tombolKiriAtasString.toFloat();
      if(a == 1){
      currentState = LEFTFORWARD;
      Serial.println("LEFTFORWARD"); }
      else{
        currentState = OFF;
      }
      
    }
    
     if (request->hasParam("tombolKiriBawah")) {
      String tombolKiriBawahString = request->getParam("tombolKiriBawah")->value();
      request->send(200, "text/plain", "Input tombol kiri bawah received: " + tombolKiriBawahString);

      int a = tombolKiriBawahString.toFloat();
      if(a == 1){
      currentState = LEFTBACKWARD;
      Serial.println("LEFT BACKWARD"); }
      else{
        currentState = OFF;
      }
    }

    if (request->hasParam("speed")) {
      String speedString = request->getParam("speed")->value();
      request->send(200, "text/plain", "Input tombol speed received: " + speedString);

      int a = speedString.toFloat();
      int b = constrain(a, pwmMin, pwmMax);
       pwm = b;
      Serial.println("speed");}
    

    // if (request->hasParam("kicker")) {
    //   String kickerString = request->getParam("kicker")->value();
    //   request->send(200, "text/plain", "Input tombol kicker received: " + kickerString);

    //   int a = kickerString.toFloat();
    //   if(a == 1){
    //   isKickerOn = true;
    //   Serial.println("KICK!");
    //    }
    //   else{
    //   isKickerOn = false;
    //   }
      
    //   }


    else {
      request->send(400, "text/plain", "Bad Request: No message content provided");
    }
  });
 
  server.begin();
}