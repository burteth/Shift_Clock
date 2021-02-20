#include <Arduino.h>
#include <Process.h>
#include <Stepper.h>
#include <time.h>
#include <RTClib.h>
#include "DS3231.h"

#include "colors.h"



// // Init the DS3231 using the hardware interface
// DS3231  rtc(SDA, SCL);

// // Init a Time-data structure
// Time  t;

// void setup()
// {
//   // Setup Serial connection
//   Serial.begin(115200);
//   // Uncomment the next line if you are using an Arduino Leonardo
//   //while (!Serial) {}

//   // Initialize the rtc object
//   rtc.begin();
  
//   // The following lines can be uncommented to set the date and time
//   //rtc.setDOW(WEDNESDAY);     // Set Day-of-Week to SUNDAY
//   //rtc.setTime(12, 0, 0);     // Set the time to 12:00:00 (24hr format)
//   //rtc.setDate(1, 1, 2014);   // Set the date to January 1st, 2014
// }

// void loop()
// {
//   // Get data from the DS3231
//   t = rtc.getTime();
  
//   // Send date over serial connection
//   Serial.print("Today is the ");
//   Serial.print(t.date, DEC);
//   Serial.print(". day of ");
//   Serial.print(rtc.getMonthStr());
//   Serial.print(" in the year ");
//   Serial.print(t.year, DEC);
//   Serial.println(".");
  
//   // Send Day-of-Week and time
//   Serial.print("It is the ");
//   Serial.print(t.dow, DEC);
//   Serial.print(". day of the week (counting monday as the 1th), and it has passed ");
//   Serial.print(t.hour, DEC);
//   Serial.print(" hour(s), ");
//   Serial.print(t.min, DEC);
//   Serial.print(" minute(s) and ");
//   Serial.print(t.sec, DEC);
//   Serial.println(" second(s) since midnight.");

//   // Send a divider for readability
//   Serial.println("  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -");
  
//   // Wait one second before repeating :)
//   delay (1000);
// }