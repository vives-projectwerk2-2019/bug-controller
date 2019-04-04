#include "mbed.h"
#include "Simple-LoRaWAN.h"
#include "LoRaMessage.h"
#include "Array8bits.h"
#include <string>
#include "QT1070.h"
#include "eeprom.h"
#include "PCA9548A.h"

using namespace SimpleLoRaWAN;

uint8_t devEui[8] = { 0x00, 0x9E, 0x88, 0x73, 0x27, 0x27, 0xD8, 0x3C };
uint8_t appEui[8] = { 0x70, 0xB3, 0xD5, 0x7E, 0xD0, 0x01, 0x7E, 0x9E };
uint8_t appKey[16] = { 0xC5, 0x07, 0xF6, 0xC1, 0x45, 0xA9, 0x2F, 0xA2, 0x0C, 0x8F, 0xF4, 0x30, 0xB3, 0x6D, 0x21, 0x2D };


I2C i2c1(I2C_SDA, I2C_SCL);
I2C i2c2(PB_14,PB_13);
Serial pc(SERIAL_TX, SERIAL_RX); // tx, rx
DigitalOut myled(LED1);


Node node(devEui, appEui, appKey);
unsigned int dir, act;

int main(void)
{
  
  //char id[8] = {};
  LoRaMessage ident;
  Array8Bits addon;
  uint8_t pid[] = {0x00 , 0xFA , 0xFB , 0xE9 , 0x95 , 0x5F , 0xA1 , 0xD6};
  addon.addArray(pid, sizeof(pid));
  //char* testid = id;

  pc.baud(115200);

  //switch kan nog niet uitgetest worden
  //PCA9548A s(&i2c1);
  //s.write_sel(0);

  EEPROM d(&i2c1);
  wait(1);
  // d.get_id(testid, 8);
  // pc.printf("pid: %s",testid);

  pc.printf("\r\n*** Starting LoRaWAN Shield Example ***\r\n");

  QT1070 direction(&i2c1);
  QT1070 action(&i2c2);
  
  wait(0.5);
  //s.write_sel(1);
  uint8_t addOn1[] = {0x01 , 0xF0 , 0x0F , 0xAA , 0xF0 , 0x0F , 0xAA , 0xF0};
  addon.addArray(addOn1, sizeof(addOn1));

  uint8_t addOn2[] = {0x01 , 0x0F , 0xAA , 0xF0 , 0x0F , 0xAA , 0xF0 , 0x0F};
  addon.addArray(addOn2, sizeof(addOn2));

  uint8_t addOn3[] = {0x01 , 0xAA , 0xF0 , 0x0F , 0xAA , 0xF0 , 0x0F , 0xAA};
  addon.addArray(addOn3, sizeof(addOn3));

  node.send(addon.getMessage(), addon.getLength());
  
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

    if(dir != 0 || act !=0){
      LoRaMessage message;
      message.addUint8(dir);
      message.addUint8(act);
      node.send(message.getMessage(), message.getLength(), 2);
    }
    pc.printf("Message sent. message: %d en %d\r\n",dir,act); 
    
    wait(3);
  }
}