#include <stdio.h>
#include <stdlib.h>


//make it work

int main(){

    int number=0;
    int a=0;
    printf("Your number is:");
    scanf("%d", &number);
    printf("\t**********\n\tHello User\n\t**********\nYou have an integer named 'number'\n");
    printf("- for it's memory address please press 1\n");
    printf("- for it's current value please press 2\n");
    printf("- to double it's value please press 3\n");


    while(1){

         scanf("%d", &a);
        if (a==1){
            printf("%x\n", &number);
        }
        else if (a==2){
            printf("%d\n", number);
        }
        else if (a==3){
            number=number*2;
        }
    }

    //next time switch case

    return 0;

}
