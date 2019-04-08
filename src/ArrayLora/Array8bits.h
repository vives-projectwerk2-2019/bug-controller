#pragma once

#include <iostream>
#include "stdint.h"
#include "LoRaEncoder.h"
#include "LoRaMessage.h"

class Array8Bits 
{
  public:
    Array8Bits();
    ~Array8Bits();
    LoRaMessage addon;

    Array8Bits& addUint8(uint16_t value);    
    Array8Bits& addArray(uint8_t* value, uint8_t size);

    LoRaEncoder reallocBuffer(int delta);
    uint8_t* getMessage();
    uint8_t getLength();

  private:
    uint8_t* buffer;
    uint8_t size;
};
