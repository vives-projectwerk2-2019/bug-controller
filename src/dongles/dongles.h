#pragma once
#include "mbed.h"
class Dongle{
    public:
    Dongle(I2C * i2c);

    public:
    void get_id(char * id);
    void write_test();

    private:
    I2C * i2c;
    int i2cAddress; //8-bit address
    
};