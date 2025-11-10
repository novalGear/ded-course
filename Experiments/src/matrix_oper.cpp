#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "matrix_oper.h"

void print_triange_array(int array[], size_t array_size)
{
    size_t elems_in_line = 1;
    size_t count_elems_in_line = 0;

    for(size_t i = 0; i < array_size; i++)
    {
        printf("%d ", *(array + i));
        count_elems_in_line++;

        if(count_elems_in_line == elems_in_line)
        {
            printf("\n");
            elems_in_line++;
            count_elems_in_line = 0;
        }
    }
}

void print_matrix(int *matrix, size_t size_x, size_t size_y)
{
    for(size_t x = 0; x < size_x; x++)
    {
        for(size_t y = 0; y < size_y; y++)
        {
            printf("%d ", *(matrix + x * size_y + y));
        }
        printf("\n");
    }
}

void insert_in_triange_matrix(int *matrix, int insert_val, size_t size_y, size_t x, size_t y)
{
    if(x >= y)
    {
        *(matrix + x * size_y + y) = insert_val;
    }
    else
    {
        *(matrix + y * size_y + x) = insert_val;
    }
}

int *make_matrix(size_t size_x, size_t size_y)
{
    int *matrix = (int*)calloc(size_x * size_y, sizeof(int));

    for(size_t x = 0; x < size_x; x++)
    {
        for(size_t y = 0; y < size_y; y++)
        {
            *(matrix + x * size_y + y) = rand();
        }
    }

    return matrix;
}


int *make_triangle_matrix(size_t size_x, size_t size_y)
{
    int *matrix = (int*)calloc(size_x * size_y, sizeof(int));

    for(size_t x = 0; x < size_x; x++)
    {
        for(size_t y = 0; y < x; y++)
        {
            *(matrix + x * size_y + y) = rand();
        }
    }

    return matrix;
}

void draw_rhombus(int rhomb_size)
{
    int n_left = 0, n_right = 0;

    for(int i = 1; i < rhomb_size - 1; i++)
    {
        n_left = abs(rhomb_size / 2 - i);
        n_right = 2 * (rhomb_size / 2 - n_left - 1);

        for(int k = 0; k < n_left; k++)
        {
            printf(" ");
        }
        printf("%d", 1);
        for(int k = 0; k < n_right; k++)
        {
            printf(" ");
        }
        if(n_right > 0)
        {
            printf("%d", 1);
        }
        printf("\n");
    }
}

void draw_circle(double R)
{
    int n_left = 1, n_right=1;
    double step = 3.5 / R;

    for(double x = 1; x < 4; x = x + step)
    {
        double a = 2.5 - fabs(x - 2.5);
        n_left = round(R / (a * a * a));
        n_right = round(R) - n_left;

        for(int k = 0; k < n_left; k++)
        {
            printf(" ");
        }
        printf("%d", 1);
        for(int k = 0; k < n_right; k++)
        {
            printf("  ");
        }
        printf("%d\n", 1);
    }
}

int *multipy_matrix (int *m1, int *m2, size_t m1_x, size_t m1_y, size_t m2_x, size_t m2_y)
{
    assert(m1_y == m2_x);
    if(m1_y != m2_x)
    {
        fprintf(stderr, "Cannot multipy matrixes with sizes %d * %d and %d * %d", m1_x, m1_y, m2_x, m2_y);
        return NULL;
    }

    int *matrix = (int*)calloc(m1_x * m2_y, sizeof(int));//assert

    //matrix[i][j] = m1[i][r] * m2[r][j]

    for(size_t r = 0; r < m1_y; r++)
    {
        for(size_t i = 0; i < m1_x; i++)
        {
            for(size_t j = 0; j < m2_y; j++)
            {
                *(matrix + i * m2_y + j) += *(m1 + i * m1_y + r) * *(m2 + r * m2_y + j);
            }
        }
    }

    return matrix;
}

void dynamic_matrix()
{
    size_t n_arrays = 0;
    printf("[dynamic matrix]\n");
    printf("Enter number of strings in two-dimensional matrix\n");

    while(scanf("%d", &n_arrays) != 1)
    {
        while(getchar() != '\n')
            continue;
        printf("Only decimal positive number of strings possible");
    }

    int* elems_in_array = (int*)calloc(n_arrays, sizeof(int));

    assert(elems_in_array);

    size_t elems_number = 0;
    printf("Enter number of elements for each string\n");
    for(size_t arr_num = 0; arr_num < n_arrays; arr_num++)
    {
        int n = 0;
        printf("%d: ", arr_num);
        while(scanf("%d", &n) != 1 && n < 0)
        {
            while(getchar() != '\n')
                continue;
            printf("Only decimal positive number of elements possible");
        }
        elems_in_array[arr_num] = n;
        elems_number += n;

    }

    int* matrix = (int*)calloc(elems_number, sizeof(int));
    int ** pointers_array = (int**)calloc(n_arrays, sizeof(int));
    pointers_array[0] = &matrix[0];
    for(size_t i = 1; i < n_arrays; i++)
    {
        pointers_array[i] = elems_in_array[i-1] + pointers_array[i-1];
    }

    for(size_t i = 0; i < n_arrays; i++)
    {
        printf("%d %p %d %d\n", elems_in_array[i], pointers_array[i], (int)pointers_array[i],
               *pointers_array[i]);
    }

    printf("/////////////////////////////\n");

    for(size_t i = 0; i < n_arrays; i++)
    {
        for(size_t j = 0; j < elems_in_array[i]; j++)
        {
            pointers_array[i][j] = rand();
            printf("%d ", pointers_array[i][j]);
        }
        printf("\n");
    }
}

// int* find_reverse_matrix(int* matrix; size_t m_size)
// {
//
// }
