#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "libgeometry/out.h"

void circle(int x,int y,double rad)
{
	float pi=3.14;
	double perimetr,area;
	perimetr=2*pi*rad;
	area=pi*pow(rad,2);
	printf("P=%.2lf\n",perimetr);
	printf("S=%.2lf",area);
}

