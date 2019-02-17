#include "mbed.h"
#include "QT1070.h"
#include "TLC59116.h"
#define LOOP_WAIT_TIME   0.5

I2C i2c(I2C_SDA, I2C_SCL);
Serial pc(SERIAL_TX, SERIAL_RX); // tx, rx
DigitalOut myled(LED1);
 
int main()
{
    QT1070 qt1070(&i2c);
    pc.printf("Chip id = %d \r \n", qt1070.get_chip_id());
    wait(0.5);
    int val;
    while (1) {
        val = qt1070.get_value();
        switch (val)
        {
        case 1:
            cout << "rechts" << endl;
            break;
        case 2:
            
            cout << "links" << endl;
            break;
        case 4:
            cout << "vooruit" << endl;
            break;
        case 8:
            cout << "achteruit" << endl;
            break;
        case 16:
            cout << "actie B" << endl;
            break;
        case 32:
            cout << "actie A" << endl;
            break;
        case 64:
            cout << "actie X" << endl;
            break;
        default:
            cout << "geen bediening" << endl;
            break;
        }
        myled = !myled;
        wait(LOOP_WAIT_TIME);
        pc.printf("Pressed button value = %d \r \n", val);
    }
 
}
