// Practica4

/*
        Equipo: Los Bichos
		Hernández Martínez Ramón
		Rendón Deloya Alan
		Paulín Astrid Cassandra
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Matrix_AdOn.h"

int main(int argc, char** argv)
{
	srand(time(NULL));
	int i,j,fila,col;
	int *Mat1=NULL;
	int *Mat2=NULL;
	int NumProcess,MaxHilos,NumHilos;

	double normal,parallel;
	NumProcess = omp_get_num_procs();
	MaxHilos = omp_get_max_threads();

	printf("Numero de procesadores: \t %d\n Numero de hilos: \t%d\n",NumProcess,MaxHilos);

	for (i=1;i<5;i++){
		
		printf("\n-----------------------Hilo Numero. %d----------------------------------\n",i);
		for(j=0;j<6;j++){
			switch (j)
			{
				case 0:
					printf("case 0\n");
					fila = 10;
					col = 20;
					break;
				case 1:
					printf("case 1\n");
					fila = 50;
					col = 50;
					break;
				case 2:
					printf("case 2\n");
					fila = 100;
					col = 200;
					break;
				case 3:
					printf("case 3\n");
					fila = 1000;
					col = 1000;
					break;
				case 4:
					printf("case 4\n");
					fila = 1200;
					col = 1200;
					break;
				case 5:
					printf("case 5\n");
					fila = 1920;
					col = 1080;
					break;
			}
			Mat1 = (int*)malloc(fila*col*sizeof(int));
			fill_mat(Mat1,fila,col);
			Mat2 = (int*)malloc(fila*col*sizeof(int));
			fill_mat(Mat2,fila,col);
			normal = suma_normal(Mat1,Mat2,fila,col);
			parallel = suma_parallel(Mat1,Mat2,fila,col,i);
			printf("\tTiempo normal Suma: %lf Tiempo paralelo Suma: %lf\n",normal,parallel);
			normal = max_valor_normal(Mat1,fila,col);
			parallel = max_valor_parallel(Mat1,fila,col,i);
			printf("\tTiempo normal Max: %lf Tiempo paralelo Max: %lf\n",normal,parallel);

		}
		
	}

	return EXIT_SUCCESS;
}
