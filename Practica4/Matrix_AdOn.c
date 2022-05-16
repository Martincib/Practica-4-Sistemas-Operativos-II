
#include "Matrix_AdOn.h"

void fill_mat(int* mat,int fila,int col){
    int r,c;
    for(r = 0; r < fila; r++)
	{
		for(c = 0; c < col; c++)
		{
			*(mat + r * col + c) = rand()%255;
		}
	}

}

double suma_normal(int*Mat1,int*Mat2,int fila,int col){

    struct timespec t0, t1;
	double TimeUsed;

    int r,c,*r_mat=NULL;

    if(clock_gettime(CLOCK_REALTIME,&t0) != 0)
	{
		printf("Error en t0\n");
		exit(EXIT_FAILURE);
	}

    r_mat=(int*)malloc(fila*col*sizeof(int));
    for(r = 0; r < fila; r++)
	{
		for(c = 0; c < col; c++)
		{
			*(r_mat + r * col + c) = *(Mat1 + r * col + c)+*(Mat2 + r * col + c);
		}
	}
    if(clock_gettime(CLOCK_REALTIME, &t1) != 0)
	{
		printf("Error en t1\n");
		exit(EXIT_FAILURE);
	}
    TimeUsed = (double)(t1.tv_sec - t0.tv_sec) + ((double)(t1.tv_nsec - t0.tv_nsec)/1000000000L);
    return TimeUsed;
}

double max_valor_normal(int* mat,int fila ,int col){
    int r,c,max=0;
    struct timespec t0, t1;
	double TimeUsed;
    if(clock_gettime(CLOCK_REALTIME,&t0) != 0)
	{
		printf("Error en t0\n");
		exit(EXIT_FAILURE);
	}

	for(r = 0; r < fila; r++)
	{
		for(c = 0; c < col; c++)
		{
			if(*(mat + r * col + c)>max) max = *(mat + r * col + c);
		}
	}
     if(clock_gettime(CLOCK_REALTIME,&t1) != 0)
	 {
	 	printf("Error en t1\n");
	 	exit(EXIT_FAILURE);
	}

    TimeUsed = (double)(t1.tv_sec - t0.tv_sec) + ((double)(t1.tv_nsec - t0.tv_nsec)/1000000000L);
    return TimeUsed;
}

double suma_parallel(int*Mat1,int*Mat2,int fila,int col,int threads){
    struct timespec t0, t1;
	double TimeUsed;

    int r,c,*r_mat=NULL;
    r_mat=(int*)malloc(fila*col*sizeof(int));
    omp_set_num_threads(threads);
    if(clock_gettime(CLOCK_REALTIME,&t0) != 0)
	{
		printf("Error en t0\n");
		exit(EXIT_FAILURE);
	}
    #pragma omp parallel for private(c)
    for(r = 0; r < fila; r++)
	{
		for(c = 0; c < col; c++)
		{
			*(r_mat + r * col + c) = *(Mat1 + r * col + c)+ *(Mat2 + r * col + c);
		}
	}
    if(clock_gettime(CLOCK_REALTIME, &t1) != 0)
	{
		printf("Error en t1\n");
		exit(EXIT_FAILURE);
	}
    TimeUsed = (double)(t1.tv_sec - t0.tv_sec) + ((double)(t1.tv_nsec - t0.tv_nsec)/1000000000L);
    return TimeUsed;
}

double max_valor_parallel(int*mat,int fila,int col,int threads){
    struct timespec t0, t1;
	double TimeUsed;

    int r,c,max=0;
    omp_set_num_threads(threads);
    if(clock_gettime(CLOCK_REALTIME,&t0) != 0)
	{
		printf("Error en t0\n");
		exit(EXIT_FAILURE);
	}
    #pragma omp parallel for private(c)
    for(r = 0; r < fila; r++)
	{
		for(c = 0; c < col; c++)
		{
			if(*(mat + r * col + c)>max) max = *(mat + r * col + c);
		}
	}
    if(clock_gettime(CLOCK_REALTIME, &t1) != 0)
	{
		printf("Error en t1\n");
		exit(EXIT_FAILURE);
	}
    TimeUsed = (double)(t1.tv_sec - t0.tv_sec) + ((double)(t1.tv_nsec - t0.tv_nsec)/1000000000L);
    return TimeUsed;
}
