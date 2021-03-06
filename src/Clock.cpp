#include <RTClib.h>
#include <Wire.h>
#include <Stepper.h>
#include "Clock.h"
#include "colors.cpp"


Clock::Clock(Stepper motor_in) : motor(motor_in){

    motor.setSpeed(20);

}

void Clock::Init(int rgb_red_pin_in, int rgb_green_pin_in, 
             int rgb_blue_pin_in, int motor_a_pin_in, 
             int motor_a_bar_pin_in, int motor_b_pin_in, 
             int motor_b_bar_pin_in, int speed_up_factor_in){

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
                
                rtc.begin();
                rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));

                // Setup LEDs
                pinMode(RGB_RED_PIN, OUTPUT);
                pinMode(RGB_GREEN_PIN, OUTPUT);
                pinMode(RGB_BLUE_PIN, OUTPUT);

                // Setup Motor
                // int steps_per_revolution = 200;
                // int stepper_speed = 20;                
         

                speed_up_factor = speed_up_factor_in;
                
            };

// unsigned long long Clock::seconds_per_week  = 60 * 60 * 24;
// unsigned long long Clock::seconds_per_day = 604800;

void Clock::UpdateLEDs(){    
    Serial.println("Updating LEDs");

    int min_this_week = MinutesThisWeek();

    int min_per_week = 10080;

    double percentage = (double)min_this_week / (double)min_per_week;
    
    double degrees = percentage * (double)360.0;

    hsv temp_hsv({degrees, 1.0, 1.0});
    rgb temp_rgb = temp_hsv.to_rgb();    
    Serial.print("Degrees: ");
    Serial.println(degrees);
    SetRGBColor(temp_rgb.r, temp_rgb.g, temp_rgb.b);    

};

void Clock::StepMotor(){
    Serial.println("Stepping Motor");
    
    int perdicted_steps = perdict_num_steps();

    int steps_needed = perdicted_steps - steps_this_cycle;
    
    // if (steps_needed < 0){
    //     steps_needed = 190 - steps_this_cycle + perdicted_steps;
    // }

    Serial.println("Steps Needed: ");
    Serial.println(steps_needed);        
    // exit(1);
    if (steps_needed < 0){
        for (int i = 0; i < abs(steps_needed); i++){
            motor.step(-1);
            delay(40);
            Serial.println(steps_needed + i);
        }
    }else{
        for (int i = 0; i < abs(steps_needed); i++){
            motor.step(1);
            delay(40);
            Serial.println(steps_needed - i);                
        }
    }
        
    
    steps_this_cycle += steps_needed;

    // make sure it doesnt get above 200 
    steps_this_cycle %= 200;

};

void Clock::ResetClockHand(){
    return;
};

unsigned long Clock::SecondsThisWeek(){

    unsigned long seconds_per_hour = 60*60;    
    unsigned long seconds_per_day = seconds_per_hour*24;
    

    unsigned long seconds_this_week = 0;
    DateTime now = rtc.now();

    seconds_this_week += now.dayOfTheWeek() * seconds_per_day;

    seconds_this_week += now.hour() * seconds_per_hour;

    seconds_this_week += now.minute() * 60;

    seconds_this_week += now.minute();


    return(seconds_this_week);
}

int Clock::MinutesThisWeek(){
  
    int min_per_day = 60*24;
    
    int min_this_week = 0;

    DateTime now = rtc.now();

    // if it isnt saturday then adjust
    // so that week starts on monday
    if (now.dayOfTheWeek() != 0){
        min_this_week += (now.dayOfTheWeek() - 1) * min_per_day;
    }else{
        // if it is sunday
        min_this_week += (6) * min_per_day;
    }
    
    min_this_week += now.hour() * 60;

    min_this_week += now.minute();
    Serial.print("min_this_week: ");
    Serial.println(min_this_week);
    return(min_this_week);
}

void Clock::PrintTime(){
    Serial.println("Printing Time");

    char t[32];

    DateTime now = rtc.now();
    
    // Serial.println(now.day());
    // sprintf(t, "%02d:%02d:%02d %02d/%02d/%02d",  now.hour(), now.minute(), now.second(), now.day(), now.month(), now.year());  
    
    // Serial.print(F("Date/Time: "));
    // Serial.println(t);

}

void Clock::SetRGBColor(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(RGB_RED_PIN, red_light_value);
  analogWrite(RGB_GREEN_PIN, green_light_value);
  analogWrite(RGB_BLUE_PIN, blue_light_value);
 }

void Clock::SpeedTimeUp(){
    DateTime now = rtc.now();

    // Set clock to new time
    rtc.adjust(now.unixtime() + speed_up_factor);
}

int Clock::perdict_num_steps(){    

    double min_per_day = 60*24;

    DateTime now = rtc.now();

    double min_today = now.hour() * 60 + now.minute();
    
    double percent_of_today = min_today / min_per_day;

    int steps = (percent_of_today * 200.0);

    return(steps);
}
