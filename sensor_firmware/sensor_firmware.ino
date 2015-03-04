/*
 * Wind Sensor Firmware
 *
 */


#include "TimerOne.h"

int counter = 0;
int average = 0;
float output = 0;
float previous_output = 0;
int freq = 4000;

void setup() {
    int baud_rate = 9600;
    Serial.begin(baud_rate);
    Serial.println("Begin program");
    // analogReference(EXTERNAL);

    // Set frequency
    long period = ((float)1.0/(float)freq)*(1E6);
    Serial.print("Period: ");
    Serial.println(period);
    long timer_delay_us = period;

    // Attach timer
    Timer1.initialize(timer_delay_us);
    Timer1.attachInterrupt(interrupt_loop);
}

void loop() {
}

/* Here is the routine that is run when the timer interrupt goes off */
void interrupt_loop(){
    int sensorValue = analogRead(A0);

    // Print out every second
    if(counter >= freq){
        previous_output = output;
        output = output*0.190 + 2.753;
        // output = 2.753;
        Serial.println(output);
        counter = 0;
    }
    // Sample continiously
    else{
        output = 0.0002*abs(sensorValue - 508) + 0.9998*(previous_output);
        previous_output = output;
        counter++;
    }
}


