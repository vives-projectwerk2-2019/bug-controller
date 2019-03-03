#include "dongles.h"
#include <iostream>
#include "mbed.h"

using namespace std;
Dongle::Dongle(I2C * i2c){
    this->i2c = i2c;
    this->i2cAddress = 0xA0; //slave address
}
void Dongle::write_test(){
    char adr[2] = {0x1F,0xE0};
    char test[16] = "test567HDP9g2dM"; //0x41, 0xE2, 0xC3,0x04,0x01, 0x12, 0x53,0x04,0x01, 0x02, 0x03,0x04,0x01, 0x02, 0x03,'a'
    char buffer[18] = {};
    for(int i = 0; i<18; i++){
        if(i<2){
            buffer[i] = adr[i];
        }
        else{
            buffer[i] = test[i-2];
        }
    }
    if (i2c->write(i2cAddress, buffer, 18, 0) != 18)
    {
        
    }
    else{
        cout << "Failed to set pointer." << endl;
    }
}
void Dongle::get_id(char * id){
    char buffer[2] = {0x1F,0xE0};
    if (i2c->write(i2cAddress, buffer, 2, 0) != 2)
    {
        
    }
    else{
        cout << "Failed to set pointer." << endl;
    }
    wait(0.5);
    if (i2c->read(i2cAddress, id, 16, 0) != 16)
    {
        
    }
    else
    {
        cout << "Failed to read from the i2c device." << endl;  
    }
}