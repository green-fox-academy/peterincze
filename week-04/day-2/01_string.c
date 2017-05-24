#include <stdio.h>
#include <stdlib.h>


   int main()
{
    char my_name_array[] = "My Name";

    //TODO:
    // Print out the array character-by-character
    for (int i = 0; i < sizeof(my_name_array)/sizeof(char); i++) {
        printf("%c\n", my_name_array[i]);
    }

    return 0;
}
