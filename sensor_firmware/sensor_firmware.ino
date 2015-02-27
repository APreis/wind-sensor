/*
 * Wind Sensor Firmware
 *
 */


#include "TimerOne.h"

int counter = 0;
int average = 0;

void setup() {
    int baud_rate = 9600;
    Serial.begin(baud_rate);

    // Set sample period in microseconds for 8kHz
    long timer_delay_us = 125;
    Timer1.initialize(timer_delay_us);
    Timer1.attachInterrupt(interrupt_loop);
}

void loop() {
    // We don't actually need anything in here since all of our 
    // logic is in the Interrupt Service Routine (ISR)
}

/* Here is the routine that is run when the timer interrupt goes off */
void interrupt_loop(){
    int sensorValue = analogRead(A0);

    // prints out an average value after 5000 samples
    // TODO: Implement our actual filter here
    if(counter == 5000){
        Serial.println(sensorValue);
        counter = 0;
    }
    else{
        average = (average + sensorValue)/2;
        counter++;
    }
}


