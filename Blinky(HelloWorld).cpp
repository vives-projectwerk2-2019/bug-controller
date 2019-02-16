#include "mbed.h"

DigitalOut myled(LED1);
Serial pc(SERIAL_TX, SERIAL_RX); // tx, rx
int main() {
    pc.printf("test dubbel");
    while(1) {
        pc.printf("Hello World !\r\n");
        myled = 1;
        wait(0.5);
        myled = 0;
        wait(0.5);
    }
}
