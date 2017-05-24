#include <stdio.h>
#include <stdlib.h>



int main()
{
    int number=0;
    printf("Your number is: ");
    scanf("%d", &number);

    switch (number){
        case 0: printf("Zero");
            break;
        case 1: printf("One");
            break;
        case 2: printf("Two");
            break;
        case 3: printf("Thre");
            break;
        case 4: printf("Four");
            break;
        case 5: printf("Five");
            break;
        case 6: printf("Six");
            break;
        case 7: printf("Seven");
            break;
        case 8: printf("Eight");
            break;
        case 9: printf("Nine");
            break;
        default: printf("Invalid value!");
    }
    return 0;
}
