void CommunicationTask(void * pvParameters) {
    WiFi.softAP(ssid, password);
    IPAddress IP = WiFi.softAPIP();

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        struct Command {
            const char *name;
            int stateValue;
        };

        // Define the button commands
        Command commands[] = {
            {"tombolKanan", RIGHT}, {"tombolKiri", LEFT}, {"tombolMaju", FORWARD},
            {"tombolMundur", BACKWARD}, {"tombolCW", CW}, {"tombolCCW", CCW},
            {"tombolKananAtas", RIGHTFORWARD}, {"tombolKananBawah", RIGHTBACKWARD},
            {"tombolKiriAtas", LEFTFORWARD}, {"tombolKiriBawah", LEFTBACKWARD}
        };

        bool receivedCommand = false;

        for (const auto &cmd : commands) {
            if (request->hasParam(cmd.name)) {
                String value = request->getParam(cmd.name)->value();
                request->send(200, "text/plain", "Input received: " + value);

                int a = value.toInt();
                if (a == 1) {
                    currentState = static_cast<state>(cmd.stateValue);;
                    Serial.println(cmd.name);
                } else {
                    currentState = OFF;
                }
                receivedCommand = true;
            }
        }

        // Handle speed separately
        if (request->hasParam("speed")) {
            String speedString = request->getParam("speed")->value();
            request->send(200, "text/plain", "Speed received: " + speedString);

            int a = speedString.toInt();
            pwm = constrain(a, pwmMin, pwmMax);
            Serial.println("speed");
            receivedCommand = true;
        }

        // Handle invalid request
        if (!receivedCommand) {
            request->send(400, "text/plain", "Bad Request: No valid input provided");
        }
    });

    server.begin();
}
