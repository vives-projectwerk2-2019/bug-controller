#include "mbed.h"

DigitalOut myled(LED1);
Serial pc(SERIAL_TX, SERIAL_RX); // tx, rx
I2C i2c(I2C_SDA, I2C_SCL);

int main() {
    
    pc.printf(" test dubbel charlotte");
    while(1) {
        char buffer[1] = {0x00};
        pc.printf(" Hello World !\r \n");
        pc.printf(" laten we dit nog een beetje verder testen.\r \n ");
        if(i2c.write(0x1B, buffer, 1, false) != 1){
            pc.printf("failed to set pointer \r \n");
        }
        else{printf("YESSSS");}
        if(i2c.read(0x1B,buffer,1, false) != 1){
            pc.printf("failed to read from device");
        }
        pc.printf(" get chip id: %d", buffer[0]);
        myled = 1;
        wait(0.5);
        myled = 0;
        wait(0.5);
    }
}
