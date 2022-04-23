#include "print.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void printCircle(char *str, char *rad)
{
	float r, p, s;
	r = atoi(rad);
	
	p = 2 * M_PI * r;
	s = M_PI * r * r;
	
	printf("%s", str);
	printf("perimeter: %.2f, area: %.2f\n", p, s);
}