#include <ctest.h>
#include <libgeometry/out.h>
#define EMPTY 11

CTEST(determine_figure, circle_figure)
{
    char str[] = { "circle (23 5, 3)\n" };
    char* cursor_start = str;
    char* cursor_end = str;
    int real = determine_figure(&cursor_start, &cursor_end);
    int exp = CIRCLE;
    ASSERT_EQUAL(exp, real);
}

CTEST(determine_figure, triangle_figure)
{
    char str[] = { "triangle ((23 5, 25 10, 14 9, 23 5))\n" };
    char* cursor_start = str;
    char* cursor_end = str;
    int real = determine_figure(&cursor_start, &cursor_end);
    int exp = TRIANGLE;
    ASSERT_EQUAL(exp, real);
}

CTEST(determine_figure, incorrect_figure_1)
{
    char str[] = { "c (23 5, 3)\n" };
    char* cursor_start = str;
    char* cursor_end = str;
    int real = determine_figure(&cursor_start, &cursor_end);
    int exp = UNKNOWN;
    ASSERT_EQUAL(exp, real);
}

CTEST(determine_figure, incorrect_figure_2)
{
    char str[] = { "8circle (23 5, 3)\n" };
    char* cursor_start = str;
    char* cursor_end = str;
    int real = determine_figure(&cursor_start, &cursor_end);
    int exp = UNKNOWN;
    ASSERT_EQUAL(exp, real);
}

CTEST(determine_figure, incorrect_figure_3)
{
    char str[] = { "triannngle ((23 5, 25 10, 14 9, 23 5))\n" };
    char* cursor_start = str;
    char* cursor_end = str;
    int real = determine_figure(&cursor_start, &cursor_end);
    int exp = UNKNOWN;
    ASSERT_EQUAL(exp, real);
}

CTEST(parse_circle, correct)
{
    char str[] = { "(23 5, 3)\n" };
    char* cursor_start = str;
    char* cursor_end = str;
    int figure_counter = 0;
    Shape circle[1];
    int real
        = parse_circle(&cursor_start, &cursor_end, &figure_counter, circle);
    int exp = SUCCESS;
    ASSERT_EQUAL(exp, real);
}

CTEST(parse_circle, miss_left_bracket)
{
    char str[] = { "23 5, 3)\n" };
    char* cursor_start = str;
    char* cursor_end = str;
    int figure_counter = 0;
    Shape circle[1];
    int real
        = parse_circle(&cursor_start, &cursor_end, &figure_counter, circle);
    int exp = LBRACKET;
    ASSERT_EQUAL(exp, real);
}

CTEST(parse_circle, wrong_coord_x)
{
    char str[] = { "(x23 5, 3)\n" };
    char* cursor_start = str;
    char* cursor_end = str;
    int figure_counter = 0;
    Shape circle[1];
    int real
        = parse_circle(&cursor_start, &cursor_end, &figure_counter, circle);
    int exp = X1;
    ASSERT_EQUAL(exp, real);
}

CTEST(parse_circle, wrong_coord_y)
{
    char str[] = { "(23 x5, 3)\n" };
    char* cursor_start = str;
    char* cursor_end = str;
    int figure_counter = 0;
    Shape circle[1];
    int real
        = parse_circle(&cursor_start, &cursor_end, &figure_counter, circle);
    int exp = Y1;
    ASSERT_EQUAL(exp, real);
}

CTEST(parse_circle, miss_comma)
{
    char str[] = { "(23 5 3)\n" };
    char* cursor_start = str;
    char* cursor_end = str;
    int figure_counter = 0;
    Shape circle[1];
    int real
        = parse_circle(&cursor_start, &cursor_end, &figure_counter, circle);
    int exp = COMMA;
    ASSERT_EQUAL(exp, real);
}

CTEST(parse_circle, wrong_radius)
{
    char str[] = { "(23 5, x3)\n" };
    char* cursor_start = str;
    char* cursor_end = str;
    int figure_counter = 0;
    Shape circle[1];
    int real
        = parse_circle(&cursor_start, &cursor_end, &figure_counter, circle);
    int exp = RADIUS1;
    ASSERT_EQUAL(exp, real);
}

CTEST(parse_circle, miss_right_bracket)
{
    char str[] = { "(23 5, 3\n" };
    char* cursor_start = str;
    char* cursor_end = str;
    int figure_counter = 0;
    Shape circle[1];
    int real
        = parse_circle(&cursor_start, &cursor_end, &figure_counter, circle);
    int exp = RBRACKET;
    ASSERT_EQUAL(exp, real);
}

CTEST(parse_circle, extra_token)
{
    char str[] = { "(23 5, 3)  extraa\n" };
    char* cursor_start = str;
    char* cursor_end = str;
    int figure_counter = 0;
    Shape circle[1];
    int real
        = parse_circle(&cursor_start, &cursor_end, &figure_counter, circle);
    int exp = EXTRATOKEN;
    ASSERT_EQUAL(exp, real);
}

CTEST(parse_triangle, correct)
{
    char str[] = { "((23 5, 25 10, 14 9, 23 5))\n" };
    char* cursor_start = str;
    char* cursor_end = str;
    int figure_counter = 0;
    Shape triangle[1];
    int real = parse_triangle(
        &cursor_start, &cursor_end, &figure_counter, triangle);
    int exp = SUCCESS;
    ASSERT_EQUAL(exp, real);
}

CTEST(parse_triangle, miss_left_bracket)
{
    char str[] = { "(23 5, 25 10, 14 9, 23 5))\n" };
    char* cursor_start = str;
    char* cursor_end = str;
    int figure_counter = 0;
    Shape triangle[1];
    int real = parse_triangle(
        &cursor_start, &cursor_end, &figure_counter, triangle);
    int exp = LBRACKET;
    ASSERT_EQUAL(exp, real);
}

CTEST(parse_triangle, wrong_coord_x)
{
    char str[] = { "((23 5, x25 10, 14 9, 23 5))\n" };
    char* cursor_start = str;
    char* cursor_end = str;
    int figure_counter = 0;
    Shape triangle[1];
    int real = parse_triangle(
        &cursor_start, &cursor_end, &figure_counter, triangle);
    int exp = X2;
    ASSERT_EQUAL(exp, real);
}

CTEST(parse_triangle, wrong_coord_y)
{
    char str[] = { "((23 5, 25 10, 14 x9, 23 5))\n" };
    char* cursor_start = str;
    char* cursor_end = str;
    int figure_counter = 0;
    Shape triangle[1];
    int real = parse_triangle(
        &cursor_start, &cursor_end, &figure_counter, triangle);
    int exp = Y3;
    ASSERT_EQUAL(exp, real);
}

CTEST(parse_triangle, miss_comma)
{
    char str[] = { "((23 5, 25 10 14 9, 23 5))\n" };
    char* cursor_start = str;
    char* cursor_end = str;
    int figure_counter = 0;
    Shape triangle[1];
    int real = parse_triangle(
        &cursor_start, &cursor_end, &figure_counter, triangle);
    int exp = COMMA;
    ASSERT_EQUAL(exp, real);
}

CTEST(parse_triangle, match_points)
{
    char str[] = { "((23 5, 25 10, 14 9, 26 8))\n" };
    char* cursor_start = str;
    char* cursor_end = str;
    int figure_counter = 0;
    Shape triangle[1];
    int real = parse_triangle(
        &cursor_start, &cursor_end, &figure_counter, triangle);
    int exp = DONTMATCH;
    ASSERT_EQUAL(exp, real);
}

CTEST(parse_triangle, miss_right_bracket)
{
    char str[] = { "((23 5, 25 10, 14 9, 23 5)\n" };
    char* cursor_start = str;
    char* cursor_end = str;
    int figure_counter = 0;
    Shape triangle[1];
    int real = parse_triangle(
        &cursor_start, &cursor_end, &figure_counter, triangle);
    int exp = RBRACKET;
    ASSERT_EQUAL(exp, real);
}

CTEST(parse_triangle, extra_token)
{
    char str[] = { "((23 5, 25 10, 14 9, 23 5))  extraa\n" };
    char* cursor_start = str;
    char* cursor_end = str;
    int figure_counter = 0;
    Shape triangle[1];
    int real = parse_triangle(
        &cursor_start, &cursor_end, &figure_counter, triangle);
    int exp = EXTRATOKEN;
    ASSERT_EQUAL(exp, real);
}
