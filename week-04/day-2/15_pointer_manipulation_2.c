#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int high_number = 6655;
    int low_number = 2;

    int* hight_number_pointer = &low_number;
    int* low_number_pointer = &high_number;
    printf("high_number %p, low_number %p, hight_number_pointer %p, low_number_pointer %p\n", &high_number, &low_number, hight_number_pointer, low_number_pointer);
    //TODO:
    // Please fix the problem and swap where the pointers point,
    // without using the "&" operator.
    int v = hight_number_pointer;
    hight_number_pointer = low_number_pointer;
    low_number_pointer = v;
    printf("high_number %p, low_number %p, hight_number_pointer %p, low_number_pointer %p", &high_number, &low_number, hight_number_pointer, low_number_pointer);


    return 0;
}
