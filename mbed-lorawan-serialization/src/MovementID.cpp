/*#include "mbed.h"
#include "MovementID.h"
#include "QT1070.h"
#define LOOP_WAIT_TIME   0.5


 
MovementID::MovementID(int pushButton){
  this->pushButton = pushButton;

    QT1070 qt1070(&i2c);
    pc.printf("Chip id = %d \r \n", qt1070.get_chip_id());
    wait(0.5);

    //while (1) {
        pushButton = qt1070.get_value();
        switch (pushButton)
        {
        case 1:
            controllergegevens = 128; //8bits: 1000 0000 "Links"
            break;
        case 2:
            controllergegevens = 64; //8bits: 0100 0000 "Rechts"
            break;
        case 4:
            controllergegevens =  32; //8bits: 0010 0000 "vooruit"
            break;
        case 8:
            controllergegevens =  16; //8bits: 0001 0000 "achteruit"
            break;
        case 16:
            controllergegevens =  8; //8bits: 0000 1000 "BX"
            break;
        case 32:
            controllergegevens =  4; //8bits: 0000 0100 "A"
            break;
        case 64:
            controllergegevens =  2; //8bits: 0000 0010 "XB"
            break;
        default:
            controllergegevens = 0; //8bits: 0000 0000   "Idle"
            break;
        }
        //myled = !myled;
        //wait(LOOP_WAIT_TIME);
        //pc.printf("Pressed button value = %d \r \n", pushButton);
    //}
 
}

int MovementID::to_string(){
  return controllergegevens;
}
*/