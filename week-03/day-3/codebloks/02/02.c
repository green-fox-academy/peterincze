#include <stdio.h>
#include <stdlib.h>

int main() {
 // int* pointer = NULL;

  // TODO:
  // Please allocate a 5 long array and fill it with numbers from 0 to 4, then print the whole array
    int* data = calloc (5 ,sizeof(int));
    for(int i=0; i<5; i++) {
        data[i]=i;
    }
    for(int i=0; i<5; i++) {
        printf("%d\n", data[i]);
    }

  // Please delete the array before the program exits
    free (data)
    for(int i=0; i<5; i++) {
        printf("%d\n", data[i]);
    }

  return 0;
}
