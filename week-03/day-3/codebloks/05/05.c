#include <stdio.h>
#include <stdlib.h>

// TODO:
/**
 * Create a function called "resize" that takes a pointer to an int array, it's size and it's new size,
 * then it should return a new pointer that points to the new resized array.
 * It should copy all the elements to the new array, if the array is bigger it should fill all the new slots with zeros.
 * It should delete the old array.
 */
 int* Resize(int arr_f, int old_size_f, int re_size_f) {
    int* arr = realloc (arr_f, re_size_f * sizeof(int));
    if (old_size_f<re_size_f) {
        for (int i=old_size_f; i< re_size_f; i++) {
            arr[i]=0;
        }

    }
 return arr;
 }


int main() {
    int old_size=10;
    int* arr = malloc(old_size*sizeof(int));
    for (int i= 0; i < 10; i++) {
        arr[i]= i+1;
    }

    for (int i= 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }
    int re_size=8;

    int* back = Resize(arr, old_size, re_size);

    for (int i= 0; i < re_size; i++) {
        printf("%d\n", back[i]);
    }







  return 0;
}
