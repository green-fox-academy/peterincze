#include <stdio.h>
#include <stdlib.h>


int main()
{
    int int_array[] = {1, 654, 987, 654, 31};
    float float_array[] = {1.2, 3.14, 1.41, 0.707, 1.73};

     //TODO:
    // Print out the content of the arrays
    int a = sizeof(int_array) / sizeof(int);
    int b = sizeof(float_array) / sizeof(float);

    for (int i = 0; i < a ; i++) {
        printf("%d\n", int_array[i]);
    }
    for (int j = 0; j < a ; j++) {
        printf("%f\n", float_array[j]);
    }


    return 0;
    return 0;
}
