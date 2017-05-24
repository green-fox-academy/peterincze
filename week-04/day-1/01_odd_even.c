#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number=0;
    printf("your number is: ");
    scanf("%d", &number);
    if (number%2==0){
        printf("It is even.\n");
    } else{
        printf("It is odd.\n");
    }
    return 0;
}
