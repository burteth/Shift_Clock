#include <Arduino.h>
#include "ds3231.h"
#include "Clock.h"
#include <time.h>
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

Clock led_clock;


void setup() {
    Serial.begin(115200);
        
    led_clock.Init(rgb_red_pin, rgb_green_pin, rgb_blue_pin,
            motor_a_pin, motor_a_bar_pin, motor_b_pin, 
            motor_b_bar_pin);

    Wire.begin();
    
}

void loop() {
        
    led_clock.PrintTime();

    delay(1000);
  
}

