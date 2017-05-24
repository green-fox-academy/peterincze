#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void safe_union(int *a, int l_a, int *b, int l_b, int *result, int l_res)
{
    //TODO:
    // Implement this function to create the union of a and b into the array result!
    //int len = l_a + l_b;
    for (int i = 0; i < l_a; i++){
        result[i] = a[i];
    }
    int j=0;
    for (int i = l_a; i < l_res; i++){
        result[i] = b[j];
        j++;
    }
    return;
}

int main(int argc, char** argv)
{
    int a[3] = {1,2,3};
    int b[3] = {4,5,6};
    int c[6];
    safe_union(a,3,b,3,c,6);
    for (int i = 0; i<6; i++) {
        printf("%d\n", c[i]);
    }
    return 0;
}
