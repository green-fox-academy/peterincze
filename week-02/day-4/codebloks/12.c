#include <stdio.h>

int main() {
    int high_number = 6655;
    int low_number = 2;
    printf("%x \n", high_number);

    int* hight_number_pointer = &low_number;
    int* low_number_pointer = &high_number;
    printf("%x \n", hight_number_pointer);
    printf("%x \n", low_number_pointer);
    //TODO:
    // Please fix the problem and swap where the pointers point,
    // without using the "&" operator.
    int* changePointer = hight_number_pointer;
    hight_number_pointer = low_number_pointer;
    low_number_pointer = changePointer;
    printf("%x \n", hight_number_pointer);
    printf("%x \n", low_number_pointer);

    return 0;
}
