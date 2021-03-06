#include "QT1070.h"

using namespace std;
QT1070::QT1070(I2C * i2c) {
        this->i2c = i2c;
    }

char QT1070::get_chip_id()
{
    return read_register(0x00);
}
char QT1070::get_pressed_key()
{
    return  read_register(0x03);
}
void QT1070::calibrate()
{
    char buffer = 0x38;
    if (i2c->write(i2cAddress, &buffer, 1, 0) != 1)
    {
        cout << "Failed to set pointer." << endl;
    }
    else
    {
        cout << "Calibrate: " << endl;
    }
}
void QT1070::write_register(char reg, char value){
    if (i2c->write(i2cAddress, &reg, 1, 0) != 1){
        
    }
    else{
        cout << "Failed to set pointer." << endl;
    }
    wait(0.5);
    if (i2c->write(i2cAddress, &value, 1, 0) != 1)
    {
    
    }
    else
    {
        cout << "Failed to write to the i2c device." << endl;  
    }
}
char QT1070::read_register(char reg){
    char value;
    if (i2c->write(i2cAddress, &reg, 1, 0) != 1)
    {
        
    }
    else{
        cout << "Failed to set pointer." << endl;
    }
    wait(0.5);
    if (i2c->read(i2cAddress, &value, 1, 0) != 1)
    {
    
    }
    else
    {
        cout << "Failed to read from the i2c device." << endl;  
    }
    return value;
}