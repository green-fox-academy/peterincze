#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int high_number = 2;
    int low_number = 6655;

    int* hight_number_pointer = &high_number;
    int* low_number_pointer = &low_number;
     printf("high_number\t, low_number\t, hight_number_pointer\t, low_number_pointer\n %p\t %p\t %p\t %p\t\n", &high_number, &low_number, hight_number_pointer, low_number_pointer);
    //TODO:
    // Please fix the problem and swap the value of the variables,
    // without using the "high_number" and the "low_number" variables.
    int v = high_number;
    high_number = low_number;
    low_number = v;
    printf("%p\t %p\t %p\t %p\t\n", &high_number, &low_number, hight_number_pointer, low_number_pointer);
    printf("%d\t %d\t %d\t %d\t\n", high_number, low_number, *hight_number_pointer, *low_number_pointer);
    return 0;
}
