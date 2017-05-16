#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

#define TOTORO 19

// Define the TOTORO macro which holds the number of students in our class

int main()
{
    // Use the #ifdef and #ifndef macros!

    // If the TOTORO macro is not defined print out 32
    #ifndef TOTORO
        printf("the TOTORO macro is not defined print error 32");
    #endif // TOTORO
    // If the TOTORO macro is defined print out it's value
    #ifdef TOTORO
        printf("Totoro class member count:\t%d", TOTORO);
    #endif // TOTORO

    return 0;
}
