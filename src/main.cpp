#include "mbed.h"
#include "Simple-LoRaWAN.h"
#include "LoRaMessage.h"
#include <string>
#include "QT1070.h"
#include "dongles.h"

using namespace SimpleLoRaWAN;

uint8_t devEui[8] = { 0x00, 0x9E, 0x88, 0x73, 0x27, 0x27, 0xD8, 0x3C };
uint8_t appEui[8] = { 0x70, 0xB3, 0xD5, 0x7E, 0xD0, 0x01, 0x7E, 0x9E };
uint8_t appKey[16] = { 0xC5, 0x07, 0xF6, 0xC1, 0x45, 0xA9, 0x2F, 0xA2, 0x0C, 0x8F, 0xF4, 0x30, 0xB3, 0x6D, 0x21, 0x2D };


I2C i2c1(I2C_SDA, I2C_SCL);
I2C i2c2(PB_14,PB_13);
Serial pc(SERIAL_TX, SERIAL_RX); // tx, rx
DigitalOut myled(LED1);


//Node node(devEui, appEui, appKey);
unsigned int dir, act;
//unsigned char portData = 0;
int main(void)
{
  Dongle d(&i2c1);
  pc.baud(115200);
  char help[16] = {};
  d.write_test();
  char* test = help;
  wait(1);
  d.get_id(test);
  pc.printf("id: %s",test);
  //pc.printf("\r\n*** Starting LoRaWAN Shield Example ***\r\n");
  //int controllergegevens = 0;   //Range:  255 = 1111 1111 = FF 
                               //        0   = 0000 0000 = 00
    QT1070 direction(&i2c1);
    QT1070 action(&i2c2);
    pc.printf("Chip id = %d \r \n", direction.get_chip_id());
    
    /*wait(0.5);
    unsigned int testId = 156;
    unsigned int add_on = 44;
    unsigned int add_on2 = 43;
    unsigned int add_on3 = 42;
    LoRaMessage addon;
    addon.addUint8(testId); 
    addon.addUint8(add_on); 
    addon.addUint8(add_on2);
    addon.addUint8(add_on3);
    node.send(addon.getMessage(), addon.getLength());
  */
  while(true) {
    if(direction.get_pressed_key()>15){
      dir = 0;
    }
    else{
      dir = direction.get_pressed_key();
    }
    if(action.get_pressed_key() < 16){
      act = 0;
    }
    else{
      act = action.get_pressed_key();
    }
    /*LoRaMessage message;
    message.addUint8(dir);
    message.addUint8(act);
    node.send(message.getMessage(), message.getLength(), 2);
    */
    pc.printf("Message sent. message: %d en %d\r\n",dir,act); 
    
    wait(3);
  }
}