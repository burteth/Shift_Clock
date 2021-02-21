#include <Arduino.h>
#include <RTClib.h>
#include <Wire.h>
#include <Stepper.h>
#include "Clock.h"
#include "colors.cpp"

// LED Pins
int rgb_red_pin = 11;
int rgb_green_pin = 10;
int rgb_blue_pin = 9;

// Motor Pins
int motor_a_pin = 2;
int motor_a_bar_pin = 3;
int motor_b_pin = 4;
int motor_b_bar_pin = 5;

// Speed up factor how many sec per loop
int speed_up_factor = 0;

Clock led_clock;

Stepper motor(200,2,3,4,5);

void setup() {
    Serial.begin(9600);
        
    led_clock.Init(rgb_red_pin, rgb_green_pin, rgb_blue_pin,
            motor_a_pin, motor_a_bar_pin, motor_b_pin, 
            motor_b_bar_pin, speed_up_factor);

    Wire.begin();

    motor.setSpeed(40);
    
}

void loop() {
        
    led_clock.PrintTime();

    // led_clock.UpdateLEDs();    

    // led_clock.StepMotor();

    // led_clock.SpeedTimeUp();
    
    motor.step(200);

    delay(1000);
}




