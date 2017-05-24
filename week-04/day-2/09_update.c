#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number = 1234;
    int* number_pointer = &number;
    *number_pointer = 42;		//ertek feluliras
    //TODO:
    // update the value of number variable to 42 using the "number_pointer"
    printf("%d", *number_pointer);

    return 0;
}
