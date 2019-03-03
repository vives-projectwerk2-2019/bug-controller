# EEPROM read
Can be used to read out the data of the dongles that will be used and also for the ID.

The i2c slave address for this EEPROM is 0xA0 (8bit). The EEPROM has a memory space of 8kbyte, you can address this with 12 address bits so 2 bytes must be used. I've decided to place the ID at "0x0F 0xE0", this are the last 16 bytes. I've assumed we use a 128 bit ID so that equals to 16 bytes.

## Datasheet
For further info about the EEPROM used (eeprom 24aa64t-i/ot) you can consult the datasheet by using following link:
http://ww1.microchip.com/downloads/en/devicedoc/21189r.pdf
