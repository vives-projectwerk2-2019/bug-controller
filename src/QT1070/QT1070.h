#pragma once
#include <iostream>
#include "mbed.h"
class QT1070{
         
    public:
        QT1070(I2C * i2c);
        char get_chip_id();
        char get_pressed_key();
        void calibrate();
    private:
        void write_register(char reg, char value);
        char read_register(char reg);

    private:
        I2C * i2c;
        const int i2cAddress = 0x1B<<1;
};