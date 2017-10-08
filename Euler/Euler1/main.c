#include <stdio.h>
#include <stdlib.h>

/*If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000. */

int main()
{
    int arr[1000];
    int len = sizeof (arr) / sizeof (arr[0]);
    int multiplies = 0;
    for (int i = 0; i < len; i++) {
        arr[i] = i;
    }
    for (int i = 0; i < len; i++) {
        if (arr[i] % 3 == 0 || arr[i] % 5 == 0) {
            multiplies += arr[i];
        }
    }
    printf("%d", multiplies);
    return 0;
}
