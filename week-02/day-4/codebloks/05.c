#include <stdio.h>

int main() {
    char buffer[255];   // Buffer variable for user input
    char petName[255];
    //TODO:
    // Get the user's name with gets
    puts("What is your name?");
    gets(buffer);
    //TODO:
    // Print it out with puts
    puts(buffer);
    //TODO:
    // Get the user's pet name with getch
    puts("What is yout pets name?");
    gets(petName);
    puts(petName);
    //TODO:
    // Print it out

    return 0;
}
