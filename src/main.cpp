#include "mbed.h"
#include "Simple-LoRaWAN.h"
#include "LoRaMessage.h"
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
DigitalOut myled(PC_8);
DigitalOut myled2(PC_9);
DigitalOut myled3(PC_10);
DigitalOut myled4(LED1);


Node node(devEui, appEui, appKey);
unsigned int dir, act;

int main(void)
{
  while(true){
  myled = 1;
  myled2 = 1;
  myled3 = 1;
  myled4 = 1;
  wait(0.2);
  myled = 0;
  myled2 = 0;
  myled3 = 0;
  myled4 = 0;
  wait(0.2);
  }
  char id[8] = {};
  char* testid = id;

  pc.baud(115200);

  //switch kan nog niet uitgetest worden
  //PCA9548A s(&i2c1);
  //s.write_sel(0);

  EEPROM d(&i2c1);
  wait(1);
  d.get_id(testid, 8);
  pc.printf("id: %s",testid);

  pc.printf("\r\n*** Starting LoRaWAN Shield Example ***\r\n");

  QT1070 direction(&i2c1);
  QT1070 action(&i2c2);

  LoRaMessage ident, addon;
  for(int i = 0; i<8; i++){
    unsigned int testId = id[i];
    //cout<<id[i]<<"\r \n";
    addon.addUint8(testId);
  }
  wait(0.5);
  //s.write_sel(1);
  char add_on[] = {0x00, 0x01, 0x02,0x03,0X04,0X05, 0x06, 0X07};
  // s.write_sel(2);
  for(int i = 0; i<8; i++){
    addon.addUint8(add_on[i]);
  }
  char add_on2[] = {0x00, 0x01, 0x02,0x03,0X04,0X05, 0x06, 0X00};
  for(int i = 0; i<8; i++){
    addon.addUint8(add_on2[i]);
  }
  char add_on3[] = {0x00, 0x01, 0x02,0x03,0X04,0X05, 0x06, 0X01};
  for(int i = 0; i<8; i++){
    addon.addUint8(add_on3[i]);
  }
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