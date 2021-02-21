#include "Clock.h"
#include <Wire.h>


Clock::Clock(){}

void Clock::Init(int rgb_red_pin_in, int rgb_green_pin_in, 
             int rgb_blue_pin_in, int motor_a_pin_in, 
             int motor_a_bar_pin_in, int motor_b_pin_in, 
             int motor_b_bar_pin_in){

                // rtc(SDA,SCL);

                // Initialize LED Pins
                RGB_RED_PIN = rgb_red_pin_in;
                RGB_GREEN_PIN = rgb_green_pin_in;
                RGB_BLUE_PIN  = rgb_blue_pin_in;

                // Initialize Motor Pins
                MOTOR_A_PIN = motor_a_pin_in;
                MOTOR_A_BAR_PIN = motor_a_bar_pin_in;
                MOTOR_B_PIN = motor_b_pin_in;
                MOTOR_B_BAR_PIN = motor_b_bar_pin_in;



            };

// unsigned long long Clock::seconds_per_week  = 60 * 60 * 24;
// unsigned long long Clock::seconds_per_day = 604800;

void Clock::UpdateLEDs(){
    return;
};

void Clock::StepMotor(){
    return;
};

void Clock::ResetClockHand(){
    return;
};
