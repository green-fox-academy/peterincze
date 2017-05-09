#include <stdio.h>

int main() {
    int i;
    for(i = 0; i<20; i++){
        if (i % 2 == 0){
            printf("%d \n", i);
        }
    }
	// print the even numbers till 20
	return 0;
}
