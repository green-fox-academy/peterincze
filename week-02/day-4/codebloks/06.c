#include <stdio.h>

int main() {
    int number = 1234;
    //TODO:
    // print the memory address of the variable
    printf("Address \t Name \t Value \n");
    printf("%p \t %s \t %d \n", &number, "number", number);
    return 0;
}
