#include <Arduino.h>
// digital pin 2 is the hall pin
int hall_pin = 2;
// set number of hall trips for RPM reading (higher improves accuracy)
float hall_thresh = 100.0;

int red_light_pin= 11;
int green_light_pin = 10;
int blue_light_pin = 9;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  // make the hall pin an input:
  pinMode(hall_pin, INPUT);

  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);

}
void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
// the loop routine runs over and over again forever:
void loop() {

    
  // preallocate values for tach
//   float hall_count = 1.0;
//   float start = micros();
//   bool on_state = false;
  // counting number of times the hall sensor is tripped
  // but without double counting during the same trip

if (digitalRead(hall_pin)==0){      
    Serial.write("Tripped\n");    
    RGB_color(255, 0, 0);
} else{
    Serial.write("Not Tripped\n");
    RGB_color(0, 0, 0);
}

  
//   // print information about Time and RPM
//   float end_time = micros();
//   float time_passed = ((end_time-start)/1000000.0);
//   Serial.print("Time Passed: ");
//   Serial.print(time_passed);
//   Serial.println("s");
//   float rpm_val = (hall_count/time_passed)*60.0;
//   Serial.print(rpm_val);
//   Serial.println(" RPM");
  delay(100);        // delay in between reads for stability
}