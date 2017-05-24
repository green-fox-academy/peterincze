#include <stdio.h>
#include <stdlib.h>
void Print (int num, char txt[] ){
    for (int i=0; i<num; i++){
        printf("%d %s\n", i, txt);
    }
}


int main()
{
    for(int i = 0; i< 100; i++){
        printf("%d I won't cheat on the test! for\n", i);
    }
    int i=0;
    while(i<100){
        printf("%d I won't cheat on the test! while\n", i);
        i++;
    }
    i=0;
    do{
       printf("%d I won't cheat on the test! do_while\n", i);
        i++;
    }while(i<100);

    int pv=0;
    char wt [255];
    printf("How many times do you want to print?");
    scanf("%d", &pv);
    printf("what do you want to print?");
    scanf("%s", &wt);
    //printf("%s", wt);
    Print(pv, wt);
    return 0;
}
