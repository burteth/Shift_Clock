#include "Clock.h"
#include "ds3231.h"
#include <Wire.h>


struct ts t; 

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


                DS3231_init(DS3231_CONTROL_INTCN);
    
                t.hour=12; 
                t.min=30;
                t.sec=0;
                t.mday=25;
                t.mon=12;
                t.year=2019;
                
                DS3231_set(t); 

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

void Clock::PrintTime(){

    DS3231_get(&t);
    Serial.print("Date : ");
    Serial.print(t.mday);
    Serial.print("/");
    Serial.print(t.mon);
    Serial.print("/");
    Serial.print(t.year);
    Serial.print("\t Hour : ");
    Serial.print(t.hour);
    Serial.print(":");
    Serial.print(t.min);
    Serial.print(".");
    Serial.println(t.sec); 
}
