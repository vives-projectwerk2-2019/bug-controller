
#include "QT1070.h"

using namespace std;
QT1070::QT1070(I2C * i2c) {
        this->i2c = i2c;
    }

int QT1070::get_chip_id()
{
    char buffer[1] = {0x00};
    schrijf(buffer);
    return (int)buffer[0];
}
int QT1070::get_value()
{
    char buffer[1] = {0x03};
    schrijf(buffer);
    return (int)buffer[0];
}
void QT1070::calibrate()
{
    char buffer[1] = {0x38};
    if (i2c->write(0x1B<<1, buffer, 1, 0) != 1)
    {
        cout << "Failed to set pointer." << endl;
    }
    else
    {
        cout << "Calibrate: " << endl;
    }
}

void QT1070::schrijf(char buffer[1]){
    if (i2c->write(0x1B<<1, buffer, 1, 0) != 1)
    {
        
    }
    else{
        cout << "Failed to set pointer." << endl;
    }
    wait(0.5);
    if (i2c->read(0x1B<<1, buffer, 1, 0) != 1)
    {
    
    }
    else
    {
        cout << "Failed to read from the i2c device." << endl;  
    }
}
