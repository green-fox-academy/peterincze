#include <stdio.h>
#include <stdlib.h>

int main()
{
    int year;
    char name [255];
    printf("What is your name?");
    scanf("%s", &name);
    printf("what is your birth year?");
    scanf("%d", &year);

    int a= 2017-year;
    int b= 100-a;

    printf("You mast wait to %d years to will be 100 years old", b);


    return 0;
}
