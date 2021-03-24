#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    char figure[7];
    double x, y, rad;
    char cir[] = "circle";
    printf("Введите фигуру в формате WKT:");
    scanf("%s", figure);
    scanf("%*[( ] %lf %lf %*[, ] %lf %*[) ]", &x, &y, &rad);
    if (strncmp(cir, figure, 6) == 0) {
        if ((x != (int)x) || (y != (int)y) || (rad != (int)rad)) {
            if (rad > 0) {
               circle (x,y,rad);
            } else printf("Error: data entered incorrectly\n");
        } else printf("Error at column 7: expected '<double>'\n");
    } else printf("Error at column 0: expected 'circle'\n");
    return 0;
}
