#include <stdio.h>

int main() {
    int int_array[] = {1, 654, 987, 654, 31};
    float float_array[] = {1.2, 3.14, 1.41, 0.707, 1.73};

	//TODO:
    // Print out the content of the arrays
    int i;
    for (i=0; i<5; i++){
        printf("%d, ", int_array[i]);
    }
    for (i=0; i<5; i++){
        printf("%.3f, ", float_array[i]);
    }
    return 0;
}
