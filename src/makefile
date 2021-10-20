
CFLAGS=-O3 -g -o
CFLAGS_LIB=-c -O3 -g 


all:	mm500exe mm512exe mm1000exe mm1024exe mm2000exe mm2048exe



mm500exe: vector_lib.a matrix_lib.a
	gcc matmul_N500.c vector_lib.a matrix_lib.a $(CFLAGS) mm500exe

mm512exe: vector_lib.a matrix_lib.a
	gcc matmul_N512.c vector_lib.a matrix_lib.a $(CFLAGS)  mm512exe

mm1000exe: vector_lib.a matrix_lib.a
	gcc matmul_N1000.c vector_lib.a matrix_lib.a $(CFLAGS) mm1000exe

mm1024exe: vector_lib.a matrix_lib.a
	gcc matmul_N1024.c vector_lib.a matrix_lib.a $(CFLAGS) mm1024exe

mm2000exe: vector_lib.a matrix_lib.a
	gcc matmul_N2000.c vector_lib.a matrix_lib.a $(CFLAGS) mm2000exe

mm2048exe: vector_lib.a matrix_lib.a
	gcc matmul_N2000.c vector_lib.a matrix_lib.a $(CFLAGS) mm2048exe

vector_lib.a: vector_lib.o
	ar rc vector_lib.a vector_lib.o


matrix_lib.a: matrix_lib.o 
	ar rc matrix_lib.a matrix_lib.o 

vector_lib.o: vector_lib.c
	gcc $(CFLAGS_LIB) vector_lib.c


matrix_lib.o: matrix_lib.c
	gcc $(CFLAGS_LIB) matrix_lib.c

clean:
	rm -f *.o  *.a mm500exe mm512exe mm1000exe mm2000exe mm1024exe mm2048exe 

