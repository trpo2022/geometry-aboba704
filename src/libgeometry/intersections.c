#include "intersections.h"
#include <stdio.h>
#include <stdlib.h>

int intersection(char* cx1, char* cy1,
				 char* cx2, char* cy2,
				 char* cr1, char* cr2)
{
	int x1, y1, x2, y2, r1, r2;
	
	x1 = atoi(cx1);
	y1 = atoi(cy1);
	x2 = atoi(cx2);
	y2 = atoi(cy2);
	r1 = atoi(cr1);
	r2 = atoi(cr2);
	
	int distSq = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	int radSumSq = (r1 + r2) * (r1 + r2);
	
	if (distSq == radSumSq)
		return 1;
	else if (distSq > radSumSq)
		return -1;
	else
		return 0;
}

int printIntersection(int t)
{
	if (t == 1)
		printf("Circle touch to each other");
	else if (t < 0)
		printf("Circle not touch to each other");
	else
		printf("Circle intersect to each other");
	return 0;
}