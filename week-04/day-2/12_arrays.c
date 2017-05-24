#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int numbers[] = {5, 6, 7, 8, 9};
    int* number_pointer;
    number_pointer = &numbers[0];   //cimet rakok bele, nem értéket írok felül
    //TODO:
    // The "number_pointer" should point to the first element of the array called "numbers",
    // than please print its value with it.
    printf("%d", *number_pointer);

    return 0;
}
