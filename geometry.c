#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//Формат записи: <figure> (x y, radius)

int main()
{
	char figure[7];
	double x,y,rad;
	char geometry;
	char cir[]="circle";
	printf("Введите фигуру в формате WKT:");
	scanf("%s", figure);
	scanf("%*[( ] %lf %lf %*[, ] %lf %*[) ]",&x,&y,&rad);
    if (strncmp(cir,figure,6)!=0)
    {
    	printf("Error at column 0: expected 'circle'\n");
    }
    if ((x==(int)x) || (y==(int)y) || (rad==(int)rad))
    {
        printf ("Error at column 7: expected '<double>'\n");
    }
    if (rad<=0)
    {
        printf ("Error: data entered incorrectly");
    }
	return 0;
}
