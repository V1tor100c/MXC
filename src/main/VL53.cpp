#include "VL53.h"

void VL53_sensors::sensorsInit(TwoWire &wire) {
    for (uint8_t i = 0; i < number_sensor; i++) {
        pinMode(x_shut_pins[i], OUTPUT);
        digitalWrite(x_shut_pins[i], LOW);
    }

    for (uint8_t i = 0; i < number_sensor; i++) {
        pinMode(x_shut_pins[i], INPUT);
        sensor[i].init(true);
        sensor[i].setAddress((uint8_t)0x21 + i);
        sensor[i].setTimeout(50);
    }
}

void VL53_sensors::distanceRead() {
    for (uint8_t i = 0; i < number_sensor; i++) {
        dist[i] = sensor[i].readRangeSingleMillimeters();
    }
}