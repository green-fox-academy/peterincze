#include <stdio.h>
#include <stdint.h>

int main() {
	float w = 24;
	int out = 0;
	if ((int) w % 2 == 0){
        out++;
	}
	printf("%d \n", out);
	// if w is even increment out by one
	return 0;
}
