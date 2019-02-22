#include "mbed.h"
#include "Simple-LoRaWAN.h"
#include "LoRaMessage.h"
#include <string>
#include "MovementID.h"

using namespace SimpleLoRaWAN;

uint8_t devEui[8] = { 0x00, 0x9E, 0x88, 0x73, 0x27, 0x27, 0xD8, 0x3C };
uint8_t appEui[8] = { 0x70, 0xB3, 0xD5, 0x7E, 0xD0, 0x01, 0x7E, 0x9E };
uint8_t appKey[16] = { 0xC5, 0x07, 0xF6, 0xC1, 0x45, 0xA9, 0x2F, 0xA2, 0x0C, 0x8F, 0xF4, 0x30, 0xB3, 0x6D, 0x21, 0x2D };

Serial pc(USBTX, USBRX, 115200);

Node node(devEui, appEui, appKey);

int main(void)
{
  pc.baud(115200);
  pc.printf("\r\n*** Starting LoRaWAN Shield Example ***\r\n");
  
  //int controllergegevens = 0;   //Range:  255 = 1111 1111 = FF 
                                //        0   = 0000 0000 = 00
    MovementID id(0);
    MovementID add_on(0);
    LoRaMessage addon;
    addon.addUint8( id.to_string());
    addon.addUint16( add_on.to_string()); //verzenden van Add_on -> direct 3 bytes in 1 keer.
    node.send(addon.getMessage(), addon.getLength());

  while(true) {
    MovementID movement(1);
    LoRaMessage message;
    message.addUint8( movement.to_string());
    node.send(message.getMessage(), message.getLength(), '0');
    pc.printf("Message sent. message: %d\r\n", movement.to_string());

    // if (controllergegevens == 255){
    //   controllergegevens = 0;
    // } else { controllergegevens++; }
    
    wait(15.0);
  }
}