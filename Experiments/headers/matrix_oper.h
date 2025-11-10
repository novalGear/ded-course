#ifndef _MATRIX_OPERATIONS_H__
#define _MATRIX_OPERATIONS_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_triange_array(int array[], size_t array_size);
void print_matrix(int *matrix, size_t size_x, size_t size_y);

void insert_in_triange_matrix(int *matrix, int insert_val, size_t size_y, size_t x, size_t y);

int *make_matrix(size_t size_x, size_t size_y);
int *make_triangle_matrix(size_t size_x, size_t size_y);

void draw_rhombus(int rhomb_size);
void draw_circle(double R);

int * multipy_matrix(int *m1, int *m2, size_t m1_x, size_t m1_y, size_t m2_x, size_t m2_y);

void dynamic_matrix();

// int* find_reverse_matrix(int* matrix; size_t m_size);
#endif //_MATRIX_OPERATIONS_H__
