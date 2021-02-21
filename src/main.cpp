#include <Arduino.h>
#include "DS3231.h"
#include <time.h>
#include "Clock.h"

int rgb_red_pin = 11;
int rgb_green_pin = 10;
int rgb_blue_pin = 9;

// Motor Pins
int motor_a_pin = 2;
int motor_a_bar_pin = 3;
int motor_b_pin = 4;
int motor_b_bar_pin = 5;

Clock led_clock(rgb_red_pin, rgb_green_pin, rgb_blue_pin,
            motor_a_pin, motor_a_bar_pin, motor_b_pin, 
            motor_b_bar_pin);

void setup() {

    Serial.begin(115200);
    

  
}

void loop() {

    Time t = led_clock.rtc.getTime();
    // Send date over serial connection
    Serial.print("Today is the ");
    Serial.print(t.date, DEC);
    Serial.print(". day of ");
    Serial.print(led_clock.rtc.getMonthStr());
    Serial.print(" in the year ");
    Serial.print(t.year, DEC);
    Serial.println(".");
    
    // Send Day-of-Week and time
    Serial.print("It is the ");
    Serial.print(t.dow, DEC);
    Serial.print(". day of the week (counting monday as the 1th), and it has passed ");
    Serial.print(t.hour, DEC);
    Serial.print(" hour(s), ");
    Serial.print(t.min, DEC);
    Serial.print(" minute(s) and ");
    Serial.print(t.sec, DEC);
    Serial.println(" second(s) since midnight.");

    // Send a divider for readability
    Serial.println("  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -");
    
    // Wait one second before repeating :)
    delay (1000);


  
}

