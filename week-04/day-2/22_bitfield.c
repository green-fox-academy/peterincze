#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

struct bitfield {
    uint8_t boolean_value_1:1;
    uint8_t boolean_value_2:1;
    uint8_t boolean_value_3:1;
    uint8_t boolean_value_4:1;
    uint8_t boolean_value_5:1;
    uint8_t boolean_value_6:1;
    uint8_t boolean_value_7:1;
    uint8_t boolean_value_8:1;
}bit;

struct not_bitfield {
    uint8_t boolean_value_1;
    uint8_t boolean_value_2;
    uint8_t boolean_value_3;
    uint8_t boolean_value_4;
    uint8_t boolean_value_5;
    uint8_t boolean_value_6;
    uint8_t boolean_value_7;
    uint8_t boolean_value_8;
}not_bit;

int main()
{
    // TODO:
    // Print out the size of both structs (use sizeof() function)
    printf("%d, %d", sizeof(bit), sizeof(not_bit));
    return 0;
}
