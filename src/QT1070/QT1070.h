#pragma once
#include <iostream>
#include "mbed.h"
using namespace std;
class QT1070{
    private:
        //int i2cfile; //geen default constructor
        I2C * i2c;
        int adr;
        
    public:
        QT1070(I2C * i2c);
        int get_chip_id();
        int get_value();
        void calibrate();
    private:
        void schrijf(char buffer[1]);
};
