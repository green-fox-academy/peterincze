#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Add two numbers using pointers
*/


int main()
{

    int a  = 20;
    int b = 17;

    int *c = &a;
    int *d = &b;

    printf("%d, %d", *c, *d);

    return 0;
}
