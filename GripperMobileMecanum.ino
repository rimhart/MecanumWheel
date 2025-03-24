//Wifi Library
#include "esp_wifi.h"

//BAUD RATE 
#define BAUDRATE 115200

//WIFI Configuration
#include "WiFi.h"

#include "ESPAsyncWebServer.h"//for more than 1 user
AsyncWebServer server(80);

//connecting
const char* ssid = "dagozilla";
const char* password = "PIZZAhut";

//PIN LOCOMOTION DECLARATION
#define Motor1ENA 32
#define Motor1IN1 25
#define Motor1IN2 33
#define Motor2ENA 23 
#define Motor2IN1 22
#define Motor2IN2 21
#define Motor3ENA 14
#define Motor3IN1 27
#define Motor3IN2 26
#define Motor4ENA 5
#define Motor4IN1 19
#define Motor4IN2 18

//PIN GRIPPLER + HAND DECLARATION
#define PrimaryServo 
#define SecondaryServo
#define SuckerENA

//LEDCWRITE CHANNEL 
const int Motor1 = 1; 
const int Motor2 = 2;
const int Motor3 = 3; 
const int Motor4 = 4; 
const int Sucker = 5; 

//for ledcWrite program
const int PWM_FREQ = 500;     // Recall that Arduino Uno is ~490 Hz. Official ESP32 example uses 5,000Hz
const int PWM_RESOLUTION = 8; // We'll use same resolution as Uno (8 bits, 0-255) but ESP32 can go up to 16 bits 


//DECLARE VARIABLE 
int pwm =0;
int pwmMax = 255;
int pwmMin = 0; //tuning lagi, cari deadzone

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
  RIGHT, LEFT, FORWARD, BACKWARD, CW, CCW, RIGHTFORWARD, RIGHTBACKWARD, LEFTFORWARD, LEFTBACKWARD
};

state currentState;

//DECLARE FUNCTION
void CommunicationTask(void * pvParameters);
void MotorTask(void * pvParameters);

TaskHandle_t CommunicationTask;
TaskHandle_t SystemControlTask;