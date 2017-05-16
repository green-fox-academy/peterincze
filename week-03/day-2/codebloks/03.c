#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

#define TOTORO 19
// Define the TOTORO macro which holds the number of students in our class

int main()
{
     // Use the #if, #elif, #else macros

    // If the TOTORO macro is greater than 3 print out "Greater than 3"
    // TOTORO
    #if TOTORO > 3
        printf("Greater than 3");
    #endif
    // If the TOTORO macro is lower than 3 print out "Lower than 3"
    #elif TOTORO < 3
        printf("Lower than 3");
    #endif
	// Else print out "TOTORO is 3"
	#else
        printf("TOTORO is 3");
	#endif

}
