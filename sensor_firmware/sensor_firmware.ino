/*
 * Wind Sensor Firmware
 *
 */


#include "TimerOne.h"

void setup() {
    int baud_rate = 115200;
    Serial.begin(baud_rate);

    // Set sample period in microseconds for 8kHz
    long timer_delay_us = 125;
    Timer.initialize(timer_delay_us);
}

void loop() {
    // We don't need to do anything for now
}

void interrupt_loop(){
    // Sample sensor
    int sensorValue = analogRead(A0);
    Serial.println(sensorValue);
}


