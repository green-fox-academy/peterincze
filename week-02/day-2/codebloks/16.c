#include <stdio.h>
#include <stdint.h>

int main() {
	uint16_t v = 426;
	int8_t a = 4;
	if (v % a == 0){
        printf("Yeah");
	}
	// print 'Yeah!' if dividable by 4 but print 'End of program' after regardless
	return 0;
}
