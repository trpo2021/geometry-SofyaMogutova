#include "out.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void circle(double rad)
{
    float pi = 3.14;
    double perimetr, area;
    perimetr = 2 * pi * rad;
    area = pi * rad * rad;
    printf("P=%.2lf\n", perimetr);
    printf("S=%.2lf\n", area);
}
