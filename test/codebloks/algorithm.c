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
    /* Write a function which is called "get_fibonacci_number". It returns the "N"th
 * Fibonacci number, where "N" is received as a paramter.
 * For example:
 *  - get_fibonacci_number(1) returns 0
 *  - get_fibonacci_number(2) returns 1
 *  - get_fibonacci_number(3) returns 1
 *  - get_fibonacci_number(4) returns 2
 *  - get_fibonacci_number(5) returns 3
 *  - get_fibonacci_number(6) returns 5
 *
 *  If the function gets invalid parameter it returns -1.
 */
    int number=0;
    printf("pleas the number!");
    scanf("%d", &number);
    if (number <0){
        printf("-1");
    }else{
        int s= Get_fibonacci_number(number);
        printf("\n%d ", s);
    }
    return 0;
}
