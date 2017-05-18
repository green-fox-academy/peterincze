#include <stdio.h>
#include <stdlib.h>



/** TODO:
 * Create a function called "range" that creates a new array and returns a pointer to it.
 * It should fill the array with numbers based on it's paramters.
 * It should take 3 paramters:
 * int from: the first number in the array
 * int to: it will fill the array till it would reach this number (so this number is not in the array)
 * int step: the step between the numbers
 *
 * Examples:
 * range(0, 10, 2) -> {0, 2, 4, 6, 8}
 * range(1, -8, -3) -> {1, -2, -5}
 *
 * It should delete any dynamically allocated resource before the program exits.
 */

 int* Arr(int from1, int to1, int step1) {
    int length = (to1-from1)/ step1;
    int* arr = malloc(length * sizeof(int));
    for (int i=0; i<length; i++) {
        arr[i]= from1;
        from1 += step1;
    }
    return arr;
}


int main() {

    int from=0;
    int to=0;
    int step=0;
    printf("From:");
    scanf("%d",&from);
    printf("To:");
    scanf("%d",&to);
    printf("Step:");
    scanf("%d",&step);


    int* back=Arr(from, to, step);

    for(int i=0; i<5; i++) {
        printf("%d\n",back[i] );
    }
   // int* arr;
   // printf("%d", *arr);

  return 0;
}
