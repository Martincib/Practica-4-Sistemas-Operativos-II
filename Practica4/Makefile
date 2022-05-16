# Makefile


CC = gcc
CPPFLAGS = -Wall -fopenmp

Practica4: Main.o Matrix_AdOn.o
	$(CC) $(CPPFLAGS) -o $@ $^

%o:%.c
	$(CC) $(CPPFLAGS) -c $<

clean:
	rm *.o
	rm Practica4
