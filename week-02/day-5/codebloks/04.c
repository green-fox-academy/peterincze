#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    srand(time(NULL));
    int a=0;
    printf("What is the maximum?");
    scanf("%d", &a);
    int rnd = rand() % a + 1;
    printf("I've the number between 1-%d. You have 5 lives.\n", a);
    for(int i=5; i>0; i--){
        int number=0;
        printf("your number is:");
        scanf("%d", &number);
        if(number > rnd){
            printf("Too high. You have %d lives left.\n", i-1);
        }
        if(number < rnd){
            printf("Too low. You have %d lives left.\n", i-1);
        }
        if(number==rnd){
            printf("\nCongratulation! You WON!!!!\n");
            break;
        }
        else if(i==1){
            printf("\nYOU LOOS!!!!\n");
            printf("The number was: %d", rnd);
        }

    }

    return 0;
}
