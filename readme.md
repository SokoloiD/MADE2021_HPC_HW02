 
# Домашнее задание №2 по курсу "Высокопроизводительные вычисления" Соколов Александр
# 1.Реализовать классическое перемножение матриц и умножение матрицы на вектор## 
# 2. Разбейте на модули, со статической линковкой скомпилируйте

Файлы находятся в подпапке /src
```
makefile
matmul_N1000.c
matmul_N1024.c
matmul_N2000.c
matmul_N2024.c
matmul_N500.c
matmul_N512.c

matrix_lib.c
matrix_lib.h
vector_lib.c
vector_lib.h
```
сборка происходит с ключами -g -O3

```
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

```

# 3.Измерьте времена исполнения для размеров $N = 500, 512, 1000, 1024, 2000, 2048
## N500
```
runtime 0.000199 seconds
runtime 0.000218 seconds
runtime 0.000197 seconds
runtime 0.000206 seconds
runtime 0.000210 seconds
average runtime matrix by vector  0.000206 seconds
---------------------------------
runtime 0.033957 seconds
runtime 0.033510 seconds
runtime 0.035873 seconds
runtime 0.033621 seconds
runtime 0.034038 seconds
average runtime matrix by matrix 0.034200 seconds
---------------------------------
```
## N512
```
runtime 0.000157 seconds
runtime 0.000150 seconds
runtime 0.000161 seconds
runtime 0.000187 seconds
runtime 0.000181 seconds
average runtime matrix by vector  0.000167 seconds
---------------------------------
runtime 0.042091 seconds
runtime 0.043061 seconds
runtime 0.048160 seconds
runtime 0.044125 seconds
runtime 0.043353 seconds
average runtime matrix by matrix 0.044158 seconds
---------------------------------
```

## N1000
```
runtime 0.000923 seconds
runtime 0.000934 seconds
runtime 0.000911 seconds
runtime 0.000956 seconds
runtime 0.000932 seconds
average runtime matrix by vector  0.000931 seconds
---------------------------------
runtime 0.711534 seconds
runtime 0.713921 seconds
runtime 0.713605 seconds
runtime 0.716574 seconds
runtime 0.716369 seconds
average runtime matrix by matrix 0.714401 seconds
---------------------------------
```

## N1024
```
runtime 0.000843 seconds
runtime 0.000973 seconds
runtime 0.001208 seconds
runtime 0.000907 seconds
runtime 0.001095 seconds
average runtime matrix by vector  0.001005 seconds
---------------------------------
runtime 0.760929 seconds
runtime 0.763657 seconds
runtime 0.763225 seconds
runtime 0.757601 seconds
runtime 0.760025 seconds
average runtime matrix by matrix 0.761087 seconds
---------------------------------
```

## N2000
```
runtime 0.003311 seconds
runtime 0.003517 seconds
runtime 0.003545 seconds
runtime 0.003534 seconds
runtime 0.003208 seconds
average runtime matrix by vector  0.003423 seconds
---------------------------------
runtime 5.793195 seconds
runtime 5.628238 seconds
runtime 5.533903 seconds
runtime 5.620162 seconds
runtime 5.834721 seconds
average runtime matrix by matrix 5.682044 seconds
---------------------------------
```

## N2048
```
runtime 0.003559 seconds
runtime 0.003447 seconds
runtime 0.003351 seconds
runtime 0.003402 seconds
runtime 0.003422 seconds
average runtime matrix by vector  0.003436 seconds
---------------------------------
runtime 5.631951 seconds
runtime 5.626809 seconds
runtime 5.744932 seconds
runtime 5.806118 seconds
runtime 5.890734 seconds
average runtime matrix by matrix 5.740109 seconds
---------------------------------
```
# 4. Базовые баш скрипты в каталоге /scripts

```
01_print_even_nums
02_print_array
03_float_sum
04_check_file




```
