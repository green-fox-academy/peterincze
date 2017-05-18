#include <stdio.h>
#include <stdlib.h>

// TODO:
// Please create a program that asks for a count when it starts.
// It should ask for a number count times, then it shoud print the average of the numbers.
// It should delete any dynamically allocated resource before the program exits.

int main() {

    int count=0;
    int a=0;
    float b=0;
    printf("Tell me!\n");
    scanf("%d", &count);
    int* numbers = malloc(count * sizeof(int));
    for (int i=0; i<count; i++) {
        printf("\nThe %d number is:", i+1);
        scanf("%d", &numbers[i]);
        a += numbers[i];
    }
    b = ((float)a/count);
    printf("It is: %f", b);
    free(numbers);

  return 0;
}
