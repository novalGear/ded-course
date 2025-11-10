#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "matrix_oper.h"

int main()
{
    srand(time(NULL));

    draw_rhombus(21);
    printf("---------------------\n");
    draw_circle(20);
    printf("--------------------\n");
    dynamic_matrix();
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print_triange_array(array, sizeof(array)/sizeof(array[0]));

    printf("\n");

    int matrix[5][4] = {
    {11, 12, 13, 14},
    {21, 22, 23, 24},
    {31, 32, 33, 34},
    {41, 42, 43, 44},
    {51, 52, 53, 54}};

    print_matrix((int*)matrix, sizeof(matrix)/sizeof(matrix[0]), sizeof(matrix[0])/sizeof(matrix[0][0]));

    int triangle_matrix[4][4] = {
    {1, 0, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 1}};

    int ins = 99;
    int x = 1, y = 3;

    insert_in_triange_matrix((int*)triangle_matrix, ins,
                             sizeof(triangle_matrix[0])/sizeof(triangle_matrix[0][0]), x, y);
    printf("Insert %d on %d %d\n", ins, x, y);
    print_matrix((int*)triangle_matrix, 4, 4);


    ins = 99;
    x = 2, y = 1;
    insert_in_triange_matrix((int *)triangle_matrix, ins,
                             sizeof(triangle_matrix[0])/sizeof(triangle_matrix[0][0]), x, y);
    printf("Insert %d on %d %d\n", ins, x, y);
    print_matrix((int*)triangle_matrix, 4, 4);

    printf("----------\n");
    const int size_x = 5;
    const int size_y = 7;

    int *matrix_ptr = make_matrix(size_x, size_y);
    print_matrix(matrix_ptr, size_x, size_y);

    printf("--------------------\n");

    matrix_ptr = make_triangle_matrix(size_x, size_y);
    print_matrix(matrix_ptr, size_x, size_y);




    printf("---------------------\n");
    draw_circle(20);

    printf("--------------------\n");

    int m1[2][3] = {
    {1, 2, 3},
    {4, 5, 6}};

    int m2[3][5] = {
    {1, 2, 3, 4 ,5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15}};

    int * matrix_mult = multipy_matrix((int*)m1, (int*)m2, sizeof(m1)/sizeof(m1[0]), sizeof(m1[0])/sizeof(m1[0][0]),
                                 sizeof(m2)/sizeof(m2[0]), sizeof(m2[0])/sizeof(m2[0][0]));

    print_matrix(matrix_mult, 2, 5);

    return EXIT_SUCCESS;
}
