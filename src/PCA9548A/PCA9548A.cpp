#include "PCA9548A.h"
#include <iostream>
using namespace std;

PCA9548A::PCA9548A(I2C * i2c){
    this->i2c = i2c;
}
PCA9548A::~PCA9548A(){
    delete(i2c);
}
void PCA9548A::write_sel(int sel){
    char buffer;
    switch(sel){
    case 0:
        buffer = 0x01;
        break;
    case 1:
        buffer = 0x02;
        break;
    case 2:
        buffer = 0x04;
        break;
    case 3:
        buffer = 0x08;
        break;
    case 4:
        buffer = 0x10;
        break;
    case 5:
        buffer = 0x20;
        break;
    case 6:
        buffer = 0x40;
        break;
    case 7:
        buffer = 0x80;
        break;
}
    write_reg(buffer);
}
void PCA9548A::disable(){
    write_reg(0x00);
}
void PCA9548A::write_reg(char buffer){
    if (i2c->write(i2cAddress, &buffer, 1, 0) != 1)
    {
    
    }   
    else{
        cout << "Failed to set pointer." << endl;
    }
}
