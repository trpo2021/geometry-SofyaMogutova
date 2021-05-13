#include <ctest.h>
#include <libgeometry/out.h>
#include <math.h>

CTEST(check_figure, circle)
{
    char figure[] = "CIRCLE";
    char* s = figure;
    char* e = figure;
    int real = check_figure(&s, &e), exp = CIRCLE;
    ASSERT_EQUAL(exp, real);
}
CTEST(check_figure, circle2)
{
    char figure[] = "Circle";
    char* s = figure;
    char* e = figure;
    int real = check_figure(&s, &e), exp = CIRCLE;
    ASSERT_EQUAL(exp, real);
}
CTEST(check_figure, triangle)
{
    char figure[] = "TRIANGLE";
    char* s = figure;
    char* e = figure;
    int real = check_figure(&s, &e), exp = TRIANGLE;
    ASSERT_EQUAL(exp, real);
}
CTEST(check_figure, triangle2)
{
    char figure[] = "Triangle";
    char* s = figure;
    char* e = figure;
    int real = check_figure(&s, &e), exp = TRIANGLE;
    ASSERT_EQUAL(exp, real);
}
CTEST(splitting, circle3)
{
    Shape circle[1];
    char figure[] = "(0 0 1.5)";
    char* s = figure;
    char* e = figure;
    int figure_counter = 0, real = parse_circle(&s, &e, &figure_counter, circle), exp = COMMA;
    ASSERT_EQUAL(exp, real);
}
CTEST(splitting, triangle3)
{
    Shape triangle[1];
    char figure[] = "((3 2 6 5 -1 3 5 7))";
    char* s = figure;
    char* e = figure;
    int figure_counter = 0, real = parse_triangle(&s, &e, &figure_counter, triangle), exp = COMMA;
    ASSERT_EQUAL(exp, real);
}
CTEST(area, circle4)
{
    float pi = 3.14159, real;
    float circle_area;
    double rad = 1.5;
    circle_area = pi * pow(rad, 2);
    real = circle_area;
    float exp = 7.1;
    ASSERT_EQUAL(exp, real);
}
CTEST(perimetr, circle4)
{
    float pi = 3.14159, real;
    float circle_perimetr;
    double rad = 1.5;
    circle_perimetr = pi * rad * 2;
    real = circle_perimetr;
    float exp = 9.4;
    ASSERT_EQUAL(exp, real);
}
