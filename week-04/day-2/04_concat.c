#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
TODO: Implement a function that concatenates 2 strings (dest and source).
The return value should be the concatenated strings.
*/
char *concatenate(char *dest[], char *source[])
{
    strcat(dest, source);
    return *dest;
}

int main()
{
   char first_name[50] = "Pityuka";
   char last_name[] = "Kiss";
     //TODO:
    // Print out the content of the arrays
    concatenate(first_name, last_name);
    printf("%s", first_name);

    return 0;

}
