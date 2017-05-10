#include <stdio.h>

/* Write a non void function which has a paramters (let's say for example x).
The funtion than returns the "xth" fibonaci number.
What the hack is a fibonacci number? Search it on wikipedia!
*/
int Fib(){
    int a=0;
    int b = 1;
    int c=0;
    int i;
    for (i=0; i<10; i++){
        c=a+b;
        b=a;
        a=c;
        printf("%d, ", b);
    }
    return b;
}

int main(){

    printf("\n%d ", Fib());

    return 0;
}
