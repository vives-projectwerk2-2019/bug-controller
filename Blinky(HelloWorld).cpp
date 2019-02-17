/*#include "mbed.h"

DigitalOut myled(LED1);
Serial pc(SERIAL_TX, SERIAL_RX); // tx, rx
I2C i2c(I2C_SDA, I2C_SCL);

int main() {
    
    pc.printf(" test dubbel charlotte");
    while(1) {
        char buffer[1] = {0x00};
        pc.printf(" Hello World !\r \n");
        pc.printf(" laten we dit nog een beetje verder testen.\r \n ");
        if(i2c.write(0x1B<<1, buffer, 1) != 1){
            pc.printf("failed to set pointer \r \n");
        }
        else{printf("YESSSS");}
        if(i2c.read(0x1B<<1,buffer,1) != 1){
            pc.printf("failed to read from device");
        }
        pc.printf(" get chip id: %d", buffer[0]);
        myled = 1;
        wait(0.5);
        myled = 0;
        wait(0.5);
    }
}*/
#include "mbed.h"
 
#define RELAY_BOARD_ADDR (0x1B<<1)
#define LOOP_WAIT_TIME   2.0
 
I2C i2c(PB_9, PB_8);
//I2C i2c(I2C_SDA, I2C_SCL);
Serial pc(SERIAL_TX, SERIAL_RX); // tx, rx
DigitalOut myled(LED1);
 
int main()
{
 
    char buffer[1];
    char buffer2[5];
    buffer[0] = 0x03;
     
    while (1) {
        
        pc.printf("wat is het res: %d \r \n",i2c.write(0x1B<<1, buffer, 1, 0));
        wait(1);
        pc.printf("res 2: %d \r \n",i2c.read(0x1B<<1, buffer2, 1, 0));
        myled = !myled;
        wait(1);
        pc.printf("Test test 2 %d \r \n ", (int) buffer2[0]);
 
        wait(LOOP_WAIT_TIME);
    }
 
}
