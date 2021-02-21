
#ifndef Clock_h
#define Clock_h

#include "DS3231.h"

class Clock{
public:
    
    Clock(int rgb_red_pin_in, int rgb_green_pin_in, 
          int rgb_blue_pin_in,int motor_a_pin_in, 
          int motor_a_bar_pin_in, int motor_b_pin_in, 
          int motor_b_bar_pin_in);

    // static unsigned long long seconds_per_week;
    // static unsigned long long seconds_per_day;
    
    // LED Pins
    int RGB_RED_PIN;
    int RGB_GREEN_PIN;
    int RGB_BLUE_PIN;

    //Motor Pins
    int MOTOR_A_PIN;
    int MOTOR_A_BAR_PIN;
    int MOTOR_B_PIN;
    int MOTOR_B_BAR_PIN;

    //Timing
    // int seconds_this_week;

    DS3231 rtc;



    void UpdateLEDs();
    
    void StepMotor();

    void ResetClockHand();

};

#endif /* Clock_h */
