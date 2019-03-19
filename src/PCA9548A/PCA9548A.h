#pragma once
#include "mbed.h"

class PCA9548A{
    public:
    PCA9548A(I2C * i2c);
    ~PCA9548A();
    public:
    void write_sel(int sel);
    void disable();
    
    private:
    void write_reg(char buffer);
    
    private:
    I2C * i2c;
    const int i2cAddress = 0xE0;
};