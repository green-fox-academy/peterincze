#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Print out the addresses with and without pointer
print out the values with and without pointer
 */


int main()
{
    int number = 2017;
    float Pi = 3.14;
    char letter = 't';

    int *num = &number;
    float *Pi2 = &Pi;
    char *let = &letter;

    printf("%p, %p, %p\n", &number, &Pi, &letter);
    printf("%p, %p, %p\n", num, Pi2, let);

    printf("%d, %f, %c\n", number, Pi, letter);
    printf("%d, %f, %c\n", *num, *Pi2, *let);


    return 0;
}
