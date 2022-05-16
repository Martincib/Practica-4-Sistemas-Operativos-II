
#pragma once

#ifndef Matrix_AdOn_h
#define Matrix_AdOn_h


#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <unistd.h>
#include <time.h>


void fill_mat(int*,int,int);
double suma_normal(int*,int*,int,int);
double suma_parallel(int*,int*,int,int,int);
double max_valor_normal(int*,int,int);
double max_valor_parallel(int*,int,int,int);





#endif
