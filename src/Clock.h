#ifndef Clock_h
#define Clock_h

#include <RTClib.h>
#include <Wire.h>
#include <Stepper.h>

class Clock{
public:
    
    Clock();

    void Init(int rgb_red_pin_in, int rgb_green_pin_in, 
          int rgb_blue_pin_in,int motor_a_pin_in, 
          int motor_a_bar_pin_in, int motor_b_pin_in, 
          int motor_b_bar_pin_in, int speed_up_factor_in);

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

    // Motor
    // Stepper motor;


    //Timing
    int speed_up_factor;
    int steps_this_cycle;
    
    RTC_DS3231 rtc;


    void UpdateLEDs();
    
    void StepMotor();

    void ResetClockHand();

    void PrintTime();

    unsigned long SecondsThisWeek();

    int MinutesThisWeek();

    void SetRGBColor(int red_light_value, int green_light_value, int blue_light_value);

    void SpeedTimeUp();    

    int perdict_num_steps();


};

#endif /* Clock_h */
