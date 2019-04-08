#include "mbed.h"
#include "Array8bits.h"

Array8Bits::Array8Bits()
{
  size = 0;
  buffer = (uint8_t*) malloc(size);
}

Array8Bits::~Array8Bits()
{
  free(buffer);
}

Array8Bits& Array8Bits::addUint8(uint16_t value)
{
  reallocBuffer(1).writeUint16(value);
  return *this;
}

Array8Bits& Array8Bits::addArray(uint8_t* value, uint8_t size)
{
  this->size = size;
  std::cout<<"size"<<size<<" ";
  for(int i = 0; i < size; i++){
    addUint8(value[i]);
    //std::cout<<"value: " <<value[i]<<endl;
  }
  return *this;
}



LoRaEncoder Array8Bits::reallocBuffer(int delta) 
{
    void* temp = realloc(buffer, (size + delta) * sizeof(uint8_t));
    if (temp == NULL) {
        free(buffer);
        printf("bad memory allocation!");
        while(true);
    } else {
        buffer = (uint8_t*) temp;
    }
    LoRaEncoder encoder(buffer + size);
    size += delta;
    return encoder;
}

uint8_t* Array8Bits::getMessage()
{
  return buffer;
}

uint8_t Array8Bits::getLength()
{
  return size;
}