#include <stdio.h>

int main() {
    char char_array[] = {'a', 'b', 'c', 'd'};
    char char_array_the_same[] = "abcd";

	//TODO:
    // Print out the two arrays character-by-character
    int i;
    for (i=0; i<4; i++){
        printf("%c\n",char_array[i]);
    }
    for (i=0; i<4; i++){
        printf("%c\n",char_array_the_same[i]);
    }

	//TODO:
    // What is the difference between the arrays?

    return 0;
}
