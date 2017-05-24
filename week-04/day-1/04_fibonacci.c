#include <stdio.h>
#include <stdlib.h>

int Get_fibonacci_number(int n){
    int a=0;
    int b = 1;
    int c=0;
    int i;
    for (i=0; i<n; i++){
        c=a+b;
        b=a;
        a=c;
    }
    return b;
}

int main()
{
    int number=0;
    printf("The number is....");
    scanf("%d", &number);
    if (number <1){
        printf("-1");
    }else{
        int s= Get_fibonacci_number(number);
        printf("\n%d ", s);
    }
    return 0;
}
