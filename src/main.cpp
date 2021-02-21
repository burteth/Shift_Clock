#include <Arduino.h>
#include "Clock.h"
#include <RTClib.h>
#include <Wire.h>


int rgb_red_pin = 11;
int rgb_green_pin = 10;
int rgb_blue_pin = 9;

// Motor Pins
int motor_a_pin = 2;
int motor_a_bar_pin = 3;
int motor_b_pin = 4;
int motor_b_bar_pin = 5;

// Clock led_clock;


char t[32];

RTC_DS3231 rtc;


void setup() {
    Serial.begin(9600);
        
    // led_clock.Init(rgb_red_pin, rgb_green_pin, rgb_blue_pin,
    //         motor_a_pin, motor_a_bar_pin, motor_b_pin, 
    //         motor_b_bar_pin);

    Wire.begin();
    rtc.begin();
    rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));
    
}

void loop() {
        
    // led_clock.PrintTime();
    DateTime now = rtc.now();

    sprintf(t, "%02d:%02d:%02d %02d/%02d/%02d",  now.hour(), now.minute(), now.second(), now.day(), now.month(), now.year());  
    
    Serial.print(F("Date/Time: "));
    Serial.println(t);

    delay(1000);

    // delay(1000);
  
}


