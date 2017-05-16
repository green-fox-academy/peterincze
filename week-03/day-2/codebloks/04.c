#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

#define TOTORO 19
// Define the TOTORO macro which holds the number of students in our class

int main()
{
    // If TOTORO is not defined throw a preprocessor error
    #ifndef TOTORO
        #error TOTORO is not defined!
    #endif // TOTORO

    printf("Class members: %d", TOTORO);
    return 0;
}
