#include <stdio.h>
#include <stdint.h>

int main() {
	uint8_t u = 123;
	int8_t a = 100;
	if (u > a){
        printf("Hooray!");
	}
	else{
        printf("Oops!");
	}
	// print 'Hooray!' if the number is bigger than 100
	return 0;
}
